#ifndef MEMORY_H
#define MEMORY_H

#define memCapacity 536870912

#include "barramento.h"

extern unsigned char *memory;
extern unsigned char *palavra;

void inicializeMemory();
void readFromMemory(int);
void writeInMemory(int);
void printMemory();


#endif