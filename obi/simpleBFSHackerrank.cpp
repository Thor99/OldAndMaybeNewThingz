#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>

#define MAXN 1000 // Maximo de vertices
#define INF 6001 // PESO * MAXN + 1

using namespace std;

queue<int> Q;
int peso = 6;
vector<vector<int> > listAdj(MAXN);
int dist[MAXN];

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
	int nTests;

	scanf("%d", &nTests);

	for(int t = 0; t < nTests; t++){
		for(int i = 0; i < MAXN; ++i) dist[i] = INF; // A cada teste deixamos o vetor de distancias como infinito
		for(int i = 0; i < MAXN; ++i) listAdj[i].clear(); // A cada teste limpamos o grafo

		int nNodes, nEdges, nodeToAnalyze;
		scanf("%d %d", &nNodes, &nEdges);

		for(int i = 0; i < nEdges; ++i){
			int start, end;
			scanf("%d %d", &start, &end);

			listAdj[start].push_back(end);
			listAdj[end].push_back(start);
		}

		scanf("%d", &nodeToAnalyze);

		bfs(nodeToAnalyze);

		for(int i = 1; i <= nNodes; ++i){
			if(i != nodeToAnalyze){ // Não printar a distancia dele para ele mesmo.
				if(dist[i] == INF){ // Se o nodeToAnalyze não consegue chegar no vertice em questão, printar -1
					printf("-1 ");
				} else { // Senão, printar a distancia de nodeToAnalyze para i
					printf("%d ", dist[i]);
				}
			}
		}

		printf("\n"); // \n antes de outro teste
	}
}