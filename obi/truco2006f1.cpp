#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int pesosPorIndice[15] = {0, 8, 9, 10, 1, 2, 3, 4, 0, 0, 0, 5, 6, 7, 0};
	int N;
	int partidasAdalberto = 0, partidasBernardete = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i){
		int cartasAdalberto[3];
		int cartasBernadete[3];

		scanf("%d %d %d %d %d %d", &cartasAdalberto[0], &cartasAdalberto[1], &cartasAdalberto[2], &cartasBernadete[0], &cartasBernadete[1], &cartasBernadete[2]);

		sort(cartasAdalberto, cartasAdalberto+3); // Sort do menor para o maior
		sort(cartasBernadete, cartasBernadete+3); // Sort do menor para o maior

		if(pesosPorIndice[cartasBernadete[2]] > pesosPorIndice[cartasAdalberto[2]]){ // Bernadete tem a maior carta
			partidasBernardete++;
		} else {
			partidasAdalberto++;
		}
	}

	printf("%d %d", partidasAdalberto, partidasBernardete);
}