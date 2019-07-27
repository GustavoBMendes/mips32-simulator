/*!
 * @header memoria.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADA A MEMÓRIA DO SIMULADOR
 * CADA PALAVRA TEM 32 BITS = 4 CHAR
 * O TAMANHO TOTAL É DE 512MB
 * tamanho real: 536 870 912 (2²⁹)
 * CADA CÉLULA TEM O TAMANHO DE 8 BITS = 1 CHAR
 * 64MB POSIÇÕES ENDEREÇÁVEIS DE MEMÓRIA
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/memoria.h"

unsigned char *memory;
unsigned char *palavra;


int conta_digitos(int valor){
    int contaDigitos = 0;
    if (valor == 0) contaDigitos = 1;
    else
        while (valor != 0)
        {
            contaDigitos = contaDigitos + 1;
            valor = valor / 10;
        }
    return contaDigitos;
}

char* converter(int num){
    int num_digitos = conta_digitos(num);
    char *aux = (char*)malloc(sizeof(num_digitos));
    sprintf(aux, "%d", num);
    return aux;
}





/*
 * @function inicializeMemory()
 * @abstract FUNÇÃO QUE ALOCA ESPAÇO PARA A MEMÓRIA PRINCIPAL
 * E PARA A PALAVRA AUXILIAR
 */
void inicializeMemory(){
    memory = malloc(memCapacity * sizeof(char));
    palavra = malloc(4 * sizeof(char));
    printf("Memoria inicializada");
}

/*
 * @function readFromMemory(int endereco)
 * @abstract FUNÇÃO PARA REALIZAR A LEITURA DA MEMÓRIA
 * LEITURA REALIZADA POR PALAVRA
 * RETORNA OS 4 BYTES CONSECUTIVOS A PARTIR DO ENDEREÇO PASSADO COMO PARÂMETRO
 */
void readFromMemory(int endereco){

    if(endereco % 4 == 0){

        int i;
        for(i = 0; i < 4; i++){

            palavra[i] = memory[endereco + i];
        }

        inserirNoBarramento(palavra);
    }

    else
        printf("Não foi possível acessar este endereço de memória");    
    
}

/*
 * @function writeInMemory(int endereco)
 * @abstract FUNÇÃO PARA REALIZAR UMA ESCRITA NA MEMÓRIA
 * PALAVRAS DE 32 BITS (4 BYTES)
 * ESCRITA 4 BYTES EM UM ENDEREÇO PASSADO COMO PARÂMETRO
 */
void writeInMemory(int endereco){

    if(endereco % 4 == 0){

        int i;

        palavra = recuperarNoBarramento();
        
        for(i = 0; i < 4; i++){
            memory[endereco + i] = palavra[i];
        }
    }

    else
        printf("Não foi possível acessar este endereço de memória");
}

/*
 * @function printMemory()
 * @abstract FUNÇÃO PARA REALIZAR UMA ESCRITA NA MEMÓRIA
 * PALAVRAS DE 32 BITS (4 BYTES)
 * ESCRITA 4 BYTES EM UM ENDEREÇO PASSADO COMO PARÂMETRO
 */
void printMemory(){

    int i;
    for(i = 0; i < memCapacity; i++){

        if(i % 4 == 0)
            printf("\n");
        printf("\n[%d] : %x", i, *(memory + i));
    }
}
