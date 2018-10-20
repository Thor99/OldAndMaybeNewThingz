#include <cstdio>

int main(){
    int n;
    int anos, meses, dias, restoAno;
    scanf("%d", &n);

    anos = n / 365;
    restoAno = n % 365;

    meses = restoAno / 30;
    dias = restoAno % 30;

    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);
}