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


int mduDivHI();
int mduDivLO();
int mduMul(); //ok
int mduMult(); //ok
int mduMadd(); //ok
int mduMfhi(); //Ok
int mduMflo(); //ok
int mduMsub(); //ok
int mduMthi(); //ok
int mduMtlo(); //ok

#endif