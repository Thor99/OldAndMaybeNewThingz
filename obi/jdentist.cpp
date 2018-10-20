#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N, maximo=0;
	vector<pair<int, int> > vet;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i){
		int ini, fim;
		scanf("%d %d", &ini, &fim);
		vet.push_back(make_pair(fim, ini));
	}

	sort(vet.begin(), vet.end());

	maximo += 1; // A primeira consulta será sempre realizada.
	int j = 0;

	for(int i = 1; i < N; ++i){
		if(vet[i].second >= vet[j].first){ // Verá se o horário da consulta não irá conflitar com o horário de inicio da outra
			maximo++;
			j = i;
		}
	}

	printf("%d", maximo);
}