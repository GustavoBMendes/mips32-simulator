/*!
 * @header executionQueue.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO O TRADUTOR DE NOSSO SIMULADOR
 * NELE É RECEBIDO UM ARQUIVO DE EXTENSÃO .ASM
 * ELE É TRADUZIDO PARA GERAR UM ARQUIVO COM O BINÁRIO DAS INSTRUÇÕES 
 * A PARTIR DESTE CÓDIGO BINÁRIO, É GERADO OUTRO ARQUIVO COM AS INSTRUÇÕES EM HEXADECIMAL
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "includes/tradutor.h"

void arquivoBin(FILE* arq){

    arq = fopen("saida.txt", "r");
    FILE* bin = fopen("binario.txt", "w");

    if(arq == NULL || bin == NULL)
        printf("\nNão foi possível abri o arquivo.\n");

    int i = 0;
    char str[7];

    while(fgets(str, 7, arq) != NULL){

        if(str[0] == '$'){

            //verificar registrador
            if(strcmp(str, "$zero\n") == 0)
                fputs("000000", bin);
            
            else if(strcmp(str, "$at\n") == 0)
                fputs("000001", bin);

            else if(strcmp(str, "$v0\n") == 0)
                fputs("000010", bin);

            else if(strcmp(str, "$v1\n") == 0)
                fputs("000011", bin);

            else if(strcmp(str, "$a0\n") == 0)
                fputs("000100", bin);

            else if(strcmp(str, "$a1\n") == 0)
                fputs("000101", bin);

            else if(strcmp(str, "$a2\n") == 0)
                fputs("000110", bin);

            else if(strcmp(str, "$a3\n") == 0)
                fputs("000111", bin);

            else if(strcmp(str, "$t0\n") == 0)
                fputs("001000", bin);

            else if(strcmp(str, "$t1\n") == 0)
                fputs("001001", bin);

            else if(strcmp(str, "$t2\n") == 0)
                fputs("001010", bin);

            else if(strcmp(str, "$t3\n") == 0)
                fputs("001011", bin);

            else if(strcmp(str, "$t4\n") == 0)
                fputs("001100", bin);

            else if(strcmp(str, "$t5\n") == 0)
                fputs("001101", bin);

            else if(strcmp(str, "$t6\n") == 0)
                fputs("001110", bin);

            else if(strcmp(str, "$t7\n") == 0)
                fputs("001111", bin);

            else if(strcmp(str, "$s0\n") == 0)
                fputs("010000", bin);

            else if(strcmp(str, "$s1\n") == 0)
                fputs("010001", bin);

            else if(strcmp(str, "$s2\n") == 0)
                fputs("010010", bin);

            else if(strcmp(str, "$s3\n") == 0)
                fputs("010011", bin);

            else if(strcmp(str, "$s4\n") == 0)
                fputs("010100", bin);

            else if(strcmp(str, "$s5\n") == 0)
                fputs("010101", bin);

            else if(strcmp(str, "$s6\n") == 0)
                fputs("010110", bin);

            else if(strcmp(str, "$s7\n") == 0)
                fputs("010111", bin);

            else if(strcmp(str, "$t8\n") == 0)
                fputs("011000", bin);

            else if(strcmp(str, "$t9\n") == 0)
                fputs("011001", bin);

            else if(strcmp(str, "$k0\n") == 0)
                fputs("011010", bin);

            else if(strcmp(str, "$k1\n") == 0)
                fputs("011011", bin);

            else if(strcmp(str, "$gp\n") == 0)
                fputs("011100", bin);

            else if(strcmp(str, "$sp\n") == 0)
                fputs("011101", bin);

            else if(strcmp(str, "$fp\n") == 0)
                fputs("011110", bin);

            else if(strcmp(str, "$ra\n") == 0)
                fputs("011111", bin);

            else
                printf("\nRegistrador não encontrado!");

            i++;

        }

        else if(isdigit(str[0])){

            //traduzir decimal para binário

            

            i++;

        }

        else{

            if(i != 0)
                fputs("\n", bin);

            //verificar instrucao
            if(strcmp(str, "add\n") == 0)
                fputs("100000", bin);
            
            else if(strcmp(str, "addi\n") == 0)
                fputs("001000", bin);

            else if(strcmp(str, "$and\n") == 0)
                fputs("100100", bin);

            else if(strcmp(str, "andi\n") == 0)
                fputs("001100", bin);

            else if(strcmp(str, "$b\n") == 0)
                fputs("001101", bin);

            else if(strcmp(str, "beq\n") == 0)
                fputs("000100", bin);

            else if(strcmp(str, "beql\n") == 0)
                fputs("010100", bin);

            else if(strcmp(str, "bgez\n") == 0)
                fputs("00001", bin);

            else if(strcmp(str, "bgtz\n") == 0)
                fputs("000111", bin);

            else if(strcmp(str, "blez\n") == 0)
                fputs("000110", bin);

            else if(strcmp(str, "bltz\n") == 0)
                fputs("00000", bin);

            else if(strcmp(str, "bne\n") == 0)
                fputs("000101", bin);

            else if(strcmp(str, "div\n") == 0)
                fputs("011010", bin);

            else if(strcmp(str, "j\n") == 0)
                fputs("000010", bin);

            else if(strcmp(str, "jr\n") == 0)
                fputs("001000", bin);

            else if(strcmp(str, "lui\n") == 0)
                fputs("001111", bin);

            else if(strcmp(str, "madd\n") == 0)
                fputs("000000", bin);

            else if(strcmp(str, "mfhi\n") == 0)
                fputs("010000", bin);

            else if(strcmp(str, "mflo\n") == 0)
                fputs("010010", bin);

            else if(strcmp(str, "movn\n") == 0)
                fputs("001011", bin);

            else if(strcmp(str, "movz\n") == 0)
                fputs("001010", bin);

            else if(strcmp(str, "$msub\n") == 0)
                fputs("000100", bin);

            else if(strcmp(str, "mthi\n") == 0)
                fputs("010001", bin);

            else if(strcmp(str, "mtlo\n") == 0)
                fputs("010011", bin);

            else if(strcmp(str, "mul\n") == 0)
                fputs("000010", bin);

            else if(strcmp(str, "mult\n") == 0)
                fputs("011000", bin);

            else if(strcmp(str, "nor\n") == 0)
                fputs("100111", bin);

            else if(strcmp(str, "or\n") == 0)
                fputs("100101", bin);

            else if(strcmp(str, "ori\n") == 0)
                fputs("001101", bin);

            else if(strcmp(str, "sub\n") == 0)
                fputs("011101", bin);

            else if(strcmp(str, "xor\n") == 0)
                fputs("100110", bin);

            else if(strcmp(str, "xori\n") == 0)
                fputs("001110", bin);

            else{

                printf("\nInstrução não encontrada, ou label encontrado");
                i = 1;
                continue;

            }

            i = 0;

        }

    }

}

void arquivoHex(){

}