#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/especulacao.h"
#include "includes/executionQueue.h"
#include "includes/scoreboarding.h"

int speculation(){
    bool especulacaoCorreta = false;
    int vetorEspeculativo[5];
    int resultToBeWritten;

    //fazer com que a próxima linha de instrução entre no estágio de capturar os valores dos registradores

    //preenchendo o vetor especulativo com os resultados para as possíveis operações: +,-,*,/ e desvio tomado como verdadeiro
    //falta mesclar com o código de capturar os valores dos registradores
    vetorEspeculativo[0] = valorReg1 + valorReg2;
    vetorEspeculativo[1] = valorReg1 - valorReg2;
    vetorEspeculativo[2] = valorReg1 * valorReg2;
    vetorEspeculativo[3] = valorReg1 / valorReg2;
    vetorEspeculativo[4] = 1; //recebendo 1 pois o desvio tomado foi verdadeiro (desvio sempre tomado)

    if(/*nome da instrucao for + - * / ou de desvio*/){
        especulacaoCorreta = true;
        if(/*nome instrucao for +*/){
            resultToBeWritten = vetorEspeculativo[0];
        }
        else if(/*nome instrucao for -*/){
            resultToBeWritten = vetorEspeculativo[1];
        }

        else if(/*nome instrucao for * */){
            resultToBeWritten = vetorEspeculativo[2];
        }

        else if(/*nome instrucao for / */){
            resultToBeWritten = vetorEspeculativo[3];
        }
        else{
            resultToBeWritten = vetorEspeculativo[4];
        }

        if(especulacaoCorreta == true){
            return resultToBeWritten;

        }
            
    }
    else{
        //adiciona de repente um ou mais cilos a mais no contador pelo tempo perdido pela especulação errada
        return; // daí segue o fluxo normal
    }
}