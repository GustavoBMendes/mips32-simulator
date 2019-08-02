#ifndef PREDICTOR_H
#define PREDICTOR_H
#include <stdbool.h>
#include "executionQueue.h"
#include "operationsUnit.h"
#include "pipeline.h"

typedef struct numerosPrevisao;

struct numerosPrevisao{
    int acertos;
    int erros;
};

struct numerosPrevisao previsao();
bool isBranch(char* instrucao);
bool prediction(char *instrucao, int a, int b);
NO* getNoBranch(FILA *F, int PC);
int getRegBranch(NO* branch, int indice);

#endif