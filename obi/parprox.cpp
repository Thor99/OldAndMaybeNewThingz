#include <cstdio>
#include <cmath>
#include <vector>

#define INF 0x3f3f3f3f // Vi que isso representa infinito

using namespace std;

double dist(pair<int, int> p1, pair<int, int> p2){
	double a = (double) abs(p1.first - p2.first);
	double b = (double) abs(p1.second - p2.second);

	return sqrt(a*a + b*b);
}

int main(){
	int N;
	vector<pair<int, int> > pontos;

	scanf("%d", &N);

	for(int i = 0; i < N; ++i){
		int x, y;
		scanf("%d %d", &x, &y);

		pontos.push_back(make_pair(x, y));
	}

	double menorDist = INF;

	/* For que pegará as distancias entre todos os pares, sem repetição de duas distancias */
	for(int i = 0; i < N-1; ++i){
		for(int j = i+1; j < N; ++j){
			menorDist = min(menorDist, dist(pontos[i], pontos[j])); // Menor distancia será o menor valor entre a atual menor e dist(pontos[i], pontos[j]) 
		}
	}

	if(menorDist != INF){
		printf("%.3f", menorDist);
	} else { 
		printf("0");
	}
}