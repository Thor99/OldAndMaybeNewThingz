#include <iostream>
#include <cstdio>
#define MAX 999999999
#define max 501

using namespace std;

int g[max][max], vertices;

int dijkstra(int origem, int destino) {
    int minimo, atual;
    int passou[max], pred[max],custo[max];
    for (int i=1; i<=vertices;i++) {
        pred[i]=-1;
        custo[i]=MAX;
        passou[i]=0;
    }
    custo[origem] = 0;
    atual = origem;
    while (atual != destino) {
        for (int i=1; i<=vertices;  i++) {
            if (custo[i] > custo[atual] + g[atual][i]) {
                custo[i] = custo[atual] + g[atual][i];
            }
        }
        minimo = MAX;
        passou[atual]=1;
        for (int i=1; i<=vertices; i++) {
            if ((custo[i]<minimo) && (!passou[i])) {
                minimo = custo[i];
                atual = i;
            }
        }
        // caso nao consiga ir a lugar algum saindo da origem
        if (minimo == MAX) {
            return MAX;
        }
    }
    return custo[destino];
}

int main() {


    int i, j, arestas, origem, destino, peso, consultas;
    cin >> vertices >> arestas;
    while (vertices!=0 || arestas!=0) {

        for (int i=1; i<=vertices; i++) {
            for (int j=1;j<=vertices;j++) {
                g[i][j]=MAX;
            }
        }
        for (i=1; i<=arestas; i++) {
            cin >> origem >> destino >> peso;
            g[origem][destino]=peso;
            if (g[destino][origem]!=MAX) {
                g[origem][destino] = 0;
                g[destino][origem] = 0;
            }
        }
        cin >> consultas;
        for (int i=1; i<=consultas;i++) {
            cin >> origem >> destino;

            if (dijkstra(origem,destino)== MAX) {
                cout << "Nao e possivel entregar a carta\n";
            } else {
                cout << dijkstra(origem,destino) << endl;
            }
        }
        cin >> vertices >> arestas;
        cout << endl;

    }
}