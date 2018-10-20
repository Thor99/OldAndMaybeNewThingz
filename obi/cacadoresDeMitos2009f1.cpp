#include <cstdio>
#define MAX 600

int main(){
	int nRaios;
	int caiuMaisDeUmRaio = false;
	int mapa[MAX][MAX];

	for(int i = 0; i < MAX; ++i){
		for(int j = 0; j < MAX; ++j){
			mapa[i][j] = 0;
		}
	}

	scanf("%d", &nRaios);

	for(int i = 0; i < nRaios; ++i){
		int x, y;
		scanf("%d %d", &x, &y);

		if(mapa[x][y] == 0){
			mapa[x][y]++;
		} else {
			caiuMaisDeUmRaio = true;
		}
	}

	if(caiuMaisDeUmRaio){
		printf("1");
	} else {
		printf("0");
	}
}