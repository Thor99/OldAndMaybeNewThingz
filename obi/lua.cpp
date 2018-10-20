#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    int quantTemps, sizeIntervalos;
    int nTests = 1;

    while(scanf("%d %d", &quantTemps, &sizeIntervalos) == 2 && quantTemps != 0){
        int vetTemps[10000];
        int vetMedia[10000];
        int vetSoma[10000];
        int menorMedia = 400; // Inicializa a menor média com um valor muito alto
        int maiorMedia = -400; // Inicializa a maior média com um valor muito baixo

        for(int i = 0; i < quantTemps; i++){
            scanf("%d", &vetTemps[i]);
        }

        // Faz o vetor de soma manual pro primeiro elemento
        for(int i = 0; i < sizeIntervalos; ++i){
            vetSoma[0] += vetTemps[i];
        }

        vetMedia[0] = vetSoma[0] / sizeIntervalos;

        // Para os elementos após o primeiro, tem como buscar a soma baseado nos elementos anteriores (No papel visualiza melhor)
        for(int k = 1; k <= (quantTemps - sizeIntervalos); k++){
            vetSoma[k] = vetSoma[k - 1] - vetTemps[k - 1] + vetTemps[k + (sizeIntervalos - 1)];

            vetMedia[k] = vetSoma[k] / sizeIntervalos;
        }
    
        for(int l = 0; l <= (quantTemps - sizeIntervalos); l++){ // No vetor de médias, pega a maior e a menor média 
            if(vetMedia[l] > maiorMedia){
                maiorMedia = vetMedia[l];
            }

            if(vetMedia[l] < menorMedia){
                menorMedia = vetMedia[l];
            }
        }

        printf("Teste %d\n%d %d\n\n", nTests, menorMedia, maiorMedia);

        nTests++;

        memset(vetTemps, 0, sizeof(vetTemps)); // Ao fim de cada teste, reseta os vetores
        memset(vetSoma, 0, sizeof(vetSoma)); // Ao fim de cada teste, reseta os vetores
        memset(vetMedia, 0, sizeof(vetMedia)); // Ao fim de cada teste, reseta os vetores
    }

    return 0;
}
