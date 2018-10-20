#include <cstdio>
#define MAX 100010

int nRaios, nTiros;
long long int raios[MAX];

int busca_binaria(long long int val){
    int ini = 0;
    int fim = nRaios - 1;

    if(val > raios[fim]) {
        return 0;
    }

    while(ini < fim){
        int meio = (ini + fim) / 2;

        if(val <= raios[meio]){
            fim = meio;
        } else { // val > meio
            ini = meio + 1;
        }
    }

    return nRaios - fim; // Número de circulos que atinge
}

int main(){
    long long int pontos = 0;

    scanf("%d %d", &nRaios, &nTiros);

    for(int i = 0; i < nRaios; i++){
        scanf("%lld", &raios[i]);

        raios[i] = raios[i] * raios[i];
    }

    // raiz de (x ** 2 + y ** 2) é a função para gerar circulos. Se esse valor for menor ou igual a algum raio, soma um ponto.
    for(int i = 0; i < nTiros; i++){
        long long int x, y;
        scanf("%lld %lld", &x, &y);

        pontos += busca_binaria(x*x + y*y);
    }

    printf("%lld\n", pontos);
}