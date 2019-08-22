/*!
 * @header barramento.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO BARRAMENTO
 * ESTE BARRAMENTO FAZ A CONEXÃO ENTRE A MEMORIA PRINCIPAL E O PROCESSADOR
 */

#include "includes/barramento.h"
#include "includes/memoria.h"

unsigned char biu[5];

/*
* @function inserirNoBarramento(unsigned char *dado)
* @abstract Insere a palavra a ser transportada pelo barramento do processador
*/
void inserirNoBarramento(unsigned int dado){

    char* sdado;
    sdado = (char*)malloc(sizeof(biu));
    strcpy(sdado,toStr(dado));

    for(int i = 0; i <= strlen(sdado); i++)
        biu[i] = sdado[i];

}


/*
* @function recuperarNoBarramento()
* @abstract Retorna a palavra transportada pelo barramento do processador
*/
unsigned int recuperarNoBarramento(){

    char *aux;
    aux = (char*)malloc(sizeof(biu));
    strcpy(aux,biu);
    unsigned int k = toInt(aux);
    
    return k;

}

void printBarramento(){

    int i;

    printf("\nConteúdo do barramento\n> | ");
    for(i = 0; i < 4; i++){
        printf("%c |", biu[i]);
    }
    printf("\n");

}