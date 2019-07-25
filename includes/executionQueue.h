#ifndef EXECQUEUE_HEADER_H
#define EXECQUEUE_HEADER_H

typedef struct exeQueue NO;
typedef struct fila FILA;

struct exeQueue{
    char *instructionName;
    int imediato;
	char *regDestino, *reg1, *reg2;
    struct exeQueue *prox;
};

struct fila{
	NO *inicio, *fim;
};

void create();
void clear();
//void queueIn(FILA* F,char *nome,int dado1, int dado2, int dest);
void queueInInst(FILA *F,char *nome);
void queueInRegDest(FILA *novo, char* reg);
void queueInReg1(FILA *novo, char* reg);
void queueInReg2(FILA *novo, char* reg);
void queueInImediato(FILA *novo, int imediato);
int queueOut(FILA* F);
void printQueue (FILA F);
void ler();
void inserirElementos(FILA *F);

#endif