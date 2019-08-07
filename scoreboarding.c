#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/scoreboarding.h"


void inicializarFus(){
    struct functionalUnitStatus fus[5];
    
    char *unidadeInt = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeInt,"Integer");
    fus[0].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[0].nomeUnidade,unidadeInt);
    fus[0].busy = false;
    fus[0].time = 1;
    
     
    char *unidadeMult1 = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeMult1,"Mult1");
    fus[1].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[1].nomeUnidade,unidadeMult1);
    fus[1].busy = false;
    fus[1].time = 10;

    char *unidadeMult2 = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeMult2,"Mult2");
    fus[2].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[2].nomeUnidade,unidadeMult2);
    fus[2].busy = false;
    fus[2].time = 10;

    char *unidadeAdd = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeAdd,"Add");
    fus[3].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[3].nomeUnidade,unidadeAdd);
    fus[3].busy = false;
    fus[3].time = 2;

    char *unidadeDiv = (char*)malloc( 8 * sizeof(char));
    strcpy(unidadeDiv,"Divide");
    fus[4].nomeUnidade = (char*) malloc(8 * sizeof(char));
    strcpy(fus[4].nomeUnidade,unidadeDiv);
    fus[4].busy = false;
    fus[4].time = 40;

    
    for(int i = 0; i < 5; i++){
        printf("%s \n",fus[i].nomeUnidade);
    }
    
}