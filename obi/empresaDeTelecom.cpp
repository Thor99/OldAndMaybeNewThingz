#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAXV 110

using namespace std;

float dist(pair<int, int> p1, pair<int, int> p2){
	float a = abs(p1.first - p2.first);
	float b = abs(p1.second - p2.second);

	return sqrt(a * a + b * b);
}

int main(){
	int nVertices;

	while(scanf("%d", &nVertices) == 1 && nVertices != 0){
		vector<pair<pair<int, int>, int> > antenas; // ((x, y), raio) 
		int nArestas;

		for(int i = 0; i < nVertices; ++i){
			int X, Y, raio;
			scanf("%d %d %d", &X, &Y, &raio);

			antenas.push_back(make_pair(make_pair(X, Y), raio));
		}

		for(int i = 0; i < nVertices; ++i){
			printf("raio: %d\n", antenas[i].second);
		}

		scanf("%d", &nArestas);

		for(int i = 0; i < nArestas; ++i){
			int ini, fim;
			scanf("%d %d", &ini, &fim);

			if((int) dist(antenas[ini - 1].first, antenas[fim - 1].first) <= antenas[ini - 1].second){
				printf("%d\n", (int) dist(antenas[ini - 1].first, antenas[fim - 1].first));
			} else {
				printf("-1\n");
			}
		}
	}
}