#include <stdio.h>
#include <string.h>

int voos[101];

int main(){
	int numAeroportos, numVoos, de, para, teste=1, max, i;

	while (scanf("%d %d", &numAeroportos, &numVoos) == 2 && numAeroportos > 0){

		memset(voos, 0, sizeof(voos));

		while (numVoos-- > 0){
			scanf("%d %d", &de, &para);
			voos[de]++;
			voos[para]++;
		}

		max = voos[0];

		for (i = 1; i < numAeroportos; i++){ // Acha o máximo de voos de um aeroporto
			if (voos[i] > max){
				max = voos[i];
			}
		}

		printf("Teste %d\n", teste++);

		for (i = 0; i < numAeroportos; i++){ // Ve quais aeroportos possuem esse max de voos
			if (voos[i] == max){
				printf("%d ", i);
			}
		}

		printf("\n\n");
	}

	return 0;
}
