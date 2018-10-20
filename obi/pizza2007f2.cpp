#include <cstdio>
#include <algorithm>

using namespace std;

int vet[100000];
int best[100000];

int kadane(int arr[], int tam){
	best[0] = arr[0];

	for(int i = 1; i < tam; ++i){
		best[i] = max(arr[i], best[i - 1] + arr[i]);
	}

	int maior = best[0];

	for(int i = 1; i < tam; ++i){
		if(best[i] > maior){
			maior = best[i];
		}
	}

	return maior;
}

int kadaneCircular(int arr[], int tam){
	int max_kadane = kadane(arr, tam);

	int max_wrap = 0;
	for(int i = 0; i < tam; ++i){
		max_wrap += arr[i];
		arr[i] = -arr[i];
	}

	max_wrap += kadane(arr, tam); 

	int maiorSomaCircular = max(max_wrap, max_kadane);

	if(maiorSomaCircular <= 0){
		return 0;
	} else {
		return maiorSomaCircular;
	}
}

int main() {
    int nElementos;

    scanf("%d", &nElementos);

    for(int i = 0; i < nElementos; ++i){
        scanf("%d", &vet[i]);
    }

    printf("%d", kadaneCircular(vet, nElementos));
}