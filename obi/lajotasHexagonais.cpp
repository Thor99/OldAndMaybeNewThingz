#include <cstdio>

/* Fiz no papel até 5 lajotas, e deu a sequencia: 1, 2, 3, 5, 8. Arrisquei ser a sequencia de fibonacci. */

int main(){
    long long int fib[41];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;

    for(int i = 3; i < 41; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int nPecas;
    while(scanf("%d", &nPecas) == 1 && nPecas != 0){
        printf("%lld\n", fib[nPecas]);
    }
}