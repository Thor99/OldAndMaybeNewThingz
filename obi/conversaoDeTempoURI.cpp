#include <cstdio>

int main(){
    int n, horas, minutos, segundos, restoHora;
    scanf("%d", &n);

    horas = n / 3600;
    restoHora = n % 3600;

    minutos = restoHora / 60;

    segundos = restoHora % 60;

    printf("%d:%d:%d\n", horas, minutos, segundos);
}