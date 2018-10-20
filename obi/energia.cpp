#include <cstdio>
#include <vector>

#define MAXV 110

using namespace std;

vector<int> visitados(MAXV); // Vetor de visitador global
vector<vector<int> > listAdj(MAXV); // Lista de adjacencia global

void dfs(int v){
  if(visitados[v] == 1){
    return;
  }

  visitados[v] = 1;

  for(int i = 0; i < (int) listAdj[v].size(); ++i){
    dfs(listAdj[v][i]);
  }
}


int main(){
  int nVertices, nArestas, teste=1, verticeAleatorio;

  while(scanf("%d %d", &nVertices, &nArestas) == 2 && nVertices != 0){
    bool conexo = true; // Ao comeco do teste, assumimos que o grafo é conexo

    fill(visitados.begin(), visitados.end(), 0); // Ao iniciar um novo teste, reseta o vector de visitados
    for(int i = 0; i < MAXV; ++i) listAdj[i].clear(); // Ao iniciar um novo teste, reseta a lista de adjacencia

    printf("Teste %d\n", teste++);

    for(int i = 0; i < nArestas; ++i){
      int ini, fim;
      scanf("%d %d", &ini, &fim);

      listAdj[ini].push_back(fim);
      listAdj[fim].push_back(ini);

      verticeAleatorio = ini;
    }

    dfs(verticeAleatorio);

    for(int i = 1; i <= nVertices; ++i){
      if(visitados[i] == 0){ // Quer dizer que o vertice não foi visitado, não é conexo
        conexo = false;
        break;
      }
    }

    if(conexo == true){
      printf("normal\n\n");
    } else {
      printf("falha\n\n");
    }
  }
}
