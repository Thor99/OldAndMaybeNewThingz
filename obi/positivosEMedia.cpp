#include <cstdio>

int main(){
    float quantidadePositivos = 0;
    float somaPositivos = 0;

    for(int i = 0; i < 6; i++){
        float num;
        scanf("%f", &num);

        if(num > 0){
            somaPositivos += num;
            quantidadePositivos++;
        }
    }

    printf("%.0f valores positivos\n", quantidadePositivos);
    printf("%.1f\n", somaPositivos / quantidadePositivos);
}