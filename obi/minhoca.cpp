#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100

using namespace std;

int main(){
	int matriz[MAX][MAX];
	int nLinhas, nColunas;
	int sum;
	vector<int> somas;

	scanf("%d %d", &nLinhas, &nColunas);

	for(int i = 0; i < nLinhas; ++i){
		for(int j = 0; j < nColunas; ++j){
			scanf("%d", &matriz[i][j]);
		}
	}

	/* Soma Colunas */
	for(int j = 0; j < nColunas; ++j){
		sum = 0;
		for(int i = 0; i < nLinhas; ++i){
			sum += matriz[i][j];
		}
		somas.push_back(sum);
	}

	/* Soma Linhas */
	for(int i = 0; i < nLinhas; ++i){
		sum = 0;
		for(int j = 0; j < nColunas; ++j){
			sum += matriz[i][j];
		}
		somas.push_back(sum);
	}

	sort(somas.rbegin(), somas.rend()); // Ordenação decrescente

	printf("%d", somas[0]);
}