#include <cstdio>
#define MAXVET 10000

/* Algortimo de busca em um vetor ordenado */

/* Consideramos o vetor indexado de 0 a N-1 */

int tam, numeroAProcurar, vet[MAXVET];

int buscab(int numero){
	int ini=0, fim=tam-1, meio;

	while(ini <= fim){ // Enquanto ainda pleo menos um elemento no intervalo
		meio = (ini + fim) / 2;

		if(numero == vet[meio]){
			if(vet[meio - 1] == vet[meio]){
				fim = meio - 1;
			} else {
				return meio;
			}
		} 

		if(numero < vet[meio]) fim = meio - 1; // se o número está atrás do meio, olho para o intervalo antes do meio

		if(numero > vet[meio]) ini = meio + 1; // se o número está na frente do meio, olho para o intervalo depois do meio
	}

	return -1;
}

int main(){
	scanf("%d %d", &tam, &numeroAProcurar);

	for(int i = 0; i < tam; ++i) scanf("%d", &vet[i]);

	printf("Index da primeira aparição de %d: %d\n", numeroAProcurar, buscab(numeroAProcurar));
}