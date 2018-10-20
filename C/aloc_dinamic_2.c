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

int main() {
	int numero_elementos;
	int* vetor;
	int i;
	
	scanf("%d", &numero_elementos);
	
	vetor = cria_vetor(numero_elementos);
	
	for(i = 1; i <= numero_elementos; i++) {
		printf("%d\n", vetor[numero_elementos - i]);
	}
	
	free(vetor);
	
	return 0;
}