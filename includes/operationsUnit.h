#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct opu{
    
    int operando1;  //valor de entrada
    int operando2;  //valor de entrada
    long long int saida_opu;    //valor de saida
    unsigned int opu_op;    //operacao executada pela opu
}opu;

void OPUb();
void OPUbeq();
void OPUbeql();
void OPUbgez();
void OPUbgtz();
void OPUblez();
void OPUbltz();
void OPUbne();
void OPUj();
void OPUjr(); 
void OPUlui();
void OPUmovn();
void OPUmovz();

#endif
