#ifndef QUEUE_HEADER_H
#define QUEUE_HEADER_H

typedef struct queue fila;
fila* create();
void clear();
void queueIn(fila* F,int elemento);
int queueOut(fila* F);
void printQueue (fila *F);

#endif