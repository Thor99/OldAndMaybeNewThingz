#include <stdio.h>
#include <stdlib.h>

int* cria_vetor(int n) {
	int i;
	int* p = malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++) {
		p[i] = i * i;
	}
	return p;
}

int* dobro(int* v, int n) {
	int* vetor_novo = malloc(n * sizeof(int));
	int i;
	
	for(i = 0; i < n; i++) {
		vetor_novo[i] = v[i] * 2;
	}
	
	return vetor_novo;
}

int main() {
	int numero_elementos;
	int* vetor;
	int* vetor_novo;
	int i;
	
	scanf("%d", &numero_elementos);
	
	vetor = cria_vetor(numero_elementos);
	
	vetor_novo = dobro(vetor, numero_elementos);
	
	for(i = 1; i <= numero_elementos; i++) {
		printf("%d\n", vetor_novo[numero_elementos - i]);
	}
	
	free(vetor);
	free(vetor_novo);
	
	return 0;	
}