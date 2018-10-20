#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

map<string, int> mapa;
queue<int> Q;
vector<vector<int> > listAdj(1010);
int INF = -1;
int peso = 1;
vector<int> dist(1010);

void BFS(int v){
    dist[v] = 0;
    Q.push(v);

    while(!(Q.empty())){
        int atual = Q.front();
        Q.pop();

        for(int i = 0; i < listAdj[atual].size(); ++i){
            if(dist[listAdj[atual][i]] == INF){
                dist[listAdj[atual][i]] = dist[atual] + peso;
                Q.push(listAdj[atual][i]);
            }
        }
    }
}

int main(){
    for(int i = 0; i < 1010; ++i) dist[i] = INF;

    int nArestas, distMax, ultimoNumero = 0;
    vector<string> nomesAchados;
    string nome1, nome2;

    scanf("%d %d", &nArestas, &distMax);

    for(int i = 0; i < nArestas; ++i){
        cin >> nome1;
        cin >> nome2;

        if(mapa.count(nome1) == 0 && mapa.count(nome2) == 0){ // Ainda não apareceu estes nomes
            mapa[nome1] = ultimoNumero + 1;
            mapa[nome2] = ultimoNumero + 2;

        } else if(mapa.count(nome1) > 0 && mapa.count(nome2) == 0){ // Ainda não apareceu nome2
            mapa[nome2] = ultimoNumero + 1;

        } else if(mapa.count(nome1) == 0 && mapa.count(nome2) > 0){ // Ainda não apareceu nome 1
            mapa[nome1] = ultimoNumero + 1;
        }

        // Se ja apareceu os 2, não faz nada

        listAdj[mapa[nome1]].push_back(mapa[nome2]);
        listAdj[mapa[nome2]].push_back(mapa[nome1]);

        ultimoNumero = max(ultimoNumero, max(mapa[nome1], mapa[nome2])); // Acha o ultimo numero, para cada elemento do mapa ter um identificador unico
    }

    BFS(mapa["Rerisson"]);

    map<string, int>::iterator it;

    /* Adiciona no vetor nomesAchados os amigos com grau <= distMax e que não seja disconexo ou não seja ele mesmo */
    for(it=mapa.begin(); it!=mapa.end(); it++){
        if((*it).second != mapa["Rerisson"] && dist[(*it).second] <= distMax && dist[(*it).second] != INF){
            nomesAchados.push_back((*it).first);
        }
    }

    sort(nomesAchados.begin(), nomesAchados.end()); // Ordem lexicografica crescente

    cout << nomesAchados.size() << endl;

    for(int i = 0; i < nomesAchados.size(); ++i){
        cout << nomesAchados[i] << endl;
    }
}
