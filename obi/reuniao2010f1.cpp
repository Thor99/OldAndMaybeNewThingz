#include <cstdio>
#include <algorithm>
#define MAXV 110
#define INF 999999999

using namespace std;

int matrizAdj[MAXV][MAXV];
int dist[MAXV][MAXV];
int nVertices, nArestas;

void floydWarshall(){
	for(int k = 0; k < nVertices; ++k){
		for(int i = 0; i < nVertices; ++i){
			for(int j = 0; j < nVertices; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(){
	scanf("%d %d", &nVertices, &nArestas);

	for(int i = 0; i < nVertices; ++i){
		for(int j = 0; j < nVertices; ++j){
			if(i == j){
				matrizAdj[i][j] = 0;
			} else {
				matrizAdj[i][j] = INF;
			}
		}
	}

	for(int i = 0; i < nArestas; ++i){
		int ini, fim, peso;
		scanf("%d %d %d", &ini, &fim, &peso);

		matrizAdj[ini][fim] = min(matrizAdj[ini][fim], peso);
		matrizAdj[fim][ini] = min(matrizAdj[fim][ini], peso);
	}

	for(int i = 0; i < nVertices; ++i){
		for(int j = 0; j < nVertices; ++j){
			dist[i][j] = matrizAdj[i][j];
		}
	}

	floydWarshall();

	/* Acha menor distancia maxima */
	int menorDistMax = INF;
	for(int i = 0; i < nVertices; ++i){
		int maiorDaLinha = -1;
		for(int j = 0; j < nVertices; ++j){
			if(dist[i][j] > maiorDaLinha){
				maiorDaLinha = dist[i][j];
			}
		}
		if(maiorDaLinha < menorDistMax){
			menorDistMax = maiorDaLinha;
		}
	}

	printf("%d", menorDistMax);
}