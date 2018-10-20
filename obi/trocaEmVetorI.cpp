#include <cstdio>

int main(){
    int N[20];

    for(int i = 0; i < 20; i++){
        scanf("%d", &N[(20 - i) - 1]);
    }

    for(int i = 0; i < 20; i++){
        printf("N[%d] = %d\n", i, N[i]);
    }
}