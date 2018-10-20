#include <cstdio>

int main(){
    float tempo, velocidade;
    scanf("%f", &tempo);
    scanf("%f", &velocidade);

    printf("%.3f\n", (velocidade * tempo) / 12);
}