#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXOBJETOS 100
#define MAXPESO 1000

using namespace std;

// Classico knapsack sem repetição

int dp[MAXOBJETOS][MAXPESO], peso[MAXOBJETOS], valor[MAXOBJETOS];
int nPacotes;

int knapsack(int obj, int aguenta){
	if(aguenta <= 0 || obj == nPacotes){
		return 0;
	}

	if(dp[obj][aguenta] >= 0){
		return dp[obj][aguenta];
	}

    int nao_coloca = knapsack(obj + 1, aguenta);
	int coloca = valor[obj] + knapsack(obj + 1, aguenta - peso[obj]);

	if(peso[obj] > aguenta){
		return dp[obj][aguenta] = nao_coloca;
	} else {
		return dp[obj][aguenta] = max(coloca, nao_coloca);
	}
}


int main(){
    int nGalhos;
    scanf("%d", &nGalhos);

    for(int g = 1; g <= nGalhos; g++){
        memset(dp, -1, sizeof(dp));
        memset(peso, -1, sizeof(peso));
        memset(valor, -1, sizeof(valor));

        int pesoGalhoAguenta;

        scanf("%d", &nPacotes);
        scanf("%d", &pesoGalhoAguenta);

        for(int i = 0; i < nPacotes; i++){
            scanf("%d %d", &valor[i], &peso[i]);
        }

        printf("Galho %d:\n", g);
        printf("Numero total de enfeites: %d\n\n", knapsack(0, pesoGalhoAguenta));
    }

}