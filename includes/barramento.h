#ifndef BIU_H
#define BIU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memoria.h"

/*
 * BARRAMENTO QUE FAZ A CONEXÃO ENTRE O PROCESSADOR E A MEMÓRIA
 */
extern unsigned char biu[4];

void inserirNoBarramento(unsigned char*);
unsigned char* recuperarNoBarramento();

#endif