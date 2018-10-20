#include <cstdio>

int main(){
    int maior = -1;
    int pos;
    for(int i = 1; i <= 100; i++){
        int val;
        scanf("%d", &val);

        if(val > maior){
            maior = val;
            pos = i;
        }
    }

    printf("%d\n%d\n", maior, pos);
}