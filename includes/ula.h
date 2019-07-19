#ifndef ULA_H
#define ULA_H
#include <stdio.h>
#include <stdlib.h>

extern unsigned int operando1;
extern unsigned int operando2;
extern unsigned int saida_ula;

int ulaAdd(int regOrigem1, int regOrigem2);
int ulaSub(int regOrigem1, int regOrigem2);
int ulaAnd(int regOrigem1, int regOrigem2);
int ulaOr(int regOrigem1, int regOrigem2);
int ulaXor(int regOrigem1, int regOrigem2);

#endif

