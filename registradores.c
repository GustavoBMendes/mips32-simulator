/*!
 * @header registradores.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÃO IMPLEMENTADOS OS REGISTRADORES
 * SÃO 32 REGISTRADORES DE USO GERAL
 * E 3 REGISTRADORES ESPECIAIS: PC(PROGRAM COUNTER), HI E LO(ACUMULADORES)
 */
#include <stdio.h>
#include "includes/registradores.h"

void printRegistradores(int *reg, int HI, int LO, int PC){
    
    int i;

    printf("\nConteúdo dos registradores:\n");
    printf("\nRegistradores especiais -> PC = %d | HI = %d | LO = %d", PC, HI, LO);

    printf("\nRegistradores de uso geral -> \n");
    for(i = 0; i < 32; i++){
        printf("reg[%d] = %d\n", i, reg[i]);
    }
    
}