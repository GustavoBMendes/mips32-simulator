#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "executionQueue.h"
#include "registradores.h"
#include "pipeline.h"

extern unsigned int reg[32];
//Retornará o número de ciclos total levado para o scoreboarding do codigo analisado
int cicloClock;
//Num de instruções que o .asm possui
int numInstrucoes;
//Essa matriz devolverá a ordem de execução das instruções
//int instructionStatus[numInstrucoes][4];

struct functionalUnitStatus{
    char *nomeUnidade, opName[5], fi[5], fj[5], fk[5], qj[5], qk[5];
    bool busy,rj,rk;
    int time, id, i_fi, i_fj, i_fk; 
    unsigned int operando1, operando2, operando3, immediate;
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
unsigned int execucao(unsigned int operando1, unsigned int operando2, unsigned int operando3, char* instrucao, int imediato);

#endif