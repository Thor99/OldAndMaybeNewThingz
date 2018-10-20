#include <cstdio>
#include <vector>
#include <string.h>

#define MAXN 50050

using namespace std;

/* Problema consiste em usar DFS pra ver quantos subgrafos conexos existem no grafo, ou se ele é um grafo conexo em sí */

int visitados[MAXN];
vector<vector<int> > listAdj(MAXN);

void dfs(int v){
	if(visitados[v] == 1){
		return;
	}

	visitados[v] = 1;

	for(int i = 0; i < listAdj[v].size(); ++i){
		dfs(listAdj[v][i]);
	}
}

int main(){
	int nVertices, nArestas, numeroFamilias=0;

	memset(visitados, 0, sizeof(visitados));

	scanf("%d %d", &nVertices, &nArestas);

	for (int i = 0; i < nArestas; ++i){
		int membro1, membro2;
		scanf("%d %d", &membro1, &membro2);

		listAdj[membro1].push_back(membro2);
		listAdj[membro2].push_back(membro1);
	}

	for (int i = 1; i <= nVertices; ++i){
		if(visitados[i] == 0){ // Achamos o inicio de uma nova familia
			numeroFamilias++;
			dfs(i);
		}
	}

	printf("%d", numeroFamilias);
}