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

void ulaAdd(ula *ula_executavel){
    ula_executavel->saida_ula = ula_executavel->operando1 + ula_executavel->operando2;
}

void ulaSub(ula *ula_executavel){
    ula_executavel->saida_ula = ula_executavel->operando1 - ula_executavel->operando2;
}

void ulaAnd(ula *ula_executavel){
    ula_executavel->saida_ula = ula_executavel->operando1 & ula_executavel->operando2;
}

void ulaOr(ula *ula_executavel){
    ula_executavel->saida_ula = ula_executavel->operando1 | ula_executavel->operando2;
}

void ulaXor(ula *ula_executavel){
    ula_executavel->saida_ula = ula_executavel->operando1 ^ ula_executavel->operando2;
}

void ulaNot(ula *ula_executavel){
    ula_executavel->saida_ula = ~(ula_executavel->operando1);
}

void ulaLeftShift(ula *ula_executavel){
    ula_executavel->saida_ula = ula_executavel->operando1 << ula_executavel->operando2;
}

void ulaRightShift(ula *ula_executavel){
    ula_executavel->saida_ula = ula_executavel->operando1 >> ula_executavel->operando2;
}

/*

 DIV E MULT FICARÃO EM OUTRA UNIDADE DE EXECUÇÃO
 
void ulaDiv(){

}

void ulaMult(){

}

*/