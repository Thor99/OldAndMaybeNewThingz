#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 110 // Maximo de vertices é 100
#define INF 0x3F3F3F3F

using namespace std;

// Algoritmo para gerar MST. Nessa adaptação, iremos ver o tamanho da MST e a MST em sí.

int nVertices, nArestas, matrizAdj[MAX][MAX], dist[MAX], visitado[MAX], chamadoPor[MAX], tamMST;

void resetVisitado(){
    memset(visitado, 0, sizeof(visitado));
}

void resetDist(){
    memset(dist, INF, sizeof(dist));
}

void resetMatrix(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            matrizAdj[i][j] = INF;
        }
    }
}

void resetChamadoPor(){
    memset(chamadoPor, -1, sizeof(chamadoPor));
}

void prim(){
    resetDist();
    resetVisitado();
    resetChamadoPor();

    int atual = 1;
    int contador = 1;

    while(contador < nVertices){
        visitado[atual] = 1;
        dist[atual] = 0;

        int menor = INF;
        int indice = -1;

        for(int i = 1; i <= nVertices; i++){
            if(visitado[i] != 1){
                if(matrizAdj[atual][i] < dist[i]){
                    dist[i] = matrizAdj[atual][i];
                    chamadoPor[i] = atual;
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

    for(int i = 1; i <= nVertices; i++){
        if(chamadoPor[i] != -1){
            // Imprimo menor número primeiro só para ficar bonito
            printf("%d - %d\n", min(i, chamadoPor[i]), max(i, chamadoPor[i]));
        }
    }

    printf("\n");

    printf("Tamanho da MST: %d\n\n", tamMST);
}
