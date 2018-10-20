#include <stdio.h>
#include <stdlib.h>

// Busca binária
// Só pode ser usao depois de ter ordenado um vetor
// Acha o número que ta no meio do vetor
// Se o número que você ta buscando é menor que o valor do meio, voce busca na esquerda, se não, direita
// Depois de ir pra esquerda ou direita também acha o valor do meio, e repete.
// Percorre no máximo log n (base 2) elementos


int busca_bin(int* v, int n, int valor){
    int ini = 0; // Primeiro índice do vetor
    int fim = n - 1; // Ultimo indice do vetor
    //  Se ini e fim se sobreporem, acabou o vetor e não achou o valor
    int meio;

    while(ini <= fim){
        meio = (ini + fim) / 2;
        if(v[meio] > valor){ // Busca o valor percorrendo a direita do meio
            fim = meio - 1;
        }
        else if(v[meio] < valor) { // Busca o valor percorrendo a direita do meio
            ini = meio + 1;
        }
        else{ // v[meio] == valor
            return 1;
        }
    }
    return 0; // Não encontrou o valor
}

int main(){
    int v[5] = {1,2,3,4,5};
    int valor;
    scanf("%d", &valor);
    if(busca_bin(v, 5, valor) == 1){
        printf("Valor encontrado!\n");
    } else {
        printf("Valor não encontrado!\n");
    }
}