#ifndef PIPELINE_H
#define PIPELINE_H
#include "registradores.h"
#include "executionQueue.h"
#include "instrucoes.h"

char* Istage(FILA *execQueue);
void Estage(char* instrucao, FILA *exeQueue);
int getReg(char* reg);

#endif