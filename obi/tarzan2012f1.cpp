#include <cstdio>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;

int visitados[1010];
vector<vector<int> > listAdj(1010);

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
	vector<pair<int, int> > coordenadas;
	int nVertices, alcance;

	memset(visitados, 0, sizeof(visitados));

	scanf("%d %d", &nVertices, &alcance);

	for(int i = 0; i < nVertices; ++i){
		int xi, yi;
		scanf("%d %d", &xi, &yi);

		coordenadas.push_back(make_pair(xi, yi));
	}

	/* Loop que pega cada cada vertice, e compara com todos os outros vertices, para se a distancia entre eles for menor
	ou igual ao alcance do cipó, eles eles possuem uma aresta entre os dois */

	for(int i = 0; i < nVertices; ++i){
		for(int k = 0; k < nVertices; ++k){
			if(k != i){ // Não tentar fazer uma aresta entre um vértice e ele mesmo
				if(sqrt(pow(coordenadas[i].first - coordenadas[k].first, 2) + pow(coordenadas[i].second - coordenadas[k].second, 2)) <= alcance){ 
					// Ou seja, da pra ir da arvore k até a i, e vice versa, pois o alcance do cipó é maior ou igual a distancia

					listAdj[i + 1].push_back(k + 1); // Faz as relações entre os vertices na lista de adjacencia					
					listAdj[k + 1].push_back(i + 1); // Faz as relações entre os vertices na lista de adjacencia					
				}
			}
		}
	}

	dfs(1); // Não da identificação de vertice, então sempre boto 1, pois sempre terá pelo menos 2 arvores;

	for(int i = 1; i <= nVertices; ++i){
		if(visitados[i] == 0){
			printf("N");
			return 0;
		} 
	}

	printf("S");
}