#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue{
	int valor;
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


fila *alocar(int dado){
	fila *novo = (fila *) malloc(sizeof(fila));
	if(novo != NULL){
		novo->valor = dado;
		novo->proximo = NULL;
	}
	return novo;
}

void queueIn(fila *F,int elemento){
	fila *novo = alocar(elemento);
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
