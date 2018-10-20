#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estudaremos Árvore  do tipo: Árvore binária
// Nesse tipo de árvore, cada nó só pode ter até dois filhos, um da esquerda e um da direita
// Em qualquer tipo de árvore, um filho só pode ter um pai.
// Árvore é criada de baixo pra cima
// Quando um nó não tem filhos, ele é chamado de folha

struct arv{
	char valor[100];
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv; // Arv é um nó

Arv* arv_vazia(){
	return NULL;
}

Arv* cria_arv(char* valor, Arv* esq, Arv* dir){
	Arv* no = malloc(sizeof(Arv));
	strcpy(no->valor, valor);
	no->esq = esq;
	no->dir = dir;
	
	return no;
}

void imprime_arv(Arv* a){ // imprime (valor esq dir)
	if(a == arv_vazia()){
		printf("-");
		return;
	}
	
	printf("(%s ", a->valor);
	imprime_arv(a->esq);
	printf(" ");
	imprime_arv(a->dir);
	printf(")");
}

Arv* destroi_arv(Arv* a){
	if(a != arv_vazia()){
		destroi_arv(a->esq);
		destroi_arv(a->dir);
		free(a);
	}
	
	return arv_vazia();
}

int busca_arv(Arv* a, char* valor){
	if(a == arv_vazia()){
		return 0;
	}
	
	if(strcmp(a->valor, valor) == 0){
		return 1;
	} else {
		if(busca_arv(a->esq, valor) == 1){
			return 1;
		}
		if(busca_arv(a->dir, valor) == 1){
			return 1;
		}
	}
	
	return 0;
}

int main(){
	Arv* a4 = cria_arv("Botelho", arv_vazia(), arv_vazia());			
	Arv* a5 = cria_arv("Louis", arv_vazia(), arv_vazia());
	Arv* a6 = cria_arv("DogAmaLinux", arv_vazia(), arv_vazia());
	Arv* a2 = cria_arv("Freips", a4, a5);
	Arv* a3 = cria_arv("Famb", a6, arv_vazia());
	Arv* a1 = cria_arv("Thor", a2, a3);
	
	imprime_arv(a1);
	
	if(busca_arv(a1, "thorAmaWindows") == 1){
		printf("Achamos!");
	}else{
		printf("Nao encontramos");
	}
}