#include <stdio.h>
#include <stdlib.h>

struct arv{
	int valor;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv;

Arv* arv_vazia(){
	return NULL;
}

int busca_bin(int* v, int n, int valor){
    int ini = 0; // Primeiro índice do vetor
    int fim = n - 1; // Ultimo indice do vetor
    //  Se ini e fim se sobreporem, acabou o vetor e não achou o valor
    int meio;

    while(ini <= fim){
        meio = (ini + fim) / 2;
        if(v[meio] > valor){ // Busca o valor percorrendo a direita do meio
            fim = meio - 1;
        }
        else if(v[meio] < valor) { // Busca o valor percorrendo a direita do meio
            ini = meio + 1;
        }
        else{ // v[meio] == valor
            return 1;
        }
    }
    return 0; // Não encontrou o valor
}

Arv* insere_ord(Arv* a, int valor)
{
	if (a==arv_vazia())
	{
		a = malloc(sizeof(Arv));
		a->valor = valor;
		a->esq = arv_vazia();
		a->dir = arv_vazia();
		return a;
	}
	if(a->valor > valor)
	{
		a->esq = insere_ord(a->esq,valor);
	}
	else
	{
		a->dir = insere_ord(a->dir,valor);
	}
	return a;
}

int maior_no(Arv* a){
	if(a->dir == NULL){
		return a->valor;
	} else {
		return maior_no(a->dir);
	}
}

int menor_no(Arv* a){
	if(a->esq == NULL){
		return a->valor;
	} else {
		return menor_no(a->esq);
	}
}

int conta_valores(Arv* a){
	if(a == arv_vazia()){
		return 0;
	} else {
		return conta_valores(a->esq) + conta_valores(a->dir) + 1;
	}
}

int altura_de_x(Arv* a, int x){
	if(a == arv_vazia()){
		return -1;
	} else{
		if(a->valor > x){
			return 1 + altura_de_x(a->esq, x);
		}
		else if (a->valor < x){
			return 1 + altura_de_x(a->dir, x);
		}
		return 0; // a->valor == x
	}
}

int menores_que_x(Arv* a, int x){
	if(a == arv_vazia()){
		return 0;
	}
	else {

		if(a->valor == x){
			return conta_valores(a->esq); // Se o número for a raiz, teremos que ver toda aparte esquerda da arvore
		}

		if(x > a->valor){
			return menores_que_x(a->dir, x) + conta_valores(a->esq) + 1; // Os valores menores que x nesse caso serão a raiz, toda a subarvore esquerda a partir da raiz e os menores que x na subarvore direita
		}

		if(x < a->valor){
			return menores_que_x(a->esq, x);
		}
	}

}

int main(){
	int menores_que;
	Arv* a = arv_vazia();
	a = insere_ord(a, 9);
	a = insere_ord(a, 4);
	a = insere_ord(a, 2);
	a = insere_ord(a, 8);
	a = insere_ord(a, 11);
	a = insere_ord(a, 3);

	menores_que = menores_que_x(a, 11);
	printf("%d", menores_que);

}