#include <stdio.h>
#include <stdlib.h>

// estudaremos �rvore  do tipo: �rvore bin�ria
// Nesse tipo de �rvore, cada n� s� pode ter at� dois filhos, um da esquerda e um da direita
// Em qualquer tipo de �rvore, um filho s� pode ter um pai.
// �rvore � criada de baixo pra cima
// Quando um n� n�o tem filhos, ele � chamado de folha

struct arv{
	int valor;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv; // Arv � um n�

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


int main(){
	Arv* a4 = cria_arv(4, arv_vazia(), arv_vazia());
	Arv* a5 = cria_arv(5, arv_vazia(), arv_vazia());
	Arv* a6 = cria_arv(6, arv_vazia(), arv_vazia());
	Arv* a2 = cria_arv(2, a4, a5);
	Arv* a3 = cria_arv(3, a6, arv_vazia());
	Arv* a1 = cria_arv(1, a2, a3);

	Arv* ac1 = copia(a1);


	imprime_arv(ac1);
}