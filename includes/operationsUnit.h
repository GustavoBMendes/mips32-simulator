#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct opu{
    
    int operando1;  //valor de entrada
    int operando2;  //valor de entrada
    long long int saida_mdu;    //valor de saida
    unsigned int mdu_op;    
}opu;

void OPUb(int PC, int offset);
void OPUbeq(int regOrigem1, int regOrigem2, int PC, int offset);
void OPUbeql(int regOrigem1,int regOrigem2,int PC, int offset);
void OPUbgez(int regOrigem1, int PC, int offset);
void OPUbgtz(int regOrigem1, int PC, int offset);
void OPUblez(int regOrigem1, int PC, int offset);
void OPUbltz(int regOrigem1, int PC, int offset);
void OPUbne(int regOrigem1,int regOrigem2,int PC, int offset);
void OPUj(int PC, int offset);
void OPUjr(int PC, int regOrigem1); 
void OPUlui(int regDestino, int imediato);
void OPUmovn(int regDestino,int regOrigem1, int regOrigem2);
void OPUmovz(int regDestino,int regOrigem1, int regOrigem2);

#endif
