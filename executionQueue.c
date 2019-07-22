#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/executionQueue.h"

struct exeQueue{
    char *instructionName;
    int valor1,valor2,regDestino;
    struct exeQueue *prox;
};

fila* create (){
	fila *F;
	F = (fila*) calloc(1,sizeof(fila));
	if(F != NULL){
		F->prox = NULL;
	}
	return F;
}

fila *alocar(char *nome,int dado1, int dado2, int dest){
	fila *novo = (fila *) malloc(sizeof(fila));
	if(novo != NULL){
		strcpy(novo->instructionName,nome);
		novo->valor1 = dado1;
		novo->valor2 = dado2;
		novo->regDestino = dest;
		novo->prox = NULL;
	}
	return novo;
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

fila queueOut (fila* F){
	fila *excluir;
	fila *saida;
	excluir = F->prox;
	if(excluir != NULL){
		F->prox = F->prox->prox;
		saida = excluir;
		free(excluir);
		return *saida;
	}
}

void clear(fila* F){
	fila *aux; 							
	aux = F;
	while(aux->prox != NULL){
		queueOut(F);
		aux->prox = aux->prox->prox;
	}
	free(F);
	F = NULL; 
}


void printQueue(fila *F){
	fila *aux;
	aux = F->prox;
	int k = 1;
	if(aux == NULL){
		printf("FIla vazia!\n");
	}
	else{
		printf("Inicio --> ");
		while(aux != NULL){
			printf("Posição da fila: %d => Nome: %s , Valor1: %d , Valor2: %d , ValorDestino: %d \n",k,aux->instructionName,aux->valor1,aux->valor2,aux->regDestino);
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

    saida = fopen("saida.txt", "r");
    char str[6];

    while(!feof(saida)){

        fgets(str, 6, saida);

        if(str[0] == '$'){
			//é um registrador destino ou operando
			//inserir str em fila->valor ou fila->regDestino
		}
		
		else{
			//str é uma instrução
			//inserir str em fila->instructionName
		}

    }

    fclose(saida);
}