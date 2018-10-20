#include <cstdio>
#include <algorithm>
#define MAX 100001

using namespace std;

int fatias[MAX];
int best[MAX];
int best2[MAX];

int kadaneCircular(int arr[], int tam){
	best[0] = arr[0];

	for(int i = 1; i < tam; ++i){
		best[i] = max(arr[i], best[i - 1] + arr[i]);
	}

	best2[0] = max(arr[0], best[tam - 1] + arr[0]);

	for(int i = 1; i < tam; ++i){
		best2[i] = max(arr[i], best2[i - 1] + arr[i]);
	}

	int maior1 = best[0];
	int maior2 = best2[0];

	for(int i = 1; i < tam; ++i){
		if(best[i] > maior1){
			maior1 = best[i];
		}

		if(best2[i] > maior2){
			maior2 = best2[i];
		}
	}

	int maior = max(maior1, maior2);


	if(maior < 0){
		return 0;
	} else {
		return maior;
	}
}

int main(){
	int nFatias;

	scanf("%d", &nFatias);

	for(int i = 0; i < nFatias; ++i){
		scanf("%d", &fatias[i]);
	}

	printf("%d", kadaneCircular(fatias, nFatias));
}