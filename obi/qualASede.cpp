#include <cstdio>
#include <vector>
#include <queue>
#define MAXV 100001


using namespace std;

queue<int> Q;
int peso = 1;
vector<pair<int, int> > dist;
int INF = 100001;
vector<vector<int> > listAdj;

void bfs(int v){
	dist[v] = make_pair(0, v); // Distancia dele para ele mesmo

	Q.push(v);

	while(!(Q.empty())){ // Enquanto tiver ainda algum adjacente para ver a distancia
		int atual = Q.front();
		Q.pop();

		for(int i = 0; i < listAdj[atual.second].size(); ++i){ // Atualiza as distancias de todos os vizinhos do listAdj[atual], se a mesma estiver como INF
			if(dist[listAdj[atual.second][i]].first == INF){
                dist[listAdj[atual][i]].first = dist[atual] + peso;
				dist[listAdj[atual][i]].second = listAdj[atual][i];
				Q.push(listAdj[atual][i]);
			}
		}
	}
}

int main(){
    int nLocais, nSedes, nAlunos, nRuas;
    map<int, pair<long int, long int> > mapa;

    scanf("%d %d %d %d", &nLocais, &nSedes, &nAlunos, &nRuas);

    listAdj.reserve(nLocais + 1);
    dist.reserve(nLocais + 1);

    for(int i  = 0; i < nSedes; i++){
        int sede;
        long int medalhas, dias;
        scanf("%d %ld %ld", &sede, &medalhas, &dias);

        mapa[sede] = make_pair(medalhas, dias);
    }

    for(int i = 0; i < nRuas; i++){
        int ini, fim;
        scanf("%d %d", &ini, &fim);

        listAdj[ini].push_back(fim);
        listAdj[fim].push_back(ini);
    }

    for(int i = 0; i < nAlunos; i++){
        int localizacao;
        scanf("%d", &localizacao);

        fill(dist.begin(), dist.end(), make_pair(INF, INF));

        bfs(localizacao);

        sort(dist.begin(), dist.end());
    }
}