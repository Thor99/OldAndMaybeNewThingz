#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 3001 // Definimos maximo de vertices como 15, para usar com um maximo de 10 e ter folga
#define INF 0x3f3f3f3f

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q; // (distancia ate vertice de partida, identificador)
int dist[MAX];
int nVertices, nArestas;
bool vis[MAX];
vector<vector<pair<int, int> > > listAdj(MAX); // (distancia, vertice)

void dijkstra(int v){
    dist[v] = 0;
    Q.push(make_pair(0, v));

    while(!(Q.empty())){
        pair<int, int> front = Q.top();
        Q.pop();

        int disDavez = front.first; // Distancia de "davez" para "v"
        int davez = front.second; // Identificador de "davez"

        if(disDavez <= dist[davez]){
            for(int i = 0; i < listAdj[davez].size(); i++){
                pair<int, int> adjacenteDeDavez = listAdj[davez][i];
                // Ver qual é menos custoso: ir direto até "adjacenteDeDavez" ou ir até "davez" e depois ir até "adjacenteDeDavez"
                // Se for ir até "davez" e depois ir até "adjacenteDeDavez", atualiza a distancia e joga "adjacenteDeDavez" pra priority_queue
                if(dist[adjacenteDeDavez.second] > dist[davez] + adjacenteDeDavez.first){
                    dist[adjacenteDeDavez.second] = dist[davez] + adjacenteDeDavez.first;
                    Q.push(make_pair(dist[adjacenteDeDavez.second], adjacenteDeDavez.second));
                }
            }
        }
    }
}

int main(){

    int testes;
    scanf("%d", &testes);

    while(testes--){
        memset(dist, INF, sizeof(dist));

        int verticeDePartida;

        scanf("%d %d", &nVertices, &nArestas);

        for(int i = 0; i < nArestas; i++){
            int ini, fim, dist;
            scanf("%d %d %d", &ini, &fim, &dist);

            listAdj[ini].push_back(make_pair(dist, fim));
            listAdj[fim].push_back(make_pair(dist, ini));
        }

        scanf("%d", &verticeDePartida);

        dijkstra(verticeDePartida);

        for(int i = 1; i <= nVertices; i++){
            if(i != verticeDePartida){
                if(dist[i] == INF){
                    printf("-1 ");
                } else {
                    printf("%d ", dist[i]);
                }
            }
        }

        printf("\n");

        for(int i = 0; i < MAX; i++){
            listAdj[i].clear();
        }
    }
}