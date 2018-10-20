#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, a, b, c;
    vector<int> dp(4001);
    scanf("%d %d %d %d", &n, &a, &b, &c);

    fill(dp.begin(), dp.end(), 0);

    dp[a] = 1;
    dp[b] = 1;
    dp[c] = 1;

    for(int i = 1; i <= n; i++){
        if(i > a && dp[i - a] != 0){
            dp[i] = max(dp[i], dp[i - a] + 1);
        }

        if(i > b && dp[i - b] != 0){
            dp[i] = max(dp[i], dp[i - b] + 1);
        }

        if(i > c && dp[i - c] != 0){
            dp[i] = max(dp[i], dp[i - c] + 1);
        }
    }

    printf("%d\n", dp[n]);

}