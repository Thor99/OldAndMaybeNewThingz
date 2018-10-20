#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

bool isPrime(int n){
    int limite = (int) ceil(sqrt(n)) + 1;

    if(n == 2 || n == 3){
        return true;
    }

    if(n % 2 == 0 || n == 1 || n == 0){
        return false;
    }

    for(int i = 3; i < limite; i+=2){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int tests;

    scanf("%d", &tests);

    while(tests--){
        int N;
        int counter = 0;
        scanf("%d", &N);

        int dp[41];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for(int i = 1; i <= N; i++){
            dp[i] += dp[i - 1];
            if(i >= 4){
                dp[i] += dp[i - 4];
            }
        }

        for(int i = 1; i <= dp[N]; i++){
            if(isPrime(i) == true){
                counter++;
            }
        }

        printf("%d\n", counter);
    }
}