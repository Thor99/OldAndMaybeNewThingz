#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int numeroDeDigitos(long long int n){
    int tamanho = 0;
    while(n != 0){
       tamanho++;
       n = n / 10;
   }

   return tamanho;
}

int main(){
    long int a, b;

    while(scanf("%ld %ld", &a, &b) == 2 && (a + b) != 0){
        vector<int> freq(10);
        fill(freq.begin(), freq.end(), 0);

        // Percorre o range de números
        for(long int i = a; i <= b; i++){
            int tam = numeroDeDigitos(i); // Retorna o número de dígitos do número atual
            long long int numero = i;
            int digito;

            // Percorre cada digito do número atual
            for(int k = 0; k < tam; k++){
                digito = numero % 10;
                numero = numero / 10;

                freq[digito]++;
            }
        }

        for(int i = 0; i < 10; i++){
            printf("%d ", freq[i]);
        }

        printf("\n");
    }
}