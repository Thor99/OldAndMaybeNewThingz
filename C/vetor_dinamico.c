#include <stdio.h>
#include <stdio.h>

struct vetor{
	int* valores;
	int tamanho;
};

typedef struct vetor Vetor;

Vetor cria_vetor(){
	Vetor v;
	v.valores = NULL;
	v.tamanho = 0;
	return v;
}

void insere_valor(Vetor* v, int valor){
	int tamanho_antigo = v->tamanho;
	int tamanho_novo = tamanho_antigo + 1;
	int i;
	int* vetor_novo; //cria um novo vetor de numeros com os numeros do vetor antigo + 1 valor
	vetor_novo = malloc(tamanho_novo * sizeof(int)); //tamanho do vetor novo na memoria
	
	for(i = 0; i < tamanho_antigo; i++){
		vetor_novo[i] = v->valores[i]; //índice i de p = índice i de vetor valores
	}
	
	vetor_novo[tamanho_antigo] = valor; // Adiciona o elemento novo, depois dos antigos
	
	free(v->valores); // Free libera a memória
	
	v->tamanho = tamanho_novo; //novo tamanho de v = tamanho_novo
	v->valores = vetor_novo;	// Altera a lista de valores do Vetor v
}


int main(){
	int i;

	Vetor v = cria_vetor();

	insere_valor(&v, 1);
	insere_valor(&v, 2);
	
	printf("Elementos do vetor dinâmico: \n");
	for(i=0; i < v.tamanho; i++){
		printf("%d\n", v.valores[i]);
	}
	return 0;
}