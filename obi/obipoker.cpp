#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cartas(5);

int pontuacao(){
	sort(cartas.begin(), cartas.end()); // Sort crescente

	// Uma quadra
	if((cartas[0] == cartas[1] && cartas[2] == cartas[3] && cartas[3] == cartas[1] && cartas[4] != cartas[0]) || (cartas[1] == cartas[2] && cartas[3] == cartas[4] && cartas[4] == cartas[1] && cartas[4] != cartas[0])){
		if(cartas[0] == cartas[1]){
			return cartas[0] + 180;
		} else {
			return cartas[4] + 180;
		}
	}

	// Uma trinca e um par
	else if((cartas[0] == cartas[1] && cartas[1] == cartas[2] && cartas[3] == cartas[4]) || (cartas[0] == cartas[1] && cartas[2] == cartas[3] && cartas[2] == cartas[4])){
		if(cartas[0] == cartas[1] && cartas[1] == cartas[2] && cartas[3] == cartas[4]){
			return cartas[0] + 160;
		} else {
			return cartas[4] + 160;
		}
	}

	// Uma trinca
	else if((cartas[0] == cartas[1] && cartas[1] == cartas[2] && cartas[3] != cartas[4]) || (cartas[1] == cartas[2] && cartas[2] == cartas[3] && cartas[0] != cartas[4]) || (cartas[2] == cartas[3] && cartas[3] == cartas[4] && cartas[0] != cartas[1])){
		if(cartas[0] == cartas[1] && cartas[1] == cartas[2]){
			return cartas[0] + 140;
		} else if(cartas[1] == cartas[2] && cartas[2] == cartas[3]){
			return cartas[1] + 140;
		} else {
			return cartas[4] + 140;
		}
	}

	// Dois pares
	else if((cartas[0] == cartas[1] && cartas[2] == cartas[3] && cartas[2] != cartas[0] && cartas[4] != cartas[0] && cartas[4] != cartas[2]) || (cartas[1] == cartas[2] && cartas[3] == cartas[4] && cartas[1] != cartas[3] && cartas[1] != cartas[0] && cartas[3] != cartas[0]) || (cartas[0] == cartas[1] && cartas[3] == cartas[4] && cartas[0] != cartas[3] && cartas[2] != cartas[0] && cartas[2] != cartas[3])){
		if(cartas[0] == cartas[1] && cartas[2] == cartas[3]){
			return 3 * max(cartas[0], cartas[2]) + 2 * min(cartas[0], cartas[2]) + 20;
		} else if(cartas[1] == cartas[2] && cartas[3] == cartas[4] && cartas[1] != cartas[3] && cartas[1] != cartas[0] && cartas[3] != cartas[0]){
			return 3 * max(cartas[1], cartas[3]) + 2 * min(cartas[1], cartas[3]) + 20;
		} else {
			return 3 * max(cartas[0], cartas[3]) + 2 * min(cartas[0], cartas[3]) + 20;
		}
	}

	// Um par
	else if((cartas[0] == cartas[1] && cartas[1] != cartas[2] && cartas[2] != cartas[3] && cartas[3] != cartas[4]) || (cartas[1] == cartas[2] && cartas[2] != cartas[0] && cartas[0] != cartas[3] && cartas[3] != cartas[4]) || (cartas[2] == cartas[3] && cartas[3] != cartas[0] && cartas[0] != cartas[1] && cartas[1] != cartas[4]) || (cartas[3] == cartas[4] && cartas[4] != cartas[0] && cartas[0] != cartas[1] && cartas[1] != cartas[2])){
		if(cartas[0] == cartas[1]){
			return cartas[0];
		} else if(cartas[1] == cartas[2]){
			return cartas[1];
		} else if(cartas[2] == cartas[3]){
			return cartas[2];
		} else {
			return cartas[3];
		}
	}

	// Os valores das cartas são x, x+1, x+2, x+3 e x+4
	else if((cartas[0] == cartas[1] - 1 && cartas[0] == cartas[2] - 2 && cartas[0] == cartas[3] - 3) || (cartas[1] == cartas[2] - 1 && cartas[1] == cartas[3] - 2 && cartas[1] == cartas[4] - 3)){
		if(cartas[0] == cartas[1] - 1 && cartas[0] == cartas[2] - 2 && cartas[0] == cartas[3] - 3){
			return cartas[0] + 200;
		} else {
			return cartas[1] + 200;
		}
	}

	// Todas as cartas são distintas
	else {
		return 0;
	}
}

int main(){
	int nTestes;

	scanf("%d", &nTestes);

	for(int teste = 1; teste <= nTestes; ++teste){
		cartas.clear(); // A cada teste, limpa o vector de cartas

		printf("Teste %d\n", teste);

		for(int i = 0; i < 5; ++i){
			int carta;
			scanf("%d", &carta);

			cartas.push_back(carta);
		}

		printf("%d\n\n", pontuacao());
	}
}