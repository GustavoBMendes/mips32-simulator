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
#include <ctype.h>
#include "includes/memoria.h"
#include "includes/barramento.h"

unsigned char *memory;
unsigned char *palavra;


int conta_digitos(int valor){

    int contaDigitos = 0;
    if (valor == 0) 
        contaDigitos = 1;

    else

        while (valor != 0){

            contaDigitos = contaDigitos + 1;
            valor = valor / 10;

        }

    return contaDigitos;

}

char* toStr(unsigned int num){

    int num_digitos = conta_digitos(num);
    char *aux = (char*)malloc(sizeof(num_digitos));
    sprintf(aux, "%d", num);

    return aux;

}

unsigned int toInt(char *num){

    unsigned int numero = atoi(num);
    return numero;

}

/*
 * @function inicializeMemory()
 * @abstract FUNÇÃO QUE ALOCA ESPAÇO PARA A MEMÓRIA PRINCIPAL
 * E PARA A PALAVRA AUXILIAR
 */
void inicializeMemory(){

    memory = malloc(memCapacity * sizeof(char));
    palavra = malloc(4 * sizeof(char));

}

/*
 * @function readFromMemory(int endereco)
 * @abstract FUNÇÃO PARA REALIZAR A LEITURA DA MEMÓRIA
 * LEITURA REALIZADA POR PALAVRA
 * RETORNA OS 4 BYTES CONSECUTIVOS A PARTIR DO ENDEREÇO PASSADO COMO PARÂMETRO
 */
void readFromMemory(int endereco){

    int i;        
    for(i = 0; i < 4; i++)
        palavra[i] = memory[endereco + i];

    unsigned int dado = toInt(palavra);
    inserirNoBarramento(dado);    

}

/*
 * @function writeInMemory(int endereco)
 * @abstract FUNÇÃO PARA REALIZAR UMA ESCRITA NA MEMÓRIA
 * PALAVRAS DE 32 BITS (4 BYTES)
 * ESCRITA 4 BYTES EM UM ENDEREÇO PASSADO COMO PARÂMETRO
 */
void writeInMemory(int endereco){

    //pegar do barramento
    //converter o dado oriundo do barramento para string
    unsigned int aux = recuperarNoBarramento();
    char* palavra = (char*)malloc(sizeof(biu));

    strcpy(palavra,toStr(aux));

    int i;
    for(i = 0; i < 4; i++)
        if(isdigit(palavra[i]))
            memory[endereco + i] = palavra[i];

}

/*
 * @function printMemory()
 * @abstract FUNÇÃO PARA REALIZAR UMA ESCRITA NA MEMÓRIA
 * PALAVRAS DE 32 BITS (4 BYTES)
 * ESCRITA 4 BYTES EM UM ENDEREÇO PASSADO COMO PARÂMETRO
 */
void printMemory(){

    int i;
    for(i = 0; i < 100; i++){

        if(i % 4 == 0)
            printf("\n");
        printf("\n[%d] : %c", i, *(memory + i));

    }

}
