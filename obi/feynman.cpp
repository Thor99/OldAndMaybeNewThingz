#include <cstdio>
#include <vector>

using namespace std;

/* Monta a sequencia até 5, e acha a relação. */

/* dp[i] = dp[i - 1] + acumulador ** 2 */

int main(){
    int N;
    int acumulador = 2;
    vector<int> dp;

    dp.push_back(0);
    dp.push_back(1);

    for(int i = 2; i < 101; i++){
        dp.push_back(dp[i - 1] + acumulador * acumulador);
        acumulador += 1;
    }

    while(scanf("%d", &N) == 1 && N != 0){
        printf("%d\n", dp[N]);
    }
}