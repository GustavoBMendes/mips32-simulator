#ifndef ULA_H
#define ULA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct alu{
    
    int operando1;  //valor de entrada
    int operando2;  //valor de entrada
    int saida_ula;    //valor de saida
    unsigned int ula_op;    //operação executada pela ula
}ula;

extern unsigned int operando1;
extern unsigned int operando2;
extern unsigned int saida_ula;

int ulaAdd();
void ulaSub();
void ulaAnd();
void ulaOr();
void ulaXor();

#endif

