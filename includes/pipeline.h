#ifndef PIPELINE_H
#define PIPELINE_H
#include "registradores.h"
#include "executionQueue.h"
#include "instrucoes.h"

char* Istage(fila *execQueue);
void Estage(char* instrucao, fila *exeQueue);

#endif