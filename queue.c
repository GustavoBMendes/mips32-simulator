#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/queue.h"

struct queue{
	char *nomeInstrucao;
	int valor1,valor2;
	int reg_destino;
	struct queue *proximo;
};

fila* create (){
	fila *F;
	F = (fila*) calloc(1,sizeof(fila));
	if(F != NULL){
		F->proximo = NULL;
	}
	return F;
}


fila *alocar(char *nome_instrucao,int valor1,int valor2, int reg_destino){
	fila *novo = (fila *) malloc(sizeof(fila));
	if(novo != NULL){
		strcpy(nomeInstrucao,nome_instrucao);
		novo->valor1 = valor1;
		novo->valor2 = valor2;
		novo->reg_destino = reg_destino;
		novo->proximo = NULL;
	}
	return novo;
}

void queueIn(fila *F,char *nome_instrucao,int valor1,int valor2, int reg_destino){
	fila *novo = alocar(nome_instrucao,valor1,valor2,reg_destino);
	fila *aux;
	aux = F;
	while (aux->proximo != NULL){
		aux = aux->proximo;
	}
	aux->proximo = novo;
}


int queueOut (fila* F){
	fila *excluir;
	int saida;
	excluir = F->proximo;
	if(excluir != NULL){
		F->proximo = F->proximo->proximo;
		saida = excluir->valor;
		free(excluir);
		return saida;
	}
}

void clear(fila* F){
	fila *aux; 							
	aux = F;
	while(aux->proximo != NULL){
		queueOut(F);
		aux->proximo = aux->proximo->proximo;
	}
	free(F);
	F = NULL; 
}


void printQueue(fila *F){
	fila *aux;
	aux = F->proximo;
	if(aux == NULL){
		printf("FIla vazia!\n");
	}
	else{
		printf("Inicio --> ");
		while(aux != NULL){
			printf("%d ",aux->valor);
			aux = aux->proximo;
		}			
	}
}
