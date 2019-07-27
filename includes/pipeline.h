#ifndef PIPELINE_H
#define PIPELINE_H
#include "registradores.h"
#include "executionQueue.h"
#include "instrucoes.h"

char* Istage(FILA *execQueue, int PC);
void Estage(char* instrucao, FILA *exeQueue, int PC);
int getReg(char* reg);

#endif