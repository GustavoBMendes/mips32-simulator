#ifndef EXECQUEUE_HEADER_H
#define EXECQUEUE_HEADER_H

typedef struct exeQueue fila;
fila* create();
void clear();
//void queueIn(fila* F,char *nome,int dado1, int dado2, int dest);
fila* queueInInst(fila *F,char *nome);
fila* queueInRegDest(fila *novo, char* reg);
fila* queueInReg1(fila *novo, char* reg);
fila* queueInReg2(fila *novo, char* reg);
fila* queueInImediato(fila *novo, int imediato);
fila queueOut(fila* F);
void printQueue (fila *F);
void ler();
void inserirElementos();

#endif