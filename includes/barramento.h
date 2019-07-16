#ifndef BIU_H
#define BIU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memoria.h"

extern unsigned char biuMemToProcessor[4];

void inserirNoBarramento(unsigned char*);
unsigned char* recuperarNoBarramento();

#endif