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

extern unsigned int operando1;
extern unsigned int operando2;
extern unsigned int saida_mdu;


void mduDiv();
int mduMul(); //ok
int mduMult(); //ok
int mduMadd(); //ok
void mduMfhi();
void mduMflo();
int mduMsub(); //ok
void mduMthi();
void mduMtlo();

#endif