#include <stdio.h>
#include <stdlib.h>

/* 
FIFO(first in - first out) 
Acessamos o elemento de cima e o de baixo	
Novos valores são inseridos pelo fim.
*/

struct Lista{
	int valor;
	struct Lista* prox;
};

typedef struct Lista L;

struct Fila{
	struct Lista* ini;
	struct Lista* fim;
};

typedef struct Fila F;

L* cria_lista() { 
	return NULL;
}

F* cria_fila(){
	F* fila = malloc(sizeof(F));
	fila->ini = cria_lista();
	fila->fim = cria_lista();
	return fila;
}

void insere_valor(F* fila, int valor){
	L* no = malloc(sizeof(L));
	no->valor = valor;
	no->prox = NULL;
	if(fila->ini == NULL){ // Vai ter que ser adicionado um no tanto como ini como fim
		fila->ini = no;
		fila->fim = no;
	} else {
		fila->fim->prox = no; // Adiciona um novo nó como prox do ultimo elemento
		fila->fim = no; // Agora põe o nó como ultimo
	}
}

int remove_valor(F* fila){                         
	L* tmp = fila->ini->prox;
	int valor = fila->ini->valor;
	
	if(fila->ini == fila->fim){
		fila->fim = NULL;
	}
	
	free(fila->ini);
	fila->ini = tmp;
	return valor;
}

int main(){
	F* fila = cria_fila();
	insere_valor(fila, 1);
	insere_valor(fila, 2);
	insere_valor(fila, 3);
	printf("%d e o valor que estamos removendo\n", remove_valor(fila));
	printf("%d e o valor que estamos removendo\n", remove_valor(fila));
	printf("%d e o valor que estamos removendo\n", remove_valor(fila));
	return 0;
}