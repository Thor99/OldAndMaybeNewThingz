#include <stdio.h>
#include <stdlib.h>

// estudaremos Árvore  do tipo: Árvore binária
// Nesse tipo de árvore, cada nó só pode ter até dois filhos, um da esquerda e um da direita
// Em qualquer tipo de árvore, um filho só pode ter um pai.
// Árvore é criada de baixo pra cima
// Quando um nó não tem filhos, ele é chamado de folha

struct arv{
	int valor;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv; // Arv é um nó

Arv* arv_vazia(){
	return NULL;
}

Arv* cria_arv(int valor, Arv* esq, Arv* dir){
	Arv* no = malloc(sizeof(Arv));
	no->valor = valor;
	no->esq = esq;
	no->dir = dir;

	return no;
}

void imprime_arv(Arv* a){ // imprime (valor esq dir)
	if(a == arv_vazia()){
		printf("-");
		return;
	}

	printf("(%d ", a->valor);
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

int busca_arv(Arv* a, int valor){
	if(a == arv_vazia()){
		return 0;
	}

	if(a->valor == valor){
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

Arv* copia(Arv* a1){
	if(a1 == arv_vazia()){
		return NULL;
	} else{
		return cria_arv(a1->valor, copia(a1->esq), copia(a1->dir));
	}
}

int igual(Arv* a1, Arv* a2){

	if(a1 == arv_vazia() && a2 == arv_vazia()){
		return 1;
	}

	return a1->valor == a2->valor && igual(a1->esq, a2->esq) && igual(a1->dir, a2->dir); // Se todos retornarem 1, são iguais
}

int main(){
	Arv* a4 = cria_arv(4, arv_vazia(), arv_vazia());
	Arv* a5 = cria_arv(5, arv_vazia(), arv_vazia());
	Arv* a6 = cria_arv(6, arv_vazia(), arv_vazia());
	Arv* a2 = cria_arv(2, a4, a5);
	Arv* a3 = cria_arv(3, a6, arv_vazia());
	Arv* a1 = cria_arv(1, a2, a3);

	Arv* ac4 = cria_arv(3, arv_vazia(), arv_vazia());
	Arv* ac5 = cria_arv(5, arv_vazia(), arv_vazia());
	Arv* ac6 = cria_arv(6, arv_vazia(), arv_vazia());
	Arv* ac2 = cria_arv(2, ac4, ac5);
	Arv* ac3 = cria_arv(3, ac6, arv_vazia());
	Arv* ac1 = cria_arv(1, ac2, ac3);


	if(igual(a1, ac1) == 1){
		printf("Árvores iguais!");
	} else {
		printf("Árvores diferentes!");
	}
}