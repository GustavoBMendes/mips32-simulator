#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/instrucoes.h"

//Falta definir os registradores que iriam entrar nas operações porém os desconheço
//Acredito que com certeza não serão do tipo void mas isso vamos ver ainda, por enquanto meti um void

void add(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 + regOrigem2;
}

void addi(){

}

void And(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 & regOrigem2;
}

void andi(){

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

void div(){
    //não entendi essa parada de Lo e Hi
}

void j(){

}

void jr(){

}

void lui(){

}

void madd(){

}

void mfhi(){

}

void mflo(){

}

void movn(int regDestino,int regOrigem1, int regOrigem2){
    if(regOrigem2 != 0){
        regDestino = regOrigem1;
    }
}

void movz(int regDestino,int regOrigem1, int regOrigem2){
    if(regOrigem2 == 0){
        regDestino = regOrigem1;
    }
}

void msub(){

}

void mthi(){

}

void mtlo(){

}

void mul(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 * regOrigem2;
}

void mult(){

}

void nop(){

}

void nor(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = ~(regOrigem1 | regOrigem2);
}

void Or(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = (regOrigem1 | regOrigem2);
}

void ori(){

}

void sub(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 - regOrigem2;
}

void Xor(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 ^ regOrigem2;
}

void xori(){

}

//funções sem comentários significa "sim"


//na verdade significa "sim eu não sei como implementar ainda"