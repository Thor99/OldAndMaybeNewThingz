#include <stdio.h>
#include <stdio.h>


struct Lista { // lista == n�
	int valor;
	struct Lista* prox; // ponteiro que aponta pra outra instancia da struct Lista
};

typedef struct Lista L; // apelido pra "struct Lista"

L* cria_lista() {  // L* aponta para um n� da struct Lista //// n� =nbvczxespa�o do vetor, slot
	return NULL;
}

L* insere_valor(L* lista, int valor_para_inserir) {
	L* novo_no = malloc(sizeof(L)); // sizeof struct Lista, que � composto por um ponteiro que aponta pra uma nova instancia e um valor.
	novo_no->valor = valor_para_inserir; // Usa -> para representar o "." (como em novo.valor) s� que pra ponteiros. Poderia usar (*novo_no).valor tamb�m
	novo_no->prox = lista; // Retorna o primeiro valor atual da lista
	return novo_no;
}

void imprime_lista(L* lista) { // Lembrando que lista � n�
	while(lista != NULL) {
		printf("%d ->", lista->valor);
		lista = lista->prox;
	}
	printf("NULL\n");
}

void dobra_valores(L* lista){
	while(lista != NULL){
		lista->valor = lista->valor * 2;
		lista = lista->prox;
	}
}

int main(){
	L* lista = cria_lista();
	lista = insere_valor(lista, 1);
	lista = insere_valor(lista, 2);
	lista = insere_valor(lista, 3);
	dobra_valores(lista);
	imprime_lista(lista);
	return 0;
}