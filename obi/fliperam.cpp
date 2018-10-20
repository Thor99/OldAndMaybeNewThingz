#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int nPartidas, nMostrador;
	vector<int> pontos;

	scanf("%d %d", &nPartidas, &nMostrador);

	for(int i = 0; i < nPartidas; ++i){
		int ponto;
		scanf("%d", &ponto);

		pontos.push_back(ponto);
	}

	sort(pontos.rbegin(), pontos.rend()); // Sort decrescente

	for(int i = 0; i < nMostrador; ++i){
		printf("%d\n", pontos[i]);
	}
}