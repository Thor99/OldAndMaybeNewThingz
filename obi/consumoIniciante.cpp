#include <cstdio>

int main(){
    double km, litros;
    scanf("%lf", &km);
    scanf("%lf", &litros);

    printf("%.3f km/l\n", km / litros);
}