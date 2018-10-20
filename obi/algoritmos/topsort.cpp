#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 1010 // Max de vertices é 1000

using namespace std;

/* Consiste em achar uma sequencia de passos num grafo acíclico direcionado. Ex: Para fazer cálculo 3, tem que fazer
cálculo 2 e para fazer cálculo 2 tem que fazer cálculo 1. Então, a sequencia certa seria cálculo 1 -> cálculo 2 ->
cálculo 3. Para fazer isso, criamos um vetor com os graus de entrada de cada aresta. Depois, percorremos esse vetor e
adicionamos todos os vértices que possuem grau de entrada 0 na fila. Enquanto a fila não for vazia, printamos o elemento do topo,
tiramos ele da fila e percorremos seus vizinhos para tirar uma unidade do grau de entrada dos mesmos, ja que tiramos o outro
vértice da fila. Após diminuirmos uma unidade do grau de entrada de cada vizinho, vemos se seu grau de entrada
ficou 0. Se ficou, inserimos ele na fila, se não, não inserimos. */

vector<vector<int> > listAdj(MAX);
int grauDeEntrada[MAX];
queue<int> Q;
int nVertices, nArestas;

void topsort(){
    for(int i = 1; i <= nVertices; i++){
        if(grauDeEntrada[i] == 0){
            Q.push(i);
        }
    }

    while(!(Q.empty())){
        int cur = Q.front();
        printf("%d ", cur);

        Q.pop();

        for(int i = 0; i < listAdj[cur].size(); ++i){
            grauDeEntrada[listAdj[cur][i]]--;

            if(grauDeEntrada[listAdj[cur][i]] == 0){
                Q.push(listAdj[cur][i]);
            }
        }
    }
}


int main(){

    memset(grauDeEntrada, 0, sizeof(grauDeEntrada));

    scanf("%d %d", &nVertices, &nArestas);

    for(int i = 0; i < nArestas; i++){
        int ini, fim;
        scanf("%d %d", &ini, &fim);

        listAdj[ini].push_back(fim);
        grauDeEntrada[fim]++;
    }

    topsort();
}