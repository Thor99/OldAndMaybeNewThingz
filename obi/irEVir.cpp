#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1001 // Máximo de vértices é 1000

using namespace std;

vector<vector<int> > listAdj(MAX);
vector<vector<int> > revertedListAdj(MAX);
vector<int> vis(MAX);

void dfs(int v, bool flag){
	if(vis[v] == 1){
		return;
	}

	vis[v] = 1;

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

void cleanAdjLists(){
	for(int i = 0; i < MAX; ++i){
		listAdj[i].clear();
		revertedListAdj[i].clear();
	}
}

int main(){
	int nVertices, nArestas;

	while(scanf("%d %d", &nVertices, &nArestas) && nVertices != 0){
		bool conexo = true;

		fill(vis.begin(), vis.end(), 0);

		for(int i = 0; i < nArestas; ++i){
			int ini, fim, direOuNao;
			scanf("%d %d %d", &ini, &fim, &direOuNao);

			if(direOuNao == 1){ // Não é mão dupla

				listAdj[ini].push_back(fim);
				revertedListAdj[fim].push_back(ini);

			} else { // É mão dupla

				listAdj[ini].push_back(fim);
				listAdj[fim].push_back(ini);

				revertedListAdj[ini].push_back(fim);
				revertedListAdj[fim].push_back(ini);
			}
		}

		dfs(1, true);

		for(int i = 1; i <= nVertices; ++i){
			if(vis[i] != 1){
				conexo = false;
			}
		}

		/* Se na primeira chamada de DFS pra lista de adjacência original não atingir todos os vértices, não precisa rodar a dfs pra 
		lista de adjacência invertida, pois o grafo que estamos analisando já é disconexo */
		if(!conexo){
			printf("0\n");
		} else {
			fill(vis.begin(), vis.end(), 0);

			dfs(1, false);

			for(int i = 1; i <= nVertices; ++i){
				if(vis[i] != 1){
					conexo = false;
				}
			}

			/* Se após a segunda rodagem de DFS pra lista de adjacência invertida não se alcançar todos os vértices, então o grafo que 
			estamos analisando é disconexo.  */
			if(!conexo){
				printf("0\n");
			} else {
				printf("1\n");
			}
		}

		cleanAdjLists();
	}

}