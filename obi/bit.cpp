#include <stdio.h>

using namespace std;

int main(){
    int value, a50, a10, a5, a1, aux;
    int nTest = 1;

    while(scanf("%d", &value) == 1 && value != 0){
        printf("Teste %d\n", nTest);

        a50 = value / 50; // Quantas notas de 50 está presente no valor
        aux = value % 50; // O resto do valor, depois de todas as notas possiveis de 50 terem preenchido

        a10 = aux / 10; // Quantas notas de 10 está presente no valor
        aux = aux % 10; // O resto do valor, depois de todas as notas possiveis de 10 terem preenchido

        a5 = aux / 5; // Quantas notas de 5 está presente no valor
        aux = aux % 5; // O resto do valor, depois de todas as notas possiveis de 5 terem preenchido

        a1 = aux / 1; // Quantas notas de 1 está presente no valor

        printf("%d %d %d %d\n\n", a50, a10, a5, a1);
        nTest++;
    }
    return 0;
}
