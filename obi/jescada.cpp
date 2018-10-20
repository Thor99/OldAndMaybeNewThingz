#include <stdio.h>

int main(){
	int passadas[1001];
	int N;
	int tempo = 10;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i){
		scanf("%d", &passadas[i]);
	}

	for(int i = 1; i < N; i++){
		if(passadas[i] - passadas[i - 1] > 10){
			tempo += 10;
		} else {
			tempo += passadas[i] - passadas[i - 1];
		}
	}

	printf("%d", tempo);

	return 0;
}