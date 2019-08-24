#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/scoreboarding.h"

unsigned int reg[32];
unsigned int HI = 0,LO = 0, PC = 0;

int inicializarFus(FILA *F, int total_instrucoes){

    struct functionalUnitStatus fus[5];
    struct registerResultStatus rss[32];
    int is[total_instrucoes][4];

    int linha, coluna;

    for(linha = 0; linha < total_instrucoes; linha++)
        for(coluna = 0; coluna < 4; coluna++)
            is[linha][coluna] = 0;
    
    char *unidadeInt = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeInt,"Integer");
    strcpy(fus[0].nomeUnidade,unidadeInt);
    fus[0].busy = false;
    fus[0].time = 1;
    fus[0].immediate = -1;
    strcpy(fus[0].opName, "");
    strcpy(fus[0].fi, "");
    strcpy(fus[0].fj, "");
    strcpy(fus[0].fk, "");
    strcpy(fus[0].qj, "");
    strcpy(fus[0].qk, "");
     
    char *unidadeMult1 = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeMult1,"Mult1");
    strcpy(fus[1].nomeUnidade,unidadeMult1);
    fus[1].busy = false;
    fus[1].time = 10;
    fus[1].immediate = -1;
    strcpy(fus[1].opName, "");
    strcpy(fus[1].fi, "");
    strcpy(fus[1].fj, "");
    strcpy(fus[1].fk, "");
    strcpy(fus[1].qj, "");
    strcpy(fus[1].qk, "");

    char *unidadeMult2 = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeMult2,"Mult2");
    strcpy(fus[2].nomeUnidade,unidadeMult2);
    fus[2].busy = false;
    fus[2].time = 10;
    fus[2].immediate = -1;
    strcpy(fus[2].opName, "");
    strcpy(fus[2].fi, "");
    strcpy(fus[2].fj, "");
    strcpy(fus[2].fk, "");
    strcpy(fus[2].qj, "");
    strcpy(fus[2].qk, "");

    char *unidadeAdd = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeAdd,"Add");
    strcpy(fus[3].nomeUnidade,unidadeAdd);
    fus[3].busy = false;
    fus[3].time = 2;
    fus[3].immediate = -1;
    strcpy(fus[3].opName, "");
    strcpy(fus[3].fi, "");
    strcpy(fus[3].fj, "");
    strcpy(fus[3].fk, "");
    strcpy(fus[3].qj, "");
    strcpy(fus[3].qk, "");

    char *unidadeDiv = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeDiv,"Divide");
    strcpy(fus[4].nomeUnidade,unidadeDiv);
    fus[4].busy = false;
    fus[4].time = 40;
    fus[4].immediate = -1;
    strcpy(fus[4].opName, "");
    strcpy(fus[4].fi, "");
    strcpy(fus[4].fj, "");
    strcpy(fus[4].fk, "");
    strcpy(fus[4].qj, "");
    strcpy(fus[4].qk, "");



    //PREENCHER FUS
    int indice = 0;
    int ciclo = 1;
    int dependencia = 0;
    int auxFila = 0;
    int inicioFila = 0;
    //int idInstrucao = 0;
    NO* instrucao = F->inicio;

    struct fila{
        int unidade, id, iFi, iFj, iFk, imm;
        char nomeInstrucao[7], Fi[5], Fj[5], Fk[5];
        bool RJ, RK;
    };
    struct fila fila_espera[total_instrucoes-1];

    while(indice < total_instrucoes){

        //unidade add
        if(strcmp(instrucao->instructionName, "add\n") == 0 || strcmp(instrucao->instructionName, "sub\n") == 0
        || strcmp(instrucao->instructionName, "and\n") == 0 || strcmp(instrucao->instructionName, "nor\n") == 0 
        || strcmp(instrucao->instructionName, "or\n") == 0 || strcmp(instrucao->instructionName, "xor\n") == 0)
        {

            if(fus[3].busy == false){

                fus[3].busy = true;
                fus[3].i_fi = getReg(instrucao->regDestino);
                fus[3].i_fj = getReg(instrucao->reg1);
                fus[3].i_fk = getReg(instrucao->reg2);

                strcpy(fus[3].opName, instrucao->instructionName);
                strcpy(fus[3].fi, instrucao->regDestino);
                strcpy(fus[3].fj, instrucao->reg1);
                strcpy(fus[3].fk, instrucao->reg2);
                fus[3].id = indice;

                //verificar nas instrucoes anteriores se possui dependecia de dados
                //percorrer o rss verificando se os registradores já estão sendo utilizados para escrita
                int i = 0;
                while(i <= fus[3].i_fj || i <= fus[3].i_fk){

                    if(fus[3].i_fj == i){
                        if(rss[i].indice_unidade != 0){  //dependencia
                            strcpy(fus[3].qj, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[3].rj = false;
                        }
                        else
                            fus[3].rj = true;
                    }

                    if(fus[3].i_fk == i){
                        if(rss[i].indice_unidade != 0){
                            strcpy(fus[3].qk, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[3].rk = false;
                        }
                        else
                            fus[3].rk = true;
                    }

                    i++;
                }

                rss[fus[3].i_fi].indice_unidade = 4; //indice da unidade + 1

            }

            else{
                //criar uma fila de espera
                //para as instruções que não conseguiram entrar na fus
                //marcar o indice da instrucao que entrou na fila
                //marcar dependencia do registrador desta instrucao
                rss[getReg(instrucao->regDestino)].indice_unidade = 4;
                fila_espera[auxFila].unidade = 3;
                fila_espera[auxFila].iFi = getReg(instrucao->regDestino);
                fila_espera[auxFila].iFj = getReg(instrucao->reg1);
                fila_espera[auxFila].iFk = getReg(instrucao->reg2);
                fila_espera[auxFila].id = indice;
                fila_espera[auxFila].RJ = false;
                fila_espera[auxFila].RK = false;

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);
                strcpy(fila_espera[auxFila].Fi, instrucao->regDestino);
                strcpy(fila_espera[auxFila].Fj, instrucao->reg1);
                strcpy(fila_espera[auxFila].Fk, instrucao->reg2);

                auxFila++;
            }

        }
        
        //unidade div
        else if(strcmp(instrucao->instructionName, "div\n") == 0){

            if(fus[4].busy == false){

                fus[4].busy = true;
                fus[4].i_fi = getReg(instrucao->regDestino);
                fus[4].i_fj = getReg(instrucao->reg1);

                strcpy(fus[4].opName, instrucao->instructionName);
                strcpy(fus[4].fi, instrucao->regDestino);
                strcpy(fus[4].fj, instrucao->reg1);
                fus[4].id = indice;

                //verificar nas instrucoes anteriores se possui dependecia de dados
                int i = 0;
                while(i <= fus[4].i_fj){

                    if(fus[4].i_fj == i){
                        if(rss[i].indice_unidade != 0){  //dependencia
                            strcpy(fus[4].qj, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[4].rj = false;
                        }
                        else
                            fus[4].rj = true;
                    }

                    i++;
                }
                
                fus[4].rk = true;
                rss[fus[4].i_fi].indice_unidade = 5;

            }

            else{
                rss[getReg(instrucao->regDestino)].indice_unidade = 5;
                fila_espera[auxFila].unidade = 4;
                fila_espera[auxFila].iFi = getReg(instrucao->regDestino);
                fila_espera[auxFila].iFj = getReg(instrucao->reg1);
                fila_espera[auxFila].id = indice;
                fila_espera[auxFila].RJ = false;
                fila_espera[auxFila].RK = true;

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);
                strcpy(fila_espera[auxFila].Fi, instrucao->regDestino);
                strcpy(fila_espera[auxFila].Fj, instrucao->reg1);

                auxFila++;
            }

        }

        //unidade mult1 e mult2
        else if(strcmp(instrucao->instructionName, "mul\n") == 0 || strcmp(instrucao->instructionName, "mult\n") == 0){

            if(fus[1].busy == false){

                fus[1].busy = true;
                fus[1].i_fi = getReg(instrucao->regDestino);
                fus[1].i_fj = getReg(instrucao->reg1);
                fus[1].i_fk = getReg(instrucao->reg2);

                strcpy(fus[1].opName, instrucao->instructionName);
                strcpy(fus[1].fi, instrucao->regDestino);
                strcpy(fus[1].fj, instrucao->reg1);
                strcpy(fus[1].fk, instrucao->reg2);
                fus[1].id = indice;

                //verificar nas instrucoes anteriores se possui dependecia de dados
                int i = 0;
                while(i <= fus[1].i_fj || i <= fus[1].i_fk){

                    if(fus[1].i_fj == i){
                        if(rss[i].indice_unidade != 0){  //dependencia
                            strcpy(fus[1].qj, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[1].rj = false;
                        }
                        else
                            fus[1].rj = true;
                    }

                    if(fus[1].i_fk == i){
                        if(rss[i].indice_unidade != 0){
                            strcpy(fus[1].qk, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[1].rk = false;
                        }
                        else
                            fus[1].rk = true;
                    }

                    i++;
                }
                rss[fus[1].i_fi].indice_unidade = 2;

            }

            else if(fus[2].busy == false){

                fus[2].busy = true;
                fus[2].i_fi = getReg(instrucao->regDestino);
                fus[2].i_fj = getReg(instrucao->reg1);
                fus[2].i_fk = getReg(instrucao->reg2);

                strcpy(fus[2].opName, instrucao->instructionName);
                strcpy(fus[2].fi, instrucao->regDestino);
                strcpy(fus[2].fj, instrucao->reg1);
                strcpy(fus[2].fk, instrucao->reg2);
                fus[2].id = indice;

                //verificar nas instrucoes anteriores se possui dependecia de dados
                int i = 0;
                while(i <= fus[2].i_fj || i <= fus[2].i_fk){

                    if(fus[2].i_fj == i){
                        if(rss[i].indice_unidade != 0){  //dependencia
                            strcpy(fus[2].qj, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[2].rj = false;
                        }
                        else
                            fus[2].rj = true;
                    }

                    if(fus[2].i_fk == i){
                        if(rss[i].indice_unidade != 0){
                            strcpy(fus[2].qk, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[2].rk = false;
                        }
                        else
                            fus[2].rk = true;
                    }

                    i++;
                }
                rss[fus[2].i_fi].indice_unidade = 3;

            }

            else{
                rss[getReg(instrucao->regDestino)].indice_unidade = 2;
                fila_espera[auxFila].unidade = 1;
                fila_espera[auxFila].iFi = getReg(instrucao->regDestino);
                fila_espera[auxFila].iFj = getReg(instrucao->reg1);
                fila_espera[auxFila].iFk = getReg(instrucao->reg2);
                fila_espera[auxFila].id = indice;
                fila_espera[auxFila].RJ = false;
                fila_espera[auxFila].RK = false;

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);
                strcpy(fila_espera[auxFila].Fi, instrucao->regDestino);
                strcpy(fila_espera[auxFila].Fj, instrucao->reg1);
                strcpy(fila_espera[auxFila].Fk, instrucao->reg2);

                auxFila++;
            }

        }

        else if(strcmp(instrucao->instructionName, "msub\n") == 0){

            if(fus[1].busy == false){

                fus[1].busy = true;
                fus[1].i_fi = getReg(instrucao->regDestino);
                fus[1].i_fj = getReg(instrucao->reg1);

                strcpy(fus[1].opName, instrucao->instructionName);
                strcpy(fus[1].fi, instrucao->regDestino);
                strcpy(fus[1].fj, instrucao->reg1);
                fus[1].id = indice;

                //verificar nas instrucoes anteriores se possui dependecia de dados
                int i = 0;
                while(i <= fus[1].i_fj){

                    if(fus[1].i_fj == i){
                        if(rss[i].indice_unidade != 0){  //dependencia
                            strcpy(fus[1].qj, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[1].rj = false;
                        }
                        else
                            fus[1].rj = true;
                    }

                    i++;
                }

                fus[1].rk = true;
                rss[fus[1].i_fi].indice_unidade = 2;

            }

            else if(fus[2].busy == false){

                fus[2].busy = true;
                fus[2].i_fi = getReg(instrucao->regDestino);
                fus[2].i_fj = getReg(instrucao->reg1);

                strcpy(fus[2].opName, instrucao->instructionName);
                strcpy(fus[2].fi, instrucao->regDestino);
                strcpy(fus[2].fj, instrucao->reg1);
                fus[2].id = indice;

                //verificar nas instrucoes anteriores se possui dependecia de dados
                int i = 0;
                while(i <= fus[2].i_fj){

                    if(fus[2].i_fj == i){
                        if(rss[i].indice_unidade != 0){  //dependencia
                            strcpy(fus[2].qj, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[2].rj = false;
                        }
                        else
                            fus[2].rj = true;
                    }

                    i++;
                }
                fus[2].rk = true;
                rss[fus[2].i_fi].indice_unidade = 3;

            }

            else{
                rss[getReg(instrucao->regDestino)].indice_unidade = 2;
                fila_espera[auxFila].unidade = 1;
                fila_espera[auxFila].iFi = getReg(instrucao->regDestino);
                fila_espera[auxFila].iFj = getReg(instrucao->reg1);
                fila_espera[auxFila].id = indice;
                fila_espera[auxFila].RJ = false;
                fila_espera[auxFila].RK = true;

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);
                strcpy(fila_espera[auxFila].Fi, instrucao->regDestino);
                strcpy(fila_espera[auxFila].Fj, instrucao->reg1);

                auxFila++;
            }

        }

        //unidade de inteiros
        else if(strcmp(instrucao->instructionName, "lui\n") == 0 || strcmp(instrucao->instructionName, "bgez\n") == 0
            || strcmp(instrucao->instructionName, "bgtz\n") == 0 || strcmp(instrucao->instructionName, "blez\n") == 0
            || strcmp(instrucao->instructionName, "bltz\n") == 0){

            if(fus[0].busy == false){

                fus[0].busy = true;
                fus[0].i_fi = getReg(instrucao->regDestino);
                fus[0].immediate = instrucao->imediato;

                strcpy(fus[0].opName, instrucao->instructionName);
                strcpy(fus[0].fi, instrucao->regDestino);
                fus[0].id = indice;

                //verificar nas instrucoes anteriores se possui dependecia de dados
                //percorrer o rss verificando se os registradores já estão sendo utilizados para escrita
                fus[0].rk = true;
                fus[0].rj = true;
                rss[fus[0].i_fi].indice_unidade = 1;

            }

            else{

                rss[getReg(instrucao->regDestino)].indice_unidade = 1;
                fila_espera[auxFila].unidade = 0;
                fila_espera[auxFila].iFi = getReg(instrucao->regDestino);
                fila_espera[auxFila].imm = instrucao->imediato;
                fila_espera[auxFila].id = indice;
                fila_espera[auxFila].RJ = true;
                fila_espera[auxFila].RK = true;

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);
                strcpy(fila_espera[auxFila].Fi, instrucao->regDestino);

                auxFila++;

            }

        }

        else if(strcmp(instrucao->instructionName, "b\n") == 0 || strcmp(instrucao->instructionName, "j\n") == 0){

            if(fus[0].busy == false){

                fus[0].busy = true;
                fus[0].immediate = instrucao->imediato;

                strcpy(fus[0].opName, instrucao->instructionName);
                fus[0].id = indice;

                //verificar nas instrucoes anteriores se possui dependecia de dados
                //percorrer o rss verificando se os registradores já estão sendo utilizados para escrita
                fus[0].rk = true;
                fus[0].rj = true;
                rss[fus[0].i_fi].indice_unidade = 1;

            }

            else{

                rss[getReg(instrucao->regDestino)].indice_unidade = 1;
                fila_espera[auxFila].unidade = 0;
                fila_espera[auxFila].imm = instrucao->imediato;
                fila_espera[auxFila].id = indice;
                fila_espera[auxFila].RJ = true;
                fila_espera[auxFila].RK = true;

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);

                auxFila++;

            }

        }

        else if(strcmp(instrucao->instructionName, "jr\n") == 0 || strcmp(instrucao->instructionName, "mfhi\n") == 0
            || strcmp(instrucao->instructionName, "mflo\n") == 0 || strcmp(instrucao->instructionName, "mthi\n") == 0
            || strcmp(instrucao->instructionName, "mtlo\n") == 0){

            if(fus[0].busy == false){

                fus[0].busy = true;
                fus[0].i_fi = getReg(instrucao->regDestino);

                strcpy(fus[0].opName, instrucao->instructionName);
                strcpy(fus[0].fi, instrucao->regDestino);
                fus[0].id = indice;

                
                int i = 0;
                while(i <= fus[0].i_fj){

                    if(fus[0].i_fj == i){

                        if(rss[i].indice_unidade != 0){  //dependencia
                            strcpy(fus[0].qj, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[0].rj = false;
                        }
                        else
                            fus[0].rj = true;

                    }
                    i++;

                }
                fus[0].rk = true;
                rss[fus[0].i_fi].indice_unidade = 1;

            }

            else{

                rss[getReg(instrucao->regDestino)].indice_unidade = 1;
                fila_espera[auxFila].unidade = 0;
                fila_espera[auxFila].iFi = getReg(instrucao->regDestino);
                fila_espera[auxFila].id = indice;
                fila_espera[auxFila].RJ = true;
                fila_espera[auxFila].RK = true;

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);
                strcpy(fila_espera[auxFila].Fi, instrucao->regDestino);

                auxFila++;

            }

        }

        else if(strcmp(instrucao->instructionName, "madd\n") == 0 || strcmp(instrucao->instructionName, "jr\n") == 0){

            if(fus[0].busy == false){

                fus[0].busy = true;
                fus[0].i_fi = getReg(instrucao->regDestino);
                fus[0].i_fj = getReg(instrucao->reg1);

                strcpy(fus[0].opName, instrucao->instructionName);
                strcpy(fus[0].fi, instrucao->regDestino);
                strcpy(fus[0].fj, instrucao->reg1);
                fus[0].id = indice;

               
                int i = 0;
                while(i <= fus[0].i_fj){

                    if(fus[0].i_fj == i){

                        if(rss[i].indice_unidade != 0){  //dependencia
                            strcpy(fus[0].qj, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[0].rj = false;
                        }

                        else
                            fus[0].rj = true;

                    }
                    i++;

                }
                fus[0].rk = true;
                rss[fus[0].i_fi].indice_unidade = 1;

            }

            else{

                rss[getReg(instrucao->regDestino)].indice_unidade = 1;
                fila_espera[auxFila].unidade = 0;
                fila_espera[auxFila].iFi = getReg(instrucao->regDestino);
                fila_espera[auxFila].iFj = getReg(instrucao->reg1);
                fila_espera[auxFila].id = indice;
                fila_espera[auxFila].RJ = false;
                fila_espera[auxFila].RK = true;

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);
                strcpy(fila_espera[auxFila].Fi, instrucao->regDestino);
                strcpy(fila_espera[auxFila].Fj, instrucao->reg1);

                auxFila++;

            }

        }

        else if(strcmp(instrucao->instructionName, "movn\n") == 0 || strcmp(instrucao->instructionName, "movz\n") == 0){

            if(fus[0].busy == false){

                fus[0].busy = true;
                fus[0].i_fi = getReg(instrucao->regDestino);
                fus[0].i_fj = getReg(instrucao->reg1);
                fus[0].i_fk = getReg(instrucao->reg2);

                strcpy(fus[0].opName, instrucao->instructionName);
                strcpy(fus[0].fi, instrucao->regDestino);
                strcpy(fus[0].fj, instrucao->reg1);
                strcpy(fus[0].fk, instrucao->reg2);
                fus[0].id = indice;

                
                int i = 0;
                while(i <= fus[0].i_fj || i <= fus[0].i_fk){

                    if(fus[0].i_fj == i){
                        if(rss[i].indice_unidade != 0){  //dependencia
                            strcpy(fus[0].qj, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[0].rj = false;
                        }
                        else
                            fus[0].rj = true;
                    }

                    if(fus[0].i_fk == i){
                        if(rss[i].indice_unidade != 0){
                            strcpy(fus[3].qk, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[0].rk = false;
                        }
                        else
                            fus[0].rk = true;
                    }

                    i++;
                }

                rss[fus[3].i_fi].indice_unidade = 1; //indice da unidade + 1

            }

            else{

                rss[getReg(instrucao->regDestino)].indice_unidade = 1;
                fila_espera[auxFila].unidade = 0;
                fila_espera[auxFila].iFi = getReg(instrucao->regDestino);
                fila_espera[auxFila].iFj = getReg(instrucao->reg1);
                fila_espera[auxFila].iFk = getReg(instrucao->reg2);
                fila_espera[auxFila].id = indice;
                fila_espera[auxFila].RJ = false;
                fila_espera[auxFila].RK = false;

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);
                strcpy(fila_espera[auxFila].Fi, instrucao->regDestino);
                strcpy(fila_espera[auxFila].Fj, instrucao->reg1);
                strcpy(fila_espera[auxFila].Fk, instrucao->reg2);

                auxFila++;

            }

        }

        else if(strcmp(instrucao->instructionName, "addi\n") == 0 || strcmp(instrucao->instructionName, "beq\n") == 0
            || strcmp(instrucao->instructionName, "beql\n") == 0  || strcmp(instrucao->instructionName, "bne\n") == 0
            || strcmp(instrucao->instructionName, "xori\n") == 0 || strcmp(instrucao->instructionName, "andi\n") == 0
            || strcmp(instrucao->instructionName, "ori\n") == 0)
        {

            if(fus[0].busy == false){

                fus[0].busy = true;
                fus[0].i_fi = getReg(instrucao->regDestino);
                fus[0].i_fj = getReg(instrucao->reg1);
                fus[0].immediate = instrucao->imediato;

                strcpy(fus[0].opName, instrucao->instructionName);
                strcpy(fus[0].fi, instrucao->regDestino);
                strcpy(fus[0].fj, instrucao->reg1);
                fus[0].id = indice;

                
                int i = 0;
                while(i <= fus[0].i_fj){

                    if(fus[0].i_fj == i){

                        if(rss[i].indice_unidade != 0){  //dependencia
                            strcpy(fus[0].qj, fus[rss[i].indice_unidade - 1].nomeUnidade);
                            fus[0].rj = false;
                        }
                        else
                            fus[0].rj = true;

                    }
                    i++;

                }
                fus[0].rk = true;
                rss[fus[0].i_fi].indice_unidade = 1;

            }

            else{

                rss[getReg(instrucao->regDestino)].indice_unidade = 1;
                fila_espera[auxFila].unidade = 0;
                fila_espera[auxFila].iFi = getReg(instrucao->regDestino);
                fila_espera[auxFila].iFj = getReg(instrucao->reg1);
                fila_espera[auxFila].imm = instrucao->imediato;
                fila_espera[auxFila].id = indice;
                fila_espera[auxFila].RJ = false;
                fila_espera[auxFila].RK = true;

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);
                strcpy(fila_espera[auxFila].Fi, instrucao->regDestino);
                strcpy(fila_espera[auxFila].Fj, instrucao->reg1);

                auxFila++;

            }

        }
        

        else{
            printf("\nNão foi encontrada a instrução, no operation 'nop()'");
        }

        //Válido apenas para a primeira instrução a ser executada
        if(indice == 0){
            int indiceAtual;
            int timeUnidade;
            is[indice][0] = ciclo;
            ciclo++;
            is[indice][1] = ciclo;
            //Estagio de busca
            for(int x = 0; x < 5; x++){
                if(fus[x].busy == true){
                    if(fus[x].fi[0] != '\0')
                            fus[x].operando1 = reg[fus[x].i_fi];

                    if(fus[x].fj[0] != '\0')
                        fus[x].operando2 = reg[fus[x].i_fj];
                    
                    if(fus[x].fk[0] != '\0')
                        fus[x].operando3 = reg[fus[x].i_fk];

                    indiceAtual = x;
                    timeUnidade = fus[x].time;
                    break;
                }
            }

            //Estagio de execucao;
            while(fus[indiceAtual].time > 0){
                if(fus[indiceAtual].time == 1)
                    fus[indiceAtual].operando1 = execucao(fus[indiceAtual].operando1, fus[indiceAtual].operando2, fus[indiceAtual].operando3, fus[indiceAtual].opName, fus[indiceAtual].immediate);
                fus[indiceAtual].time--;
                ciclo++;
            }
            is[indice][2] = ciclo;

            ciclo++;
            is[indice][3] = ciclo;
            //Estagio de escrita;
            reg[fus[indiceAtual].i_fi] = fus[indiceAtual].operando1;

            //reiniciar unidade e indice correspondente do rss
            rss[fus[indiceAtual].i_fi].indice_unidade = 0;
            fus[indiceAtual].id = 0;
            fus[indiceAtual].busy = false;
            fus[indiceAtual].rj = false;
            fus[indiceAtual].rk = false;
            fus[indiceAtual].time = timeUnidade;
            fus[indiceAtual].immediate = -1;
            strcpy(fus[indiceAtual].opName, "");
            strcpy(fus[indiceAtual].fi, "");
            strcpy(fus[indiceAtual].fj, "");
            strcpy(fus[indiceAtual].fk, "");
            strcpy(fus[indiceAtual].qj, "");
            strcpy(fus[indiceAtual].qk, "");

            instrucao = instrucao->prox;
            ciclo++;
            indice++;
            continue;
        }

        //execução
        int aux = 1;
        while(aux <= indice){

            //verificar se as instruções da fila de espera já podem entrar no  fus
            if(auxFila > 0){
                int i = inicioFila;
                while(i < auxFila){

                    int unidade = fila_espera[i].unidade;
                    //unidade livre, inserir
                    if(fus[unidade].busy == false){

                        fus[unidade].busy = true;
                        fus[unidade].i_fi = fila_espera[i].iFi;
                        fus[unidade].i_fj = fila_espera[i].iFj;
                        fus[unidade].i_fk = fila_espera[i].iFk;
                        fus[unidade].id = fila_espera[i].id;
                        fus[unidade].immediate = fila_espera[i].imm;
                        fus[unidade].rj = fila_espera[i].RJ;
                        fus[unidade].rk = fila_espera[i].RK;

                        strcpy(fus[unidade].opName, fila_espera[i].nomeInstrucao);
                        strcpy(fus[unidade].fi, fila_espera[i].Fi);
                        strcpy(fus[unidade].fj, fila_espera[i].Fj);
                        strcpy(fus[unidade].fk, fila_espera[i].Fk);

                        inicioFila++;   //atualiza primeiro elemento da fila
                    }
                    i++;

                }
            }

            if(aux == fus[0].id){

                if(is[aux][0] == 0)
                    is[aux][0] = ciclo;

                else if(fus[0].rj == true && fus[0].rk == true){

                    //executar
                    if(is[aux][1] == 0){

                        is[aux][1] = ciclo;

                        //estágio de busca
                        if(fus[0].fi[0] != '\0')
                            fus[0].operando1 = reg[fus[0].i_fi];

                        if(fus[0].fj[0] != '\0')
                            fus[0].operando2 = reg[fus[0].i_fj];
                        
                        if(fus[0].fk[0] != '\0')
                            fus[0].operando3 = reg[fus[0].i_fk];

                        if(fus[0].immediate != -1)
                            fus[0].operando3 = fus[0].immediate;
                        
                    }

                    else if(is[aux][2] == 0 || fus[0].time > 0){

                        is[aux][2] = ciclo;

                        //estágio de execução
                        if(fus[0].time == 1)
                            fus[0].operando1 = execucao(fus[0].operando1, fus[0].operando2, fus[0].operando3, fus[0].opName, fus[0].immediate);
                        
                        fus[0].time--;  //a cada ciclo decrementa o time em 1
                        
                    }

                    else if(is[aux][3] == 0){

                        is[aux][3] = ciclo;

                        //estágio de escrita
                        reg[fus[0].i_fi] = fus[0].operando1;

                        //reiniciar unidade e indice correspondente do rss
                        rss[fus[0].i_fi].indice_unidade = 0;
                        fus[0].id = 0;
                        fus[0].busy = false;
                        fus[0].rj = false;
                        fus[0].rk = false;
                        fus[0].time = 1;
                        fus[0].immediate = -1;
                        strcpy(fus[0].opName, "");
                        strcpy(fus[0].fi, "");
                        strcpy(fus[0].fj, "");
                        strcpy(fus[0].fk, "");
                        strcpy(fus[0].qj, "");
                        strcpy(fus[0].qk, "");

                    }
                }

                else{

                    //verificar no rss[] se o registrador da dependencia já está pronto
                    if(fus[0].rj == false)
                        if(rss[fus[0].i_fj].indice_unidade == 0)
                            fus[0].rj = true;

                    if(fus[0].rk == false)
                        if(rss[fus[0].i_fk].indice_unidade == 0)
                            fus[0].rk = true;

                    if(fus[0].rj == true && fus[0].rk == true){
                        ciclo++;
                        continue;
                    }
                }

            }

            else if(aux == fus[1].id){

                if(is[aux][0] == 0)
                    is[aux][0] = ciclo;

                else if(fus[1].rj == true && fus[1].rk == true){

                    //executar
                    if(is[aux][1] == 0){

                        is[aux][1] = ciclo;

                        //estágio de busca
                        if(fus[1].fi[0] != '\0')
                            fus[1].operando1 = reg[fus[1].i_fi];

                        if(fus[1].fj[0] != '\0')
                            fus[1].operando2 = reg[fus[1].i_fj];
                        
                        if(fus[1].fk[0] != '\0')
                            fus[1].operando3 = reg[fus[1].i_fk];

                        if(fus[1].immediate != -1)
                            fus[1].operando3 = fus[1].immediate;
                        
                    }

                    else if(is[aux][2] == 0 || fus[1].time > 0){

                        is[aux][2] = ciclo;

                        //estágio de execução
                        if(fus[1].time == 1)
                            fus[1].operando1 = execucao(fus[1].operando1, fus[1].operando2, fus[1].operando3, fus[1].opName, fus[1].immediate);
                        
                        fus[1].time--;  //a cada ciclo decrementa o time em 1
                        
                    }

                    else if(is[aux][3] == 0){

                        is[aux][3] = ciclo;

                        //estágio de escrita
                        reg[fus[1].i_fi] = fus[1].operando1;

                        //reiniciar unidade e indice correspondente do rss
                        rss[fus[1].i_fi].indice_unidade = 0;
                        fus[1].id = 0;
                        fus[1].busy = false;
                        fus[1].rj = false;
                        fus[1].rk = false;
                        fus[1].time = 10;
                        fus[1].immediate = -1;
                        strcpy(fus[1].opName, "");
                        strcpy(fus[1].fi, "");
                        strcpy(fus[1].fj, "");
                        strcpy(fus[1].fk, "");
                        strcpy(fus[1].qj, "");
                        strcpy(fus[1].qk, "");

                    }
                }

                else{

                    //verificar no rss[] se o registrador da dependencia já está pronto
                    if(fus[1].rj == false)
                        if(rss[fus[1].i_fj].indice_unidade == 0)
                            fus[1].rj = true;

                    if(fus[1].rk == false)
                        if(rss[fus[1].i_fk].indice_unidade == 0)
                            fus[1].rk = true;

                    if(fus[1].rj == true && fus[1].rk == true){
                        ciclo++;
                        continue;
                    }

                }

            }

            else if(aux == fus[2].id){

                if(is[aux][0] == 0)
                    is[aux][0] = ciclo;

                else if(fus[2].rj == true && fus[2].rk == true){

                    //executar
                    if(is[aux][1] == 0){

                        is[aux][1] = ciclo;

                        //estágio de busca
                        if(fus[2].fi[0] != '\0')
                            fus[2].operando1 = reg[fus[2].i_fi];

                        if(fus[2].fj[0] != '\0')
                            fus[2].operando2 = reg[fus[2].i_fj];
                        
                        if(fus[2].fk[0] != '\0')
                            fus[2].operando3 = reg[fus[2].i_fk];

                        if(fus[2].immediate != -1)
                            fus[2].operando3 = fus[2].immediate;
                        
                    }
                    
                    else if(is[aux][2] == 0 || fus[2].time > 0){

                        is[aux][2] = ciclo;

                        //estágio de execução
                        if(fus[2].time == 1)
                            fus[2].operando1 = execucao(fus[2].operando1, fus[2].operando2, fus[2].operando3, fus[2].opName, fus[2].immediate);
                        
                        fus[2].time--;  //a cada ciclo decrementa o time em 1
                        
                    }

                    else if(is[aux][3] == 0){

                        is[aux][3] = ciclo;

                        //estágio de escrita
                        reg[fus[2].i_fi] = fus[2].operando1;

                        //reiniciar unidade e indice correspondente do rss
                        rss[fus[2].i_fi].indice_unidade = 0;
                        fus[2].id = 0;
                        fus[2].busy = false;
                        fus[2].rj = false;
                        fus[2].rk = false;
                        fus[2].time = 10;
                        fus[2].immediate = -1;
                        strcpy(fus[2].opName, "");
                        strcpy(fus[2].fi, "");
                        strcpy(fus[2].fj, "");
                        strcpy(fus[2].fk, "");
                        strcpy(fus[2].qj, "");
                        strcpy(fus[2].qk, "");

                    }
                }

                else{

                    //verificar no rss[] se o registrador da dependencia já está pronto
                    if(fus[2].rj == false)
                        if(rss[fus[2].i_fj].indice_unidade == 0)
                            fus[2].rj = true;

                    if(fus[2].rk == false)
                        if(rss[fus[2].i_fk].indice_unidade == 0)
                            fus[2].rk = true;

                    if(fus[2].rj == true && fus[2].rk == true){
                        ciclo++;
                        continue;
                    }

                }

            }

            else if(aux == fus[3].id){

                if(is[aux][0] == 0)
                    is[aux][0] = ciclo;

                else if(fus[3].rj == true && fus[3].rk == true){

                    //executar
                    if(is[aux][1] == 0){

                        is[aux][1] = ciclo;

                        //estágio de busca
                        if(fus[3].fi[0] != '\0')
                            fus[3].operando1 = reg[fus[3].i_fi];

                        if(fus[3].fj[0] != '\0')
                            fus[3].operando2 = reg[fus[3].i_fj];
                        
                        if(fus[3].fk[0] != '\0')
                            fus[3].operando3 = reg[fus[3].i_fk];
                        
                        if(fus[3].immediate != -1)
                            fus[3].operando3 = fus[3].immediate;
                    }
                    
                    else if(is[aux][2] == 0 || fus[3].time > 0){

                        is[aux][2] = ciclo;

                        //estágio de execução
                        if(fus[3].time == 1)
                            fus[3].operando1 = execucao(fus[3].operando1, fus[3].operando2, fus[3].operando3, fus[3].opName, fus[3].immediate);
                        
                        fus[3].time--;  //a cada ciclo decrementa o time em 1
                        
                    }

                    else if(is[aux][3] == 0){

                        is[aux][3] = ciclo;

                        //estágio de escrita
                        reg[fus[3].i_fi] = fus[3].operando1;

                        //reiniciar unidade e indice correspondente do rss
                        rss[fus[3].i_fi].indice_unidade = 0;
                        fus[3].id = 0;
                        fus[3].busy = false;
                        fus[3].rj = false;
                        fus[3].rk = false;
                        fus[3].time = 2;
                        fus[3].immediate = -1;
                        strcpy(fus[3].opName, "");
                        strcpy(fus[3].fi, "");
                        strcpy(fus[3].fj, "");
                        strcpy(fus[3].fk, "");
                        strcpy(fus[3].qj, "");
                        strcpy(fus[3].qk, "");

                    }
                }

                else{

                    //verificar no rss[] se o registrador da dependencia já está pronto
                    if(fus[3].rj == false)
                        if(rss[fus[3].i_fj].indice_unidade == 0)
                            fus[3].rj = true;

                    if(fus[3].rk == false)
                        if(rss[fus[3].i_fk].indice_unidade == 0)
                            fus[3].rk = true;

                    if(fus[3].rj == true && fus[3].rk == true){
                        ciclo++;
                        continue;
                    }

                }

            }

            else if(aux == fus[4].id){

                if(is[aux][0] == 0)
                    is[aux][0] = ciclo;

                else if(fus[4].rj == true && fus[4].rk == true){

                    //executar
                    if(is[aux][1] == 0){

                        is[aux][1] = ciclo;

                        //estágio de busca
                        if(fus[4].fi[0] != '\0')
                            fus[4].operando1 = reg[fus[4].i_fi];

                        if(fus[4].fj[0] != '\0')
                            fus[4].operando2 = reg[fus[4].i_fj];
                        
                        if(fus[4].fk[0] != '\0')
                            fus[4].operando3 = reg[fus[4].i_fk];

                        if(fus[4].immediate != -1)
                            fus[4].operando3 = fus[4].immediate;
                        
                    }
                    
                    else if(is[aux][2] == 0 || fus[4].time > 0){

                        is[aux][2] = ciclo;

                        //estágio de execução
                        if(fus[4].time == 1)
                            fus[4].operando1 = execucao(fus[4].operando1, fus[4].operando2, fus[4].operando3, fus[4].opName, fus[4].immediate);
                        
                        fus[4].time--;  //a cada ciclo decrementa o time em 1
                        
                    }

                    else if(is[aux][3] == 0){

                        is[aux][3] = ciclo;

                        //estágio de escrita
                        reg[fus[4].i_fi] = fus[4].operando1;

                        //reiniciar unidade e indice correspondente do rss
                        rss[fus[4].i_fi].indice_unidade = 0;
                        fus[4].id = 0;
                        fus[4].busy = false;
                        fus[4].rj = false;
                        fus[4].rk = false;
                        fus[4].time = 40;
                        fus[4].immediate = -1;
                        strcpy(fus[4].opName, "");
                        strcpy(fus[4].fi, "");
                        strcpy(fus[4].fj, "");
                        strcpy(fus[4].fk, "");
                        strcpy(fus[4].qj, "");
                        strcpy(fus[4].qk, "");

                    }
                }

                else{

                    //verificar no rss[] se o registrador da dependencia já está pronto
                    if(fus[4].rj == false)
                        if(rss[fus[4].i_fj].indice_unidade == 0)
                            fus[4].rj = true;

                    if(fus[4].rk == false)
                        if(rss[fus[4].i_fk].indice_unidade == 0)
                            fus[4].rk = true;

                    if(fus[4].rj == true && fus[4].rk == true){
                        ciclo++;
                        continue;
                    }

                }

            }

            if((aux == total_instrucoes-1) && (fus[0].busy==true || fus[1].busy==true 
            || fus[2].busy == true || fus[3].busy == true || fus[4].busy == true)){
                aux = 1;
                ciclo++;
                continue;
            }

            aux++;

        }
        
        printFus(fus);
        instrucao = instrucao->prox;
        indice++;
        ciclo++;

    }

    return ciclo;

}

void printFus(struct functionalUnitStatus fus[5]){
    //Esses prints podem ser reaproveitado pra printar a tabela na simulação completa

    printf("Functional Unit Status - FUS\n");
    printf("TIME\tNAME\tBUSY\tOP\tFi\tFj\tFk\tQj\tQk\tRj\tRk");
    for(int i = 0; i < 5; i++){  
        printf("\n%d\t%s\t%d\n",fus[i].time,fus[i].nomeUnidade,fus[i].busy);
    }
}

unsigned int execucao(unsigned int operando1, unsigned int operando2, unsigned int operando3, char nome_instrucao[7], int imediato){

    if(strcmp(nome_instrucao, "add\n") == 0)
        operando1 = add(operando1, operando2, operando3);

    else if(strcmp(nome_instrucao, "addi\n") == 0)
        operando1 = addi(operando1, operando2, imediato);

    else if(strcmp(nome_instrucao, "and\n") == 0)
        operando1 = And(operando1, operando2, operando3);

    else if(strcmp(nome_instrucao, "andi\n") == 0)
        operando1 = andi(operando1, operando2, imediato);

    else if(strcmp(nome_instrucao, "b\n") == 0)
        PC = b(PC, imediato);

    else if(strcmp(nome_instrucao, "beq\n") == 0)
        PC = beq(operando1, operando2, PC, imediato);

    else if(strcmp(nome_instrucao, "beql\n") == 0)
        PC = beql(operando1, operando2, PC, imediato);

    else if(strcmp(nome_instrucao, "bgez\n") == 0)
        PC = bgez(operando1, PC, imediato);

    else if(strcmp(nome_instrucao, "bgtz\n") == 0)
        PC = bgtz(operando1, PC, imediato);

    else if(strcmp(nome_instrucao, "blez\n") == 0)
        PC = blez(operando1, PC, imediato);

    else if(strcmp(nome_instrucao, "bltz\n") == 0)
        PC = bltz(operando1, PC, imediato);

    else if(strcmp(nome_instrucao, "bne\n") == 0)
        PC = bne(operando1, operando2, PC, imediato);

    else if(strcmp(nome_instrucao, "div\n") == 0)
        LO = DivLO(operando1, operando2, operando3);

    else if(strcmp(nome_instrucao, "j\n") == 0)
        PC = j(PC, imediato);

    else if(strcmp(nome_instrucao, "jr\n") == 0)
        PC = jr(PC, operando1);

    else if(strcmp(nome_instrucao, "lui\n") == 0)
        operando1 = lui(operando1, imediato);

    else if(strcmp(nome_instrucao, "madd\n") == 0){
        HI += LO;
        HI = madd(operando1, operando2, HI);
    }

    else if(strcmp(nome_instrucao, "mfhi\n") == 0)
        operando1 = mfhi(operando1, HI);
    
    else if(strcmp(nome_instrucao, "mflo\n") == 0)
        operando1 = mflo(operando1, LO);

    else if(strcmp(nome_instrucao, "movn\n") == 0)
        operando1 = movn(operando1, operando2, operando3);

    else if(strcmp(nome_instrucao, "movz\n") == 0)
        operando1 = movz(operando1, operando2, operando3);

    else if(strcmp(nome_instrucao, "msub\n") == 0){
        HI += LO;
        HI = msub(operando1, operando2, HI);
    }

    else if(strcmp(nome_instrucao, "mthi\n") == 0)
        HI = mthi(operando1, HI);

    else if(strcmp(nome_instrucao, "mtlo\n") == 0)
        LO = mtlo(operando1, LO);

    else if(strcmp(nome_instrucao, "mul\n") == 0)
        operando1 = mul(operando1, operando2, operando3);

    else if(strcmp(nome_instrucao, "mult\n") == 0)
        operando1 = mult(operando2, operando3, operando1);

    else if(strcmp(nome_instrucao, "nor\n") == 0)
        operando1 = nor(operando1, operando2, operando3);

    else if(strcmp(nome_instrucao, "or\n") == 0)
        operando1 = Or(operando1, operando2, operando3);

    else if(strcmp(nome_instrucao, "ori\n") == 0)
        operando1 = Ori(operando1, operando2, imediato);

    else if(strcmp(nome_instrucao, "sub\n") == 0)
        operando1 = sub(operando1, operando2, operando3);

    else if(strcmp(nome_instrucao, "xor\n") == 0)
        operando1 = Xor(operando1, operando2, operando3);

    else if(strcmp(nome_instrucao, "xori\n") == 0)
        operando1 = Xori(operando1, operando2, imediato);

    else
        nop();

    return operando1;

}