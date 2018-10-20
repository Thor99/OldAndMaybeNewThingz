#include <cstdio>
#include <string.h>
#define MAX 10000

int matriz[MAX][MAX];
int frequencia[51];

int maisFrequenteLinha(int pos, int tam){
	int maior = 0;
	int maiorNum = -1;

	// Preencher o vetor de frequencias
	for(int j = 0; j < tam; ++j){
		frequencia[matriz[pos][j]]++;
	}

	// Achar a maior frequencia
	for(int j = 0; j < tam; ++j){
		if(frequencia[matriz[pos][j]] > maior){
			maior = frequencia[matriz[pos][j]];
		}
	}

	// Achar o maior numero que tem a maior frequencia
	for(int j = 0; j < tam; ++j){
		if(frequencia[matriz[pos][j]] == maior){
			if(matriz[pos][j] > maiorNum){
				maiorNum = matriz[pos][j];
			}
		}
	}
	
	return maiorNum;	
}

int maisFrequenteColuna(int pos, int tam){
	int maior = 0;
	int maiorNum = -1;

	// Preencher o vetor de frequencias
	for(int i = 0; i < tam; ++i){
		frequencia[matriz[i][pos]]++;
	}

	// Achar a maior frequencia
	for(int i = 0; i < tam; ++i){
		if(frequencia[matriz[i][pos]] > maior){
			maior = frequencia[matriz[i][pos]];
		}
	}

	// Achar o maior numero que tem a maior frequencia
	for(int i = 0; i < tam; ++i){
		if(frequencia[matriz[i][pos]] == maior){
			if(matriz[i][pos] > maiorNum){
				maiorNum = matriz[i][pos];
			}
		}
	}

	return maiorNum;	
}		

int main(){
	int tamTabuleiro, nOperacoes, tipoOperacao, valor, posicao;

	scanf("%d %d", &tamTabuleiro, &nOperacoes);

	for(int n = 0; n < nOperacoes; ++n){
		scanf("%d", &tipoOperacao);
		printf("Operação: %d", tipoOperacao);
		if(tipoOperacao == 1 || tipoOperacao == 2){
			scanf("%d %d", &posicao, &valor);
			printf("Posição: %d  Valor:%d", posicao, valor);

			if(tipoOperacao == 1){
				for(int j = 0; j < tamTabuleiro; ++j){
					matriz[posicao][j] = valor;
				}
			} else { // 2
				for(int i = 0; i < tamTabuleiro; ++i){
					matriz[i][posicao] = valor;
				}
			}
		} else {
			memset(frequencia, 0, sizeof(frequencia));

			scanf("%d", &posicao);
			printf("POSICAO: %d", posicao); // ERRO AQUI

			if(tipoOperacao == 3){
				printf("%d\n", maisFrequenteLinha(posicao, tamTabuleiro));
			}
			else {
				printf("%d\n", maisFrequenteColuna(posicao, tamTabuleiro));
			}
		}
	}
}