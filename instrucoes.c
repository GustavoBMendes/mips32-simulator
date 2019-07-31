/*!
 * @header instrucoes.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO 
 * TODAS AS INSTRUÇÕES REQUISITADAS PARA ESTE PROCESSADOR
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/instrucoes.h"
#include "includes/registradores.h"

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
int addi(int regDestino,int regOrigem1, int imediato){
    regDestino = regOrigem1 + imediato;
    return regDestino;
}
/*
* @function int And(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a operação lógica AND entre os valores contidos em dois registradores de origem e a insere em um registrador de destino.
*/
unsigned int And(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 & regOrigem2;
    return regDestino;
}
/*
* @function void andi(int regDestino,int regOrigem1, int imediato)
* @abstract Faz a operação lógica AND entre os valores contidos em um registrador de origem e um imediato
*  e a insere em um registrador de destino.
*/
unsigned int andi(int regDestino,int regOrigem1, int imediato){
    regDestino = regOrigem1 & imediato;
    return regDestino;
}
/* 
* @function b(int PC, int offset)
* @abstract Realiza o desvio incondicional incrementando o registrador especial PC com o valor de um offset.
*/
int b(int PC, int offset){
    PC += offset;
    return PC;
}
/* 
* @function beq(int regOrigem1,int regOrigem2, int offset)
* @abstract Realiza o desvio, incrementando o registrador especial PC em um valor de offset,
* desde que os dois registradores de origem sejam iguais.
*/
int beq(int regOrigem1,int regOrigem2,int PC, int offset){
    if(regOrigem1 == regOrigem2){
        PC += offset;
    }
    return PC;
}
/* 
* @function beql(int regOrigem1,int regOrigem2,int PC, int offset)
* @abstract Realiza o desvio se os valores dos registradores de origem forem iguais e caso contrário a próxima instrução é ignorada.
*/
int beql(int regOrigem1,int regOrigem2,int PC, int offset){
    if(regOrigem1 == regOrigem2){
        PC += offset;
    }
    else
        PC += 8;    //avançando 4 posições na memória -> pŕoxima instrução
                  //avançando mais 4 posições -> ignora a próxima instrução

    return PC;
}
/* 
* @function bgez(int regOrigem1, int PC, int offset)
* @abstract Realiza o desvio incrementando o registrador especial PC com um offset desde que o valor 
* armazenado no registrador de origem seja maior ou igual a 0.
*/
int bgez(int regOrigem1, int PC, int offset){
    if(regOrigem1 >= 0){
        PC += offset;
    }

    return PC;
}
/* 
* @function bgtz(int regOrigem1, int PC, int offset)
* @abstract  Realiza o desvio incrementando o registrador especial PC com um offset desde que o valor armazenado no
* registrador de origem seja maior que 0.
*/
int bgtz(int regOrigem1, int PC, int offset){
    if(regOrigem1 > 0){
        PC += offset;
    }

    return PC;

}
/* 
* @function blez(int regOrigem1, int PC, int offset)
* @abstract  Realiza o desvio incrementando o registrador especial PC com um offset desde que o valor 
* armazenado no registrador de origem seja menor ou igual a 0 .
*/
int blez(int regOrigem1, int PC, int offset){
    if(regOrigem1 <= 0){
        PC += offset;
    }

    return PC;

}
/* 
* @function bltz(int regOrigem1, int PC, int offset)
* @abstract Realiza o desvio incrementando o registrador especial PC com um offset desde que o valor armazenado no
* registrador de origem seja menor que 0.
*/
int bltz(int regOrigem1, int PC, int offset){
    if(regOrigem1 < 0){
        PC += offset;
    }

    return PC;

}
/* 
* @function bne(int regOrigem1,int regOrigem2,int PC, int offset)
* @abstract Realiza o desvio, incrementando o registrador especial PC em um valor de offset,
* desde que os dois registradores de origem sejam diferentes.
*/
int bne(int regOrigem1,int regOrigem2,int PC, int offset){
    if(regOrigem1 != regOrigem2){
        PC += offset;
    }

    return PC;
}
/* 
* @function divHI(int regOrigem1, int regOrigem2, int HI, int LO)
* @abstract REALIZA A OPERAÇÃO DE DIVISÃO 
* RESULTADO (QUOCIENTE) ARMAZENADO NO REGISTRADOR LO
* RESTO (MOD) ARMAZENADO NO REGISTRADOR HI
*/
int DivHI(int regOrigem1, int regOrigem2, int HI, int LO){
    LO = regOrigem1 / regOrigem2;
    HI = regOrigem1 % regOrigem2;
    return HI;
}
/* 
* @function DivLO(int regOrigem1, int regOrigem2, int HI, int LO)
* @abstract REALIZA A OPERAÇÃO DE DIVISÃO 
* RESULTADO (QUOCIENTE) ARMAZENADO NO REGISTRADOR LO
* RESTO (MOD) ARMAZENADO NO REGISTRADOR HI
*/
int DivLO(int regOrigem1, int regOrigem2, int HI, int LO){
    LO = regOrigem1 / regOrigem2;
    HI = regOrigem1 % regOrigem2;
    return LO;
}
/* 
* @function
* @abstract Realiza o salto incondicional.
* Altera o program counter (PC) 
* Acumulando com o endereco desejado para a próxima instrução.
*/
int j(int PC, int offset){
    PC += offset;
    return PC;
}
/* 
* @function
* @abstract Realiza um salto para o endereco contido no registrador especificado
*/
int jr(int PC, int regOrigem1){
    PC += regOrigem1;
    return PC;
}
/* 
* @function
* @abstract Executa um shift em 16 bits no imediato e concatena com outros 16 bits de zero.
*/
int lui(int regDestino, int imediato){
    regDestino = imediato << 16;
    return regDestino;
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
int mfhi(int HI, int regOrigem1){
    regOrigem1 = HI;
    return regOrigem1;
}
/*
* @function mflo(int LO, int regOrigem1)
* @abstract Move o conteúdo do registrador especial LO para o registrador de origem. 
*/
int mflo(int LO, int regOrigem1){
    regOrigem1 = LO;
    return regOrigem1;
}
/*
* @function void movn(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Movimenta o conteúdo do primeiro registrador de origem para o registrador de destino se o segundo
* registrador de origem for diferente de 0.
*/
int movn(int regDestino,int regOrigem1, int regOrigem2){
    if(regOrigem2 != 0){
        regDestino = regOrigem1;
    }
    return regDestino;
}

/*
* @function void movz(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Movimenta o conteúdo do primeiro registrador de origem para o registrador de destino se o segundo
* registrador de origem for igual a 0.
*/
int movz(int regDestino,int regOrigem1, int regOrigem2){
    if(regOrigem2 == 0){
        regDestino = regOrigem1;
    }
    return regDestino;
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
int mthi(int regOrigem1, int HI){
    HI = regOrigem1;
    return HI;
}
/*
* @function mtlo(int regOrigem1, int LO)
* @abstract Move o conteúdo do registrador de origem para o registrador especial LO .
*/
int mtlo(int regOrigem1, int LO){
    LO = regOrigem1;
    return LO;
}
/*
* @function void mul(int regDestino,int regOrigem1, int regOrigem2)
* @abstract Faz a multiplicação entre os valores contidos em dois registradores de origem e a insere em um registrador de destino.
*/
int mul(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = regOrigem1 * regOrigem2;
    return regDestino;
}
/* 
* @function mult(int regOrigem1, int regOrigem2, int regAcumulador)
* @abstract Armazena a multiplicação entre os valores de dois registradores de origem a um registrador acumulador.
*/
int mult(int regOrigem1, int regOrigem2, int regAcumulador){
    regAcumulador = regOrigem1 * regOrigem2;
    return regAcumulador;
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
int nor(int regDestino,int regOrigem1, int regOrigem2){
    regDestino = ~(regOrigem1 | regOrigem2);
    return regDestino;
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
int Ori(int regDestino,int regOrigem1, int imediato){
    regDestino = (regOrigem1 | imediato);
    return regDestino;
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
int Xori(int regDestino,int regOrigem1, int imediato){
    regDestino = regOrigem1 ^ imediato;
    return regDestino;
}
