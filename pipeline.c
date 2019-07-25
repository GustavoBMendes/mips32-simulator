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

extern unsigned int HI,LO;
/* 
 * @function void Istage()
 * @abstract ESTÁGIO DE BUSCA
 * REALIZA A BUSCA DA INSTRUÇÃO NA FILA
 */
char* Istage(FILA *execQueue){

    //A PRIMEIRA POSIÇÃO DA FILA SEMPRE SERÁ A INSTRUÇÃO A SER EXECUTADA
    //NÃO REMOVER O NÓ DA POSIÇÃO INICIAL DA FILA NESTE ESTÁGIO
    //POIS ESTA É NECESSAŔIA PARA PEGAR OS REGISTRADORES NO ESTÁGIO DE EXECUÇÃO
    //NO ESTÁGIO DE EXECUÇÃO ESTA POSIÇÃO MARCADA SERÁ REMOVIDA DA FILA

    /*
    char* instrucao;
    transferir string do campo instructionName para outra string auxiliar
    que será retornada e utilizada no estágio de execução
    strcpy(instrucao, fila->instructionName);
    return instrucao;
     */

    NO *aux = execQueue->inicio;
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

void Estage(char* instrucao, FILA *exeQueue){

    //A PARTIR DA POSIÇÃO INICIAL DA FILA,
    //BUSCAR OS OPERANDOS NAQUELA POSIÇÃO DA FILA
    //CASO FOREM REGISTRADORES 
    //COMPARAR COM OS NOMES("strcmp()") DOS REGISTRADORES DE "registradores.h"
    //ACESSAR VALOR DO REGISTRADOR CASO ALGUMA IGUALDADE FOR VERDADEIRA
    //EXECUTAR A OPERAÇÃO
    //SALVAR RESULTADO NA MEMÓRIA PRINCIPAL(AINDA PRECISAMOS REVISAR A MEMÓRIA)

    NO* linha = exeQueue->inicio;

    int operando1, operando2, destino;

    //verificar os campos da fila
    //os que forem difenentes de NULL serão utilizados na execução
    /*
    se fila->imediato != NULL{
        while(tenham registradores a serem percorridos){
            compara fila->imediato com todos os 32 registradores de "registradores.h" um a um
            atribuir valor ao operando2
            operando2 = registrador 
        }
    }
    se fila->regDestino != NULL {
        while(tenham registradores a serem percorridos){
            compara fila->regDestino com todos os 32 registradores de "registradores.h" um a um
            atribuir valor ao destino
            destino = registrador 
        }
    }
    se fila->reg1 != NULL{
        while(tenham registradores a serem percorridos){
            compara fila->reg1 com todos os 32 registradores de "registradores.h" um a um
            atribuir valor ao operando1
            operando1 = registrador 
        }
    }
    se fila->reg2 != NULL{
        while(tenham registradores a serem percorridos){
            compara fila->reg2 com todos os 32 registradores de "registradores.h" um a um
            atribuir valor ao operando2
            operando2 = registrador 
        }
    }
    */

    int operando1, operando2, destino;
    

    if(linha->imediato != NULL)
        operando2 = linha->imediato;

    if(linha->regDestino != NULL)
        destino = getReg(linha->regDestino);

    if(linha->reg1 != NULL){
        int k = getReg(linha->reg1);
        operando1 = reg[k];
    }

    if(linha->reg2 != NULL){
        int k = getReg(linha->reg2);
        operando2 = reg[k];
    }
    
    /* 
     * executar operacao
     * comparar o parametro recebido char* instrucao 
     * com as instruções de "intrucoes.h"
     * de acordo com a instrução verificada, 
     * passar os parametros para a instrução encontrada
     * conjunto de if else, caso verdadeiro 
     * chamar a função respectiva de instrucoes.h
     * ex:
     */

    if(strcmp(instrucao, add)){
        add(destino, operando1, operando2);
    }

    //excluir a posição inicial da fila

    //salvar o retorno da função de intrução na memória (revisar memória)
    //apontar o registrador PC na posicao de memória salva

     

    

    switch(instrucao){
        case "add": add(destino,operando1,operando2); break;
        case "addi": addi(destino,operando1,imediato); break;
        case "And": And(destino,operando1,operando2); break;
        case "andi": andi(destino,operando1,imediato); break;
        case "b": ; break;
        case "beq":  ; break;
        case "beql": ; break;
        case "bgez": ; break;
        case "bgtz": ; break;
        case "blez": ; break;
        case "bltz": ; break;
        case "bne": ;  break;
        case "DivHI": DivHI(operando1,operando2,HI,LO); break;
        case "DivLO": DivLO(operando1,operando2,HI,LO); break;
        case "j": ; break; 
        case "jr": ; break;
        case "lui": ; break; 
        case "madd": madd(operando1,operando2,destino); break;
        case "mfhi": mfhi(HI,operando1); break;
        case "mflo": mflo(LO,operando1); break;
        case "movn": movn(destino,operando1,operando2); break;
        case "movz": movz(destino,operando1,operando2); break;
        case "msub": msub(operando1,operando2,destino); break;
        case "mthi": mthi(operando1,HI); break;
        case "mtlo": mtlo(operando1,LO); break;
        case "mul": mul(destino,operando1,operando2); break;
        case "mult": mult(operando1,operando2,destino); break;
        case "nop": nop(); break;
        case "nor": nor(destino,operando1,operando2); break; 
        case "Or": Or(destino,operando1,operando2); break;
        case "Ori": Ori(destino,operando1,imediato); break;
        case "Xor": Xor(destino,operando1,operando2); break;
        case "Xori": Xori(destino,operando1,imediato); break;
    }

    queueOut(exeQueue);

}

void Mstage(){

} 


void Astage(){

} 



void Wstage(){

}

int getReg(char* reg){

    if(strcmp(reg, "$zero"))
        return 0;

    else if(strcmp(reg, "$at"))
        return 1;

    else if(strcmp(reg, "$v0"))
        return 2;

    else if(strcmp(reg, "$v1"))
        return 3;

    else if(strcmp(reg, "$a0"))
        return 4;

    else if(strcmp(reg, "$a1"))
        return 5;

    else if(strcmp(reg, "$a2"))
        return 6;

    else if(strcmp(reg, "$a3"))
        return 7;

    else if(strcmp(reg, "$t0"))
        return 8;

    else if(strcmp(reg, "$t1"))
        return 9;

    else if(strcmp(reg, "$t2"))
        return 10;

    else if(strcmp(reg, "$t3"))
        return 11;

    else if(strcmp(reg, "$t4"))
        return 12;

    else if(strcmp(reg, "$t5"))
        return 13;

    else if(strcmp(reg, "$t6"))
        return 14;

    else if(strcmp(reg, "$t7"))
        return 15;

    else if(strcmp(reg, "$s0"))
        return 16;

    else if(strcmp(reg, "$s1"))
        return 17;

    else if(strcmp(reg, "$s2"))
        return 18;

    else if(strcmp(reg, "$s3"))
        return 19;

    else if(strcmp(reg, "$s4"))
        return 20;

    else if(strcmp(reg, "$s5"))
        return 21;

    else if(strcmp(reg, "$s6"))
        return 22;

    else if(strcmp(reg, "$s7"))
        return 23;

    else if(strcmp(reg, "$t8"))
        return 24;

    else if(strcmp(reg, "$t9"))
        return 25;

    else if(strcmp(reg, "$k0"))
        return 26;

    else if(strcmp(reg, "$k1"))
        return 27;

    else if(strcmp(reg, "$gp"))
        return 28;

    else if(strcmp(reg, "$sp"))
        return 29;

    else if(strcmp(reg, "$fp"))
        return 30;

    else if(strcmp(reg, "$ra"))
        return 31;

    else{

        printf("\nRegistrador não encontrado na busca de operandos!");
        return -1;

    }

}