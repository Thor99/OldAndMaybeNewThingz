#include <cstdio>

int main(){
    int N;

    scanf("%d", &N);

    while(N--){
        unsigned long long int acumulador = 1;
        int nCasas;

        scanf("%d", &nCasas);

        if(nCasas == 64){
            printf("1537228672809129 kg\n");
        } else {
            for(int i = 1; i <= nCasas; i++){
                acumulador *= 2;
            }

            printf("%llu kg\n", acumulador / 12000);
        }
    }
}