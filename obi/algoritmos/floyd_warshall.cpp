#include <cstdio>
#include <algorithm>
#define MAXV 20 // Máximo de vertices é 15, damos só um espaçamento de 5
#define INF 999999999

/* Algoritmo que retorna a menor distância entre todos os pares de vértices possíveis, num grafo de arestas com pesos > 0 */

using namespace std;

int dist[MAXV][MAXV];
int nVertices;

void floydWarshall(){
	for(int k = 1; k <= nVertices; ++k){
		for(int i = 1; i <= nVertices; ++i){
			for(int j = 1; j <= nVertices; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(){
	int nArestas;

	scanf("%d %d", &nVertices, &nArestas);

	/* Inicializa a matriz de distâncias, para os grafos que não se conectarem diretamente terem distância infinita */
	for(int i = 1; i <= nVertices; ++i){
		for(int j = 1; j <= nVertices; ++j){
			// Se for a distancia de um vertice pra ele mesmo, escreve como 0, senão, infinito.
			if(i == j){
				dist[i][j] = 0;
			} else {
				dist[i][j] = INF;
			}
		}
	}

	for(int i = 0; i < nArestas; ++i){
		int ini, fim, peso;
		scanf("%d %d %d", &ini, &fim, &peso);

		dist[ini][fim] = min(dist[ini][fim], peso);
		dist[fim][ini] = min(dist[fim][ini], peso);
	}

	floydWarshall();

	for(int i = 1; i <= nVertices; ++i){
		for(int j = 1; j <= nVertices; ++j){
			printf("Distância de %d para %d = %d\n", i, j, dist[i][j]);
		}
	}

}


