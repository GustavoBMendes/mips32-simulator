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

int main(){

    unsigned int reg[32] = {0};
    unsigned int HI = 0,LO = 0, PC = 0;
    FILE* out = fopen("prog.out", "w");
    FILE* assembly = fopen("arq.asm", "r");
    FILE* binario = fopen("saida_hex.txt", "r");
    inicializeMemory();
    
    struct instrucoes{
        int estagio,
            indRegistrador,
            endereco,
            dado;
        char *nome;
    };
    
    FILA F;

    create(&F);
    ler("arq.asm");
    int total_instrucoes = inserirElementos(&F);
    int total_ciclos = (total_instrucoes - 1) + 5;
    struct instrucoes instrucao[total_instrucoes];
    
    arquivoBin();
    arquivoHex();
    
    fclose(assembly);

    int i;
    for (i = 0; i < total_instrucoes; i++){
        instrucao[i].estagio = 0;
    }

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
                printf("Buscou\n");

                PC = somarPC(PC);
                instrucao[i].estagio++;

            }

            else if(instrucao[i].estagio == 1){

                instrucao[i].indRegistrador = Estage(instrucao[i].nome, &F, instrucao[i].endereco, reg);
                instrucao[i].estagio++;
                printf("Executou\n");
                if(instrucao[i].indRegistrador == 32)
                    PC += returnMultiplexador();

                else if(instrucao[i].indRegistrador == 33){
                    instrucao[i].estagio = 5;
                    continue;
                }

                //suporte ao bypass
                reg[instrucao[i].indRegistrador] = returnMultiplexador();

            }

            else if(instrucao[i].estagio == 2){
                printf("Memória\n");
                instrucao[i].dado = Mstage(instrucao[i].endereco);
                instrucao[i].estagio++;

            }

            else if(instrucao[i].estagio == 3){
                printf("Alinhamento\n");
                Astage(instrucao[i].endereco);
                instrucao[i].estagio++;

            }

            else if(instrucao[i].estagio == 4){
                printf("escrita\n");
                if(instrucao[i].indRegistrador == 32){
                    instrucao[i].estagio++;
                    continue;
                }

                if(reg[instrucao[i].indRegistrador] == instrucao[i].dado)
                    reg[instrucao[i].indRegistrador] = 
                    Wstage(instrucao[i].endereco, instrucao[i].dado, instrucao[i].indRegistrador, reg);
                instrucao[i].estagio++;

            }

        }

        if(ciclo < total_instrucoes)
            ciclo++;

        total_ciclos--;
    }
    
    printRegistradores(reg, HI, LO, PC);

    char linha[50];

    assembly = fopen("arq.asm", "r");

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
    fprintf(out, "Ciclos:\n\t%d ciclos\n\n", ciclo);
    fprintf(out, "Instruções:\n");
    fprintf(out, "\tEmitidas: %d\n", total_instrucoes);
    fprintf(out, "\tEfetivadas: %d\n", ciclo);


    fclose(out);
    fclose(binario);

    return 0;

}