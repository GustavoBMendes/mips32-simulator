/*!
 * @header barramento.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO BARRAMENTO DO PROCESSADOR
 */

#include "includes/barramento.h"

unsigned char biuMemToProcessor[4];


/*
* @function Inserir dados
* @abstract Insere a palavra a ser transportada pelo barramento do processador
*/
void inserirNoBarramento(unsigned char *dado){
    biuMemToProcessor[0] = dado[0];
    biuMemToProcessor[1] = dado[1];
    biuMemToProcessor[2] = dado[2];
    biuMemToProcessor[3] = dado[3];
}


/*
* @function Recuperar dados
* @abstract Retorna a palavra transportada pelo barramento do processador
*/
unsigned char* recuperarNoBarramento(){
    return (biuMemToProcessor);
}