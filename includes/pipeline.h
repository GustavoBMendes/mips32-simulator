#ifndef PIPELINE_H
#define PIPELINE_H
#include "registradores.h"
#include "executionQueue.h"
#include "instrucoes.h"

char* Istage(FILA *execQueue, int PC);
int Estage(char* instrucao, FILA *exeQueue, int PC);
int Mstage(int PC);
int Astage(int PC);
int Wstage(int PC, int indice, int dado);
int getReg(char* reg);

#endif