/*!
 * @header multiplexador.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO O SUPORTE À PREVISÃO DE DESVIO
 * CADA INSTRUÇÃO É VERIFICADA SE SUA NATUREZA É DE DESVIO OU NÃO.
 * SENDO DE DESVIO, COMO A ESTRATÉGIA É DESVIO SEMPRE TOMADO,
 * VERIFICAMOS A NÍVEL DE EXECUÇÃO SE HOUVE UM ACERTO OU ERRO NA DECISÃO DE TOMAR O DESVIO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/branchPredictor.h"

bool prediction(char *instrucao, int a, int b){

    if(strcmp(instrucao,"beq\n") == 0 || strcmp(instrucao,"beql\n") == 0){

        if(a == b)
            return true;
        
        else
            return false;
        
    }
    else if(strcmp(instrucao,"bne\n") == 0){

        if(a != b)
            return true;
        
        else
            return false;
        
    }
    else if(strcmp(instrucao,"bgez\n") == 0){

        if(a >= 0)
            return true;
        
        else
            return false;
        
    }
    else if(strcmp(instrucao,"bgtz\n") == 0){

        if(a > 0)
            return true;
        
        else
            return false;
        
    }
    else if(strcmp(instrucao,"blez\n") == 0){

        if(a <= 0)
            return true;
        
        else
            return false;
        
    }
    else if(strcmp(instrucao,"bltz\n") == 0){

        if(a < 0)
            return true;
        
        else
            return false;
        
    }

    else{

        printf("No branch instruction");
        return false;

    }
    
}

NO* getNoBranch(FILA *F, int PC){

    NO* aux = F->inicio;

    int endereco = PC/4;

    while(endereco > 0){

        aux = aux->prox;
        endereco--;

    }

    return aux;

}

int getRegBranch(NO* branch, int indice){

    if(indice == 1)
        return getReg(branch->regDestino);

    if(indice == 2)
        return getReg(branch->reg1);
    
}

bool isBranch(char* instrucao){

    if(strcmp(instrucao,"b\n") == 0 ||strcmp(instrucao,"beq\n") == 0 ||strcmp(instrucao,"beql\n") == 0 ||
      strcmp(instrucao,"bgez\n") == 0 ||strcmp(instrucao,"bgtz\n") == 0 ||strcmp(instrucao,"blez\n") == 0 ||
      strcmp(instrucao,"bltz\n") == 0 ||strcmp(instrucao,"bne\n") == 0){
        return true;
    }

    else
        return false;
    
}


numerosPrevisao previsao(char *instrucao, int reg1, int reg2, struct numerosPrevisao n){

    bool previsao = prediction(instrucao, reg1, reg2);
    
    if(previsao == true)
        n.acertos++;

    else
        n.erros++;

    n.saltos++;
    
    return n;

}