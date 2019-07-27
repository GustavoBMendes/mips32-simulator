#ifndef MEMORY_H
#define MEMORY_H

#define memCapacity 536870912

#include "barramento.h"

typedef struct memoria{
    char *nomeInstrucao;
    int valor1,valor2;
    int reg_destino;
}memoria;


extern unsigned char *memory;
extern unsigned char *palavra;

void inicializeMemory();
void readFromMemory(int);
void writeInMemory(int);
void printMemory();
int converter(int num);


#endif