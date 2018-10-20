#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/* Se ao retirar uma aresta o grafo ficar desconexo, esta aresta NÂO faz parte de um ciclo. Se continuar conexo,
faz parte de um ciclo. Desenhando da pra ver melhor. */

vector<vector<int> > listAdj(51); // Max de cidades é 50
vector<int> vis(51); // Max de cidades é 50
int nVertices, nArestas;

void dfs(int v){
    vis[v] = 1;

    for(int i = 0; i < listAdj[v].size(); i++){
        if(vis[listAdj[v][i]] == 0){
            dfs(listAdj[v][i]);
        }
    }
}

void resetVis(){
    for(int j = 0; j < 51; j++){
        vis[j] = 0;
    }
}

void resetListAdj(){
    for(int i = 0; i < 51; i++){
        listAdj[i].clear();
    }
}

int main(){

    while(scanf("%d %d", &nVertices, &nArestas) != EOF){
        int pontesNaoContidas = 0;
        vector<pair<int, int> > arestas;

        for(int i = 0; i < nArestas; i++){
            int ini, fim;
            scanf("%d %d", &ini, &fim);

            listAdj[ini].push_back(fim);
            listAdj[fim].push_back(ini);

            arestas.push_back(make_pair(ini, fim));
        }

        for(int i = 0; i < arestas.size(); i++){
            // Retiramos a aresta (relação entre arestas[i].first e arestas[i].second), chamamos dfs(1), e reinserimos a aresta
            resetVis();
            listAdj[arestas[i].first].erase(remove(listAdj[arestas[i].first].begin(), listAdj[arestas[i].first].end(), arestas[i].second), listAdj[arestas[i].first].end());
            listAdj[arestas[i].second].erase(remove(listAdj[arestas[i].second].begin(), listAdj[arestas[i].second].end(), arestas[i].first), listAdj[arestas[i].second].end());

            dfs(1);

            for(int k = 1; k <= nVertices; k++){
                if(vis[k] == 0){
                    pontesNaoContidas++;
                    break;
                }
            }

            listAdj[arestas[i].first].push_back(arestas[i].second);
            listAdj[arestas[i].second].push_back(arestas[i].first);
        }

        printf("%d\n", pontesNaoContidas);

        resetListAdj();
    }
}