#ifndef EXECQUEUE_HEADER_H
#define EXECQUEUE_HEADER_H

typedef struct exeQueue NO;
typedef struct fila FILA;

void create();
void clear();
void queueInInst(FILA *F,char *nome);
void queueInRegDest(FILA *novo, char* reg);
void queueInReg1(FILA *novo, char* reg);
void queueInReg2(FILA *novo, char* reg);
void queueInImediato(FILA *novo, int imediato);
int queueOut(FILA* F);
void printQueue (FILA *F);
void ler();
int inserirElementos();

#endif