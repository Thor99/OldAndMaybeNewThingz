/*#include <stdio.h>

int main(){
  int nArestas;
  int verticeParaAnalisar;
  int saidasDeArestas[10];
  int chegadasDeArestas[10];

  scanf("%d", &nArestas);

  for (int i = 0; i < nArestas; ++i) {
    scanf("%d %d", &saidasDeArestas[i], &chegadasDeArestas[i]);
  }

  scanf("%d", &verticeParaAnalisar);

  for (int i = 0; i < nArestas; ++i) {
    if(saidasDeArestas[i] == verticeParaAnalisar){
      printf("%d ", chegadasDeArestas[i]);
    }
    else if(chegadasDeArestas[i] == verticeParaAnalisar){
      printf("%d ", saidasDeArestas[i]);
    }
  }
}*/

/*#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int nArestas;
  int verticeParaAnalisar;
  vector<pair<int, int> > arestas;

  scanf("%d", &nArestas);

  for (int i = 0; i < nArestas; ++i) {
    int verticeDeSaida, verticeDeChegada;
    scanf("%d %d", &verticeDeSaida, &verticeDeChegada);
    arestas.push_back(make_pair(verticeDeSaida, verticeDeChegada));
  }

  scanf("%d", &verticeParaAnalisar);

  for (int i = 0; i < nArestas; ++i) {
    if(arestas[i].first == verticeParaAnalisar){
      printf("%d ", arestas[i].second);
    }
    else if(arestas[i].second == verticeParaAnalisar){
      printf("%d ", arestas[i].first);
    }
  }
}*/

/* USANDO MATRIZ DE ADJACENCIA
#include <cstdio>

using namespace std;

int main(){
  int nArestas;
  int nVertices;
  int verticeParaAnalisar;
  int matrizAdjacencia[10][10];

  scanf("%d", &nVertices);
  scanf("%d", &nArestas);

  for (int i = 0; i < nArestas; ++i) {
    int j, k;
    scanf("%d %d", &j, &k);
    matrizAdjacencia[j][k] = 1; // Grafo bidirecional -> [j][k] = 1 && [k][j] = 1
    matrizAdjacencia[k][j] = 1; // Grafo bidirecional -> [j][k] = 1 && [k][j] = 1
  }

  scanf("%d", &verticeParaAnalisar);

  for (int i = 1; i <= nVertices; ++i) {
    if(matrizAdjacencia[verticeParaAnalisar][i] == 1){ // Não precisa analisar matrizAdjacencia[i][verticeParaAnalisar], é bidirecional
      printf("%d ", i);
    }
  }
}
*/

#include <cstdio>
#include <vector>

using namespace std;

int main(){
  int nArestas;
  int nVertices;
  int verticeParaAnalisar;

  scanf("%d", &nVertices);

  vector<vector<int> > adjList(nVertices + 10);

  scanf("%d", &nArestas);

  for (int i = 0; i < nArestas; ++i) {
    int j, k;
    scanf("%d %d", &j, &k);

    adjList[j].push_back(k); // Grafo bidirecional
    adjList[k].push_back(j); // Grafo bidirecional
  }

  scanf("%d", &verticeParaAnalisar);

  /*
  Iremos no vector mais de fora, no index do vetor para analisar. Nele, usaremos o size
  (adjList[verticeParaAnalisar] é um vector também) pra ver quantos vertices são relacionados com ele, e printaremos eles, usando
  for.
  */
  
  for (int i = 0; i < adjList[verticeParaAnalisar].size(); ++i) {
    printf("%d ", adjList[verticeParaAnalisar][i]);
  }
}
