/*!
 * @header barramento.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO BARRAMENTO
 * ESTE BARRAMENTO FAZ A CONEXÃO ENTRE A MEMORIA PRINCIPAL E O PROCESSADOR
 */

#include "includes/barramento.h"

unsigned char biu[4];


/*
* @function inserirNoBarramento(unsigned char *dado)
* @abstract Insere a palavra a ser transportada pelo barramento do processador
*/
void inserirNoBarramento(unsigned char *dado){
    biu[0] = dado[0];
    biu[1] = dado[1];
    biu[2] = dado[2];
    biu[3] = dado[3];
}


/*
* @function recuperarNoBarramento()
* @abstract Retorna a palavra transportada pelo barramento do processador
*/
unsigned char* recuperarNoBarramento(){
    return (biu);
}