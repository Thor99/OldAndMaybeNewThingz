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

int busca_bin (int*v, int n, int valor)
{
	int ini = 0;
	int fim = n-1;
	int meio;

	while(ini<=fim)
	{
		meio = (ini+fim)/2;
		if(v[meio]==valor)
		{
			return 1;
		}
		if(v[meio]<valor)
		{
			ini = meio + 1;
		}
		else //v[meio]>valor
		{
			fim = meio -1;
		}
	}
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
	int num_nos;
	if(a == arv_vazia()){
		return 0;
	} else {
		num_nos = conta_valores(a->esq) + conta_valores(a->dir) + 1;
	}

	return num_nos;
}
int main(){
	int numValores;
	Arv* a = arv_vazia();
	a = insere_ord(a, 9);
	a = insere_ord(a, 4);
	a = insere_ord(a, 2);
	a = insere_ord(a, 8);
	a = insere_ord(a, 3);

	numValores = conta_valores(a);
	printf("%d", numValores);

}