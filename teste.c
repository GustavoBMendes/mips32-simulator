#include <stdio.h>
#include "includes/memoria.h"
#include "includes/barramento.h"
#include "includes/registradores.h"
#include "includes/ula.h"

int main(){
    unsigned int reg[32];

    //inicializeMemory(); //Ok está alocando
    
    /* 
    unsigned char *dado = "15";
    inserirNoBarramento(dado);
    writeInMemory(0);

    int i;
    for(i = 0; i < 4; i++){
        printf("\n[%d] : %d", i, *(memory + i));
    }
    */
   
    T0 = 15;
    T1 = 5;

    printf("\nRESULTADO > %d \n", ulaAdd(T0, T1));

}