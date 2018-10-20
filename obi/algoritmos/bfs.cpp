#include <cstdio>
#include <queue>
#define MAXV 15 // Dizemos que o numero maximo de vertices é 15

/* Achar distancia minima de todos os vertices de um grafo com arestas de pesos iguais, para um vertice qualquer */

using namespace std;

queue<int> Q;
int peso = 1;
int dist[MAXV];
int INF = 16;
vector<vector<int> > listAdj(MAXV);

void bfs(int v){
	dist[v] = 0; // Distancia dele para ele mesmo

	Q.push(v);

	while(!(Q.empty())){ // Enquanto tiver ainda algum adjacente para ver a distancia
		int atual = Q.front();
		Q.pop();

		for(int i = 0; i < listAdj[atual].size(); ++i){ // Atualiza as distancias de todos os vizinhos do listAdj[atual], se a mesma estiver como INF
			if(dist[listAdj[atual][i]] == INF){
				dist[listAdj[atual][i]] = dist[atual] + peso;
				Q.push(listAdj[atual][i]);
			}
		}
	}
}

int main(){
	int nVertices, nArestas;
	int verticeParaAnalisar;

	scanf("%d %d", &nVertices, &nArestas);

	/* Inicializa todos os elemento de dist como "infinito"((peso * nArestas) + 1) */
	for(int i = 0; i < MAXV; i++){
		dist[i] = INF;
	}

	for(int i = 0; i < nArestas; i++){
		int ini, fim;
		scanf("%d %d", &ini, &fim);

		listAdj[ini].push_back(fim);
		listAdj[fim].push_back(ini);
	}

	scanf("%d", &verticeParaAnalisar);

	bfs(verticeParaAnalisar);

	for(int i = 1; i <= nVertices; ++i){
		printf("Distancia para %d: %d\n", i, dist[i]);
	}
}
