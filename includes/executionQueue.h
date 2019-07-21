#ifndef EXECQUEUE_HEADER_H
#define EXECQUEUE_HEADER_H

typedef struct exeQueue fila;
fila* create();
void clear();
void queueIn(fila* F,char *nome,int dado1, int dado2, int dest);
fila queueOut(fila* F);
void printQueue (fila *F);

#endif