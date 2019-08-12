#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "executionQueue.h"
#include "registradores.h"
#include "pipeline.h"

//Retornará o número de ciclos total levado para o scoreboarding do codigo analisado
int cicloClock;
//Num de instruções que o .asm possui
int numInstrucoes;
//Essa matriz devolverá a ordem de execução das instruções
//int instructionStatus[numInstrucoes][4];

struct functionalUnitStatus{
    char* nomeUnidade, opName, fi, fj, fk, qj, qk;
    bool busy,rj,rk;
    int time, id, i_fi, i_fj, i_fk;
};

struct functionalUnitStatus fus[5];

struct registerResultStatus{
    char *regName;
    char *ufName;
    int indice_unidade;
};

struct registerResultStatus rss[32];

void inicializarFus(FILA *F, int total_instrucoes);
void printFus();
int** inicializaIS(int **is, int tam);

#endif