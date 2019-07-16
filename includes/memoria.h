#ifndef MEMORY_H
#define MEMORY_H

#define memCapacity 536870912

extern unsigned char *memory;

void inicializeMemory();
void readFromMemory();
void writeInMemory();
void printMemory();


#endif