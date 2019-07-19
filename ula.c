/*!
 * @header ula.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO A ULA
 * POSSUI OPERAÇÕES PRIMITIVAS E EXECUTA AS DEMAIS
 */
#include <stdio.h>
#include <stdlib.h>
#include "includes/ula.h"
#include "includes/instrucoes.h"

ula *ula_executavel;
unsigned int operando1;
unsigned int operando2;
unsigned int saida_ula;

/*
* @function void ulaAdd(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Executa a operação ADD através da chamada da função add() no módulo "instruções"
*/
int ulaAdd(int regOrigem1, int regOrigem2){
    operando1 = regOrigem1;
    operando2 = regOrigem2;
    saida_ula = add(saida_ula, operando1, operando2);
    return saida_ula;
}

/*
* @function void ulaAnd(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Executa a operação AND através da chamada da função And() no módulo "instruções"
*/
void ulaAnd(){
    ula_executavel->saida_ula = And(ula_executavel->saida_ula, ula_executavel->operando1, ula_executavel->operando2);
}

/*
* @function void ulaSub(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Executa a operação SUB através da chamada da função sub() no módulo "instruções"
*/
void ulaSub(){
    ula_executavel->saida_ula = sub(ula_executavel->saida_ula, ula_executavel->operando1, ula_executavel->operando2);
}

/*
* @function void ulaOr(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Executa a operação OR através da chamada da função Or() no módulo "instruções"
*/
void ulaOr(){
    ula_executavel->saida_ula = Or(ula_executavel->saida_ula, ula_executavel->operando1, ula_executavel->operando2);
}

/*
* @function void ulaXor(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Executa a operação XOR através da chamada da função Xor() no módulo "instruções"
*/
void ulaXor(){
    ula_executavel->saida_ula = Xor(ula_executavel->saida_ula, ula_executavel->operando1, ula_executavel->operando2);
}
