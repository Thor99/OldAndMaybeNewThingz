#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 51
#define MAXPESO 101

using namespace std;

int dp[MAX][MAXPESO], valor[MAX], peso[MAX], nProjeteis;

int knapsack(int obj, int aguenta){
    if(dp[obj][aguenta] >= 0){
        return dp[obj][aguenta];
    }

    if(obj > nProjeteis || !aguenta){
        return dp[obj][aguenta] = 0;
    }

    int nao_coloca = knapsack(obj + 1, aguenta);

    if(peso[obj] <= aguenta){
        int coloca = valor[obj] + knapsack(obj + 1, aguenta - peso[obj]);

        return dp[obj][aguenta] = max(coloca, nao_coloca);
    }

    return dp[obj][aguenta] = nao_coloca;
}

int main(){
    int testes;
    scanf("%d", &testes);
    while(testes--){
        memset(dp, -1, sizeof(dp));
        memset(peso, -1, sizeof(peso));
        memset(valor, -1, sizeof(valor));

        int pesoAguentado;
        int resistenciaCastelo;

        scanf("%d", &nProjeteis);

        for(int i = 1; i <= nProjeteis; i++){
            scanf("%d %d", &valor[i], &peso[i]);
        }

        scanf("%d", &pesoAguentado);
        scanf("%d", &resistenciaCastelo);

        int danoTotal = knapsack(1, pesoAguentado);

        if(danoTotal >= resistenciaCastelo){
            printf("Missao completada com sucesso\n");
        } else {
            printf("Falha na missao\n");
        }
    }
}