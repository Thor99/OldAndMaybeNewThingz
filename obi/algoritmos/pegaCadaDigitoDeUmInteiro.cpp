#include <cstdio>

/* Pega cada digito de um inteiro, das unidades, para dezenas... */

int numeroDeDigitos(int n){
    int tamanho = 0;
    while(n != 0){
       tamanho++;
       n = n / 10;
   }

   return tamanho;
}

int main(){
    int num;
    int digito;
    scanf("%d", &num);

    int tam = numeroDeDigitos(num);

    for(int i = 0; i < tam; i++){
        digito = num % 10;
        num = num / 10;
        printf("%d\n", digito);
    }
}