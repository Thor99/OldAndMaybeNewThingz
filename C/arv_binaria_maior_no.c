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
int main(){
	int maior;
	Arv* a = arv_vazia();
	a = insere_ord(a, 9);
	a = insere_ord(a, 4);
	a = insere_ord(a, 2);
	a = insere_ord(a, 8);

	maior = maior_no(a);
	printf("%d", maior);

}