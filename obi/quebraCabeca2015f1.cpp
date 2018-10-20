#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<char, int> > > pecas; // Numero da esquerda, (letra, numero da direita)

void printAnswer(int number, int quant){
	for(int k = 1; k < quant; ++k){
		if(pecas[k].first == number){ // Se a sua peça da direita for igual a peça da esquerda da anterior
			printf("%c", pecas[k].second.first);
			printAnswer(pecas[k].second.second, quant); // Chama a função passando sua peça da direita como parâmetro
			return;
		} 
	}
}

int main(){
	int quantidadePecas;

	scanf("%d", &quantidadePecas);

	for(int i = 0; i < quantidadePecas; ++i){
		int esq, dir;
		char letra;
		scanf("%d %c %d",&esq, &letra, &dir);

		pecas.push_back(make_pair(esq, make_pair(letra, dir)));
	}

	sort(pecas.begin(), pecas.end());

	printf("%c", pecas[0].second.first); // A primeira letra é a que a peça da esquerda começa com zero

	printAnswer(pecas[0].second.second, quantidadePecas);
}