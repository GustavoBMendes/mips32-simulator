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

void mduDiv();
void mduMul();
void mduMult(); 

#endif