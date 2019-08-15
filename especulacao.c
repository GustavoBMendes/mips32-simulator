#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/especulacao.h"
#include "includes/scoreboarding.h"
#include "includes/mdu.h"



bool isSpec(struct functionalUnitStatus fus){
    if(strcmp(fus.opName,"mul\n") == 0 || strcmp(fus.opName,"div\n") == 0 || strcmp(fus.opName,"madd\n") == 0 || strcmp(fus.opName,"msub\n") == 0
     || strcmp(fus.opName,"mult\n") == 0){
        return true;
    }
    return false;
}

int speculation(struct functionalUnitStatus fus){
    bool especulacaoCorreta = false;
    int vetorEspeculativo[5];
    int resultToBeWritten;
    int valorReg1,valorReg2;
    unsigned int HI,LO;
    valorReg1 = fus.operando2;
    valorReg2 = fus.operando3;
    
    vetorEspeculativo[0] = mduMul(valorReg1,valorReg2);
    vetorEspeculativo[1] = mduDivLO(valorReg1,valorReg2,HI,LO);
    vetorEspeculativo[2] = mduMult(valorReg1,valorReg2);
    vetorEspeculativo[3] = mduMadd(valorReg1,valorReg2);
    vetorEspeculativo[4] = mduMsub(valorReg1,valorReg2);
    


    if(isSpec(fus) == true){
        especulacaoCorreta = true;
        
        if(strcmp(fus.opName,"mul\n") == 0){
            resultToBeWritten = vetorEspeculativo[0];
        }

        else if(strcmp(fus.opName,"div\n") == 0){
            resultToBeWritten = vetorEspeculativo[1];
        }

        else if(strcmp(fus.opName,"mult\n") == 0){
            resultToBeWritten = vetorEspeculativo[2];
        }
        else if(strcmp(fus.opName,"madd\n") == 0){
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
        return;
    }
}