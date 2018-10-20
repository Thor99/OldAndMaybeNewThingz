#include <cstdio>

int josephus(int n, int k){
    if(n == 1){
        return 1;
    } else {
        /* The position returned by josephus(n - 1, k) is adjusted because the
           recursive call josephus(n - 1, k) considers the original position
           k%n + 1 as position 1 */
        return (josephus(n - 1, k) + k-1) % n + 1;
    }
}

int main(){
    int nTests;

    scanf("%d", &nTests);

    for(int i = 0; i < nTests; i++){
        int nPessoas, salto;
        scanf("%d %d", &nPessoas, &salto);

        printf("Case %d: %d\n", i + 1, josephus(nPessoas, salto));
    }
}
