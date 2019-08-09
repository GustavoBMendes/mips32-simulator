#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/scoreboarding.h"



void inicializarFus(FILA *F, int total_instrucoes){

    struct functionalUnitStatus fus[5];
    int is[total_instrucoes][4] = inicializaIS(is, total_instrucoes);
    
    char *unidadeInt = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeInt,"Integer");
    fus[0].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[0].nomeUnidade,unidadeInt);
    fus[0].busy = false;
    fus[0].time = 1;
    fus[0].opName = (char*) malloc(5 * sizeof(char));
    fus[0].fi = (char*) malloc(5 * sizeof(char));
    fus[0].fj = (char*) malloc(5 * sizeof(char));
    fus[0].fk = (char*) malloc(5 * sizeof(char));
    fus[0].qj = (char*) malloc(5 * sizeof(char));
    fus[0].qk = (char*) malloc(5 * sizeof(char));
     
    char *unidadeMult1 = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeMult1,"Mult1");
    fus[1].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[1].nomeUnidade,unidadeMult1);
    fus[1].busy = false;
    fus[1].time = 10;
    fus[1].opName = (char*) malloc(5 * sizeof(char));
    fus[1].fi = (char*) malloc(5 * sizeof(char));
    fus[1].fj = (char*) malloc(5 * sizeof(char));
    fus[1].fk = (char*) malloc(5 * sizeof(char));
    fus[1].qj = (char*) malloc(5 * sizeof(char));
    fus[1].qk = (char*) malloc(5 * sizeof(char));

    char *unidadeMult2 = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeMult2,"Mult2");
    fus[2].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[2].nomeUnidade,unidadeMult2);
    fus[2].busy = false;
    fus[2].time = 10;
    fus[2].opName = (char*) malloc(5 * sizeof(char));
    fus[2].fi = (char*) malloc(5 * sizeof(char));
    fus[2].fj = (char*) malloc(5 * sizeof(char));
    fus[2].fk = (char*) malloc(5 * sizeof(char));
    fus[2].qj = (char*) malloc(5 * sizeof(char));
    fus[2].qk = (char*) malloc(5 * sizeof(char));

    char *unidadeAdd = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeAdd,"Add");
    fus[3].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[3].nomeUnidade,unidadeAdd);
    fus[3].busy = false;
    fus[3].time = 2;
    fus[3].opName = (char*) malloc(5 * sizeof(char));
    fus[3].fi = (char*) malloc(5 * sizeof(char));
    fus[3].fj = (char*) malloc(5 * sizeof(char));
    fus[3].fk = (char*) malloc(5 * sizeof(char));
    fus[3].qj = (char*) malloc(5 * sizeof(char));
    fus[3].qk = (char*) malloc(5 * sizeof(char));

    char *unidadeDiv = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeDiv,"Divide");
    fus[4].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[4].nomeUnidade,unidadeDiv);
    fus[4].busy = false;
    fus[4].time = 40;
    fus[4].opName = (char*) malloc(5 * sizeof(char));
    fus[4].fi = (char*) malloc(5 * sizeof(char));
    fus[4].fj = (char*) malloc(5 * sizeof(char));
    fus[4].fk = (char*) malloc(5 * sizeof(char));
    fus[4].qj = (char*) malloc(5 * sizeof(char));
    fus[4].qk = (char*) malloc(5 * sizeof(char));



    //PREENCHER FUS
    int indice = 0;
    int ciclo = 1;
    int dependencia = 0;
    //int idInstrucao = 0;
    NO* instrucao = F->inicio;

    while(indice < total_instrucoes){
        
        //verificar se as instruções da fila de espera já podem entrar no fus

        //Comparar instrucao->instructionName com o nome das instruções 
        //que entram em determinada unidade
        //provavelmente fazer um if para cada uma das 33 instrucoes

        //unidade add
        if(strcmp(instrucao->instructionName, "add\n") == 0){

            if(fus[3].busy == false){

                fus[3].busy = true;
                strcpy(fus[3].opName, instrucao->instructionName);
                int reg = getReg(instrucao->regDestino);
                rss[reg].regIndice = 4; //indice da unidade + 1
                strcpy(fus[3].fi, instrucao->regDestino);
                strcpy(fus[3].fj, instrucao->reg1);
                strcpy(fus[3].fk, instrucao->reg2);
                fus[3].id = indice;
                //verificar nas instrucoes anteriores se possui dependecia de dados
                //percorrer todas as outras unidades do fus
                if(strcmp(fus[0].fi, fus[3].fj) == 0){
                    strcpy(fus[3].qj, fus[0].fi);
                    fus[3].rj = false;
                }

                else if(strcmp(fus[0].fi, fus[3].fk) == 0){
                    strcpy(fus[3].qk, fus[0].fi);
                    fus[3].rk = false;
                }

                else if(strcmp(fus[1].fi, fus[3].fj) == 0){
                    strcpy(fus[3].qj, fus[1].fi);
                    fus[3].rj = false;
                }

                else if(strcmp(fus[1].fi, fus[3].fk) == 0){
                    strcpy(fus[3].qk, fus[1].fi);
                    fus[3].rk = false;
                }

                else if(strcmp(fus[2].fi, fus[3].fj) == 0){
                    strcpy(fus[3].qj, fus[2].fi);
                    fus[3].rj = false;
                }

                else if(strcmp(fus[2].fi, fus[3].fk) == 0){
                    strcpy(fus[3].qk, fus[2].fi);
                    fus[3].rk = false;
                }

                else if(strcmp(fus[4].fi, fus[3].fj) == 0){
                    strcpy(fus[3].qj, fus[4].fi);
                    fus[3].rj = false;
                }

                else if(strcmp(fus[4].fi, fus[3].fk) == 0){
                    strcpy(fus[3].qk, fus[4].fi);
                    fus[3].rk = false;
                }

                else{
                    //não possui dependecias
                    fus[3].rj = true;
                    fus[3].rk = true;
                }

            }

            else{
                //criar uma fila de espera
                //para as instruções que não conseguiram entrar na fus
                //marcar o indice da instrucao que entrou na fila
            }

        }
        
        //unidade div
        else if(strcmp(instrucao->instructionName, "div\n") == 0){

            if(fus[4].busy == false){

                fus[4].busy = true;
                strcpy(fus[4].opName, instrucao->instructionName);
                strcpy(fus[4].fi, HI);
                strcpy(fus[4].fj, instrucao->regDestino);
                strcpy(fus[4].fk, instrucao->reg1);

                //verificar nas instrucoes anteriores se possui dependecia de dados

            }

            else{
                //fila
            }

        }

        //unidade mult1 e mult2
        else if(strcmp(instrucao->instructionName, "mul\n") == 0){

            if(fus[1].busy == false){

                fus[1].busy = true;
                strcpy(fus[1].opName, instrucao->instructionName);
                strcpy(fus[1].fi, instrucao->regDestino);
                strcpy(fus[1].fj, instrucao->reg1);
                strcpy(fus[1].fk, instrucao->reg2);

                //verificar nas instrucoes anteriores se possui dependecia de dados

            }

            else if(fus[2].busy == false){

                fus[2].busy = true;
                strcpy(fus[2].opName, instrucao->instructionName);
                strcpy(fus[2].fi, instrucao->regDestino);
                strcpy(fus[2].fj, instrucao->reg1);
                strcpy(fus[2].fk, instrucao->reg2);

                //verificar nas instrucoes anteriores se possui dependecia de dados

            }

            else{
                //fila
            }

        }

        //unidade de inteiros
        else if(strcmp(instrucao->instructionName, "lui\n") == 0){

            if(fus[0].busy == false){

                fus[0].busy = true;
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

        if(indice == 0){
            is[indice][1] = ciclo++;
            Estage();
            is[indice][2] = ciclo++;
            Mstage();
            is[indice][3] = ciclo++;
            Wstage();

            instrucao = instrucao->prox;
            indice++;
            continue;
        }

        //execução
        int aux = 1;
        while(aux <= indice){

            if(aux == fus[0].id){
                if(fus[0].rj == true && fus[0].rk == true){
                    //executar
                    if(is[aux][0] == 0){
                        is[indice][0] = ciclo;
                    }
                    else if(is[aux][1] == 0){

                    }
                    else if(is[aux][2] == 0){

                    }
                    else if(is[aux][3] == 0){
                        
                    }
                }
                else{
                    //verificar no rss[] se o registrador da dependencia já está pronto

                }
            }

            else if(aux == fus[1].id){

            }

            else if(aux == fus[2].id){

            }

            else if(aux == fus[3].id){

            }

            else if(aux == fus[4].id){

            }

            else{
                printf("\nInstrução nao encontrada ou está na fila");
            }

            if((indice == total_instrucoes-1) && (fus[0].busy==true || fus[1].busy==true 
            || fus[2].busy == true || fus[3].busy == true || fus[4].busy == true)){
                aux = 1;
                continue;
            }

            aux++;

        }
        

        instrucao = instrucao->prox;
        indice++;
        ciclo++;

    }
}

void printFus(struct functionalUnitStatus fus[5]){
    //Esses prints podem ser reaproveitado pra printar a tabela na simulação completa

    printf("Functional Unit Status - FUS\n");
    printf("TIME\tNAME\tBUSY\tOP\tFi\tFj\tFk\tQj\tQk\tRj\tRk");
    for(int i = 0; i < 5; i++){  
        printf("\n%d\t%s\t%d\n",fus[i].time,fus[i].nomeUnidade,fus[i].busy);
    }
    printf("\nPS: O é o mesmo que false nessa tabela\n");
}

int** incializaIS(int **is, int tam1){

    int i, j;

    for(i = 0; i < tam1; i++)
        for(j = 0; j < 4; j++)
            is[i][j] = 0;

    return is;

}