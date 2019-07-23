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


/* 
 * @function void Istage()
 * @abstract ESTÁGIO DE BUSCA
 * REALIZA A BUSCA DA INSTRUÇÃO NA FILA
 */
char* Istage(fila *execQueue){

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
    fila *F = execQueue;
    char *nomeSaida;
    strcpy(nomeSaida,F->instructionName);
    return nomeSaida;
}

/* 
 * @function void Estage()
 * @abstract ESTÁGIO DE EXECUÇÃO
 * REALIZA A EXECUÇÃO DE ACORDO COM A INSTRUÇÃO ENCONTRADA EM Istage()
 * BUSCA OS REGISTRADORES, IMEDIATOS OU ENDEREÇOS CONTIDOS NA MESMA 
 * POSIÇÃO DA FILA EM QUE A INSTRUÇÃO FOI BUSCADA
 */
void Estage(char* instrucao, fila *exeQueue){

    //A PARTIR DA POSIÇÃO INICIAL DA FILA,
    //BUSCAR OS OPERANDOS NAQUELA POSIÇÃO DA FILA
    //CASO FOREM REGISTRADORES 
    //COMPARAR COM OS NOMES("strcmp()") DOS REGISTRADORES DE "registradores.h"
    //ACESSAR VALOR DO REGISTRADOR CASO ALGUMA IGUALDADE FOR VERDADEIRA
    //EXECUTAR A OPERAÇÃO
    //SALVAR RESULTADO NA MEMÓRIA PRINCIPAL(AINDA PRECISAMOS REVISAR A MEMÓRIA)
    int operando1, operando2, destino;
    
    if(exeQueue->imediato != NULL){

    }

    /*
    int operando1, operando2, destino;

    verificar os campos da fila
    os que forem difenentes de NULL serão utilizados na execução

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

    executar operacao
    comparar o parametro recebido char* instrucao com as instruções de "intrucoes.h"
    de acordo com a instrução verificada, passar os parametros para a instrução encontrada
    conjunto de if else, caso verdadeiro chamar a função respectiva de instrucoes.h
    ex: 
    if(strcmp(intrucao, add)){
        add(destino, operando1, operando2);
    }

    excluir a posição inicial da fila

    salvar o retorno da função de intrução na memória (revisar memória)
    apontar o registrador PC na posicao de memória salva

     */
}
