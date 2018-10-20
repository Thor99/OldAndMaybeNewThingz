#include <cstdio>
#include <algorithm>
#define MAXV 3001
#define MAXA 4498500

using namespace std;

struct t_aresta{
    int dist;
    int x, y;
};

bool comp(t_aresta x, t_aresta y){
    return x.dist < y.dist;
}

int pai[MAXV], peso[MAXV];
t_aresta arestas[MAXA];
t_aresta mst[MAXA];

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
    int nVertices, nArestas, inutil;
    scanf("%d %d", &nVertices, &nArestas);

    for(int i = 1; i <= nArestas; i++){
        scanf("%d %d %d", &arestas[i].x, &arestas[i].y, &arestas[i].dist);
    }

    for(int i = 1; i <= nVertices; i++){
        pai[i] = i;
    }

    scanf("%d", &inutil);

    sort(arestas+1, arestas+nArestas+1, comp);

    int indice = 0;
    int tamMst = 0;
    for(int i = 1; i <= nArestas; i++){
        if(find(arestas[i].x) != find(arestas[i].y)){
            join(arestas[i].x, arestas[i].y);
            mst[++indice] = arestas[i];
            tamMst += arestas[i].dist;
        }
    }

    printf("%d\n", tamMst);
}