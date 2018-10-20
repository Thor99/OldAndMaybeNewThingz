#include <stdio.h>
#include <stdlib.h>

struct item{
	int grupo;
	char nome[50];
};

typedef struct item Item;

int compara(const void* a, const void* b){
	Item* i1 = (Item*) a;
	Item* i2 = (Item*) b;

	if(i1->grupo == i2->grupo){
		return strcmp(i1->nome, i2->nome); // -1 se i1->nome < i2->nome; 1 se i1->nome > i2->nome; 0 se i1->nome == i2->nome
	} else {
		return i1->grupo - i2->grupo;
	}

}

int main(){
	int entradas;
	int i;
	Item* itens;
	printf("Insira o número de entradas: ");
	scanf("%d", &entradas);

	itens = malloc(entradas * sizeof(Item));

	for(i = 0; i < entradas; i++){
		scanf("%d %s", &itens[i].grupo, &itens[i].nome);
	}

	qsort(itens, entradas, sizeof(Item), compara);

	for(i = 0; i < entradas; i++){
		printf("Grupo: %d ---------- Nome: %s\n", itens[i].grupo, itens[i].nome);
	}

	return 0;
}