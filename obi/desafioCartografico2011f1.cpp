#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>  
#include <string.h>

using namespace std;

queue<int> Q;
int dist[1000010];
int peso = 1;

void bfs(int v, vector<vector<int> > list){
	dist[v] = 0;
	Q.push(v);
	while(!(Q.empty())){
		int atual = Q.front();
		Q.pop();
		for(int i = 0; i < list[atual].size(); ++i){
			if(dist[list[atual][i]] == -1){
				dist[list[atual][i]] = dist[atual] + peso;
				Q.push(list[atual][i]);
			}
		}
	}
}

int main(){
	int nVertices;

	scanf("%d", &nVertices);

	vector<vector<int> > listAdj(nVertices + 10);

	for(int i = 0; i < nVertices - 1; i++){
		int ini, fim;
		scanf("%d %d", &ini, &fim);

		listAdj[ini].push_back(fim);
		listAdj[fim].push_back(ini);
	}

	int maior = 0;

	for(int vertice = 1; vertice <= nVertices; ++vertice){
		memset(dist, -1, sizeof(dist));
		bfs(vertice, listAdj);
		sort(dist, dist+1000010, greater<int>());
		maior = max(maior, dist[0]);
	}

	printf("%d", maior);
}
