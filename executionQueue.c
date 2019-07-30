/*!
 * @header executionQueue.c
 * @author Luiz Joaquim Aderaldo Amichi <ra90568@uem.br>
 * @author Gustavo Belançon Mendes <ra99037@uem.br>
 * @author Fernando Silva Silvério <ra98936@uem.br>
 * @discussion NESTE MÓDULO ESTÁ IMPLEMENTADO A FILA DE EXECUÇÃO DO PIPELINE
 * SENDO AQUI REALIZADAS AS OPERAÇÕES DO ARQUIVO .asm 
 * APÓS SUA LEITURA, AS INSTRUÇÕES, OPERADORES OU VALORES IMEDIATOS SÃO INSERIDOS NA FILA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "includes/executionQueue.h"

/* 
 * @function void create()
 * @abstract INICIALIZA A FILA
 * PONTEIROS PARA O INÍCIO E FIM DA FILA SÃO CRIADOS
 */
void create(FILA *F){
	F->inicio = NULL;
	F->fim = NULL;
}

/* 
 * @function void queueInInst()
 * @abstract CRIA UM NOVO NÓ À PARTIR DA INSERÇÃO DE UMA INSTRUÇÃO OU LABEL
 */
void queueInInst(FILA *F,char *nome){

	NO *novo;
	novo = (NO*) malloc(sizeof(NO));
	novo->instructionName = (char*) malloc(sizeof(*nome));
	strcpy(novo->instructionName, nome);
	novo->prox = NULL;
	if(!F->inicio)
		F->inicio = novo;
	else
		F->fim->prox = novo;
	F->fim = novo;
	
}

/* 
 * @function void queueInRegDest()
 * @abstract INSERE UM REGISTRADOR DESTINO NA FILA
 * INSERIDO NO MESMO NÓ DE UMA INSTRUÇÃO ANTERIORMENTE CRIADO
 */
void queueInRegDest(FILA *F, char *reg){

	F->fim->regDestino = (char*) malloc(sizeof(*reg));
	strcpy(F->fim->regDestino, reg);

}

/* 
 * @function void queueInReg1()
 * @abstract INSERE UM REGISTRADOR OPERANDO NA FILA
 * INSERIDO NO MESMO NÓ DE UMA INSTRUÇÃO ANTERIORMENTE CRIADO
 */
void queueInReg1(FILA *F, char* reg){
	
	F->fim->reg1 = (char*) malloc(sizeof(*reg));
	strcpy(F->fim->reg1, reg);

}

/* 
 * @function void queueInReg2()
 * @abstract INSERE UM SEGUNDO REGISTRADOR OPERANDO NA FILA
 * INSERIDO NO MESMO NÓ DE UMA INSTRUÇÃO ANTERIORMENTE CRIADO
 */
void queueInReg2(FILA *F, char* reg){

	F->fim->reg2 = (char*) malloc(sizeof(*reg));
	strcpy(F->fim->reg2, reg);

}

/* 
 * @function void queueInImediato()
 * @abstract INSERE UM VALOR IMEDIATO NA FILA
 * INSERIDO NO MESMO NÓ DE UMA INSTRUÇÃO ANTERIORMENTE CRIADO
 */
void queueInImediato(FILA *F, unsigned int imediato){

	F->fim->imediato = imediato;

}

/* 
 * @function int queueOut()
 * @abstract REMOVE UM NÓ DA FILA
 */
int queueOut (FILA *F){

	NO* alvo = F->inicio;
	if(!alvo)
		return 0;
	if(F->inicio == F->fim)
		F->fim = NULL;
	F->inicio = alvo->prox;
	alvo->prox = NULL;
	free(alvo);
	return 1;
}

/* 
 * @function void printQueue()
 * @abstract EXIBE A FILA 
 */
void printQueue(FILA F){

	NO *aux = F.inicio;
	int k = 1;

	if(aux == NULL){
		printf("FIla vazia!\n");
	}

	else{
		printf("Inicio --> ");
		while(aux != NULL){

			printf("Posição da fila: %d => ", k);
			if(aux->instructionName != NULL)
				printf("Instrucao: %s", aux->instructionName);

			if(aux->regDestino != NULL)
				printf("Registrador Destino: %s", aux->regDestino);
			
			if(aux->reg1 != NULL)
				printf("Registrador 1: %s", aux->reg1);

			if(aux->reg2 != NULL)
				printf("Registrador 2: %s", aux->reg2);

			if(aux->imediato != 0)
				printf("Imediato: %d", aux->imediato);

			aux = aux->prox;
			k++;

		}			
	}

}

/* 
 * @function void ler()
 * @abstract REALIZA A LEITURA DO ARQUIVO ASM DE ENTRADA
 * SEPARA TODAS AS INSTRUÇÕES, OPERANDOS, IMEDIATOS 
 * INSERINDO TODOS EM UM NOVO ARQUIVO "saida.txt"
 */
void ler(){

    FILE* arq_asm = fopen("arq.asm", "r");
    FILE* saida = fopen("saida.txt", "w");

    char atual;

    atual = fgetc(arq_asm);

    while(atual != EOF){
            
        if(atual == ' ' || atual == ',' || atual == '\n')
            atual = fgetc(arq_asm);

        else if(atual == '$'){

            while((atual != ',') && (atual != '\n') && (atual != EOF)){

                fprintf(saida, "%c",atual);
                atual = fgetc(arq_asm);

            }

            fputs("\n", saida);

        }

        else{

            while(atual != ' '){

                fprintf(saida, "%c", atual);
                atual = fgetc(arq_asm);

            }

            fputs("\n", saida);
            atual = fgetc(arq_asm);

        }
    }

	fclose(saida);
    fclose(arq_asm);

}

/* 
 * @function void inserirElementos()
 * @abstract À PARTIR DO ARQUIVO GERADO EM ler()
 * PEGA TODAS AS INSTRUÇÕES, OPERADORES, IMEDIATOS
 * E OS INSERE NA FILA DE ACORDO COM SEU RESPECTIVO CAMPO
 */
void inserirElementos(FILA *F){

	FILE* saida = fopen("saida.txt", "r");

	if(saida == NULL)
		printf("Não foi possível abrir o arquivo");

	int i = 0;
    char str[7];

    while(fgets(str, 7, saida) != NULL){

        if(str[0] == '$'){
			
			//é um registrador destino ou operando
			//inserir str em fila->valor ou fila->regDestino
			i++;

			if(i == 1)
				queueInRegDest(F, str);

			if(i == 2)
				queueInReg1(F, str);
			
			if(i == 3)
				queueInReg2(F, str);	

		}
		
		else if(isdigit(str[0])){

			unsigned int valor = atoi(str);
			queueInImediato(F, valor);

		}

		else{

			i = 0;
			queueInInst(F, str);

		}
		

    }

    fclose(saida);
	
}