#include <cstdio>
#include <vector>
#define MAX 16 // Max de vertices é 15

/* Consiste em montar duas listas de adjacência: A original e uma invetida. Ou seja, se o grafo
nos diz que 1 se relaciona com 3 de um modo direcional, diremos na lista de adjacência invertida que 3 se relaciona com 1 de modo
direcional. Chamaremos a DFS de modo explícito duas vezes. A primeira chamada rodará de acordo com a lista de adjacência original,
e a segunda rodará de acordo com a lista de adjacência invertida. Entre as duas chamadas setaremos o vetor de visitados como 0.
Se o vetor de visitados mostrar que todos os vertices do grafo foram visitados nas duas chamadas, então o grafo que estamos analisando é
conexo, senão, é disconexo. */

using namespace std;

vector<vector<int> > listAdj(MAX);
vector<vector<int> > revertedListAdj(MAX);
vector<int> vis(MAX);

void dfs(int v, bool flag){
	if(vis[v] == 1){
		return;
	}

	vis[v] = 1;

	// Função DFS rodará pra listAdj original ou pra inversa, baseado na flag. Se true: original. Senão: Reversa
	if(flag == true){
		for(int i = 0; i < listAdj[v].size(); ++i){
			dfs(listAdj[v][i], flag);
		}
	} else {
		for(int i = 0; i < revertedListAdj[v].size(); ++i){
			dfs(revertedListAdj[v][i], flag);
		}
	}
}

int main(){
	int nVertices, nArestas;
	bool conexo = true;

	fill(vis.begin(), vis.end(), 0);

	scanf("%d %d", &nVertices, &nArestas);

	for(int i = 0; i < nArestas; ++i){
		int ini, fim;
		scanf("%d %d", &ini, &fim);

		listAdj[ini].push_back(fim);
		revertedListAdj[fim].push_back(ini);
	}

	dfs(1, true);

	for(int i = 1; i <= nVertices; ++i){
		if(vis[i] != 1){
			conexo = false;
		}
	}

	fill(vis.begin(), vis.end(), 0);

	dfs(1, false);

	for(int i = 1; i <= nVertices; ++i){
		if(vis[i] != 1){
			conexo = false;
		}
	}

	if(conexo){
		printf("Grafo é conexo\n");
	} else {
		printf("Grafo não é conexo\n");
	}
}
