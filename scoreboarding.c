#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/scoreboarding.h"



void inicializarFus(FILA *F, int total_instrucoes){

    extern unsigned int reg[32];

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
    int auxFila = 0;
    //int idInstrucao = 0;
    NO* instrucao = F->inicio;

    struct fila{
        int unidade, id, iFi, iFj, iFk, imm;
        char* nomeInstrucao, Fi, Fj, Fk;
    };
    struct fila fila_espera[total_instrucoes-1];

    while(indice < total_instrucoes){
        

        //Comparar instrucao->instructionName com o nome das instruções 
        //que entram em determinada unidade
        //provavelmente fazer um if para cada uma das 33 instrucoes

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

                    else if(fus[3].i_fk == i){
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

                /*
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
                */
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

        else if(strcmp(instrucao->instructionName, "mult\n") == 0){

            if(fus[1].busy == false){

                fus[1].busy = true;
                strcpy(fus[1].opName, instrucao->instructionName);
                strcpy(fus[1].fi, instrucao->regDestino);
                strcpy(fus[1].fj, instrucao->reg1);

                //verificar nas instrucoes anteriores se possui dependecia de dados

            }

            else if(fus[2].busy == false){

                fus[2].busy = true;
                strcpy(fus[2].opName, instrucao->instructionName);
                strcpy(fus[2].fi, instrucao->regDestino);
                strcpy(fus[2].fj, instrucao->reg1);

                //verificar nas instrucoes anteriores se possui dependecia de dados

            }

            else{
                //fila
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

                //verificar nas instrucoes anteriores se possui dependecia de dados
                //percorrer o rss verificando se os registradores já estão sendo utilizados para escrita
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

                //verificar nas instrucoes anteriores se possui dependecia de dados
                //percorrer o rss verificando se os registradores já estão sendo utilizados para escrita
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

                //verificar nas instrucoes anteriores se possui dependecia de dados
                //percorrer o rss verificando se os registradores já estão sendo utilizados para escrita
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

                    else if(fus[0].i_fk == i){
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

                //verificar nas instrucoes anteriores se possui dependecia de dados
                //percorrer o rss verificando se os registradores já estão sendo utilizados para escrita
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

                strcpy(fila_espera[auxFila].nomeInstrucao, instrucao->instructionName);
                strcpy(fila_espera[auxFila].Fi, instrucao->regDestino);
                strcpy(fila_espera[auxFila].Fj, instrucao->reg1);

                auxFila++;

            }

        }
        

        else{
            printf("\nNão foi encontrada a instrução, no operation 'nop()'");
        }

        if(indice == 0){
            is[indice][0] = ciclo;
            is[indice][1] = ciclo++;
            //Estage();
            is[indice][2] = ciclo++;
            //Mstage();
            is[indice][3] = ciclo++;
            //Wstage();

            instrucao = instrucao->prox;
            ciclo++;
            indice++;
            continue;
        }

        //execução
        int aux = 1;
        while(aux <= indice){

            //verificar se as instruções da fila de espera já podem entrar no  fus
            int i = 0;
            while(i <= auxFila){

                int unidade = fila_espera[i].unidade;
                //unidade livre, inserir
                if(fus[unidade].busy == false){

                    fus[unidade].id = aux;
                    fus[unidade].busy = true;
                    fus[unidade].i_fi = getReg(fila_espera[i].iFi);
                    fus[unidade].i_fj = getReg(fila_espera[i].iFj);
                    fus[unidade].i_fk = getReg(fila_espera[i].iFk );

                    strcpy(fus[unidade].opName, fila_espera[i].nomeInstrucao);
                    strcpy(fus[unidade].fi, fila_espera[i].Fi);
                    strcpy(fus[unidade].fj, fila_espera[i].Fj);
                    strcpy(fus[unidade].fk, fila_espera[i].Fk);

                    //remover da fila ou marcar como já inserido no fus

                }
                i++;

            }

            if(aux == fus[0].id){
                if(is[aux][0] == 0){
                    is[aux][0] = ciclo;
                }
                if(fus[0].rj == true && fus[0].rk == true){
                    //executar
                    if(is[aux][1] == 0){
                        is[aux][1] = ciclo;
                        //estágio de busca
                        if(fus[0].fi != '\0'){
                            fus[0].operando1 = reg[fus[0].i_fi];
                        }
                        if(fus[0].fj != '\0'){
                            fus[0].operando2 = reg[fus[0].i_fj];
                        }
                        if(fus[0].fk != '\0'){
                            fus[0].operando3 = reg[fus[0].i_fk];
                        }
                    }
                    else if(is[aux][2] == 0 || fus[0].time > 0){
                        is[aux][2] = ciclo;
                        //estágio de execução
                        if(fus[0].time == 1)
                            execucao(fus[0].operando1, fus[0].operando2, fus[0].operando3, fus[0].opName, fus[0].immediate);
                        fus[0].time--;  //a cada ciclo decrementa o time em 1
                    }
                    else if(is[aux][3] == 0){
                        is[aux][3] = ciclo;
                        //estágio de escrita
                        //reiniciar unidade e indice correspondente do rss
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

                    if(fus[0].rj == true && fus[0].rk == true)
                        continue;
                }
            }

            if(aux == fus[1].id){

            }

            if(aux == fus[2].id){

            }

            if(aux == fus[3].id){

            }

            if(aux == fus[4].id){

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

unsigned int execucao(unsigned int operando1, unsigned int operando2, unsigned int operando3, char* instrucao, int imediato){

    if(strcmp(instrucao, "add\n") == 0)
        operando1 = add(operando1, operando2, operando3);

    else if(strcmp(instrucao, "addi\n") == 0)
        operando1 = addi(operando1, operando2, imediato);

    else if(strcmp(instrucao, "and\n") == 0)
        operando1 = And(operando1, operando2, operando3);

    else if(strcmp(instrucao, "andi\n") == 0)
        operando1 = andi(operando1, operando2, imediato);

    else if(strcmp(instrucao, "b\n") == 0)
        PC = b(PC, imediato);

    else if(strcmp(instrucao, "beq\n") == 0)
        PC = beq(operando1, operando2, PC, imediato);

    else if(strcmp(instrucao, "beql\n") == 0)
        PC = beql(operando1, operando2, PC, imediato);

    else if(strcmp(instrucao, "bgez\n") == 0)
        PC = bgez(operando1, PC, imediato);

    else if(strcmp(instrucao, "bgtz\n") == 0)
        PC = bgtz(operando1, PC, imediato);

    else if(strcmp(instrucao, "blez\n") == 0)
        PC = blez(operando1, PC, imediato);

    else if(strcmp(instrucao, "bltz\n") == 0)
        PC = bltz(operando1, PC, imediato);

    else if(strcmp(instrucao, "bne\n") == 0)
        PC = bne(operando1, operando2, PC, imediato);

    else if(strcmp(instrucao, "div\n") == 0){
        HI = DivHI(operando1, operando2, HI, LO);
        LO = DivLO(operando1, operando2, HI, LO);
    }

    else if(strcmp(instrucao, "j\n") == 0)
        PC = j(PC, imediato);

    else if(strcmp(instrucao, "jr\n") == 0)
        PC = jr(PC, operando1);

    else if(strcmp(instrucao, "lui\n") == 0)
        operando1 = lui(operando1, imediato);

    else if(strcmp(instrucao, "madd\n") == 0){
        HI += LO;
        HI = madd(operando1, operando2, HI);
    }

    else if(strcmp(instrucao, "mfhi\n") == 0)
        operando1 = mfhi(operando1, HI);
    
    else if(strcmp(instrucao, "mflo\n") == 0)
        operando1 = mflo(operando1, LO);

    else if(strcmp(instrucao, "movn\n") == 0)
        operando1 = movn(operando1, operando2, operando3);

    else if(strcmp(instrucao, "movz\n") == 0)
        operando1 = movz(operando1, operando2, operando3);

    else if(strcmp(instrucao, "msub\n") == 0){
        HI += LO;
        HI = msub(operando1, operando2, HI);
    }

    else if(strcmp(instrucao, "mthi\n") == 0)
        HI = mthi(operando1, HI);

    else if(strcmp(instrucao, "mtlo\n") == 0)
        LO = mtlo(operando1, LO);

    else if(strcmp(instrucao, "mul\n") == 0)
        operando1 = mul(operando1, operando2, operando3);

    else if(strcmp(instrucao, "mult\n") == 0){
        HI += LO;
        HI = mult(operando1, operando2, HI);
    }

    else if(strcmp(instrucao, "nor\n") == 0)
        operando1 = nor(operando1, operando2, operando3);

    else if(strcmp(instrucao, "or\n") == 0)
        operando1 = Or(operando1, operando2, operando3);

    else if(strcmp(instrucao, "ori\n") == 0)
        operando1 = Ori(operando1, operando2, imediato);

    else if(strcmp(instrucao, "sub\n") == 0)
        operando1 = sub(operando1, operando2, operando3);

    else if(strcmp(instrucao, "xor\n") == 0)
        operando1 = Xor(operando1, operando2, operando3);

    else if(strcmp(instrucao, "xori\n") == 0)
        operando1 = Xori(operando1, operando2, imediato);

    else
        nop();

    return operando1;

}