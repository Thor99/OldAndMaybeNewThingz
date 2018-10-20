#include <cstdio>

int main(){
    long long first, second, n;
    long long dp[21];
    scanf("%lld %lld %lld", &first, &second, &n);

    dp[1] = first;
    dp[2] = second;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] * dp[i - 1]) + dp[i - 2];
    }

    printf("%lld\n", dp[n]);
}