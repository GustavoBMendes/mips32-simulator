#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/branchPredictor.h"
#include "includes/operationsUnit.h"
#include "includes/executionQueue.h"


bool isBranch(char* instrucao){
    if(strcmp(instrucao,"b\n") == 0 ||strcmp(instrucao,"beq\n") == 0 ||strcmp(instrucao,"beql\n") == 0 ||
      strcmp(instrucao,"bgez\n") == 0 ||strcmp(instrucao,"bgtz\n") == 0 ||strcmp(instrucao,"blez\n") == 0 ||
      strcmp(instrucao,"bltz\n") == 0 ||strcmp(instrucao,"bne\n") == 0){
        return true;
    }
    else{
        return false;
    }
}


struct numerosPrevisao previsao(FILA F){
    NO *aux = F.inicio;
    char* instrucao = (char*)malloc(sizeof(aux->instructionName));
    strcpy(instrucao,aux->instructionName);
    struct numerosPrevisao n;
    n.acertos = 0;
    n.erros = 0;
    if(isBranch(instrucao) == true){
        if(/*desvio tomado*/){
            n.acertos++;
            //tratar as instruções
        }
        else{
            n.erros++;
            //tratar as instruções e incrementar mais um ciclo de clock
        }
    
    //no final do programa as situações foram tratadas devidamente e será retornado como informação de saída do simulador o
    //numero de acertos e de erros

    }
    
}