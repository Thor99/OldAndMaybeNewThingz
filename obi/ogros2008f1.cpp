#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int nFaixas, nOgros;

	scanf("%d %d", &nFaixas, &nOgros);

	vector<int> faixas;
	vector<int> premioPorFaixa;
	vector<int> forcaPorOgro;

	faixas.push_back(1); // Primeira faixa é 1

	for(int i = 0; i < nFaixas - 1; ++i){
		int faixa;
		scanf("%d", &faixa);

		faixas.push_back(faixa);
	}

	for(int i = 0; i < nFaixas; ++i){
		int premio;
		scanf("%d", &premio);

		premioPorFaixa.push_back(premio);
	}

	for(int i = 0; i < nOgros; ++i){
		int forca;
		scanf("%d", &forca);

		forcaPorOgro.push_back(forca);
	}

	/* Esse loop pegará a pontuação de cada ogro no vector de forcaPorOgro e verá no vetor de faixas, em qual faixa esta força se
	aplica. Pra se aplicar numa faixa, tem que ser maior ou igual a ela e menor que a próxima. Quando é a ultima faixa, só tem que ser
	maior ou igual a ela. Ao acharmos a faixa,utilizamos o indice pra pegar o premio da faixa correspondente, no vetor de
	premioPorFaixa */

	for(int i = 0; i < nOgros; ++i){
		for(int k = 0; k < nFaixas; ++k){
			if(k == nFaixas - 1){
				if(forcaPorOgro[i] >= faixas[k]){
					printf("%d ", premioPorFaixa[k]);
				}
			} else {
				if(forcaPorOgro[i] >= faixas[k] && forcaPorOgro[i] < faixas[k + 1]){
					printf("%d ", premioPorFaixa[k]);
				}
			}
		}
	}
}
