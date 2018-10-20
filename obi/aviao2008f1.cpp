#include <cstdio>

const char getPosicao(int pos){
	if(pos == 1){
		return 'A';
	}

	else if(pos == 2){
		return 'B';
	}

	else if(pos == 3){
		return 'C';
	}

	else if(pos == 4){
		return 'D';
	}

	else if(pos == 5){
		return 'E';
	}

	else if(pos == 6){
		return 'F';
	}

	else if(pos == 7){
		return 'G';
	}

	else if(pos == 8){
		return 'H';
	}

	else if(pos == 9){
		return 'I';
	}

	else if(pos == 10){
		return 'J';
	}

	else if(pos == 11){
		return 'K';
	}

	else if(pos == 12){
		return 'L';
	}

	else if(pos == 13){
		return 'M';
	}

	else if(pos == 14){
		return 'N';
	}

	else if(pos == 15){
		return 'O';
	}

	else if(pos == 16){
		return 'P';
	}

	else if(pos == 17){
		return 'Q';
	}

	else if(pos == 18){
		return 'R';
	}

	else if(pos == 19){
		return 'S';
	}

	else if(pos == 20){
		return 'T';
	}

	else if(pos == 21){
		return 'U';
	}

	else if(pos == 22){
		return 'V';
	}

	else if(pos == 23){
		return 'W';
	}

	else if(pos == 24){
		return 'X';
	}

	else if(pos == 25){
		return 'Y';
	}

	else {
		return 'Z';
	}
}

int main(){
	int totalFileiras, posicoesPorFileiras, primeiraFileiraEco, posEmbarqueZuki;
	int fileiraAviaoZuki;
	char posicaoAviaoZuki;

	scanf("%d %d %d %d", &totalFileiras, &posicoesPorFileiras, &primeiraFileiraEco, &posEmbarqueZuki);

	fileiraAviaoZuki = (posEmbarqueZuki / posicoesPorFileiras) + primeiraFileiraEco; // Pega a fileira que zuki sentará

	posicaoAviaoZuki = getPosicao(posEmbarqueZuki % posicoesPorFileiras); // Pega a posição da fileira que zuki sentará

	if(fileiraAviaoZuki > totalFileiras){
		printf("PROXIMO VOO");
	} else {
		printf("%d %c", fileiraAviaoZuki, posicaoAviaoZuki);
	}
}