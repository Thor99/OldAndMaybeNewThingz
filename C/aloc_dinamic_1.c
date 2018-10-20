#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int* p;
	int tamanho;

	printf("Diga o tamanho do vetor que voc� quer: ");
	scanf("%d", &tamanho);

	p = malloc(tamanho * sizeof(int)); // no par�metro do malloc mostra quanto espa�o em bytes quer alocar no ponteiro .. sizeof(tipo) mostra quantos bytes o tipo ocupa

	for(i = 0; i < tamanho; i++) {
		p[i] = i * i;
	}

	for(i = 1; i <= tamanho; i++) {
		printf("%d\n", p[tamanho - i]); //imprime o vetor na ordem decrescente
	}

	free(p); //liberar a mem�ria que o ponteiro usa

	return 0;
}