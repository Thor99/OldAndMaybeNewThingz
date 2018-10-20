#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXOBJETOS 701 // Quantidade máxima de objetos dispostos
#define MAXPESO 800 // Peso máximo aguentado pela mochila

using namespace std;

/* De maneira geral, um ladrão irá roubar uma casa com uma mochila que suporta um peso s. Ele vê n objetos na casa e sabe estimar
 o peso pi e o valor vi de cada objeto i. Com essas informações, qual o maior valor que o ladrão pode roubar sem rasgar sua
 mochila? */

int dp[MAXOBJETOS][MAXPESO], peso[MAXOBJETOS], valor[MAXOBJETOS];
int nObjetos;

int knapsack(int obj, int aguenta){
	if(aguenta <= 0 || obj == nObjetos){ // casos base: a mochila nãoa guenta mais ou já olhamos todos os objetos
		return 0;
	}

	if(dp[obj][aguenta] >= 0){ // se já calculamos esse estado de dp, retornamos ela
		return dp[obj][aguenta];
	}

	int nao_coloca = knapsack(obj + 1, aguenta); // Caso não coloque o objeto
	int coloca = valor[obj] + knapsack(obj + 1, aguenta - peso[obj]); // Caso coloque o objeto

	if(peso[obj] > aguenta){ // Se a mochila não aguentar o atual objeto, pular pro próximo
		return dp[obj][aguenta] = nao_coloca;
	} else { // Se não, ver se é melhor pular direto pro próximo ou pegar esse objeto e pular pro próximo
		return dp[obj][aguenta] = max(coloca, nao_coloca);
	}
}

int main(){
	memset(dp, -1, sizeof(dp));

	int pesoMax;
	scanf("%d %d", &nObjetos, &pesoMax);

	for(int i = 0; i < nObjetos; i++){
		scanf("%d %d", &peso[i], &valor[i]);
	}

	printf("%d\n", knapsack(0, pesoMax));
}
