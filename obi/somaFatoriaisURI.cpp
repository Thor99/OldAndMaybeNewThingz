#include <cstdio>

long long int fat(int n){
    if(n == 0){
        return 1;
    }

    return n * fat(n - 1);
}

int main(){
    int x, y;

    while(scanf("%d %d", &x, &y) != EOF){
        long long int resp;

        resp = fat(x) + fat(y);

        printf("%lld\n", resp);
    }
}