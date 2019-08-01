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
        /*
        * Tem que haver uma flag setada true dentro da condição do código após o .asm para caso de fato a condição for
        * verdadeira e essa flag tem que aparecer nessa condição de if para assim disparar o incrementador de acertos.
        * Devemos considerar também que o código não possui dependencias, uma outra flag setada false para dependencias
        * seria interessante nesse if aqui também
        */
        if(/*desvio tomado*/){
            n.acertos++;
            //tratar as instruções --- considerando as proximas instruções depois do desvio, sendo assim "combinado" que o 
            // critério de cada instrução de desvio fora atendido e o tratamento de cada instrução sendo como tal
            // ex: para bne() consideramos que de fato os registradores de entrada não possuiram valores iguais.
        }
        else{
            n.erros++;
            //tratar as instruções e incrementar mais um ciclo de clock
        }
    }
    //no final do programa as situações foram tratadas devidamente e será retornado como informação de saída 
    //do simulador o numero de acertos e de erros
    return n;
}