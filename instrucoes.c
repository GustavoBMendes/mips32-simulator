#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/instrucoes.h"
#include "includes/registradores.h"


//Acredito que com certeza não serão do tipo void mas isso vamos ver ainda, por enquanto meti um void


/*
* @function void add(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a soma entre os valores contidos em dois registradores de origem e a insere em um registrador de destino
*/
void add(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 + regOrigem2;
}
/*
* @function void addi(int regDestino,int regOrigem1, int imediato)
* @abstract Faz a operação de soma entre os valores contidos em um registrador de origem e um imediato
*  e a insere em um registrador de destino
*/
void addi(int regDestino,int regOrigem1, int imediato){
    regDestino = regOrigem1 + imediato;
}
/*
* @function void And(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a operação lógica AND entre os valores contidos em dois registradores de origem e a insere em um registrador de destino
*/
void And(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 & regOrigem2;
}
/*
* @function void andi(int regDestino,int regOrigem1, int imediato)
* @abstract Faz a operação lógica AND entre os valores contidos em um registrador de origem e um imediato
*  e a insere em um registrador de destino
*/
void andi(int regDestino,int regOrigem1, int imediato){
    regDestino = regOrigem1 & imediato;
}

void b(){

}

void beq(){

}

void beql(){

}

void bgez(){

}

void bgtz(){

}

void blez(){

}

void bltz(){

}

void bne(){

}
//não sei oq comentar nessa mas a documentação mandou fazer isso
void div(int regOrigem1, int regOrigem2, int HI, int LO){
    LO = regOrigem1 / regOrigem2;
    HI = regOrigem1 % regOrigem2;
}

void j(){

}

void jr(){

}

void lui(int regDestino, int imediato){
    regDestino = imediato << 16;
    
}
/* 
* @function madd(int regOrigem1, int regOrigem2, int regAcumulador)
* @abstract Adiciona a multiplicação entre os valores de dois registradores de origem a um registrador acumulador
*/
void madd(int regOrigem1, int regOrigem2, int regAcumulador){
    regAcumulador += regOrigem1 * regOrigem2;
}
/*
* @function mfhi(int HI, int regOrigem1)
* @abstract Move o conteúdo do registrador especial HI para o registrador de origem   
*/
void mfhi(int regOrigem1, int HI){
    regOrigem1 = HI;
}
/*
* @function mflo(int LO, int regOrigem1)
* @abstract Move o conteúdo do registrador especial LO para o registrador de origem   
*/
void mflo(int regOrigem1, int LO){
    
    regOrigem1 = LO;
}
/*
* @function void movn(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Movimenta o conteúdo do primeiro registrador de origem para o registrador de destino se o segundo
* registrador de origem for diferente de 0
*/
void movn(int regDestino,int regOrigem1, int regOrigem2){
    if(regOrigem2 != 0){
        regDestino = regOrigem1;
    }
}

/*
* @function void movz(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Movimenta o conteúdo do primeiro registrador de origem para o registrador de destino se o segundo
* registrador de origem for igual a 0
*/
void movz(int regDestino,int regOrigem1, int regOrigem2){
    if(regOrigem2 == 0){
        regDestino = regOrigem1;
    }
}
/* 
* @function msub(int regOrigem1, int regOrigem2, int regAcumulador)
* @abstract Subtrai a multiplicação entre os valores de dois registradores de origem a um registrador acumulador
*/
void msub(int regOrigem1, int regOrigem2, int regAcumulador){
    regAcumulador -= regOrigem1 * regOrigem2;
}
/*
* @function mthi(int regOrigem1, int HI)
* @abstract Move o conteúdo do registrador de origem para o registrador especial HI 
*/
void mthi(int regOrigem1, int HI){
    HI = regOrigem1;
}
/*
* @function mtlo(int regOrigem1, int HI)
* @abstract Move o conteúdo do registrador de origem para o registrador especial LO 
*/
void mtlo(int regOrigem1, int LO){
    LO = regOrigem1;
}
/*
* @function void mul(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a multiplicação entre os valores contidos em dois registradores de origem e a insere em um registrador de destino
*/
void mul(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 * regOrigem2;
}
/* 
* @function mult(int regOrigem1, int regOrigem2, int regAcumulador)
* @abstract Armazena a multiplicação entre os valores de dois registradores de origem a um registrador acumulador
*/
void mult(int regOrigem1, int regOrigem2, int regAcumulador){
    regAcumulador = regOrigem1 * regOrigem2;
}
/* 
* @function void nop()
* @abstract Apenas retorna uma mensagem dizendo que não há nenhuma operação a ser executada
*/
void nop(){
    printf("Sem operação");
}
/*
* @function void nor(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a operação lógica NOR entre os valores contidos em dois registradores de origem e a insere em um registrador de destino
*/
void nor(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = ~(regOrigem1 | regOrigem2);
}
/*
* @function void Or(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a operação lógica OR entre os valores contidos em dois registradores de origem e a insere em um registrador de destino
*/
void Or(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = (regOrigem1 | regOrigem2);
}
/*
* @function void ori(int regDestino,int regOrigem1, int imediato)
* @abstract Faz a operação lógica OR entre os valores contidos em um registrador de origem e um imediato
*  e a insere em um registrador de destino
*/
void ori(int regDestino,int regOrigem1, int imediato){
    regDestino = (regOrigem1 | imediato);
}
/*
* @function void sub(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a subtração entre os valores contidos em dois registradores de origem e a insere em um registrador de destino
*/
void sub(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 - regOrigem2;
}

/*
* @function void Xor(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a operação lógica XOR entre os valores contidos em dois registradores de origem e a insere em um registrador de destino
*/
void Xor(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 ^ regOrigem2;
}
/*
* @function void xori(int regDestino,int regOrigem1, int imediato)
* @abstract Faz a operação lógica XOR entre os valores contidos em um registrador de origem e um imediato
*  e a insere em um registrador de destino
*/
void xori(int regDestino,int regOrigem1, int imediato){
    regDestino = regOrigem1 ^ imediato;
}
