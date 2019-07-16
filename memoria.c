/*!
 * @header memory.c
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

/*
 * @function alocar
 * @abstract FUNÇÃO QUE ALOCA ESPAÇO PARA A MEMÓRIA PRINCIPAL
 * E PARA A PALAVRA AUXILIAR
 */
void inicializeMemory(){
    memory = malloc(memCapacity * sizeof(char));
    palavra = malloc(4 * sizeof(char));
    printf("Memoria inicializada");
}

/*
 * @function ler
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

        //caso implementarmos um barramento, inserir palavra no barramento
    }

    else
        printf("Não foi possível acessar este endereço de memória");    
    
}

void writeInMemory(int endereco){

    if(endereco % 4 == 0){

        //caso implementarmos um barramento, fazer um for para pegar a palavra do barramento

        int i;
        for(i = 0; i < 4; i++){

            memory[endereco + i] = palavra[i];
        }
    }

    else
        printf("Não foi possível acessar este endereço de memória");
}

void printMemory(){

    int i;
    for(i = 0; i < memCapacity; i++){

        if(i % 4 == 0)
            printf("\n");
        printf("\n[%d] : %x", i, *(memory + i));
    }
}
