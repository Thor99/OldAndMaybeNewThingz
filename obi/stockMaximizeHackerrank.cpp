#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int testes;
    scanf("%d", &testes);

    while(testes--){
        int N;
        vector<int> prices;
        long long int profit = 0;
        scanf("%d", &N);

        for(int i = 0; i < N; i++){
            int price;
            scanf("%d", &price);

            prices.push_back(price);
        }

        int max_local_profit = 0;
        for(int i = N - 1; i >= 0; i--){
            max_local_profit = max(max_local_profit, prices[i]);
            profit += (long long int) max_local_profit - prices[i];
        }

        printf("%lld\n", profit);
    }
}