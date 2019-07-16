#ifndef MEMORY_H
#define MEMORY_H

#define memCapacity 536870912

extern unsigned char *memory;
extern unsigned char *palavra;

void inicializeMemory();
void readFromMemory();
void writeInMemory();
void printMemory();


#endif