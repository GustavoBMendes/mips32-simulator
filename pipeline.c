/*!
 * @header pipeline.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO O PIPELINE
 * RESPONSÁVEL PELOS ESTÁGIOS DE:
 * BUSCA(I), EXECUÇÃO(E), BUSCA DA MEMÓRIA(M), ALINHAMENTO(A) E ESCRITA(W)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/pipeline.h"
#include "includes/executionQueue.h"
#include "includes/memoria.h"
#include "includes/memoria.h"

extern unsigned int HI,LO;

/* 
 * @function void Istage()
 * @abstract ESTÁGIO DE BUSCA
 * REALIZA A BUSCA DA INSTRUÇÃO NA FILA
 * REALIZA O CÁLCULA DA POSIÇÃO CORRETA E PERCORRE DESDE O INÍCIO
 * ATÉ ONDE SE ENCONTRA O ÍNDICE CERTO
 */
char* Istage(FILA *execQueue, int PC){

    NO *aux = execQueue->inicio;
    int posicao = PC/4;

    while(posicao > 0){

        aux = aux->prox;
        posicao--;

    }

    char* nomeSaida = (char*) malloc(sizeof(aux->instructionName));
    strcpy(nomeSaida,aux->instructionName);

    return nomeSaida;

}

/* 
 * @function void Estage()
 * @abstract ESTÁGIO DE EXECUÇÃO
 * REALIZA A EXECUÇÃO DE ACORDO COM A INSTRUÇÃO ENCONTRADA EM Istage()
 * BUSCA OS REGISTRADORES, IMEDIATOS OU ENDEREÇOS CONTIDOS NA MESMA 
 * POSIÇÃO DA FILA EM QUE A INSTRUÇÃO FOI BUSCADA
 * REALIZA O CÁLCULA DA POSIÇÃO CORRETA E PERCORRE DESDE O INÍCIO
 * ATÉ ONDE SE ENCONTRA O ÍNDICE CERTO
 */
int Estage(char* instrucao, FILA *exeQueue, int PC, int *reg){

    NO* linha = exeQueue->inicio;
    int posicao = PC/4;
    int iOp2 = 0, iOp3 = 0, iDest = 0;

    while(posicao > 0){

        linha = linha->prox;
        posicao--;

    }

    unsigned int operando1, operando2, operando3, imediato;

    /*
    if(linha->imediato != 0){
        imediato = linha->imediato;
    }

    if(linha->regDestino != NULL){
        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];
    }

    if(linha->reg1 != NULL){
        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];
    }

    if(linha->reg2 != NULL){
        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];
    }
    */

    if(strcmp(instrucao, "add\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        operando1 = add(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "addi\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;

        operando1 = addi(operando1, operando2, imediato);

    }

    else if(strcmp(instrucao, "and\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        operando1 = And(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "andi\n") == 0){
        
        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;

        operando1 = andi(operando1, operando2, imediato);

    }

    else if(strcmp(instrucao, "b\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;

        PC = b(PC, imediato);

        inserirNoBarramento(PC);
        writeInMemory(PC);

        return 32;

    }

    else if(strcmp(instrucao, "beq\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;

        PC = beq(operando1, operando2, PC, imediato);

        inserirNoBarramento(PC);
        writeInMemory(PC);

        return 32;

    }

    else if(strcmp(instrucao, "beql\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;
        
        PC = beql(operando1, operando2, PC, imediato);

        inserirNoBarramento(PC);
        writeInMemory(PC);

        return 32;

    }

    else if(strcmp(instrucao, "bgez\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;
        
        PC = bgez(operando1, PC, imediato);

        inserirNoBarramento(PC);
        writeInMemory(PC);

        return 32;

    }

    else if(strcmp(instrucao, "bgtz\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;
        
        PC = bgtz(operando1, PC, imediato);

        inserirNoBarramento(PC);
        writeInMemory(PC);

        return 32;

    }

    else if(strcmp(instrucao, "blez\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;

        PC = blez(operando1, PC, imediato);

        inserirNoBarramento(PC);
        writeInMemory(PC);

        return 32;

    }

    else if(strcmp(instrucao, "bltz\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;
        
        PC = bltz(operando1, PC, imediato);

        inserirNoBarramento(PC);
        writeInMemory(PC);

        return 32;

    }

    else if(strcmp(instrucao, "bne\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;
        
        PC = bne(operando1, operando2, PC, imediato);

        inserirNoBarramento(PC);
        writeInMemory(PC);

        return 32;

    }

    else if(strcmp(instrucao, "div\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];
        
        HI = DivHI(operando1, operando2, HI, LO);
        LO = DivLO(operando1, operando2, HI, LO);

    }

    else if(strcmp(instrucao, "j\n") == 0){

        imediato = linha->imediato;
        
        PC = j(PC, imediato);

        inserirNoBarramento(PC);
        writeInMemory(PC);

        return 32;

    }

    else if(strcmp(instrucao, "jr\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        PC = jr(PC, operando1);

        inserirNoBarramento(PC);
        writeInMemory(PC);

        return 32;

    }

    else if(strcmp(instrucao, "lui\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;
        
        operando1 = lui(operando1, imediato);

    }

    else if(strcmp(instrucao, "madd\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];
        HI += LO;
        HI = madd(operando1, operando2, HI);    //registrador acumulador, HI e LO são deste tipo

    }

    else if(strcmp(instrucao, "mfhi\n") == 0){
        
        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        operando1 = mfhi(operando1, HI);

    }
    
    else if(strcmp(instrucao, "mflo\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        operando1 = mflo(operando1, LO);

    }

    else if(strcmp(instrucao, "movn\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];
        
        operando1 = movn(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "movz\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        operando1 = movz(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "msub\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        HI += LO;

        HI = msub(operando1, operando2, HI);

    }

    else if(strcmp(instrucao, "mthi\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        HI = mthi(operando1, HI);

    }

    else if(strcmp(instrucao, "mtlo\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        LO = mtlo(operando1, LO);

    }

    else if(strcmp(instrucao, "mul\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        operando1 = mul(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "mult\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        HI += LO;
        
        HI = mult(operando1, operando2, HI);

    }

    else if(strcmp(instrucao, "nor\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        operando1 = nor(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "or\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        operando1 = Or(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "ori\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;

        operando1 = Ori(operando1, operando2, imediato);

    }

    else if(strcmp(instrucao, "sub\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        operando1 = sub(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "xor\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        operando1 = Xor(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "xori\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;
        
        operando1 = Xori(operando1, operando2, imediato);

    }

    else
        nop();
        
    inserirNoBarramento(operando1);
    writeInMemory(PC);

    return iDest;

}

/*
 * @function int Mstage(int PC)
 * @abstract NESTE ESTÁGIO É FEITA NA MEMÓRIA,
 * A BUSCA DO DADO RESULTANTE DO ESTÁGIO DE EXECUÇÃO
 */
int Mstage(int PC){

    readFromMemory(PC);
    int dado = recuperarNoBarramento();

    return dado;

} 

/*
 * @function int Astage(int PC)
 * @abstract NESTE ESTÁGIO É FEITO O ALINHAMENTO
 * QUE VERIFICA SE O ENDEREÇO É MÚLTIPLO DE 4 BYTES
 */
int Astage(int PC){

if(PC % 4 != 0)
    return 0;

else
    return 1;

} 


/*
 * @function int Wstage(int PC)
 * @abstract NESTE ESTÁGIO É FEITA A ESCRITA DO RESULTADO NO REGISTRADOR
 */
int Wstage(int PC, int dado, int indice, int *reg){

    if(indice == 32){

        PC = dado;
        return PC;

    }

    else{

        reg[indice] = dado;
        return reg[indice];

    }

}

/*
 * @function int getReg(char* reg)
 * @abstract ESTA FUNÇÃO É RESPONSÁVEL POR RETORNAR O ÍNDICE CORRETO 
 * DO REGISTRADOR A SER UTILIZADO NAS OPERAÇÕES DO ESTÁGIO DE EXECUÇÃO
 */
int getReg(char* reg){

    if(strcmp(reg, "$zero\n") == 0)
        return 0;

    else if(strcmp(reg, "$at\n") == 0)
        return 1;

    else if(strcmp(reg, "$v0\n") == 0)
        return 2;

    else if(strcmp(reg, "$v1\n") == 0)
        return 3;

    else if(strcmp(reg, "$a0\n") == 0)
        return 4;

    else if(strcmp(reg, "$a1\n") == 0)
        return 5;

    else if(strcmp(reg, "$a2\n") == 0)
        return 6;

    else if(strcmp(reg, "$a3\n") == 0)
        return 7;

    else if(strcmp(reg, "$t0\n") == 0)
        return 8;

    else if(strcmp(reg, "$t1\n") == 0)
        return 9;

    else if(strcmp(reg, "$t2\n") == 0)
        return 10;

    else if(strcmp(reg, "$t3\n") == 0)
        return 11;

    else if(strcmp(reg, "$t4\n") == 0)
        return 12;

    else if(strcmp(reg, "$t5\n") == 0)
        return 13;

    else if(strcmp(reg, "$t6\n") == 0)
        return 14;

    else if(strcmp(reg, "$t7\n") == 0)
        return 15;

    else if(strcmp(reg, "$s0\n") == 0)
        return 16;

    else if(strcmp(reg, "$s1\n") == 0)
        return 17;

    else if(strcmp(reg, "$s2\n") == 0)
        return 18;

    else if(strcmp(reg, "$s3\n") == 0)
        return 19;

    else if(strcmp(reg, "$s4\n") == 0)
        return 20;

    else if(strcmp(reg, "$s5\n") == 0)
        return 21;

    else if(strcmp(reg, "$s6\n") == 0)
        return 22;

    else if(strcmp(reg, "$s7\n") == 0)
        return 23;

    else if(strcmp(reg, "$t8\n") == 0)
        return 24;

    else if(strcmp(reg, "$t9\n") == 0)
        return 25;

    else if(strcmp(reg, "$k0\n") == 0)
        return 26;

    else if(strcmp(reg, "$k1\n") == 0)
        return 27;

    else if(strcmp(reg, "$gp\n") == 0)
        return 28;

    else if(strcmp(reg, "$sp\n") == 0)
        return 29;

    else if(strcmp(reg, "$fp\n") == 0)
        return 30;

    else if(strcmp(reg, "$ra\n") == 0)
        return 31;

    else{

        printf("\nRegistrador não encontrado na busca de operandos!");
        return -1;

    }

}