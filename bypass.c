/*!
 * @header multiplexador.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO O SUPORTE AO BYPASS
 * ONDE, SEGUNDO A DOCUMENTAÇÃO DO MIPS32,
 * O MULTIPLEXADOR DO BYPASS É UTILIZADO PARA GUARDAR O RESULTADO DE UMA INSTRUÇÃO
 * SENDO ÚTIL PARA A PRÓXIMA INSTRUÇÃO UTILIZAR O VALOR REAL DO REGISTRADOR
 */

#include <stdio.h>
#include "includes/bypass.h"

unsigned int multiplexador;

void inserirMultiplexador(unsigned int dado){
    multiplexador = dado;
}

unsigned int returnMultiplexador(){

    return multiplexador;

}
