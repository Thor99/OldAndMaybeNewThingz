#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/* Mapear o index de todos os elementos que tem valor 0, e depois, para cada elemento que não tenha valor 0, achar a menor distancia
para um elemento que tenha valor 0 */

int main(){
	int tam;
	scanf("%d", &tam);

	vector<int> vetorFitaInicial;
	vector<int> indexDosZeros;
	vector<int> distMinDoZero;

	for(int i = 0; i < tam; i++){
		int valor;
		scanf("%d", &valor);

		if(valor == 0){
			indexDosZeros.push_back(i);
		}

		vetorFitaInicial.push_back(valor);
	}

	for(int i = 0; i < tam; i++){
		distMinDoZero.push_back(999999);
	}

	for(int i = 0; i < tam; i++){
		if(vetorFitaInicial[i] != 0){
			for(int j = 0; j < indexDosZeros.size(); j++){
				/* Para cada elemento do array, verá qual a distancia mínima para um elemento que tenha valor 0, dentre todos os 
				fornecidos no indexDosZeros */
				distMinDoZero[i] = abs(min(distMinDoZero[i], indexDosZeros[j] - i));
			}
		} else {
			distMinDoZero[i] = 0;
		}
	}

	for(int i = 0; i < tam; i++){
		printf("%d ", distMinDoZero[i]);
	}
}