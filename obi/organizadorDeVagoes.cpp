#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int testes;
    scanf("%d", &testes);

    while(testes--){
        vector<int> trem;
        int tamTrem;
        int contador = 0;
        scanf("%d", &tamTrem);

        for(int i = 0; i < tamTrem; i++){
            int pos;
            scanf("%d", &pos);

            trem.push_back(pos);
        }

        // Bubble sort
        for(int i = 0; i < tamTrem - 1; i++){
            if(trem[i] > trem[i + 1]){
                int aux = trem[i];
                trem[i] = trem[i + 1];
                trem[i + 1] = aux;
                contador++;
                i = -1;
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", contador);
    }
}