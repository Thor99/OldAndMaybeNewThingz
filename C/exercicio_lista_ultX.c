#include <stdio.h>
#include <stdlib.h>

struct Lista { 
	int valor;
	struct Lista* prox; 
};

typedef struct Lista L; // apelido pra "struct Lista" = "L"

L* cria_lista() {  // L* aponta para um nó da struct Lista //// nó =nbvczxespaço do vetor, slot
	return NULL;
}

L* insere_valor(L* lista, int valor_para_inserir) {
	L* novo_no = malloc(sizeof(L)); // sizeof struct Lista, que é composto por um ponteiro que aponta pra uma nova instancia e um valor.
	novo_no->valor = valor_para_inserir; // Usa -> para representar o "." (como em novo.valor) só que pra ponteiros. Poderia usar (*novo_no).valor também
	novo_no->prox = lista; // Retorna o primeiro valor atual da lista
	return novo_no;
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

L* remove_valor(L* lista, int valor){
	L* anterior = lista; // Guardar o nó (lista) anterior
	L* primeira = lista;
	while(lista != NULL) {
		if(lista->valor == valor) {
			anterior->prox = lista->prox;
			free(lista);
			if(lista == primeira){
				return anterior->prox;
			} else {
				return primeira;
			}
		}
		anterior = lista;
		lista = lista->prox;
	}
	return primeira;
}

L* separa (L* lista, int n) {
	L* nova1 = busca_valor(lista, n); // retorna um nó que possui prox, valor.
	L* nova2 = nova1->prox; // O novo nó será o nó depois de nova1. Esse nó terá o restante da lista.
	nova1->prox = NULL; // Fecha a nova lista, botando o prox do nó como NULL
	return nova2;
}

void imprime_lista(L* lista) { // Lembrando que lista é nó
	while(lista != NULL) {
		printf("%d ->", lista->valor);
		lista = lista->prox;
	}
	printf("NULL\n");
}

L* ultimo_x(L* lista, int x){
	L* ultimoNo = NULL;
	while(lista != NULL){
		if(lista->valor == x){
			ultimoNo = lista;
		}
		lista = lista->prox;
	}
	return NULL;
} 

int main() {
	L* lista = cria_lista();
	L* ult;
	lista = insere_valor(lista, 1);
	lista = insere_valor(lista, 2);
	lista = insere_valor(lista, 3);
	lista = insere_valor(lista, 3);
	lista = insere_valor(lista, 4);
	lista = insere_valor(lista, 5);
	lista = insere_valor(lista, 6);

	
	return 0;
}