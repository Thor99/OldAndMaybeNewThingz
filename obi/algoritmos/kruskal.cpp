#include <cstdio>
#include <algorithm>
#define MAXV 101 // Máximo de vértices é 100
#define MAXA 201 // Máximo de arestas 200

using namespace std;

struct t_aresta{
    int x, y; // Vértice 1 e vértice 2
    int dist; // Distância entre os vértices
};

bool comp(t_aresta x, t_aresta y){
    return x.dist < y.dist;
}

int pai[MAXV];
int peso[MAXV];

t_aresta arestas[MAXA]; // Vetor de arestas
t_aresta mst[MAXA]; // A MST

// Funções do union find.
int find(int x){
    if(pai[x] == x){
        return x;
    } else {
        return pai[x] = find(pai[x]);
    }
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
    scanf("%d %d", &nVertices, &nArestas);

    for(int i = 1; i <= nArestas; i++){
        scanf("%d %d %d", &arestas[i].x, &arestas[i].y, &arestas[i].dist);
    }

    // inicializar os pais para o union-find
    for(int i = 1; i <= nVertices; i++){
        pai[i] = i;
    }

    // Ordena o vetor de arestas, da aresta de menor distância para a aresta de maior distância
    sort(arestas+1, arestas+nArestas+1, comp);

    int indice = 0;
    int tamanhoMST = 0;

    for(int i = 1; i <= nArestas; i++){
        if(find(arestas[i].x) != find(arestas[i].y)){ // Vértices estão em componentes distintas
            join(arestas[i].x, arestas[i].y); // Bota os vértices na mesma componente

            mst[++indice] = arestas[i];
            tamanhoMST += arestas[i].dist;
        }
    }

    // Imprimo a MST
    for(int i = 1; i <= indice; i++){
        printf("Ligacao %d-%d: %d de distancia\n", mst[i].x, mst[i].y, mst[i].dist);
    }

    printf("\n");

    printf("Tamanho da MST: %d\n", tamanhoMST);
}