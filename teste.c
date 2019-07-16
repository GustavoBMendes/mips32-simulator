#include <stdio.h>
#include "includes/memoria.h"
#include "includes/barramento.h"


int main(){
    inicializeMemory(); //Ok está alocando
    
    /*
     * Testado, inserindo na memória, barramento
     */
    unsigned char *dado = "case";
    inserirNoBarramento(dado);
    writeInMemory(0);

    int i;
    for(i = 0; i < 4; i++){
        printf("\n[%d] : %x", i, *(memory + i));
    }
}