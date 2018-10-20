#include <cstdio>

int main(){
    int nPositivos = 0;

    for(int i = 0; i < 6; i++){
        float n;
        scanf("%f", &n);

        if(n > 0){
            nPositivos++;
        }
    }

    printf("%d valores positivos\n", nPositivos); 
}
