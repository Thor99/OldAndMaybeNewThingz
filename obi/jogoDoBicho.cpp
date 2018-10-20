#include <cstdio>
#include <cmath>

/*
47990 % 10000 = 7990
56708 % 1000 = 708
5689 % 100 = 89
*/

int main(){
    double valor;
    int numeroEscolhido, numeroSorteado;

    while(scanf("%lf %d %d", &valor, &numeroEscolhido, &numeroSorteado) == 3 && valor != 0){
        if(numeroEscolhido % 10000 == numeroSorteado % 10000){ // Quatro ultimos digitos iguais
            printf("%.2f\n", valor * 3000);
        }

        else if(numeroEscolhido % 1000 == numeroSorteado % 1000){ // Tres ultimos digitos iguais
            printf("%.2f\n", valor * 500);
        }

        else if(numeroEscolhido % 100 == numeroSorteado % 100){ // Tres ultimos digitos iguais
            printf("%.2f\n", valor * 50);
        }

        else {
            if((numeroEscolhido % 100 == 97 || numeroEscolhido % 100 == 98 || numeroEscolhido % 100 == 99 || numeroEscolhido % 100 == 00) && (numeroSorteado % 100 == 97 || numeroSorteado % 100 == 98 || numeroSorteado % 100 == 99 || numeroSorteado % 100 == 00)){ // Caso especial
                printf("%.2f\n", valor * 16);
            }

            else if(ceil((float)(numeroEscolhido % 100) / 4) == ceil((float)(numeroSorteado % 100) / 4)){ // Mesmo grupo
                printf("%.2f\n", valor * 16);
            }

            else { // Não ganha nada
                printf("0.00\n");
            }
        }
    }
}