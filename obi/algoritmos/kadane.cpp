#include <cstdio>
#include <algorithm>

/* Algoritmo para achar o segmento de soma maxima de um array */

using namespace std;

int v[100000];
int best[100000];

int kadane(int arr[], int tam){
    best[0] = arr[0];
    int maior = best[0];

    for(int i = 1; i < tam; ++i){
        best[i] = max(arr[i], best[i - 1] + arr[i]);
        maior = max(maior, best[i]);
    }

    return maior;
}

int main() {
    int nElementos;

    scanf("%d", &nElementos);

    for(int i = 0; i < nElementos; ++i){
        scanf("%d", &v[i]);
    }

    printf("Soma máxima de subarray: %d\n", kadane(v, nElementos));
}
