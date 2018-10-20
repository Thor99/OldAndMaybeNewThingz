#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 3001
#define INF 0x3F3F3F3F

using namespace std;

int nVertices, nArestas, verticeInicial, dist[MAX], matrizAdj[MAX][MAX], visitado[MAX], tamanhoMST = 0;

void resetDist(){
    memset(dist, INF, sizeof(dist));
}

void resetVisitado(){
    memset(visitado, 0, sizeof(visitado));
}

void resetMatrix(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            matrizAdj[i][j] = INF;
        }
    }
}

void prim(){
    resetVisitado();
    resetDist();

    int contador = 1, atual = 1;

    while(contador < nVertices){
        visitado[atual] = 1;
        dist[atual] = 0;

        int menor = INF;
        int indice = -1;

        for(int i = 1; i <= nVertices; i++){
            if(visitado[i] != 1){
                if(matrizAdj[atual][i] < dist[i]){
                    dist[i] = matrizAdj[atual][i];
                }

                if(dist[i] < menor){
                    menor = dist[i];
                    indice = i;
                }
            }

        }

        if(indice == -1){
            break;
        }


        tamanhoMST += menor;
        contador++;
        atual = indice;
    }
}

int main(){
    resetMatrix();

    scanf("%d %d", &nVertices, &nArestas);

    for(int i = 0; i < nArestas; i++){
        int ini, fim, tamanho;
        scanf("%d %d %d", &ini, &fim, &tamanho);

        matrizAdj[ini][fim] = tamanho;
        matrizAdj[fim][ini] = tamanho;
    }

    scanf("%d", &verticeInicial);

    prim();

    printf("%d\n", tamanhoMST);
}