#include <stdio.h>
#include <stdlib.h>

// Listas inserem o elemento pela frente

struct Lista { // lista == nó
	int valor;
	struct Lista* prox; // ponteiro que aponta pra outra instancia da struct Lista
};

typedef struct Lista L; // apelido pra "struct Lista"

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

void imprime_lista(L* lista) { // Lembrando que lista é nó
	while(lista != NULL) {
		printf("%d ->", lista->valor);
		lista = lista->prox;
	}
	printf("NULL\n");
}

void libera_lista(L* lista){
	L* tmp;
	while(lista != NULL){
		tmp = lista;
		lista = lista->prox;
		free(tmp);
	}
}

int main() {
	L* lista = cria_lista();
	lista = insere_valor(lista, 1);
	lista = insere_valor(lista, 2);
	imprime_lista(lista);
	
	if(busca_valor(lista, 2) == NULL) {
		printf("Nao encontrado\n");
	} else {
		printf("Encontrado\n");
	}
	
	if(remove_valor(lista, 1)){
		printf("Removido\n");
		imprime_lista(lista);
	} else {
		printf("Valor não encontrado.\n");
	}
	return 0;
}