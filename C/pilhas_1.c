#include <stdio.h>
#include <stdlib.h>

/* 
Last in, first out: último que entrou é o primeiro a sair.

Só pode fazer duas operações na pilha, push e pop

Push: Insere valor no topo ;  Pop: Remove valor do topo

Podemos implementar com vetores ou listas.

Listas tem a vantagem de não precisarem ter um tamanho pré definido.
*/ 

struct Lista{
	int valor;
	struct Lista* prox;
};

typedef struct Lista L;

struct Pilha{
	L* topo;
};

typedef struct Pilha P;

L* cria_lista() { 
	return NULL;
}

L* insere_valor(L* lista, int valor_para_inserir) {
	L* novo_no = malloc(sizeof(L));
	novo_no->valor = valor_para_inserir; 
	novo_no->prox = lista; 
	return novo_no;
}

void imprime_lista(L* lista) { // Lista é tipo um nó
	while(lista != NULL) {
		printf("%d ->", lista->valor);
		lista = lista->prox;
	}
	printf("NULL\n");
}

P* cria_pilha(){
	P* pilha = malloc(sizeof(P));	// Cria um bloco de memória com o tamanho de uma struct Pilha
	pilha->topo = cria_lista();
	return pilha;
}

void push(P* pilha, int valor){
	pilha->topo = insere_valor(pilha->topo, valor); // pilha->topo é do tipo L*
}

void pop(P* pilha){
	L* no_temp = pilha->topo; // Variavel temporaria pro topo da pilha
	if(pilha->topo == NULL){
		return;
	}
	pilha->topo = pilha->topo->prox;
	free(no_temp);
}

int valor_topo(P* pilha){
	return pilha->topo->valor;
}

void libera_lista(L* lista){
	L* tmp;
	while(lista != NULL){
		tmp = lista;
		lista = lista->prox;
		free(tmp);
	}
}

void libera_pilha(P* pilha){
	libera_lista(pilha->topo);
	free(pilha); 
}

int main(){
	P* pilha = cria_pilha();
	push(pilha, 1);
	push(pilha, 2);
	push(pilha, 3);
	pop(pilha);
	printf("%d\n", valor_topo(pilha));
	libera_pilha(pilha);
	return 0; 
}              						