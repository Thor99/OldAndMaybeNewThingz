#include <stdlib.h>
#include <stdio.h>

// Quick sort
// Ao inv�s de fazer usualmente N ** 2 opera��es, ele faz N log N opera��es
// J� temos essa fun��o em C: qsort() 
// void qsort(int* v, int n, int tam, int (*compara)(const void*, const void*));
// v: Vetor para ser ordenado
// n: N�mero de elementos
// tam: Tamanho, em bytes, de cada elemento do vetor (sizeof)
// compara: Fun��o de compara��o, que compara os dois elementos. Ela retorna um inteiro, que tem uma especifica��o, definida pelo qsort. 
// Essa especifica��o � o seguinte: retorna um n�mero menor que zero se o primeiro elemento � menor que o segundo. Retorna 0 se o primeiro elemento for igual que o segundo. Retorna um n�mero maior que 0 se o primeiro elemento � maior que o segundo

int compara(const void* p1, const void* p2){
	int a = *(int*) p1; // Converte um void* em um int* e pega seu conte�do
	int b = *(int*) p2; // Converte um void* em um int* e pega seu conte�do
	
	return a - b;    // Ordem crescente.
	
	//return b - a; // Ordem decrescente.
}
int main(){
	int v[] = {1, 22, -6, 68, -58};
	int i;
	qsort(v, 5, sizeof(int), compara);
	for(i = 0; i < 5; i++){
		printf("%d\n", v[i]);
	}
	return 0;
}