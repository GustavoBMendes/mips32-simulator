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

unsigned int operando1;
unsigned int operando2;
unsigned int saida_ula;

/*
 * @function int ulaAdd(int regOrigem1, int regOrigem2)
 * @abstract Executa a operação ADD 
 * Chamada da função add() no módulo "instruções"
 * Retornando um valor inteiro no componente de saida da ula
 */
int ulaAdd(int regOrigem1, int regOrigem2){
    operando1 = regOrigem1;
    operando2 = regOrigem2;
    saida_ula = add(saida_ula, operando1, operando2);
    return saida_ula;
}


int ulaAddi(int regOrigem1, int imediato){
    operando1 = regOrigem1;
    operando2 = imediato;
    saida_ula = addi(saida_ula, operando1, operando2);
    return saida_ula;
}


/*
 * @function int ulaAnd(int regOrigem1, int regOrigem2)
 * @abstract Executa a operação AND 
 * Chamada da função And() no módulo "instruções"
 * Retornando um valor inteiro no componente de saida da ula
 */
int ulaAnd(int regOrigem1, int regOrigem2){
    operando1 = regOrigem1;
    operando2 = regOrigem2;
    saida_ula = And(saida_ula, operando1, operando2);
    return saida_ula;
}

/*
 * @function int ulaSub(int regOrigem1, int regOrigem2)
 * @abstract Executa a operação SUB
 * Chamada da função sub() no módulo "instruções"
 * Retornando um valor inteiro no componente de saida da ula
 */
int ulaSub(int regOrigem1, int regOrigem2){
    saida_ula = sub(saida_ula, operando1, operando2);
    return saida_ula;
}

/*
 * @function void ulaOr(int regDestino,int regOrigem1, int regOrigem2)
 * @abstract Executa a operação OR
 * Chamada da função Or() no módulo "instruções"
 * Retornando um valor inteiro no componente de saida da ula
 */
int ulaOr(int regOrigem1, int regOrigem2){
    operando1 = regOrigem1;
    operando2 = regOrigem2;
    saida_ula = Or(saida_ula, operando1, operando2);
}

/*
 * @function void ulaXor(int regDestino,int regOrigem1, int regOrigem2)
 * @abstract Executa a operação XOR 
 * Chamada da função Xor() no módulo "instruções"
 * Retornando um valor inteiro no componente de saida da ula
 */
int ulaXor(int regOrigem1, int regOrigem2){
    operando1 = regOrigem1;
    operando2 = regOrigem2;
    saida_ula = Xor(saida_ula, operando1, operando2);
}
