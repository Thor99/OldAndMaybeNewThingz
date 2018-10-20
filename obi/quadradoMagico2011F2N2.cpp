#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

int main(){
    int n;
    long int matriz[MAX][MAX];
    long long int sumOutro;
    long long int sumInicial;
    bool magico = true;
    vector<long int> numeros;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%ld", &matriz[i][j]);
            numeros.push_back(matriz[i][j]);
        }
    }

    sort(numeros.begin(), numeros.end());

    int tamVec = numeros.size();
    for(int i = 0; i < tamVec; i++){
        if(numeros[i] != i + 1){ // Número que devia estar no quadrado não esta lá.
            magico = false;
            break;
        }
    }

    if(magico == false){
        printf("0\n");
    } else {
        // Ainda não foi acusado que é false, pegamos a soma da primeiro linha primeiro para testar.
        sumInicial = 0;
        for(int j = 0; j < n; j++){
            sumInicial += matriz[0][j];
        }

        // Analisamos a soma das outras linhas e comparamos com a da primeira;
        for(int i = 1; i < n; i++){
            sumOutro = 0;
            for(int j = 0; j < n; j++){
                sumOutro += matriz[i][j];
            }

            if(sumInicial != sumOutro){
                magico = false;
                break;
            }
        }

        if(magico == false){
            printf("0\n");
        } else {
            // Ainda não foi acusado que é false, analisamos as colunas.
            for(int j = 0; j < n; j++){
                sumOutro = 0;
                for(int i = 0; i < n; i++){
                    sumOutro += matriz[i][j];
                }

                if(sumInicial != sumOutro){
                    magico = false;
                    break;
                }
            }

            if(magico == false){
                printf("0\n");
            } else {
                // Ainda não foi acusado que é false, analisamos a diagonal principal.
                sumOutro = 0;
                for(int i = 0; i < n; i++){
                    sumOutro += matriz[i][i];
                }

                // Se no último teste revelar que a soma deu diferente, printa 0. Se não, printa a soma.
                if(sumInicial != sumOutro){
                    printf("0\n");
                } else {
                    printf("%lld\n", sumOutro);
                }
            }
        }
    }
}