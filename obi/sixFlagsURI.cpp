#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 101 // Máximo de atrações
#define MAXC 601 // Tempo máximo de duração

using namespace std;

int pontuacao[MAXL], duracao[MAXC], tab[MAXL][MAXC], nAtracoes, tempoMax;

int knapsack(int atracao, int tempo_restante){
	if(tab[atracao][tempo_restante] >= 0){
		return tab[atracao][tempo_restante];
	}

	if(atracao > nAtracoes || !tempo_restante){
		return tab[atracao][tempo_restante] = 0;
	}

	int nao_vai = knapsack(atracao + 1, tempo_restante);

	if(duracao[atracao] <= tempo_restante){
		// Difere do knapsack original pois nesse caso pode haver repetição de elementos
		int vai = 
			max(pontuacao[atracao] + knapsack(atracao + 1, tempo_restante - duracao[atracao]), 
				pontuacao[atracao] + knapsack(atracao, tempo_restante - duracao[atracao]));

		return tab[atracao][tempo_restante] = max(vai, nao_vai);
	}

	return tab[atracao][tempo_restante] = nao_vai;
}

int main(){
	int teste=1;

	while(scanf("%d %d", &nAtracoes, &tempoMax) == 2 && nAtracoes != 0){
		memset(tab, -1, sizeof(tab));

		printf("Instancia %d\n", teste);

		for(int i = 1; i <= nAtracoes; i++){
			scanf("%d %d", &duracao[i], &pontuacao[i]);
		}

		printf("%d\n\n", knapsack(1, tempoMax));

		teste++;
	}
}