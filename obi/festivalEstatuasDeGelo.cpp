#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#define INF 100000000

using namespace std;

int main(){
    int nTests;

    scanf("%d", &nTests);

    for(int t = 0; t < nTests; ++t){
        vector<int> blocos;
        int nTipoDeBlocos, comprimentoDesejado;
        vector<int> dp;
        dp.push_back(0);

        scanf("%d %d", &nTipoDeBlocos, &comprimentoDesejado);

        for(int i = 1; i <= comprimentoDesejado; ++i) dp.push_back(INF);

        for(int i = 0; i < nTipoDeBlocos; ++i){
            int comprimento;
            scanf("%d", &comprimento);

            blocos.push_back(comprimento);
        }

        sort(blocos.begin(), blocos.end()); // Sort crescente

        for(int i = 1; i <= comprimentoDesejado; ++i){
            for(int j = 0; j < blocos.size(); ++j){
                if(blocos[j] > i){
                    break;
                } else {
                    dp[i] = min(dp[i], dp[i - blocos[j]] + 1);
                }
            }
        }

        printf("%d\n", dp[comprimentoDesejado]);
    }
}
