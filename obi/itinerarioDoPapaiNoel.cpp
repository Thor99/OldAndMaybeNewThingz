#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXA 50000
#define MAXV 40000

using namespace std;

struct t_aresta{
    int x, y;
    int dist;
};

bool comp(t_aresta x, t_aresta y){
    return x.dist < y.dist;
}

t_aresta arestas[MAXA]; // não precisamos da nossa mst em sí, já que só queremos a distancia total
int pai[MAXV], peso[MAXV];

int find(int x){
    if(pai[x] == x){
        return x;
    }

    return pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y){
        return;
    }

    if(peso[x] < peso[y]){
        pai[x] = y;
    }

    else if(peso[x] > peso[y]){
        pai[y] = x;
    }

    else {
        pai[x] = y;
        peso[y]++;
    }
}

int main(){
    int nVertices, nArestas;
    while(scanf("%d %d", &nVertices, &nArestas) == 2 && nVertices != 0){
        memset(peso, 0, sizeof(peso)); // Para cada teste, inicializamos os pesos

        for(int i = 0; i < nVertices; i++){
            pai[i] = i;
        }

        for(int i = 1; i <= nArestas; i++){
            scanf("%d %d %d", &arestas[i].x, &arestas[i].y, &arestas[i].dist);
        }

        sort(arestas+1, arestas+nArestas+1, comp);

        long int tamanhoMst = 0;
        for(int i = 1; i <= nArestas; i++){
            if(find(arestas[i].x) != find(arestas[i]. y)){
                join(arestas[i].x, arestas[i].y);
                tamanhoMst += arestas[i].dist;
            }
        }

        printf("%ld\n", tamanhoMst);
    }
}