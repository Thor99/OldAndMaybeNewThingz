#include <cstdio>

int main(){
    double raio;
    double area;

    scanf("%lf", &raio);

    area = 3.14159 * (raio * raio);

    printf("A=%.4f\n", area);
}