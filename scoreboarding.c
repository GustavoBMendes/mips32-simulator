#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/scoreboarding.h"


void inicializarFus(){
    functionalUnitStatus fus[5];
    
    char *unidadeInt = (char*)malloc( 7 * sizeof(char));
    strcpy(unidadeInt,"Integer");
    strcpy(fus[0].nomeUnidade,unidadeInt);
    fus[0].busy = false;
    fus[0].time = 1;
    
    char *unidadeMult1 = (char*)malloc( 7 * sizeof(char));
    strcpy(unidadeMult1,"Mult1");
    strcpy(fus[1].nomeUnidade,unidadeMult1);
    fus[1].busy = false;
    fus[0].time = 10;

    char *unidadeMult2 = (char*)malloc( 7 * sizeof(char));
    strcpy(unidadeMult2,"Mult2");
    strcpy(fus[2].nomeUnidade,unidadeMult2);
    fus[2].busy = false;
    fus[0].time = 10;

    char *unidadeAdd = (char*)malloc( 7 * sizeof(char));
    strcpy(unidadeAdd,"Add");
    strcpy(fus[3].nomeUnidade,unidadeAdd);
    fus[3].busy = false;
    fus[3].time = 2;

    char *unidadeDiv = (char*)malloc( 7 * sizeof(char));
    strcpy(unidadeDiv,"Divide");
    strcpy(fus[4].nomeUnidade,unidadeDiv);
    fus[4].busy = false;
    fus[4].time = 40;
    
}