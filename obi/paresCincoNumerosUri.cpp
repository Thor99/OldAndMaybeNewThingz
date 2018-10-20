#include <cstdio>

int main(){
    int nPares = 0;
    for(int i = 0; i < 5; i++){
        int valor;
        scanf("%d", &valor);
        
        if(valor % 2 == 0){
            nPares++;
        }
    }

    printf("%d valores pares\n", nPares);
}
