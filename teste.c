#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/memoria.h"
#include "includes/barramento.h"
#include "includes/registradores.h"
#include "includes/ula.h"
#include "includes/mdu.h"
#include "includes/executionQueue.h"
#include "includes/pipeline.h"
#include "includes/somadorPC.h"

int main(){
    unsigned int reg[32];
    reg[0] = 0;
    unsigned int HI = 11,LO = 0, PC = 0;
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
   
    //$T0 = 15;
    //$T1 = 5;
    /*
    printf("\nRESULTADO ACIONANDO A ULA (+) > %d \n", ulaAdd(T0, T1));
    printf("\nRESULTADO ACIONANDO O MDU (*) > %d \n", mduMul(T0, T1));
    printf("\nRESULTADO ACIONANDO O MDU (MADD) > %d \n", mduMadd(T0, T1));
    printf("\nRESULTADO ACIONANDO O MDU (MSUB) > %d \n", mduMsub(T0, T1));
    printf("REsultado do HI: %d\nResultado do LO: %d\n",mduDivHI(T0, T1,HI,LO),mduDivLO(T0, T1,HI,LO));
    */
    /* 
    printf("Teste MFLO, MTLO, MTHI E MTHI:\n\n");
    printf("MTHI: %d\nMFHI: %d",mduMthi(T0,HI),mduMfhi(HI,T0));
    */
    
    FILA F;

    create(&F);
    ler();
    inserirElementos(&F);

    char *a = (char*) malloc(7 * sizeof(char));
    strcpy(a, Istage(&F, PC));
    printf("%s ",a);

    int indiceReg = Estage(a, &F, PC, reg);
    printf("\nIndice registrador destino: %d\n", indiceReg);

    int dado = Mstage(PC);
    printf("\nResultado: %d", dado);
    
    if(Astage(PC) == 1)
        printf("\nEndereço Correto!\n");
    else
        printf("\nEndereço incorreto!\n");

    reg[indiceReg] = Wstage(PC, dado, indiceReg, reg);
    printf("\nEscrita no Registrador[%d] = %d\n", indiceReg, reg[indiceReg]);

    PC = somarPC(PC);
    printf("\nPC = %d\n", PC);

    /*
    int a = 111;
    inserirNoBarramento(a);
    printf("%s \n",biu);
    printf("Recuperado do barramento o valor: %d",recuperarNoBarramento());
    */
    
}