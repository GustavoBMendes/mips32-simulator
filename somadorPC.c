/*!
 * @header somadorPC.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion MÓDULO CRIADO PARA REALIZAR A SOMA DO PROGRAM COUNTER (PC)
 * SOMA 4 BYTES AO ENDEREÇO ATUAL DO PC PARA AVANÇAR À PRÓXIMA INSTRUÇÃO
 */
#include <stdio.h>
#include "includes/somadorPC.h"


/* 
* @function void somarPC()
* @abstract acumula mais 4 bytes no registrador PC, avançando à próxima intrução
*/
int somarPC(int PC){

    PC += 4;
    return PC;
    
}

