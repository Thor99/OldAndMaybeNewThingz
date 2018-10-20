#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 10000000

using namespace std;

int main(){
    int nMoedas, valorDesejado;
    vector<int> moedas;
    vector<int> dp;

    // dp[i] = número mínimo de moedas para atingir o valor i

    dp.push_back(0); // dp[0] = 0

    scanf("%d %d", &nMoedas, &valorDesejado);

    for(int i = 1; i <= valorDesejado; ++i) dp.push_back(INF);

    for(int i = 0; i < nMoedas; ++i){
        int valorMoeda;
        scanf("%d", &valorMoeda);

        moedas.push_back(valorMoeda);
    }

    sort(moedas.begin(), moedas.end());

    // dp[i] = min(dp[i], dp[i - moedas[j]] + 1), se moedas[j] <= i
    for(int i = 1; i <= valorDesejado; ++i){
        for(int j = 0; j < moedas.size(); ++j){
            if(moedas[j] > i){
                break;
            } else {
                dp[i] = min(dp[i], dp[i - moedas[j]] + 1);
            }
        }
    }

    printf("Valor minimo de moedas para atingir o valor %d: %d\n", valorDesejado, dp[valorDesejado]);
}
