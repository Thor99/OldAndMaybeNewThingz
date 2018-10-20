#include <cstdio>
#include <algorithm>
#include <vector>

/* Algoritmo para encontrar o tamanho da maior LIS (maior sequencia crescente) */

using namespace std;

int main(){
	vector<int> pilha;
	int tam;

	scanf("%d", &tam);

	for(int i = 0; i < tam; ++i){
		int num;
		scanf("%d", &num);

		// declaro um iterador que guardará o elemento mais à esquerda de pilha, que tenha valor maior ou igual a num
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), num);

		// se it for o fim do vector, então todos os elementos da pilha são menores que num
		// logo, adicionaremos num no final na pilha
		if(it == pilha.end()){
			pilha.push_back(num);
		}

		// porém, se it apontar para alguma posição válida do vector substituimos o valor que it aponta por num
		else {
			*it = num;
		}

		// Com isso, teremos uma pilha ordenada crescentemente, com o tamanho da maior subsequencia crescente (LIS)
	}

	printf("%d\n", (int) pilha.size()); // Printa tamanho da LIS

	for(int i = 0; i < (int) pilha.size(); i++){ // Printa uma LIS qualquer da sequencia
		printf("%d ", pilha[i]);
	}

	printf("\n");
}