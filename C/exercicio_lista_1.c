#include <stdio.h>
#include <stdlib.h>

struct Lista { 
	int valor;
	struct Lista* prox; 
};

typedef struct Lista L; // apelido pra "struct Lista" = "L"

L* cria_lista() {  // L* aponta para um n� da struct Lista //// n� =nbvczxespa�o do vetor, slot
	return NULL;
}

L* insere_valor(L* lista, int valor_para_inserir) {
	L* novo_no = malloc(sizeof(L)); // sizeof struct Lista, que � composto por um ponteiro que aponta pra uma nova instancia e um valor.
	novo_no->valor = valor_para_inserir; // Usa -> para representar o "." (como em novo.valor) s� que pra ponteiros. Poderia usar (*novo_no).valor tamb�m
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
	L* anterior = lista; // Guardar o n� (lista) anterior
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
	L* nova1 = busca_valor(lista, n); // retorna um n� que possui prox, valor.
	L* nova2 = nova1->prox; // O novo n� ser� o n� depois de nova1. Esse n� ter� o restante da lista.
	nova1->prox = NULL; // Fecha a nova lista, botando o prox do n� como NULL
	return nova2;
}

void imprime_lista(L* lista) { // Lembrando que lista � n�
	while(lista != NULL) {
		printf("%d ->", lista->valor);
		lista = lista->prox;
	}
	printf("NULL\n");
}

int main() {
	L* lista = cria_lista();
	L* lista_nova;
	lista = insere_valor(lista, 1);
	lista = insere_valor(lista, 2);
	lista = insere_valor(lista, 3);
	lista = insere_valor(lista, 4);
	lista = insere_valor(lista, 5);
	lista = insere_valor(lista, 6);

	printf("Imprimindo a lista inicial:\n");
	imprime_lista(lista);
	
	lista_nova = separa(lista, 3);
	
	printf("Imprimindo as duas listas novas:\n");
	imprime_lista(lista);
	imprime_lista(lista_nova);
	
	return 0;
}