#ifndef MDU_H
#define MDU_H
#include <stdio.h>
#include <stdlib.h>

typedef struct mdu{
    
    int operando1;  //valor de entrada
    int operando2;  //valor de entrada
    long long int saida_mdu;    //valor de saida
    unsigned int mdu_op;    
}mdu;

void mduDiv(mdu *mdu_executavel);
void mduMul(mdu *mdu_executavel);
void mduMult(mdu *mdu_executavel); 
void mduMadd(mdu *mdu_executavel);
void mduMfhi(mdu *mdu_executavel);
void mduMflo(mdu *mdu_executavel);
void mduMsub(mdu *mdu_executavel);
void mduMthi(mdu *mdu_executavel);
void mduMtlo(mdu *mdu_executavel);

#endif