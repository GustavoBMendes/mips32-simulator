#include <stdio.h>
#include "includes/memoria.h"
#include "includes/barramento.h"
#include "includes/registradores.h"
#include "includes/ula.h"

int main(){
    inicializeMemory(); //Ok está alocando
    
    /* 
    unsigned char *dado = "15";
    inserirNoBarramento(dado);
    writeInMemory(0);

    int i;
    for(i = 0; i < 4; i++){
        printf("\n[%d] : %d", i, *(memory + i));
    }
    */
   
    reg[8] = 15;
    reg[9] = 5;

    printf("\nRESULTADO > %lld \n", ulaAdd(reg[8], reg[9]));

}