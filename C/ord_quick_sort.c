#include <stdlib.h>
#include <stdio.h>

// Quick sort
// Ao invés de fazer usualmente N ** 2 operações, ele faz N log N operações
// Já temos essa função em C: qsort() 
// void qsort(int* v, int n, int tam, int (*compara)(const void*, const void*));
// v: Vetor para ser ordenado
// n: Número de elementos
// tam: Tamanho, em bytes, de cada elemento do vetor (sizeof)
// compara: Função de comparação, que compara os dois elementos. Ela retorna um inteiro, que tem uma especificação, definida pelo qsort. 
// Essa especificação é o seguinte: retorna um número menor que zero se o primeiro elemento é menor que o segundo. Retorna 0 se o primeiro elemento for igual que o segundo. Retorna um número maior que 0 se o primeiro elemento é maior que o segundo

int compara(const void* p1, const void* p2){
	int a = *(int*) p1; // Converte um void* em um int* e pega seu conteúdo
	int b = *(int*) p2; // Converte um void* em um int* e pega seu conteúdo
	
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