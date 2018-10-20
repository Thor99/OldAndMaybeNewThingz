#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 110

using namespace std;

int nVertices, nArestas;
vector<vector<int> > listAdj(MAX);
// Usa uma priority queue reversa (adiciona no topo da heap os menores elementos)
priority_queue< int, vector<int>, greater<int> > heap;
int grauDeEntrada[MAX];

void topsort(){
    for(int i = 1; i <= nVertices; i++){
        if(grauDeEntrada[i] == 0){
            heap.push(i);
        }
    }

    while(!(heap.empty())){
        int cur = heap.top();
        printf("%d ", cur);

        heap.pop();

        for(int i = 0; i < listAdj[cur].size(); i++){
            grauDeEntrada[listAdj[cur][i]]--;

            if(grauDeEntrada[listAdj[cur][i]] == 0){
                heap.push(listAdj[cur][i]);
            }
        }
    }
}

int main(){
    memset(grauDeEntrada, 0, sizeof(grauDeEntrada));

    scanf("%d %d", &nVertices, &nArestas);

    // Vértice ini aponta para fim
    for(int i = 0; i < nArestas; ++i){
        int fim, nInis;
        scanf("%d %d", &fim, &nInis);

        for(int j = 0; j < nInis; j++){
            int ini;
            scanf("%d", &ini);

            listAdj[ini].push_back(fim);
            grauDeEntrada[fim]++;
        }
    }

    // Ordena crescentemente a lista de adjacencia de cada vértice
    for(int i = 1; i <= nVertices; i++){
        sort(listAdj[i].begin(), listAdj[i].end());
    }

    topsort();
}
