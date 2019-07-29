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

unsigned int reg[32];
extern unsigned int HI,LO;

/* 
 * @function void Istage()
 * @abstract ESTÁGIO DE BUSCA
 * REALIZA A BUSCA DA INSTRUÇÃO NA FILA
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
 */

int Estage(char* instrucao, FILA *exeQueue, int PC){

    //A PARTIR DA POSIÇÃO INICIAL DA FILA,
    //BUSCAR OS OPERANDOS NAQUELA POSIÇÃO DA FILA
    //CASO FOREM REGISTRADORES 
    //COMPARAR COM OS NOMES("strcmp()") DOS REGISTRADORES DE "registradores.h"
    //ACESSAR VALOR DO REGISTRADOR CASO ALGUMA IGUALDADE FOR VERDADEIRA
    //EXECUTAR A OPERAÇÃO
    //SALVAR RESULTADO NA MEMÓRIA PRINCIPAL(AINDA PRECISAMOS REVISAR A MEMÓRIA)

    NO* linha = exeQueue->inicio;
    int posicao = PC/4;
    int iOp2 = 0, iOp3 = 0, iDest = 0;

    while(posicao > 0){

        linha = linha->prox;
        posicao--;

    }

    int operando1, operando2, operando3, imediato;

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
    /* 
    executar operacao
    comparar o parametro recebido char* instrucao com as instruções de "intrucoes.h"
    de acordo com a instrução verificada, passar os parametros para a instrução encontrada
    conjunto de if else, caso verdadeiro chamar a função respectiva de instrucoes.h
    ex: 
    if(strcmp(intrucao, add)){
        add(operando1, operando1, operando2);
    }

    excluir a posição inicial da fila

    salvar o retorno da função de intrução na memória (revisar memória)
    apontar o registrador PC na posicao de memória salva

     
    */
    //char *aux;
    //aux = (char*)malloc(sizeof(exeQueue->inicio->instructionName));
    //strcpy(aux,"add");
    //printf("Tamanho de instrucao: %ld\nTamanho de aux: %ld",sizeof(instrucao),sizeof(aux));
    //printf("aux: %s \ninstrucao: %s",aux,instrucao);
   

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

        And(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "andi\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;

        andi(operando1, operando2, imediato);

    }

    else if(strcmp(instrucao, "b\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;

        b(PC, imediato);

    }

    else if(strcmp(instrucao, "beq\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;

        beq(operando1, operando2, PC, imediato);

    }

    else if(strcmp(instrucao, "beql\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;
        
        beql(operando1, operando2, PC, imediato);

    }

    else if(strcmp(instrucao, "bgez\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;
        
        bgez(operando1, PC, imediato);

    }

    else if(strcmp(instrucao, "bgtz\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;
        
        bgtz(operando1, PC, imediato);

    }

    else if(strcmp(instrucao, "blez\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;

        blez(operando1, PC, imediato);

    }

    else if(strcmp(instrucao, "bltz\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;
        
        bltz(operando1, PC, imediato);

    }

    else if(strcmp(instrucao, "bne\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;
        
        bne(operando1, operando2, PC, imediato);

    }

    else if(strcmp(instrucao, "div\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];
        
        DivHI(operando1, operando2, HI, LO);
        DivLO(operando1, operando2, HI, LO);

    }

    else if(strcmp(instrucao, "j\n") == 0){

        imediato = linha->imediato;
        
        j(PC, imediato);

    }

    else if(strcmp(instrucao, "jr\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        jr(PC, operando1);

    }

    else if(strcmp(instrucao, "lui\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        imediato = linha->imediato;
        
        lui(operando1, imediato);

    }

    else if(strcmp(instrucao, "madd\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        madd(operando1, operando2, HI);    //registrador acumulador, HI e LO são deste tipo

    }

    else if(strcmp(instrucao, "mfhi\n") == 0){
        
        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        mfhi(operando1, HI);

    }
    
    else if(strcmp(instrucao, "mflo\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        mflo(operando1, LO);

    }

    else if(strcmp(instrucao, "movn\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];
        
        movn(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "movz\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        movz(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "msub\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        msub(operando1, operando2, HI);

    }

    else if(strcmp(instrucao, "mthi\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        mthi(operando1, HI);

    }

    else if(strcmp(instrucao, "mtlo\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        mtlo(operando1, LO);

    }

    else if(strcmp(instrucao, "mul\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        mul(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "mult\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        mult(operando1, operando2, HI);

    }

    else if(strcmp(instrucao, "nor\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        nor(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "or\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        Or(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "ori\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;

        Ori(operando1, operando2, imediato);

    }

    else if(strcmp(instrucao, "sub\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        sub(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "xor\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        iOp3 = getReg(linha->reg2);
        operando3 = reg[iOp3];

        Xor(operando1, operando2, operando3);

    }

    else if(strcmp(instrucao, "xori\n") == 0){

        iDest = getReg(linha->regDestino);
        operando1 = reg[iDest];

        iOp2 = getReg(linha->reg1);
        operando2 = reg[iOp2];

        imediato = linha->imediato;
        
        Xori(operando1, operando2, imediato);

    }

    else
        nop();
        
    inserirNoBarramento(operando1);
    writeInMemory(PC);

    return iDest;

}
 
int Mstage(int PC){

    /*
    * Durante o estágio de busca de memória, a operação aritmética ou lógica da ALU é concluída, a busca 
    * do cache de dados e a conversão de endereços virtuais para dados são executadas para instruções 
    * de carga e armazenamento. 
    */

    //Nesse estagio, será realizada a busca na memória do dado escrito no estágio de execução
    readFromMemory(PC);
    
    //pega o dado do barramento
    int dado = recuperarNoBarramento();

    //Retornar o dado buscado
    return dado;

} 


int Astage(int PC){
/*
* Durante o estágio Alinhar / Acumular, um alinhador separado alinha os dados carregados com seu limite de palavras, uma 
* operação MUL disponibiliza o resultado para write-back. O writeback real do registrador é executado no 
* estágio W (todos os núcleos 4K), uma operação MULT / MADD / MSUB executa o carry-propagate-add. 
* Isso inclui o passo acumulado para as operações MADD / MSUB. 
* O writeback de registro real para HI e LO é realizado no estágio W (4Kc e 4Km núcleos),uma operação de divisão executa 
* o ajuste de sinal final. O writeback real do registrador para HI e LO é executado no W estágio (núcleos de 4Kc e 4Km), 
* uma operação de multiplicação / divisão grava em registradores HI / LO (apenas no core 4Kp).
*/

if(PC % 4 != 0)
    return 0;

else
    return 1;

} 



int Wstage(int PC, int dado, int indice){

    /*
    * Para registrador-para-registrador ou carregar instruções,o resultado é gravado de volta no arquivo de registro
    * durante o estágio W.
    */
    
    //Escrever os dados no registrador com índice retornado pelo estágio E
    //O parametro dado vem do estágio M
    reg[indice] = dado;

    return reg[indice];

}

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