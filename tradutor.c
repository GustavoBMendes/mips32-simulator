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


/*
 * @function void arquivoBin()
 * @abstract 32 bits ao todo para cada linha
 * 16 bits para números inteiros
 * 6 bits para instruções
 * 5 bits para registradores
 */
void arquivoBin(){

    FILE* arq = fopen("saida.txt", "r");
    FILE* bin = fopen("binario.txt", "w");

    if(arq == NULL || bin == NULL)
        printf("\nNão foi possível abri o arquivo.\n");

    int num, i = 0;
    char str[7];
    char imediato[17];


    while(fgets(str, 7, arq) != NULL){

		if(i != 0)
			fputs("\n", bin);

		//verificar instrucao
		if(strcmp(str, "add\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("100000", bin);

		}
		
		else if(strcmp(str, "addi\n") == 0){

			fputs("001000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else if(strcmp(str, "$and\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("100100", bin);
		
		}

		else if(strcmp(str, "andi\n") == 0){

			fputs("001100", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);	
		}

		else if(strcmp(str, "beq\n") == 0){

			fputs("000100", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);
		}

		else if(strcmp(str, "beql\n") == 0){

			fputs("010100", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else if(strcmp(str, "bgez\n") == 0){

			fputs("000001", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00001", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else if(strcmp(str, "bgtz\n") == 0){

			fputs("000111", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else if(strcmp(str, "blez\n") == 0){

			fputs("000110", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else if(strcmp(str, "bltz\n") == 0){

			fputs("000001", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else if(strcmp(str, "bne\n") == 0){

			fputs("000101", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else if(strcmp(str, "div\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("0000000000", bin);
			fputs("011010", bin);

		}

		else if(strcmp(str, "j\n") == 0){

			fputs("000010", bin);
			fputs("0000000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else if(strcmp(str, "jr\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("000000000000000", bin);
			fputs("001000", bin);

		}

		else if(strcmp(str, "lui\n") == 0){

			fputs("001111", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else if(strcmp(str, "madd\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("0000000000000000", bin);

		}

		else if(strcmp(str, "mfhi\n") == 0){

			fputs("000000", bin);
			fputs("0000000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("010000", bin);

		}

		else if(strcmp(str, "mflo\n") == 0){

			fputs("000000", bin);
			fputs("0000000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("010010", bin);

		}

		else if(strcmp(str, "movn\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("001011", bin);

		}

		else if(strcmp(str, "movz\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("001010", bin);

		}

		else if(strcmp(str, "$msub\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("0000000000", bin);
			fputs("000100", bin);

		}

		else if(strcmp(str, "mthi\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("000000000000000", bin);
			fputs("010001", bin);

		}

		else if(strcmp(str, "mtlo\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("000000000000000", bin);
			fputs("010011", bin);

		}

		else if(strcmp(str, "mul\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("000010", bin);

		}

		else if(strcmp(str, "mult\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("0000000000", bin);
			fputs("011000", bin);

		}

		else if(strcmp(str, "nor\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("100111", bin);

		}

		else if(strcmp(str, "or\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("100101", bin);

		}

		else if(strcmp(str, "ori\n") == 0){

			fputs("001101", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else if(strcmp(str, "sub\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("011101", bin);

		}

		else if(strcmp(str, "xor\n") == 0){

			fputs("000000", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			fputs("00000", bin);
			fputs("100110", bin);

		}

		else if(strcmp(str, "xori\n") == 0){

			fputs("001110", bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(getRegistrador(str), bin);
			if(fgets(str, 7, arq) != NULL)
				fputs(intToBin(str, imediato), bin);

		}

		else
			printf("\nInstrução não encontrada, ou label encontrado");
		
		i++;

    }

    fclose(arq);
    fclose(bin);

}

void arquivoHex(){

    FILE* bin = fopen("binario.txt", "r");
    FILE* hexa = fopen("saida_hex.txt", "w");

    while(!feof(bin)){

        int i, k = 0;
        char hex;
		char sub1[5];
		char sub2[5];
		char sub3[5];
		char sub4[5];
		char sub5[5];
		char sub6[5];
		char sub7[5];
		char sub8[5];

		fgets(sub1, 5, bin);
		hex = tradutorHex(sub1);
		fputc(hex, hexa);
		fgets(sub2, 5, bin);
		hex = tradutorHex(sub2);
		fputc(hex, hexa);
		fgets(sub3, 5, bin);
		hex = tradutorHex(sub3);
		fputc(hex, hexa);
		fgets(sub4, 5, bin);
		hex = tradutorHex(sub4);
		fputc(hex, hexa);
		fgets(sub5, 5, bin);
		hex = tradutorHex(sub5);
		fputc(hex, hexa);
		fgets(sub6, 5, bin);
		hex = tradutorHex(sub6);
		fputc(hex, hexa);
		fgets(sub7, 5, bin);
		hex = tradutorHex(sub7);
		fputc(hex, hexa);
		fgets(sub8, 5, bin);
		hex = tradutorHex(sub8);
		fputc(hex, hexa);

		char pula_linha[3];
		fgets(pula_linha, 3, bin);

        fputs("\n", hexa);

    }

    fclose(hexa);
    fclose(bin);

}

char* intToBin(char* decimal, char* binario){

	char imediato[17];

	if(isdigit(decimal[0])){

		//traduzir decimal para binário
		int aux, primeiro = 0;
		int num = atoi(decimal);

		if(num < 0){
			imediato[0] = 1;
			primeiro++;
		}
		
		for(aux = 15; aux >= primeiro; aux--){

			if(num % 2 == 0)
				imediato[aux] = '0';

			else
				imediato[aux] = '1';

			num = num / 2;

		}

    }
	strcpy(binario, imediato);
	return binario;

}

char tradutorHex(char* substr){

    if(strcmp(substr, "0000") == 0)
        return '0';

    else if(strcmp(substr, "0001") == 0)
        return '1';

    else if(strcmp(substr, "0010") == 0)
        return '2';

    else if(strcmp(substr, "0011") == 0)
        return '3';

    else if(strcmp(substr, "0100") == 0)
        return '4';

    else if(strcmp(substr, "0101") == 0)
        return '5';

    else if(strcmp(substr, "0110") == 0)
        return '6';

    else if(strcmp(substr, "0111") == 0)
        return '7';

    else if(strcmp(substr, "1000") == 0)
        return '8';

    else if(strcmp(substr, "1001") == 0)
        return '9';

    else if(strcmp(substr, "1010") == 0)
        return 'A';

    else if(strcmp(substr, "1011") == 0)
        return 'B';

    else if(strcmp(substr, "1100") == 0)
        return 'C';

    else if(strcmp(substr, "1101") == 0)
        return 'D';

    else if(strcmp(substr, "1110") == 0)
        return 'E';

    else if(strcmp(substr, "1111") == 0)
        return 'F';

	else
		printf("\nProblema com Opcode!");

}

char* getRegistrador(char* str){

    if(strcmp(str, "$zero\n") == 0)
        return "00000";
            
    else if(strcmp(str, "$at\n") == 0)
        return "00001";

    else if(strcmp(str, "$v0\n") == 0)
        return "00010";

    else if(strcmp(str, "$v1\n") == 0)
        return "00011";

    else if(strcmp(str, "$a0\n") == 0)
        return "00100";

    else if(strcmp(str, "$a1\n") == 0)
        return "00101";

    else if(strcmp(str, "$a2\n") == 0)
        return "00110";

    else if(strcmp(str, "$a3\n") == 0)
        return "00111";

    else if(strcmp(str, "$t0\n") == 0)
        return "01000";

    else if(strcmp(str, "$t1\n") == 0)
        return "01001";

    else if(strcmp(str, "$t2\n") == 0)
        return "01010";

    else if(strcmp(str, "$t3\n") == 0)
        return "01011";

    else if(strcmp(str, "$t4\n") == 0)
        return "01100";

    else if(strcmp(str, "$t5\n") == 0)
        return "01101";

    else if(strcmp(str, "$t6\n") == 0)
        return "01110";

    else if(strcmp(str, "$t7\n") == 0)
        return "01111";

    else if(strcmp(str, "$s0\n") == 0)
        return "10000";

    else if(strcmp(str, "$s1\n") == 0)
        return "10001";

    else if(strcmp(str, "$s2\n") == 0)
        return "10010";

    else if(strcmp(str, "$s3\n") == 0)
        return "10011";

    else if(strcmp(str, "$s4\n") == 0)
        return "10100";

    else if(strcmp(str, "$s5\n") == 0)
        return "10101";

    else if(strcmp(str, "$s6\n") == 0)
        return "10110";

    else if(strcmp(str, "$s7\n") == 0)
        return "10111";

    else if(strcmp(str, "$t8\n") == 0)
        return "11000";

    else if(strcmp(str, "$t9\n") == 0)
        return "11001";

    else if(strcmp(str, "$k0\n") == 0)
        return "11010";

    else if(strcmp(str, "$k1\n") == 0)
        return "11011";

    else if(strcmp(str, "$gp\n") == 0)
        return "11100";

    else if(strcmp(str, "$sp\n") == 0)
        return "11101";

    else if(strcmp(str, "$fp\n") == 0)
        return "11110";

    else if(strcmp(str, "$ra\n") == 0)
        return "11111";

    else
        printf("\nRegistrador não encontrado!");

}