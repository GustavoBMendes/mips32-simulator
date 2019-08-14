/*!
 * @header mdu.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO A MDU
 * RESPONSÁVEL PELAS OPERAÇÕES DE MULTIPLICAÇÃO E DIVISÃO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/instrucoes.h"
#include "includes/mdu.h"
#include "includes/registradores.h"


unsigned int operando1;
unsigned int operando2;
unsigned int saida_mdu;
unsigned int HI, LO, PC;

/* 
* @function void mduDiv(mdu *mdu_executavel)
* @abstract Executa a operação DIV através da chamada da função div() no módulo "instruções".
*/
int mduDivHI(int regOrigem1, int regOrigem2, int HI, int LO){
    int res = DivHI(regOrigem1,regOrigem2,HI,LO);
    return res;
}
/* 
* @function void mduDiv(mdu *mdu_executavel)
* @abstract Executa a operação DIV através da chamada da função div() no módulo "instruções".
*/
int mduDivLO(int regOrigem1, int regOrigem2,int HI, int LO){
    int res = DivLO(regOrigem1,regOrigem2,HI,LO);
    return res;
}
/* 
* @function void mduMul(mdu *mdu_executavel)
* @abstract Executa a operação MUL através da chamada da função mul() no módulo "instruções".
*/
int mduMul(int regOrigem1, int regOrigem2){
    //mul(mdu_executavel->saida_mdu,mdu_executavel->operando1,mdu_executavel->operando2);
    operando1 = regOrigem1;
    operando2 = regOrigem2;
    saida_mdu = mul(saida_mdu, operando1, operando2);
    return saida_mdu;
}
/* 
* @function int mduMult(mdu *mdu_executavel)
* @abstract Executa a operação MULT através da chamada da função mult() no módulo "instruções".
*/
int mduMult(int regOrigem1, int regOrigem2){
    //mult(mdu_executavel->operando1,mdu_executavel->operando2,mdu_executavel->saida_mdu);
    operando1 = regOrigem1;
    operando2 = regOrigem2;
    saida_mdu = mult(operando1, operando2, saida_mdu);
    return saida_mdu;
}

/* 
* @function int mduMadd()
* @abstract Executa a operação MADD através da chamada da função madd() no módulo "instruções".
*/
int mduMadd(int regOrigem1, int regOrigem2){
    operando1 = regOrigem1;
    operando2 = regOrigem2;
    saida_mdu = madd(operando1, operando2, saida_mdu);
    return saida_mdu;
}
/* 
* @function void mduMfhi()
* @abstract Executa a operação MFHI através da chamada da função mfhi() no módulo "instruções".
*/
int mduMfhi(int HI, int regOrigem1){
    operando1 = regOrigem1;
    saida_mdu = mfhi(HI,operando1);
    return saida_mdu;
}
/* 
* @function void mduMflo()
* @abstract Executa a operação MFLO através da chamada da função mflo() no módulo "instruções".
*/
int mduMflo(int LO, int regOrigem1){
    operando1 = regOrigem1;
    saida_mdu = mflo(LO,operando1);
    return saida_mdu;
}
/* 
* @function int mduMsub()
* @abstract Executa a operação MSUB através da chamada da função msub() no módulo "instruções".
*/
int mduMsub(int regOrigem1, int regOrigem2){
    operando1 = regOrigem1;
    operando2 = regOrigem2;
    saida_mdu = msub(operando1, operando2, saida_mdu);
    return saida_mdu;
}
/* 
* @function void mduMthi()
* @abstract Executa a operação MTHI através da chamada da função mthi() no módulo "instruções".
*/
int mduMthi(int regOrigem1, int HI){
    operando1 = regOrigem1;
    saida_mdu = mthi(operando1,HI);
    return saida_mdu;
}
/* 
* @function void mduMtlo()
* @abstract Executa a operação MTLO através da chamada da função mtlo() no módulo "instruções".
*/
int mduMtlo(int regOrigem1, int LO){
     operando1 = regOrigem1;
    saida_mdu = mthi(operando1,LO);
    return saida_mdu;
}

