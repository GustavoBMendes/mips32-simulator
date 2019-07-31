#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/branchPredictor.h"

struct numerosPrevisao previsao(/* vai entrar provavelmente a fila de execução*/){
    struct numerosPrevisao n;
    n.acertos = 0;
    n.erros = 0;
    //if(/* condition: se for instrucoes de desvio (bne,beq,..., etc) e se não houver dependencias */){
        //tratar instruções posteriores dentro do if (consideramos que sempre ira acontecer)
        //se for tomado de fato incrementar a variavel acertos
        //se não foi tomado de fato
            // incrementar a variavel erros
            // fazer a instrução voltar mais uma vez gastando mais um ciclo de clock
    //}

    //no final do programa as situações foram tratadas devidamente e será retornado como informação de saída do simulador o
    //numero de acertos e de erros

}