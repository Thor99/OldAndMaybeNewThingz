#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/* Problema consiste em achar o index da primeira ocorrencia de um numero num array, usando busca binária. */

vector<int> vec;

int busca_bin_first_index(int n){
	int ini = 0;
	int fim = vec.size() - 1;

	while(ini <= fim){
		int meio = (ini + fim) / 2;

		if(n == vec[meio]){
			if(vec[meio - 1] == vec[meio]){
				fim = meio - 1; // Se o elemento anterior for igual ao vec[meio], refazemos a busca com fim = meio - 1
			} else {
				return meio;
			}
		}

		else if(n > vec[meio]){
			ini = meio + 1;
		}

		else { // n < vec[meio]
			fim = meio - 1;
		}
	}

	return -1;
}

int main(){
	int teste = 1;
	int nMarmores, nConsultas;

	while(scanf("%d %d", &nMarmores, &nConsultas) == 2 && nMarmores != 0){
		printf("CASE# %d:\n", teste);

		vec.reserve(nMarmores);

		for(int i = 0; i < nMarmores; i++){
			int valor;
			scanf("%d", &valor);

			vec.push_back(valor);
		}

		// Sort cescente
		sort(vec.begin(), vec.end());

		for(int i = 0; i < nConsultas; i++){
			int numero;
			scanf("%d", &numero);

			int index = busca_bin_first_index(numero);

			if(index == -1){
				printf("%d not found\n", numero);
			} else {
				printf("%d found at %d\n", numero, index + 1); // Index + 1 porque pede a posição
			}
		}

		teste++;

		vec.clear();
	}
}