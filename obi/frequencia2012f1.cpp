#include <cstdio>
#include <set>

using namespace std;

// O set é uma estrutura de dados para guardar elementos com valores únicos, sem repetição. Ou seja, se o elemento que quisermos
// inserir já estiver na lista, ele ignora.

int main(){
	set<int> freq;
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i){
		int registro;
		scanf("%d", &registro);

		freq.insert(registro);
	}

	printf("%d", (int) freq.size());
}