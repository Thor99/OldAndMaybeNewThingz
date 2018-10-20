#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[20][30];
int nPedidos;
int peso[20], valor[20];

int knapsack(int obj, int aguenta){
    if(aguenta <= 0 || obj == nPedidos){
        return 0;
    }

    if(dp[obj][aguenta] >= 0){
        return dp[obj][aguenta];
    }

    if(peso[obj] > aguenta){
        return dp[obj][aguenta] = knapsack(obj + 1, aguenta);
    } else {
        int nao_coloca = knapsack(obj + 1, aguenta);
        int coloca = valor[obj] + knapsack(obj + 1, aguenta - peso[obj]);
        
        return dp[obj][aguenta] = max(coloca, nao_coloca);
    }
}

int main(){
    while(scanf("%d", &nPedidos) == 1 && nPedidos != 0){
        memset(dp, -1, sizeof(dp));
        int maxPizzas;
        scanf("%d", &maxPizzas);

        for(int i = 0; i < nPedidos; i++){
            scanf("%d %d", &valor[i], &peso[i]);
        }

        printf("%d min.\n", knapsack(0, maxPizzas));
    }
}