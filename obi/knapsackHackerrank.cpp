#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 2001

using namespace std;

int nObjetos, valorMax, peso[MAX], valor[MAX], dp[MAX][MAX];

int knapsack(int obj, int aguenta){
    if(dp[obj][aguenta] >= 0){
        return dp[obj][aguenta];
    }

    if(obj > nObjetos || !aguenta){
        return dp[obj][aguenta] = 0;
    }

    int nao_coloca = knapsack(obj+1, aguenta);

    if(peso[obj] <= aguenta){
        int coloca = max(valor[obj] + knapsack(obj+1, aguenta - peso[obj]), valor[obj] + knapsack(obj, aguenta - peso[obj]));

        return dp[obj][aguenta] = max(coloca, nao_coloca);
    }

    return dp[obj][aguenta] = nao_coloca;
}

int main(){
    int tests;
    scanf("%d", &tests);

    while(tests--){
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &nObjetos, &valorMax);
        for(int i = 1; i <= nObjetos; i++){
            int pesoValor;
            scanf("%d", &pesoValor);

            peso[i] = pesoValor;
            valor[i] = pesoValor;
        }

        printf("%d\n", knapsack(1, valorMax));
    }
}