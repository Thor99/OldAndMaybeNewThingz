#include <cstdio>
#define MAX 101

int main(){
	int nRedes, xi, xf, yi, yf, areaOcupada;
	int matriz[MAX][MAX];

	for(int i = 0; i < MAX; ++i){
		for(int j = 0; j < MAX; ++j){
			matriz[i][j] = 0;
		}
	}

	scanf("%d", &nRedes);

	for(int k = 0; k < nRedes; ++k){
		int menorX, menorY;
		scanf("%d %d %d %d", &xi, &xf, &yi, &yf);

		/* Preenchera todo o range que a rede cobre */
		for(int x = xi; x < xf; ++x){
			for(int y = yi; y < yf; ++y){
				matriz[x][y] = 1;
			}
		}
	}

	for(int i = 0; i < MAX; ++i){
		for(int j = 0; j < MAX; ++j){
			areaOcupada += matriz[i][j];
		}
	}

	printf("%d\n", areaOcupada);
}