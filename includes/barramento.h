#ifndef BIU_H
#define BIU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memoria.h"

/*
 * BARRAMENTO QUE FAZ A CONEXÃO ENTRE O PROCESSADOR E A MEMÓRIA
 */
extern unsigned char biu[5];

void inserirNoBarramento(unsigned int dado);
unsigned int recuperarNoBarramento();

#endif