#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 100100

using namespace std;

int main(){
	int arquivos[MAX];
	int nArquivos, capacidadeMax;
	int nPastas = 0;

	scanf("%d %d", &nArquivos, &capacidadeMax);

	for(int i = 1; i <= nArquivos; i++){
		scanf("%d", &arquivos[i]);
	}

	// Sort crescente
	sort(arquivos+1, arquivos+nArquivos+1); // + 1 porque usamos os index como os verdadeiros numeros dos arquivos

	int menor = 1;

	for(int i = nArquivos; i >= menor; i--){
		nPastas++;

		if(arquivos[i] + arquivos[menor] <= capacidadeMax){
			menor++; // "Retiramos" o menor.
		}
	}

	printf("%d\n", nPastas);
}