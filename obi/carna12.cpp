#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    float notas[5];

    for(int i = 0; i < 5; i++){
        scanf("%f", &notas[i]);
    }

    sort(notas, notas+5); // Ordena crescentemente

    printf("%.1f\n", notas[1] + notas[2] + notas[3]); // Retira a menor e a maior nota

    return 0;
}
