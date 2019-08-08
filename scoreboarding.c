#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/scoreboarding.h"


void inicializarFus(FILA *F, int total_instrucoes){
    struct functionalUnitStatus fus[5];
    
    char *unidadeInt = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeInt,"Integer");
    fus[0].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[0].nomeUnidade,unidadeInt);
    fus[0].busy = false;
    fus[0].time = 1;
    
     
    char *unidadeMult1 = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeMult1,"Mult1");
    fus[1].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[1].nomeUnidade,unidadeMult1);
    fus[1].busy = false;
    fus[1].time = 10;

    char *unidadeMult2 = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeMult2,"Mult2");
    fus[2].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[2].nomeUnidade,unidadeMult2);
    fus[2].busy = false;
    fus[2].time = 10;

    char *unidadeAdd = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeAdd,"Add");
    fus[3].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[3].nomeUnidade,unidadeAdd);
    fus[3].busy = false;
    fus[3].time = 2;

    char *unidadeDiv = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeDiv,"Divide");
    fus[4].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[4].nomeUnidade,unidadeDiv);
    fus[4].busy = false;
    fus[4].time = 40;


    //Esses prints podem ser reaproveitado pra printar a tabela na simulação completa

    printf("Functional Unit Status - FUS\n");
    printf("TIME\tNAME\tBUSY\tOP\tFi\tFj\tFk\tQj\tQk\tRj\tRk");
    for(int i = 0; i < 5; i++){  
        printf("\n%d\t%s\t%d\n",fus[i].time,fus[i].nomeUnidade,fus[i].busy);
    }
    printf("\nPS: O é o mesmo que false nessa tabela\n");

    //PREENCHER FUS
    int indice = 0;
    NO* instrucao = F->inicio;

    while(indice < total_instrucoes){
        
        //verificar se as instruções da fila de espera já podem entrar no fus

        //Comparar instrucao->instructionName com o nome das instruções 
        //que entram em determinada unidade
        //provavelmente fazer um if para cada uma das 33 instrucoes

        //unidade add
        if(strcmp(instrucao->instructionName, "add") == 0){

            if(fus[3].busy == false){

                fus[3].busy = true;
                
                fus[3].opName = (char*) malloc(5 * sizeof(char));
                strcpy(fus[3].opName, instrucao->instructionName);
                fus[3].fi = (char*) malloc(5 * sizeof(char));
                strcpy(fus[3].fi, instrucao->regDestino);
                fus[3].fj = (char*) malloc(5 * sizeof(char));
                strcpy(fus[3].fj, instrucao->reg1);
                fus[3].fk = (char*) malloc(5 * sizeof(char));
                strcpy(fus[3].fk, instrucao->reg2);

                //verificar nas instrucoes anteriores se possui dependecia de dados
                //percorrer todas as outras unidades do fus
                if(strcmp(fus[0].fi, fus[3].fj) == 0)
                    strcpy(fus[3].qj, fus[0].opName);

                else if(strcmp(fus[0].fi, fus[3].fk) == 0)
                    strcpy(fus[3].qk, fus[0].opName);

                else if(strcmp(fus[1].fi, fus[3].fj) == 0)
                    strcpy(fus[3].qj, fus[1].opName);

                else if(strcmp(fus[1].fi, fus[3].fk) == 0)
                    strcpy(fus[3].qk, fus[1].opName);

                else if(strcmp(fus[2].fi, fus[3].fj) == 0)
                    strcpy(fus[3].qj, fus[2].opName);

                else if(strcmp(fus[2].fi, fus[3].fk) == 0)
                    strcpy(fus[3].qk, fus[2].opName);

                else if(strcmp(fus[4].fi, fus[3].fj) == 0)
                    strcpy(fus[3].qj, fus[4].opName);

                else if(strcmp(fus[4].fi, fus[3].fk) == 0)
                    strcpy(fus[3].qk, fus[4].opName);

                else{
                    //não possui dependecias
                    //chamar função para executar
                }

            }

            else{
                //criar uma fila de espera
                //para as instruções que não conseguiram entrar na fus
                //marcar o indice da instrucao que entrou na fila
            }

        }
        
        //unidade div
        else if(strcmp(instrucao->instructionName, "div") == 0){

            if(fus[4].busy == false){

                fus[4].busy = true;
                fus[4].opName = (char*) malloc(5 * sizeof(char));
                strcpy(fus[4].opName, instrucao->instructionName);
                fus[4].fi = (char*) malloc(5 * sizeof(char));
                strcpy(fus[4].fi, HI);
                fus[4].fj = (char*) malloc(5 * sizeof(char));
                strcpy(fus[4].fj, instrucao->regDestino);
                fus[4].fk = (char*) malloc(5 * sizeof(char));
                strcpy(fus[4].fk, instrucao->reg1);

                //verificar nas instrucoes anteriores se possui dependecia de dados

            }

            else{
                //fila
            }

        }

        //unidade mult1 e mult2
        else if(strcmp(instrucao->instructionName, "mul") == 0){

            if(fus[1].busy == false){

                fus[1].busy = true;
                fus[1].opName = (char*) malloc(5 * sizeof(char));
                strcpy(fus[1].opName, instrucao->instructionName);
                fus[1].fi = (char*) malloc(5 * sizeof(char));
                strcpy(fus[1].fi, instrucao->regDestino);
                fus[1].fj = (char*) malloc(5 * sizeof(char));
                strcpy(fus[1].fj, instrucao->reg1);
                fus[1].fk = (char*) malloc(5 * sizeof(char));
                strcpy(fus[1].fk, instrucao->reg2);

                //verificar nas instrucoes anteriores se possui dependecia de dados

            }

            else if(fus[2].busy == false){

                fus[2].busy = true;
                fus[2].opName = (char*) malloc(5 * sizeof(char));
                strcpy(fus[2].opName, instrucao->instructionName);
                fus[2].fi = (char*) malloc(5 * sizeof(char));
                strcpy(fus[2].fi, instrucao->regDestino);
                fus[2].fj = (char*) malloc(5 * sizeof(char));
                strcpy(fus[2].fj, instrucao->reg1);
                fus[2].fk = (char*) malloc(5 * sizeof(char));
                strcpy(fus[2].fk, instrucao->reg2);

                //verificar nas instrucoes anteriores se possui dependecia de dados

            }

            else{
                //fila
            }

        }

        //unidade de inteiros
        else if(strcmp(instrucao->instructionName, "lui") == 0){

            if(fus[0].busy == false){

                fus[0].busy = true;
                fus[0].opName = (char*) malloc(5 * sizeof(char));
                strcpy(fus[0].opName, instrucao->instructionName);
                fus[0].fi = instrucao->regDestino;

                //verificar nas instrucoes anteriores se possui dependecia de dados

            }

            else{
                //fila
            }

        }
        

        else{
            printf("\nNão foi encontrada a instrução");
        }

        instrucao = instrucao->prox;
        indice++;

    }
}