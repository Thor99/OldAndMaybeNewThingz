#include <cstdio>
#include <cstring>
#define INF 0x3F3F3F3F
#define MAX 501

int tamMST = 0, dist[MAX], matrizAdj[MAX][MAX], vis[MAX], nVertices, nArestas;

void resetDist(){
    memset(dist, INF, sizeof(dist));
}

void resetVis(){
    memset(vis, 0, sizeof(vis));
}

void resetMatrix(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            matrizAdj[i][j] = INF;
        }
    }
}

void prim(){
    resetDist();
    resetVis();

    int contador = 1, atual = 1;

    while(contador < nVertices){
        vis[atual] = 1;
        dist[atual] = 0;

        int indice = -1;
        int menor = INF;

        for(int i = 1; i <= nVertices; i++){
            if(vis[i] != 1){
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

        contador++;
        tamMST += menor;
        atual = indice;
    }
}

int main(){
    resetMatrix();
    scanf("%d %d", &nVertices, &nArestas);

    for(int i = 0; i < nArestas; i++){
        int ini, fim, dista;
        scanf("%d %d %d", &ini, &fim, &dista);

        matrizAdj[ini][fim] = dista;
        matrizAdj[fim][ini] = dista;
    }

    prim();

    printf("%d\n", tamMST);
}