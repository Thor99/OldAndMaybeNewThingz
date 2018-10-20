#include <cstdio>

int main(){
    int N;  
    scanf("%d", &N);

    for(long long int i = 2; i <= N; i+=2){
        printf("%lld^2 = %lld\n", i, i * i);   
    }
}
