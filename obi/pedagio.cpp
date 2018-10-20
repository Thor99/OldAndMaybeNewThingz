#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

/* Fazer BFS no vertice que a familia ta, e percorrer o vetor de distancia pra ver os que são <= numero maximo de pedagios */

queue<int> Q;
int peso = 1;
int INF = -1;
vector<vector<int> > listAdj(60);
int dist[60];

void bfs(int v){
	dist[v] = 0;
	Q.push(v);

	while(!(Q.empty())){
		int atual = Q.front();
		Q.pop();

		for(int i = 0; i < listAdj[atual].size(); ++i){
			if(dist[listAdj[atual][i]] == INF){
				dist[listAdj[atual][i]] = dist[atual] + peso;
				Q.push(listAdj[atual][i]);
			}
		}
	}
}

int main(){
	int nVertices, nArestas, verticeQueSeEncontra, maxPedagios, teste=1;

	while(scanf("%d %d %d %d", &nVertices, &nArestas, &verticeQueSeEncontra, &maxPedagios) == 4 && nVertices != 0){
		printf("Teste %d\n", teste++);
		memset(dist, INF, sizeof(dist)); // A cada teste reseta o vetor de distancias pra INF
		for(int i = 0; i < 60; ++i) listAdj[i].clear(); // A cada teste reseta a lista de adjacencia 

		for(int i = 0; i < nArestas; ++i){
			int ini, fim;
			scanf("%d %d", &ini, &fim);

			listAdj[ini].push_back(fim);
			listAdj[fim].push_back(ini);
		}

		bfs(verticeQueSeEncontra);

		// Printa as cidades que precisa pegar um numero menor ou igual ao maxPedagios, e que essa dist não seja -1
		for(int vertice = 1; vertice <= nVertices; ++vertice){
			if(vertice != verticeQueSeEncontra && dist[vertice] != -1 && dist[vertice] <= maxPedagios){
				printf("%d ", vertice);
			}
		}

		printf("\n\n");
	}
}
