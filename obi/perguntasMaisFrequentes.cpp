#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int nNumeros, quantidadeMinima;
    while(scanf("%d %d", &nNumeros, &quantidadeMinima) == 2 && nNumeros != 0){
        int freq[1001];
        int quantidade = 0;
        memset(freq, 0, sizeof(freq));

        for(int i = 0; i < nNumeros; i++){
            int valor;
            scanf("%d", &valor);

            freq[valor]++;
        }

        // Sort maior para menor
        sort(freq, freq + 1001, greater<int>());

        for(int i = 0; i < 1001; i++){
            if(freq[i] >= quantidadeMinima){
                quantidade++;
            } else { // como ta ordenado, não haverá mais a partir desse ponto.
                break;
            }
        }

        printf("%d\n", quantidade);
    }
}