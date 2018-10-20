#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int> > listAdj;
int vis[20];

void dfs(int v, int espacos){
	if(vis[v] == 1){
		return;
	}

	vis[v] = 1;

	for(int i = 0; i < listAdj[v].size(); i++){
		for(int k = 0; k < espacos; k++){
			printf("");
		}

		if(vis[listAdj[v][i]] == 1){
			printf("%d-%d\n", v, listAdj[v][i]);
		} else {
			printf("%d-%d pathR(G,%d)\n", v, listAdj[v][i], listAdj[v][i]);
		}

		dfs(listAdj[v][i], espacos + 2);
	}
}

int main(){
	int nVertices, nArestas;
	int nTestes;
	int mini = 21;

	scanf("%d", &nTestes);

	for(int t = 1; t <= nTestes; t++){
		printf("Caso %d:\n", t);

		scanf("%d %d", &nVertices, &nArestas);

		memset(vis, 0, sizeof(vis));
		listAdj.reserve(nVertices);

		for(int i = 0; i < nArestas; i++){
			int ini, fim;
			scanf("%d %d", &ini, &fim);

			if(find(listAdj[ini].begin(), listAdj[ini].end(), fim) == listAdj[ini].end()){
				listAdj[ini].push_back(fim);
			}

			mini = min(mini, min(ini, fim));
		}

		for(int i = 0; i < nVertices; i++){
			sort(listAdj[i].begin(), listAdj[i].end());
		}

		dfs(mini, 2);

		for(int i = 0; i < nVertices; i++){
			if(vis[i] == 0){
				printf("\n");
				dfs(i, 2);
			}
		}

		for(int i = 0; i < nVertices; i++){
			listAdj[i].clear();
		}

		printf("\n\n");
	}
}