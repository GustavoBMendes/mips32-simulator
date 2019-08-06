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
#define VAZIO 0

int main(){
    unsigned int reg[32];
    reg[0] = 0;
    unsigned int HI = 0,LO = 0, PC = 0;
    inicializeMemory(); //Ok está alocando
    
    /* 
    unsigned char *dado = "15";
    inserirNoBarramento(dado);
    writeInMemory(0);

    int i;
    for(i = 0; i < 4; i++){
        printf("\n[%d] : %d", i, *(memory + i));
    }
    */
   
    //$T0 = 15;
    //$T1 = 5;
    /*
    printf("\nRESULTADO ACIONANDO A ULA (+) > %d \n", ulaAdd(T0, T1));
    printf("\nRESULTADO ACIONANDO O MDU (*) > %d \n", mduMul(T0, T1));
    printf("\nRESULTADO ACIONANDO O MDU (MADD) > %d \n", mduMadd(T0, T1));
    printf("\nRESULTADO ACIONANDO O MDU (MSUB) > %d \n", mduMsub(T0, T1));
    printf("REsultado do HI: %d\nResultado do LO: %d\n",mduDivHI(T0, T1,HI,LO),mduDivLO(T0, T1,HI,LO));
    */
    /* 
    printf("Teste MFLO, MTLO, MTHI E MTHI:\n\n");
    printf("MTHI: %d\nMFHI: %d",mduMthi(T0,HI),mduMfhi(HI,T0));
    */
    
    /*
    FILA F;

    create(&F);
    ler();
    int instrucoes = inserirElementos(&F);

    printf("\n%d instrucoes\n", instrucoes);

    char *a = (char*) malloc(7 * sizeof(char));
    strcpy(a, Istage(&F, PC));
    printf("%s ",a);

    int indiceReg = Estage(a, &F, PC, reg);
    printf("\nIndice registrador destino: %d\n", indiceReg);

    int dado = Mstage(PC);
    printf("\nResultado: %d", dado);
    
    if(Astage(PC) == 1)
        printf("\nEndereço Correto!\n");
    else
        printf("\nEndereço incorreto!\n");

    reg[indiceReg] = Wstage(PC, dado, indiceReg, reg);
    printf("\nEscrita no Registrador[%d] = %d\n", indiceReg, reg[indiceReg]);

    PC = somarPC(PC);
    printf("\nPC = %d\n", PC);
    

    struct instrucoes{
        int estagio,
            indRegistrador,
            endereco,
            dado;
        char *nome;
    };

    struct numerosPrevisao n;
    n.acertos = 0;
    n.erros = 0;

    FILA F;

    create(&F);
    ler();
    int total_instrucoes = inserirElementos(&F);
    int total_ciclos = (total_instrucoes - 1) + 5;
    struct instrucoes instrucao[total_instrucoes];
    int ciclo = 1;

    int i;
    for (i = 0; i < total_instrucoes; i++){
        instrucao[i].estagio = VAZIO;
    }
    

    while(total_ciclos > 0){
        
        for (i = 0; i < ciclo; i++){

            if(instrucao[i].estagio >= 5)
                continue;

            else if(instrucao[i].estagio == 0){

                instrucao[i].nome = (char*) malloc(7 * sizeof(char));
                strcpy(instrucao[i].nome, Istage(&F, PC));
                instrucao[i].endereco = PC;

                //suporte a previsão de desvio
                if(isBranch(instrucao[i].nome)){

                    NO* aux = getNoBranch(&F, PC);
                    int indReg1 = getRegBranch(aux, 1);
                    int indReg2 = getRegBranch(aux, 2);

                    n = previsao(instrucao[i].nome, reg[indReg1], reg[indReg2], n);

                }

                PC = somarPC(PC);
                instrucao[i].estagio++;

            }

            else if(instrucao[i].estagio == 1){

                instrucao[i].indRegistrador = Estage(instrucao[i].nome, &F, instrucao[i].endereco, reg);
                instrucao[i].estagio++;

                //suporte ao bypass
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
    printMemory();

    printf("\nPrevisor de desvio:\n");
    printf("Total de acertos = %d\n", n.acertos);
    printf("Total de erros = %d\n", n.erros);
    */    

    // TESTE TRADUTOR
    FILA F;
    ler();
    arquivoBin();
    arquivoHex();
    

    /*
    int a = 111;       
    inserirNoBarramento(a);
    printf("%s \n",biu);
    printf("Recuperado do barramento o valor: %d",recuperarNoBarramento());
    */
    
}