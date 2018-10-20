#include <stdio.h>
#include <stdlib.h>

struct Lista { 
	int valor;
	struct Lista* prox; 
};

typedef struct Lista L; // apelido pra "struct Lista"

L* cria_lista() {  // L* aponta para um n� da struct Lista //// n� =nbvczxespa�o do vetor, slot
	return NULL;
}

L* busca_valor(L* lista, int valor) {
	while(lista != NULL) {
		if(lista->valor == valor){
			return lista;
		}
		lista = lista->prox;
	}
	return NULL;
}

L* insere_valor(L* lista, int valor_para_inserir) {
	L* novo_no = malloc(sizeof(L)); // sizeof struct Lista, que � composto por um ponteiro que aponta pra uma nova instancia e um valor.
	novo_no->valor = valor_para_inserir; // Usa -> para representar o "." (como em novo.valor) s� que pra ponteiros. Poderia usar (*novo_no).valor tamb�m
	novo_no->prox = lista; // Retorna o primeiro valor atual da lista
	return novo_no;
}

L* separa (L* lista, int n) {
	L* nova1 = busca_valor(lista, n); // retorna um n� que possui prox, valor.
	L* nova2 = nova1->prox; // O novo n� ser� o n� depois de nova1. Esse n� ter� o restante da lista.
	nova1->prox = NULL; // Fecha a nova lista, botando o prox do n� como NULL
	return nova2;
}

L* constroi(int n, int* v){ // recebe um vetor e constroi uma nova lista com os elementos desse vetor, do primeiro ao ultimo. 
	int i;
	L* lista;
	lista = cria_lista();
	for(i = n - 1; i >= 0; i--){
		lista = insere_valor(lista, v[i]);
	}
	
	return lista;
}

void imprime_lista(L* lista) { // Lembrando que lista � n�
	while(lista != NULL) {
		printf("%d ->", lista->valor);
		lista = lista->prox;
	}
	printf("NULL\n");
}

int main() {
	L* lista;
	int v[5] = {1, 2, 3, 7, 9};
	lista = constroi(5, v);
	
	imprime_lista(lista);
	
	return 0;
}