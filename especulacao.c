#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/especulacao.h"
#include "includes/scoreboarding.h"
#include "includes/mdu.h"
#include "includes/ula.h"


bool isSpec(struct functionalUnitStatus fus){
    if(strcmp(fus.opName,"add\n") == 0 || strcmp(fus.opName,"sub\n") == 0
     || strcmp(fus.opName,"mul\n") == 0 || strcmp(fus.opName,"div\n") == 0 
     || strcmp(fus.opName,"addi\n") == 0 || strcmp(fus.opName,"madd\n") == 0 || strcmp(fus.opName,"msub\n") == 0
     || strcmp(fus.opName,"mult\n") == 0){
        return true;
    }
    return false;
}

int speculation(struct functionalUnitStatus fus){
    bool especulacaoCorreta = false;
    int vetorEspeculativo[8];
    int resultToBeWritten;
    int valorReg1,valorReg2,valorImm, valorRegDestino;
    unsigned int HI,LO;
    valorReg1 = fus.operando2;
    valorReg2 = fus.operando3;
    valorImm = fus.immediate;
    
    vetorEspeculativo[0] = ulaAdd(valorReg1,valorReg2);
    vetorEspeculativo[1] = ulaSub(valorReg1,valorReg2);
    vetorEspeculativo[2] = mduMul(valorReg1,valorReg2);
    vetorEspeculativo[3] = mduDivLO(valorReg1,valorReg2,HI,LO);
    vetorEspeculativo[4] = mduMult(valorReg1,valorReg2);
    vetorEspeculativo[5] = mduMadd(valorReg1,valorReg2);
    vetorEspeculativo[6] = mduMsub(valorReg1,valorReg2);
    vetorEspeculativo[7] = ulaAddi(valorReg1,valorImm);


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

        else if(strcmp(fus.opName,"div\n") == 0){
            resultToBeWritten = vetorEspeculativo[3];
        }

        else if(strcmp(fus.opName,"mult\n") == 0){
            resultToBeWritten = vetorEspeculativo[4];
        }
        else if(strcmp(fus.opName,"madd\n") == 0){
            resultToBeWritten = vetorEspeculativo[5];
        }
        else if(strcmp(fus.opName,"msub\n") == 0){
            resultToBeWritten = vetorEspeculativo[6];
        }
        else{
            resultToBeWritten = vetorEspeculativo[7];
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