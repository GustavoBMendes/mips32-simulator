#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Retornará o número de ciclos total levado para o scoreboarding do codigo analisado
int cicloClock;
//Num de instruções que o .asm possui
int numInstrucoes;
//Essa matriz devolverá a ordem de execução das instruções
int instructionStatus[numInstrucoes][4];

typedef struct functionalUnitStatus{
    char *nomeUnidade,*opName,*fi,*fj,*fk,*qj,*qk;
    bool busy,rj,rk;
    int time;
};

functionalUnitStatus fus[5];

typedef struct registerResultStatus{
    char *regName;
    char *ufName;
}

registerResultStatus rss[32];


#endif