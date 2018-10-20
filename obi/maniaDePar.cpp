#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 10001
#define INF 0x3f3f3f3f

using namespace std;

int matrizAdj[MAX][MAX], cidadesAte[MAX][MAX], dist[MAX], cidades[MAX];
bool vis[MAX];
int nVertices, nArestas;

void dijkstra(int v){
	for(int i = 1; i <= nVertices; i++){
		dist[i] = matrizAdj[v][i];
		cidades[i] = cidadesAte[v][i];
	}

	dist[v] = 0;
	cidades[v] = 0;

	vis[v] = true;

	while(true){
		int menor = INF;
		int cur = -1;

		for(int i = 1; i <= nVertices; i++){
			if(!vis[i] && dist[i] < INF){
				menor = dist[i];
				cur = i;
			}
		}

		if(cur == -1){
			break;
		}

		vis[cur] = true;

		for(int i = 1; i <= nVertices; i++){
			dist[i] = min(dist[i], dist[cur] + matrizAdj[cur][i]);
			cidades[i] = min(cidades[i], cidades[cur] + cidadesAte[cur][i]);
		}
	}
}

int main(){
	scanf("%d %d", &nVertices, &nArestas);

	memset(dist, INF, sizeof(dist));
	memset(vis, false, sizeof(vis));
	memset(matrizAdj, INF, sizeof(matrizAdj[0][0]) * MAX * MAX);
	memset(cidadesAte, INF, sizeof(cidadesAte[0][0]) * MAX * MAX);

	for(int i = 0; i < nArestas; i++){
		int ini, fim, valor;
		scanf("%d %d %d", &ini, &fim, &valor);

		matrizAdj[ini][fim] = valor;
		matrizAdj[fim][ini] = valor;

		cidadesAte[ini][fim] = 1;
		cidadesAte[fim][ini] = 1;
	}

	dijkstra(1);

	if(cidades[nVertices] % 2 == 0){
		printf("%d\n", dist[nVertices]);
	} else {
		printf("-1\n");
	}

}