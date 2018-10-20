#include <stdio.h>
#include <algorithm>

using namespace std;

int p1, p2;

int getSequence(int arr[], int length){
    int best[length];

    best[0] = arr[0];

    for (int i = 1; i < length; i++) {
        best[i] = max(arr[i], best[i-1] + arr[i]); // Usar if's para desmembrar essa funçaõ max e achar as partidas da melhor sequencia
    }

    int maior = best[0];

    for (int i = 1; i < length; i++) {
        if (best[i] > maior) {
            maior = best[i];
        }
    }

    return maior;
}

int main(){
    int matches, proScore, againstScore;
    int nTest = 1;

    while(scanf("%d", &matches) == 1 && matches != 0){
        int goalsBalance[matches];

        for(int i = 0; i < matches; i++){
            scanf("%d %d", &proScore, &againstScore);
            goalsBalance[i] = proScore - againstScore;
        }

        printf("%d\n", getSequence(goalsBalance, matches));
    }

    return 0;
}