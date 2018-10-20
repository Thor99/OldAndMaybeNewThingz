#include <cstdio>

int main(){
    float volume, diametro;

    while(scanf("%f %f", &volume, &diametro) != EOF){
        printf("ALTURA = %.2f\n", volume / (3.14 * (diametro / 2) * (diametro / 2)));
        printf("AREA = %.2f\n", 3.14 * (diametro / 2) * (diametro / 2));
    }
}