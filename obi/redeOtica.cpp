#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 110
#define INF 0x3F3F3F3F

using namespace std;

int matrizAdj[MAX][MAX], dist[MAX], vis[MAX], nVertices, nArestas, chamadoPor[MAX];

void resetMatrix(){
    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 110; j++){
            matrizAdj[i][j] = INF;
        }
    }
}

void resetDist(){
    memset(dist, INF, sizeof(dist));
}

void resetChamadoPor(){
    memset(chamadoPor, -1, sizeof(chamadoPor));
}

void resetVis(){
    memset(vis, 0, sizeof(vis));
}

void prim(){
    resetVis();
    resetDist();
    resetChamadoPor();

    int cur=1, cont=1;

    while(cont < nVertices){
        vis[cur] = 1;
        dist[cur] = 0;
        int menor = INF, indice = -1;

        for(int i = 1; i <= nVertices; i++){
            if(vis[i] == 0){
                if(matrizAdj[cur][i] < dist[i]){
                    chamadoPor[i] = cur; // i foi chamado por cur
                    dist[i] = matrizAdj[cur][i];
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

        cont++;
        cur = indice;
    }
}

int main(){
    int teste = 1;

    while(scanf("%d %d", &nVertices, &nArestas) == 2 && nVertices != 0){
        resetMatrix();

        for(int i = 0; i < nArestas; i++){
            int ini, fim, custo;
            scanf("%d %d %d", &ini, &fim, &custo);

            matrizAdj[ini][fim] = custo;
            matrizAdj[fim][ini] = custo;
        }

        prim();

        printf("Teste %d\n", teste);

        for(int i = 1; i <= nVertices; i++){
            if(chamadoPor[i] != -1){
                printf("%d %d\n", min(i, chamadoPor[i]), max(i, chamadoPor[i]));
            }
        }

        printf("\n");
        
        teste++;
    }
}