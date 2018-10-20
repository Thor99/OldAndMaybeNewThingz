#include <stdlib.h>
#include <stdio.h>

//Bubble sort: Você tem uma sequencia de números e quer ordena-los em ordem crescente. Você pegara cada elemento e verificará se o próximo elemento é menor que ele. Se for, trocará os dois elementos. Ao houver uma troca, o algoritmo percorre os elementos desde o inicio de novo.
//A tendêcia desse algoritmo é que se você tem um vetor de N elementos, o bubble sort vai fazer N ** 2 operações. 

void bubble_sort(int* v, int n){
	int  i;
	for(i = 0; i < n - 1; i++){ // n - 1 para ir até o penultimo para comparar com o último.
		if(v[i] > v[i + 1]){
			int tmp = v[i];
			v[i] = v[i + 1]; // v[i] assumira o valor de v[i + 1].
			v[i + 1] = tmp; // v[i + 1] assumirá o valor de v[i], que esta representado por tmp.
			i = -1; //Para voltar pro começo do vetor, após ocorrer a troca.
		}
	}
}

int main(){
	int v[] = {1, 2, 4, 3, 0, -5};
	int i;
	bubble_sort(v, 6);
	for(i = 0; i < 6; i++){
		printf("%d\n", v[i]);
	}
	return 0;
}

// Ex:
// vetor [a, b, c, d] a = 1; b = 0; c = 2; d = 3
// 1 > 0
// tmp = 1 (a);
// a = 0 (b);
// b = tmp (1);
// vetor [0, 1, 2, 3]