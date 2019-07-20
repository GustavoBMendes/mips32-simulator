#ifndef MDU_H
#define MDU_H
#include <stdio.h>
#include <stdlib.h>


extern unsigned int operando1;
extern unsigned int operando2;
extern unsigned int saida_mdu;


int mduDivHI(int regOrigem1, int regOrigem2, int HI, int LO);
int mduDivLO(int regOrigem1, int regOrigem2,int HI, int LO);
int mduMul(int regOrigem1, int regOrigem2); 
int mduMult(int regOrigem1, int regOrigem2); 
int mduMadd(int regOrigem1, int regOrigem2); 
int mduMfhi(int HI, int regOrigem1); 
int mduMflo(int LO, int regOrigem1); 
int mduMsub(int regOrigem1, int regOrigem2); 
int mduMthi(int regOrigem1, int HI); 
int mduMtlo(int regOrigem1, int LO); 

#endif