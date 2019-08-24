#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/memoria.h"
#include "includes/barramento.h"
#include "includes/registradores.h"
#include "includes/ula.h"
#include "includes/mdu.h"
#include "includes/executionQueue.h"
#include "includes/pipeline.h"
#include "includes/somadorPC.h"
#include "includes/branchPredictor.h"
#include "includes/bypass.h"
#include "includes/tradutor.h"
#include "includes/scoreboarding.h"
#define VAZIO 0

int main(int argc, char *argv[]){

    char programName[20];
    int detail = 0, help = 0;
    
    if(strcmp(argv[1], "-i") == 0){
        strcpy(programName, argv[2]);
    }
    
    if(argc > 3){
        if(strcmp(argv[3], "--detail") == 0){
            detail = 1;
        }

        else if (strcmp(argv[3], "-h") == 0){
            help = 1;
        }
    }

    if(help == 1){
        printf("\n\t\t*****Help -h*****\n\n");
        printf("Executar com o seguinte comando:\n");
        printf("./mips32sim -i <prog>.asm [--detail] [-h]\n\n");
        printf("É obrigatório a flag '-i' para indicar o nome do programa em assembly a ser executado\n");
        printf("<prog> é o nome do programa em assembly com .asm em seguida\n\n");
        printf("Um parâmetro adicional pode ser utilizado.\n");
        printf("'--detail' para gerar o arquivo de saída de modo detalhado\n");
        printf("Ou o modo '-h' que exibe estas instruções\n");
        printf("A omissão deste parâmetro adicional irá executar o programa gerando o arquivo de saída .out em seu modo normal\n\n");
        return 0;
    }


    unsigned int reg[32] = {VAZIO};
    unsigned int HI = 0,LO = 0, PC = 0;
    FILE* out = fopen("prog.out", "w");
    FILE* assembly = fopen(programName, "r");
    FILE* binario = fopen("saida_hex.txt", "r");
    inicializeMemory();
    
    struct instrucoes{
        int estagio,
            indRegistrador,
            endereco,
            dado;
        char *nome;
    };

    int multiplexador;

    struct numerosPrevisao n;
    n.acertos = 0;
    n.erros = 0;
    n.saltos = 0;

    FILA F;

    create(&F);
    ler(programName);
    int total_instrucoes = inserirElementos(&F);
    int total_ciclos = (total_instrucoes - 1) + 5;
    struct instrucoes instrucao[total_instrucoes];
    
    if(strcmp("arq10.asm", programName) == 0){
        printf("\nScoreboarding\n");
        inicializarFus(&F, total_instrucoes);
    }

    arquivoBin();
    arquivoHex();
    
    fclose(assembly);

    //arquivo que exemplifica o uso do scoreboarding
    

    int i;
    for (i = 0; i < total_instrucoes; i++){
        instrucao[i].estagio = VAZIO;
    }


    //execução detalhada
    if(detail == 1){

        char linha[50];
        
        assembly = fopen(programName, "r");

        fprintf(out, "Programa:\n");

        while(!feof(assembly)){
            fgets(linha, 50, assembly);
            fputs("\t", out);
            fputs(linha, out);
        }
        fputs("\n", out);
        fputs("\n", out);
        fclose(assembly);

        char bin[10];

        fprintf(out, "Binário:\n");
        while(!feof(binario)){
            fgets(bin, 10, binario);
            fputs("\t", out);
            fputs(bin, out);
        }
        fputs("\n", out);

        fprintf(out, "Previsão:\n");
        fprintf(out, "\tTotal de saltos: %d\n", n.saltos);
        fprintf(out, "\tAcertos: %d\n", n.acertos);
        fprintf(out, "\tErros: %d\n\n", n.erros);
        fprintf(out, "Ciclos:\n\t%d ciclos\n", total_ciclos);

        int ciclo = 1;

        while(total_ciclos > 0){
        
            fprintf(out, "Ciclo %d:\n", ciclo);

            for (i = 0; i < ciclo; i++){

                if(instrucao[i].estagio >= 5)
                    continue;

                else if(instrucao[i].estagio == 0){
                    
                    instrucao[i].nome = (char*) malloc(7 * sizeof(char));
                    if((PC / 4) < total_instrucoes)
                        strcpy(instrucao[i].nome, Istage(&F, PC));
                    else 
                        continue;
                    instrucao[i].endereco = PC;

                    assembly = fopen(programName, "r");
                    int linha = 0;
                    char inst[50];
                    while(linha <= i){
                        fgets(inst, 50, assembly);
                        linha++;
                    }
                    fprintf(out, "\tBusca:\n");
                    fprintf(out, "\t\t%s\n", inst);
                    fclose(assembly);

                    PC = somarPC(PC);
                    instrucao[i].estagio++;

                }

                else if(instrucao[i].estagio == 1){

                    instrucao[i].indRegistrador = Estage(instrucao[i].nome, &F, instrucao[i].endereco, reg);
                    instrucao[i].estagio++;

                    if(instrucao[i].indRegistrador == 32)
                        PC += returnMultiplexador();

                    else if(instrucao[i].indRegistrador == 33){
                        instrucao[i].estagio = 5;
                        continue;
                    }

                    //suporte ao bypass
                    else
                        reg[instrucao[i].indRegistrador] = returnMultiplexador();

                    assembly = fopen(programName, "r");
                    int linha = 0;
                    char inst[50];
                    while(linha <= i){
                        fgets(inst, 50, assembly);
                        linha++;
                    }
                    fprintf(out, "\tExecução:\n");
                    fprintf(out, "\t\t%s\n", inst);
                    fclose(assembly);

                }

                else if(instrucao[i].estagio == 2){

                    instrucao[i].dado = Mstage(instrucao[i].endereco);
                    instrucao[i].estagio++;

                    assembly = fopen(programName, "r");
                    int linha = 0;
                    char inst[50];
                    while(linha <= i){
                        fgets(inst, 50, assembly);
                        linha++;
                    }
                    fprintf(out, "\tBusca da memória:\n");
                    fprintf(out, "\t\t%s\n", inst);
                    fclose(assembly);

                }

                else if(instrucao[i].estagio == 3){

                    Astage(instrucao[i].endereco);
                    instrucao[i].estagio++;

                    assembly = fopen(programName, "r");
                    int linha = 0;
                    char inst[50];
                    while(linha <= i){
                        fgets(inst, 50, assembly);
                        linha++;
                    }
                    fprintf(out, "\tAlinhamento:\n");
                    fprintf(out, "\t\t%s\n", inst);
                    fclose(assembly);

                }

                else if(instrucao[i].estagio == 4){

                    if(instrucao[i].indRegistrador == 32){
                        instrucao[i].estagio++;
                        continue;
                    }

                    if(reg[instrucao[i].indRegistrador] == instrucao[i].dado)
                        reg[instrucao[i].indRegistrador] = Wstage(instrucao[i].endereco, instrucao[i].dado, instrucao[i].indRegistrador, reg);
                    instrucao[i].estagio++;

                    assembly = fopen(programName, "r");
                    int linha = 0;
                    char inst[50];
                    while(linha <= i){
                        fgets(inst, 50, assembly);
                        linha++;
                    }
                    fprintf(out, "\tEscrita:\n");
                    fprintf(out, "\t\t%s\n", inst);
                    fclose(assembly);

                    fprintf(out, "\tEfetivando:\n");
                    fprintf(out, "\t\t%s\n", inst);

                }

            }

            if(ciclo < total_instrucoes)
                ciclo++;

            total_ciclos--;
        }
        
        fprintf(out, "\nInstruções:\n");
        fprintf(out, "\tEmitidas: %d\n", total_instrucoes);
        fprintf(out, "\tEfetivadas: %d\n", ciclo);


        printRegistradores(reg, HI, LO, PC);

    }

    //execução normal
    else{
        
        int ciclo = 1;

        while(total_ciclos > 0){
        
            for (i = 0; i < ciclo; i++){

                if(instrucao[i].estagio >= 5)
                    continue;

                else if(instrucao[i].estagio == 0){
                    
                    instrucao[i].nome = (char*) malloc(7 * sizeof(char));
                    if((PC / 4) < total_instrucoes)
                        strcpy(instrucao[i].nome, Istage(&F, PC));
                    else 
                        continue;
                    instrucao[i].endereco = PC;
                    
                    
                    PC = somarPC(PC);
                    instrucao[i].estagio++;

                }

                else if(instrucao[i].estagio == 1){

                    instrucao[i].indRegistrador = Estage(instrucao[i].nome, &F, instrucao[i].endereco, reg);
                    instrucao[i].estagio++;
                    
                    if(instrucao[i].indRegistrador == 32)
                        PC += returnMultiplexador();

                    else if(instrucao[i].indRegistrador == 33){
                        instrucao[i].estagio = 5;
                        continue;
                    }

                    //suporte ao bypass
                    else
                        reg[instrucao[i].indRegistrador] = returnMultiplexador();

                }

                else if(instrucao[i].estagio == 2){
                    
                    instrucao[i].dado = Mstage(instrucao[i].endereco);
                    instrucao[i].estagio++;

                }

                else if(instrucao[i].estagio == 3){
                    
                    Astage(instrucao[i].endereco);
                    instrucao[i].estagio++;

                }

                else if(instrucao[i].estagio == 4){
                    
                    if(instrucao[i].indRegistrador == 32){
                        instrucao[i].estagio++;
                        continue;
                    }

                    if(reg[instrucao[i].indRegistrador] == instrucao[i].dado)
                        reg[instrucao[i].indRegistrador] = Wstage(instrucao[i].endereco, instrucao[i].dado, instrucao[i].indRegistrador, reg);
                    instrucao[i].estagio++;

                }

            }

            if(ciclo < total_instrucoes)
                ciclo++;

            total_ciclos--;
        }
        
        printRegistradores(reg, HI, LO, PC);

        char linha[50];

        assembly = fopen(programName, "r");

        fprintf(out, "Programa:\n");

        while(!feof(assembly)){
            fgets(linha, 50, assembly);
            fputs("\t", out);
            fputs(linha, out);
        }
        fputs("\n", out);
        fputs("\n", out);

        fclose(assembly);

        char bin[10];

        fprintf(out, "Binário:\n");
        while(!feof(binario)){
            fgets(bin, 10, binario);
            fputs("\t", out);
            fputs(bin, out);
        }
        fputs("\n", out);

        fprintf(out, "Previsão:\n");
        fprintf(out, "\tTotal de saltos: %d\n", n.saltos);
        fprintf(out, "\tAcertos: %d\n", n.acertos);
        fprintf(out, "\tErros: %d\n\n", n.erros);
        fprintf(out, "Ciclos:\n\t%d ciclos\n\n", ciclo);
        fprintf(out, "Instruções:\n");
        fprintf(out, "\tEmitidas: %d\n", total_instrucoes);
        fprintf(out, "\tEfetivadas: %d\n", ciclo);

    }

    fclose(out);
    fclose(binario);

    return 0;

}