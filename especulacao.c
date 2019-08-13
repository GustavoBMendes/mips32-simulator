#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/especulacao.h"
#include "includes/executionQueue.h"
#include "includes/scoreboarding.h"


bool isSpec(struct functionalUnitStatus fus){
    if(strcmp(fus.opName,"add\n") == 0 || strcmp(fus.opName,"sub\n") == 0 || strcmp(fus.opName,"mul\n") == 0 || strcmp(fus.opName,"div\n") == 0){
        return true;
    }
    return false;
}

int speculation(struct functionalUnitStatus fus){
    bool especulacaoCorreta = false;
    int vetorEspeculativo[4];
    int resultToBeWritten;
    int valorReg1,valorReg2;
    valorReg1 = fus.operando2;
    valorReg2 = fus.operando3;
    
    vetorEspeculativo[0] = valorReg1 + valorReg2;
    vetorEspeculativo[1] = valorReg1 - valorReg2;
    vetorEspeculativo[2] = valorReg1 * valorReg2;
    vetorEspeculativo[3] = valorReg1 / valorReg2;
    if(isSpec(fus) == true){
        especulacaoCorreta = true;
        if(strcmp(fus.opName,"add\n") == 0){
            resultToBeWritten = vetorEspeculativo[0];
        }
        else if(strcmp(fus.opName,"sub\n") == 0 ){
            resultToBeWritten = vetorEspeculativo[1];
        }

        else if(strcmp(fus.opName,"mul\n") == 0){
            resultToBeWritten = vetorEspeculativo[2];
        }

        else{
            resultToBeWritten = vetorEspeculativo[3];
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