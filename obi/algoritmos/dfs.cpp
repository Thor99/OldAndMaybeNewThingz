#include <cstdio>
#include <vector>

/* Algoritmo para saber se um grafo não orientado é conexo */

using namespace std;

vector<int> visitados(100);
vector<vector<int> > adjList(110);

/* Consiste em pegar um vertice qualquer, e ver se ele já foi vistado. Se não, marca como visitado. Depois chama a mesma função para seus
vizinhos. Se ao acabar a função, todos os vertices tiverem sido visitados, o grafo é conexo. Se não, ele é disconexo. */

void dfs(int v){
  if(visitados[v] == 1){
    return;
  }

  visitados[v] = 1;

  int tam = adjList[v].size();

  for(int i = 0; i < tam; ++i){
    dfs(adjList[v][i]); // Rodará a função para cada vizinho, independente do "return;"
  }
}

int main(){
  fill(visitados.begin(), visitados.end(), 0);

  int nArestas;
  int nVertices;

  scanf("%d", &nVertices);
  scanf("%d", &nArestas);

  for (int i = 0; i < nArestas; ++i) {
    int j, k;
    scanf("%d %d", &j, &k);

    adjList[j].push_back(k); // Grafo bidirecional
    adjList[k].push_back(j); // Grafo bidirecional
  }

  dfs(adjList[1][0]);

  for(int k = 1; k <= nVertices; ++k){
    if(visitados[k] == 0){
      printf("Grafo nao conexo\n");
      return 0;
    }
  }

  printf("Grafo conexo\n");
}
