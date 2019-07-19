#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/instrucoes.h"
#include "includes/registradores.h"


//Acredito que com certeza não serão do tipo void mas isso vamos ver ainda, por enquanto meti um void


/*
* @function int add(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a soma entre os valores contidos em dois registradores de origem e a insere em um registrador de destino.
*/
int add(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 + regOrigem2;
    return regDestino;
}
/*
* @function void addi(int regDestino,int regOrigem1, int imediato)
* @abstract Faz a operação de soma entre os valores contidos em um registrador de origem e um imediato
*  e a insere em um registrador de destino.
*/
void addi(int regDestino,int regOrigem1, int imediato){
    regDestino = regOrigem1 + imediato;
}
/*
* @function int And(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a operação lógica AND entre os valores contidos em dois registradores de origem e a insere em um registrador de destino.
*/
int And(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 & regOrigem2;
    return regDestino;
}
/*
* @function void andi(int regDestino,int regOrigem1, int imediato)
* @abstract Faz a operação lógica AND entre os valores contidos em um registrador de origem e um imediato
*  e a insere em um registrador de destino.
*/
void andi(int regDestino,int regOrigem1, int imediato){
    regDestino = regOrigem1 & imediato;
}
/* 
* @function b(int PC, int offset)
* @abstract Realiza o desvio incondicional incrementando o registrador especial PC com o valor de um offset.
*/
void b(int PC, int offset){
    PC += offset;
}
/* 
* @function beq(int regOrigem1,int regOrigem2, int offset)
* @abstract Realiza o desvio, incrementando o registrador especial PC em um valor de offset,
* desde que os dois registradores de origem sejam iguais.
*/
void beq(int regOrigem1,int regOrigem2,int PC, int offset){
    if(regOrigem1 == regOrigem2){
        PC += offset;
    }
}
/* 
* @function beql(int regOrigem1,int regOrigem2,int PC, int offset)
* @abstract Realiza o desvio se os valores dos registradores de origem forem iguais e caso contrário a próxima instrução é ignorada.
*/
void beql(int regOrigem1,int regOrigem2,int PC, int offset){
    if(regOrigem1 == regOrigem2){
        PC += offset;
    }
    else
        PC += 8;    //avançando 4 posições na memória -> pŕoxima instrução
                  //avançando mais 4 posições -> ignora a próxima instrução
}
/* 
* @function bgez(int regOrigem1, int PC, int offset)
* @abstract Realiza o desvio incrementando o registrador especial PC com um offset desde que o valor 
* armazenado no registrador de origem seja maior ou igual a 0.
*/
void bgez(int regOrigem1, int PC, int offset){
    if(regOrigem1 >= 0){
        PC += offset;
    }
}
/* 
* @function bgtz(int regOrigem1, int PC, int offset)
* @abstract  Realiza o desvio incrementando o registrador especial PC com um offset desde que o valor armazenado no
* registrador de origem seja maior que 0.
*/
void bgtz(int regOrigem1, int PC, int offset){
    if(regOrigem1 > 0){
        PC += offset;
    }
}
/* 
* @function blez(int regOrigem1, int PC, int offset)
* @abstract  Realiza o desvio incrementando o registrador especial PC com um offset desde que o valor 
* armazenado no registrador de origem seja menor ou igual a 0 .
*/
void blez(int regOrigem1, int PC, int offset){
    if(regOrigem1 <= 0){
        PC += offset;
    }
}
/* 
* @function bltz(int regOrigem1, int PC, int offset)
* @abstract Realiza o desvio incrementando o registrador especial PC com um offset desde que o valor armazenado no
* registrador de origem seja menor que 0.
*/
void bltz(int regOrigem1, int PC, int offset){
    if(regOrigem1 < 0){
        PC += offset;
    }
}
/* 
* @function bne(int regOrigem1,int regOrigem2,int PC, int offset)
* @abstract Realiza o desvio, incrementando o registrador especial PC em um valor de offset,
* desde que os dois registradores de origem sejam diferentes.
*/
void bne(int regOrigem1,int regOrigem2,int PC, int offset){
    if(regOrigem1 != regOrigem2){
        PC += offset;
    }
}
/* 
* @function div(int regOrigem1, int regOrigem2, int HI, int LO)
* @abstract REALIZA A OPERAÇÃO DE DIVISÃO 
* RESULTADO (QUOCIENTE) ARMAZENADO NO REGISTRADOR LO
* RESTO (MOD) ARMAZENADO NO REGISTRADOR HI
*/
void Div(int regOrigem1, int regOrigem2, int &HI, int &LO){
    *LO = regOrigem1 / regOrigem2;
    *HI = regOrigem1 % regOrigem2;
}
/* 
* @function
* @abstract Realiza o salto incondicional.
* Altera o program counter (PC) 
* Acumulando com o endereco desejado para a próxima instrução.
*/
void j(int PC, int offset){
    PC += offset;
}
/* 
* @function
* @abstract Realiza um salto para o endereco contido no registrador especificado
*/
void jr(int PC, int regOrigem1){
    PC += regOrigem1;
}
/* 
* @function
* @abstract Executa um shift em 16 bits no imediato e concatena com outros 16 bits de zero.
*/
void lui(int regDestino, int imediato){
    regDestino = imediato << 16;
    
}
/* 
* @function madd(int regOrigem1, int regOrigem2, int regAcumulador)
* @abstract Adiciona a multiplicação entre os valores de dois registradores de origem a um registrador acumulador.
*/
int madd(int regOrigem1, int regOrigem2, int regAcumulador){
    regAcumulador += regOrigem1 * regOrigem2;
}
/*
* @function mfhi(int HI, int regOrigem1)
* @abstract Move o conteúdo do registrador especial HI para o registrador de origem .  
*/
void mfhi(int HI, int regOrigem1){
    regOrigem1 = HI;
}
/*
* @function mflo(int LO, int regOrigem1)
* @abstract Move o conteúdo do registrador especial LO para o registrador de origem. 
*/
void mflo(int LO, int regOrigem1){
    
    regOrigem1 = LO;
}
/*
* @function void movn(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Movimenta o conteúdo do primeiro registrador de origem para o registrador de destino se o segundo
* registrador de origem for diferente de 0.
*/
void movn(int regDestino,int regOrigem1, int regOrigem2){
    if(regOrigem2 != 0){
        regDestino = regOrigem1;
    }
}

/*
* @function void movz(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Movimenta o conteúdo do primeiro registrador de origem para o registrador de destino se o segundo
* registrador de origem for igual a 0.
*/
void movz(int regDestino,int regOrigem1, int regOrigem2){
    if(regOrigem2 == 0){
        regDestino = regOrigem1;
    }
}
/* 
* @function msub(int regOrigem1, int regOrigem2, int regAcumulador)
* @abstract Subtrai a multiplicação entre os valores de dois registradores de origem a um registrador acumulador.
*/
int msub(int regOrigem1, int regOrigem2, int regAcumulador){
    regAcumulador -= regOrigem1 * regOrigem2;
}
/*
* @function mthi(int regOrigem1, int HI)
* @abstract Move o conteúdo do registrador de origem para o registrador especial HI. 
*/
void mthi(int regOrigem1, int HI){
    HI = regOrigem1;
}
/*
* @function mtlo(int regOrigem1, int LO)
* @abstract Move o conteúdo do registrador de origem para o registrador especial LO .
*/
void mtlo(int regOrigem1, int LO){
    LO = regOrigem1;
}
/*
* @function void mul(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a multiplicação entre os valores contidos em dois registradores de origem e a insere em um registrador de destino.
*/
int mul(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 * regOrigem2;
}
/* 
* @function mult(int regOrigem1, int regOrigem2, int regAcumulador)
* @abstract Armazena a multiplicação entre os valores de dois registradores de origem a um registrador acumulador.
*/
int mult(int regOrigem1, int regOrigem2, int regAcumulador){
    regAcumulador = regOrigem1 * regOrigem2;
}
/* 
* @function void nop()
* @abstract Apenas retorna uma mensagem dizendo que não há nenhuma operação a ser executada.
*/
void nop(){
    printf("Sem operação");
}
/*
* @function void nor(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a operação lógica NOR entre os valores contidos em dois registradores de origem e a insere em um registrador de destino.
*/
void nor(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = ~(regOrigem1 | regOrigem2);
}
/*
* @function int Or(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a operação lógica OR entre os valores contidos em dois registradores de origem e a insere em um registrador de destino.
*/
int Or(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = (regOrigem1 | regOrigem2);
    return regDestino;
}
/*
* @function void Ori(int regDestino,int regOrigem1, int imediato)
* @abstract Faz a operação lógica OR entre os valores contidos em um registrador de origem e um imediato
*  e a insere em um registrador de destino.
*/
void Ori(int regDestino,int regOrigem1, int imediato){
    regDestino = (regOrigem1 | imediato);
}
/*
* @function int sub(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a subtração entre os valores contidos em dois registradores de origem e a insere em um registrador de destino.
*/
int sub(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 - regOrigem2;
    return regDestino;
}

/*
* @function int Xor(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a operação lógica XOR entre os valores contidos em dois registradores de origem e a insere em um registrador de destino.
*/
int Xor(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 ^ regOrigem2;
    return regDestino;
}
/*
* @function void Xori(int regDestino,int regOrigem1, int imediato)
* @abstract Faz a operação lógica XOR entre os valores contidos em um registrador de origem e um imediato
*  e a insere em um registrador de destino.
*/
void Xori(int regDestino,int regOrigem1, int imediato){
    regDestino = regOrigem1 ^ imediato;
}
