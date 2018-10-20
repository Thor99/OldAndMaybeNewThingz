#include <cstdio>
#include <algorithm>
#define MAXV 15 // Definimos maximo de vertices como 15, para usar com um maximo de 10 e ter folga
#define INFINITO 999999999 // como não existe o Infinito no computador, usaremos um número bem grande

/* Algoritmo para retorna o menor caminho de todos os vértices do grafo para um vertice qualquer, tendo as arestas com peso > 0 */

using namespace std;

bool processado[MAXV];
int dist[MAXV];
int matrizAdj[MAXV][MAXV];
int nVertices, nArestas;

/* O algoritmo consiste em ir atualizando as distancias do vertice escolhido (V) a outros vertices, baseado em um vetor referente aos 
vertices que ja foram processados. Veremos se um vertice não foi processado e a distancia dele para V for menor que INF. 
Se nenhum vertice tenha distancia menor que V e não tenha sido processado, encerra o algoritmo. Senão, iremos ver se não 
é menos custoso ir de V até ele e dele até os outros vertices do grafo. Se sim, atualizamos o vetor de distancias. Se não, mantem a distancia 
original. */

void dijkstra(int v){

    // Atualiza o vetor de distancias com o vertice v usado como referência
    for(int i = 1; i <= nVertices; ++i){
        dist[i] = matrizAdj[v][i];
    }

    dist[v] = 0; // Distancia de um vertice para ele mesmo é 0

    processado[v] = true;

    while(true){
        int vizinho = -1;
        int menor = INFINITO;

        for(int i = 1; i <= nVertices; ++i){
            // Se o vertice não foi processado e sua dist é menor que "menor" (ou seja, vizinho de v e não processado ainda)
            if(!processado[i] && dist[i] < menor){ 
                vizinho = i;
                menor = dist[i];
            }
        }

        if(vizinho == -1){ // Não foi encontrado nenhum vertice, acaba o programa
            break;
        }   

        processado[vizinho] = true;

        for(int i = 1; i <= nVertices; ++i){
            // Vemos se é menos custoso ir de v para i diretamente ou ir de v para vizinho e de vizinho para i
            dist[i] = min(dist[i], dist[vizinho] + matrizAdj[vizinho][i]);
        }
    }
}



int main(){
    int verticeParaAnalisar;

    scanf("%d %d", &nVertices, &nArestas);

    /* Inicializamos todas as distancias como infinito */
    for(int i = 1; i <= nVertices; ++i){
        for(int j = i; j <= nVertices; ++j){
            matrizAdj[i][j] = INFINITO;
        }
    }

    for(int i = 0; i < nArestas; ++i){
        int ini, fim, dist;
        scanf("%d %d %d", &ini, &fim, &dist);

        matrizAdj[ini][fim] = dist;
        matrizAdj[fim][ini] = dist;
    }

    scanf("%d", &verticeParaAnalisar);

    dijkstra(verticeParaAnalisar);

    for(int i = 1; i <= nVertices; ++i){
        printf("Menor distancia de %d para %d: %d\n", verticeParaAnalisar, i, dist[i]);
    }
}