#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "includes/executionQueue.h"

typedef struct exeQueue{
    char *instructionName;
    int imediato;
	char *regDestino, *reg1, *reg2;
    struct exeQueue *prox;
};

typedef struct fila{
	NO *inicio, *fim;
};

void create(FILA *F){
	F->inicio = NULL;
	F->fim = NULL;
}

/*
fila *alocar(char *nome,int dado1, int dado2, int dest){
	fila *novo = (fila *) malloc(sizeof(fila));
	if(novo != NULL){
		strcpy(novo->instructionName,nome);
		novo->reg1 = dado1;
		novo->imediato = dado2;
		novo->regDestino = dest;
		novo->prox = NULL;
	}
	return novo;
}

void alocarInst(char *nome){
	fila *novo = (fila *) malloc(sizeof(fila));
	if(novo != NULL){
		strcpy(novo->instructionName,nome);
		novo->prox = NULL;
	}
	return novo;
}

void alocarRegDest(fila *F, char *registrador){

	if(F != NULL){
		strcpy(F->regDestino, registrador);
	}

}

void alocarReg1(fila *F, char *registrador){

	if(F != NULL){
		strcpy(F->reg1, registrador);
	}

}

void alocarReg2(fila *F, char *registrador){

	if(F != NULL){
		strcpy(F->reg2, registrador);
	}

}

void alocarDado(fila *F, int dado){

	if(F != NULL){
		F->imediato = dado;
	}

}

void queueIn(fila *F,char *nome,int dado1, int dado2, int dest){
	fila *novo = alocar(nome,dado1,dado2,dest);
	fila *aux;
	aux = F;
	while (aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = novo;
}
*/
void queueInInst(FILA *F,char *nome){

	NO *novo;
	novo = (NO*) malloc(sizeof(NO));
	strcpy(novo->instructionName, nome);
	novo->prox = NULL;
	if(!F->inicio)
		F->inicio = novo;
	else
		F->fim->prox = novo;
	F->fim = novo;
	
}

void queueInRegDest(FILA *F, char* reg){

	strcpy(F->fim->regDestino, reg);

}

void queueInReg1(FILA *F, char* reg){
	
	strcpy(F->fim->reg1, reg);

}

void queueInReg2(FILA *F, char* reg){

	strcpy(F->fim->reg2, reg);

}

void queueInImediato(FILA *F, int imediato){

	F->fim->imediato = imediato;

}

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

void printQueue(FILA *F){
	NO *aux = F->inicio;
	int k = 1;
	if(aux == NULL){
		printf("FIla vazia!\n");
	}
	else{
		printf("Inicio --> ");
		while(aux != NULL){
			printf("Posição da fila: %d => Nome: %s , reg1: %s , reg2: %s , ValorDestino: %s, imediato: %d \n",k,aux->instructionName,aux->reg1,aux->reg2,aux->regDestino, aux->imediato);
			aux = aux->prox;
			k++;
		}			
	}
}

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

void inserirElementos(){

	FILE *saida = fopen("saida.txt", "r");

	int i;
    char str[6];

	FILA F;
	create(&F);

    while(!feof(saida)){

        fgets(str, 6, saida);

        if(str[0] == '$'){
			
			//é um registrador destino ou operando
			//inserir str em fila->valor ou fila->regDestino
			i++;

			if(i == 1)
				queueInRegDest(&F, str);

			else if(i == 2)
				queueInReg1(&F, str);
			
			else
				queueInReg2(&F, str);	

		}
		
		else if(isdigit(str[0])){

			int valor = atoi(str);
			queueInImediato(&F, valor);

		}

		else{

			i = 0;
			queueInInst(&F, str);

		}
		

    }

    fclose(saida);
}