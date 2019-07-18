/*!
 * @header operationsUnit.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO SERÃO EXECUTADAS AS DEMAIS INSTRUÇÕES
 * ESTAS EXCEDEM AS UNIDADES DE EXECUÇÃO ULA E MDU
 * SÃO INSTRUÇÕES DE SALTO, MOVE E COMPARAÇÃO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/instrucoes.h"
#include "includes/operationsUnit.h"
#include "includes/registradores.h"

opu *opu_executavel;

/* 
* @function void OPUb(int offset)
* @abstract Executa a instrução b através da chamada da função b(int PC, int offset) no módulo "instrucoes".
*/
void OPUb(int offset){

    b(PC, offset);
}

/* 
* @function void OPUbeq(int offset)
* @abstract Executa a instrução beq através da chamada da função beq(int regOrigem1, int regOrigem2, int PC, int offset) no módulo "instrucoes".
*/
void OPUbeq(int offset){
    beq(opu_executavel->operando1, opu_executavel->operando2, PC, offset);
}

/* 
* @function void OPUbeql(int offset)
* @abstract Executa a instrução beql através da chamada da função beql(int regOrigem1, int regOrigem2, int PC, int offset) no módulo "instrucoes".
*/
void OPUbeql(int offset){
    beql(opu_executavel->operando1, opu_executavel->operando2, PC, offset);
}

/* 
* @function void OPUbgez(int offset)
* @abstract Executa a instrução bgez através da chamada da função bgez(int regOrigem1, int PC, int offset) no módulo "instrucoes".
*/
void OPUbgez(int offset){
    bgez(opu_executavel->operando1, PC, offset);
}

/* 
* @function void OPUbgtz(int regOrigem1, int PC, int offset)
* @abstract Executa a instrução bgtz através da chamada da função bgtz(int regOrigem1, int PC, int offset) no módulo "instrucoes".
*/
void OPUbgtz(int offset){
    bgtz(opu_executavel->operando1, PC, offset);
}

/* 
* @function void OPUblez(int offset)
* @abstract Executa a instrução blez através da chamada da função blez(int regOrigem1, int PC, int offset) no módulo "instrucoes".
*/
void OPUblez(int offset){
    blez(opu_executavel->operando1, PC, offset);
}

/* 
* @function void OPUbltz(int offset)
* @abstract Executa a instrução bltz através da chamada da função bltz(int regOrigem1, int PC, int offset) no módulo "instrucoes".
*/
void OPUbltz(int regOrigem1, int PC, int offset){
    bltz(opu_executavel->operando1, PC, offset);
}

/* 
* @function void OPUbne(int offset)
* @abstract Executa a instrução bne através da chamada da função bne(int regOrigem1,int regOrigem2,int PC, int offset) no módulo "instrucoes".
*/
void OPUbne(int regOrigem1,int regOrigem2,int PC, int offset){
    bne(opu_executavel->operando1, opu_executavel->operando2, PC, offset);
}

/* 
* @function void OPUj(int offset)
* @abstract Executa a instrução j através da chamada da função j(int PC, int offset) no módulo "instrucoes".
*/
void OPUj(int offset){
    j(PC, offset);
}

/* 
* @function void OPUjr()
* @abstract Executa a instrução jr através da chamada da função jr(int PC, int regOrigem1) no módulo "instrucoes".
*/
void OPUjr(){
    jr(PC, opu_executavel->operando1);
}

/* 
* @function void OPUlui(int imediato)
* @abstract Executa a instrução lui através da chamada da função lui(int regDestino, int imediato) no módulo "instrucoes".
*/
void OPUlui(int imediato){
    lui(opu_executavel->saida_opu, imediato);
}

/* 
* @function void OPUmovn()
* @abstract Executa a instrução movn através da chamada da função movn(int regDestino,int regOrigem1, int regOrigem2) no módulo "instrucoes".
*/
void OPUmovn(){
    movn(opu_executavel->saida_opu, opu_executavel->operando1, opu_executavel->operando2);
}

/* 
* @function void OPUmovz()
* @abstract Executa a instrução movz através da chamada da função movz(int regDestino,int regOrigem1, int regOrigem2) no módulo "instrucoes".
*/
void OPUmovz(){
    movz(opu_executavel->saida_opu, opu_executavel->operando1, opu_executavel->operando2);
}
