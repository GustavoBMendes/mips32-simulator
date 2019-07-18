#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/instrucoes.h"
#include "includes/mdu.h"
#include "includes/registradores.h"

int HI, LO;

/* 
* @function void mduDiv(mdu *mdu_executavel)
* @abstract .
*/
void mduDiv(mdu *mdu_executavel){
    div(mdu_executavel->operando1,mdu_executavel->operando2,HI,LO);
}
/* 
* @function void mduMul(mdu *mdu_executavel)
* @abstract .
*/
void mduMul(mdu *mdu_executavel){
    mul(mdu_executavel->saida_mdu,mdu_executavel->operando1,mdu_executavel->operando2);
}
/* 
* @function void mduMult(mdu *mdu_executavel)
* @abstract .
*/
void mduMult(mdu *mdu_executavel){
    mult(mdu_executavel->operando1,mdu_executavel->operando2,mdu_executavel->saida_mdu);
}

/* 
* @function void mduMadd(mdu *mdu_executavel)
* @abstract .
*/
void mduMadd(mdu *mdu_executavel){
    madd(mdu_executavel->operando1,mdu_executavel->operando2,mdu_executavel->saida_mdu);
}
/* 
* @function void mduMfhi(mdu *mdu_executavel)
* @abstract .
*/
void mduMfhi(mdu *mdu_executavel){
    mfhi(HI, mdu_executavel->operando1);
}
/* 
* @function void mduMflo(mdu *mdu_executavel)
* @abstract .
*/
void mduMflo(mdu *mdu_executavel){
    mflo(LO, mdu_executavel->operando1);
}
/* 
* @function void mduMsub(mdu *mdu_executavel)
* @abstract .
*/
void mduMsub(mdu *mdu_executavel){
    msub(mdu_executavel->operando1,mdu_executavel->operando2,mdu_executavel->saida_mdu);
}
/* 
* @function void mduMthi(mdu *mdu_executavel)
* @abstract .
*/
void mduMthi(mdu *mdu_executavel){
    mthi(mdu_executavel->operando1,HI);
}
/* 
* @function void mduMtlo(mdu *mdu_executavel)
* @abstract .
*/
void mduMtlo(mdu *mdu_executavel){
    mthi(mdu_executavel->operando1,LO);
}

