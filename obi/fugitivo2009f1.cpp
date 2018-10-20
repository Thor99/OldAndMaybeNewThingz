#include <cstdio>

int main(){
	char direcao;
	int nRegistros, distanciaPercorrida;
	long long int distanciaMaxima, eixoX=0, eixoY=0; // Trabalha com ** 2
	bool ultrapassou = false;

	scanf("%d %lld\n", &nRegistros, &distanciaMaxima);

	for(int i = 0; i < nRegistros; ++i){
		scanf("%c %d", &direcao, &distanciaPercorrida);

		switch(direcao){
			case 'N': eixoY += distanciaPercorrida; break;
			case 'S': eixoY -= distanciaPercorrida; break;
			case 'L': eixoX += distanciaPercorrida; break;
			case 'O': eixoX -= distanciaPercorrida; break;
		}

		if(eixoX * eixoX + eixoY * eixoY > distanciaMaxima * distanciaMaxima){
			ultrapassou = true;
		}
	}

	if(ultrapassou){
		printf("1");
	} else {
		printf("0");
	}
}