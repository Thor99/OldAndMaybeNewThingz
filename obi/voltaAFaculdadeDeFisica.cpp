#include <cstdio>

int main(){
    int velocidade, tempo;

    while(scanf("%d %d", &velocidade, &tempo) != EOF){
        int deslocamento = (velocidade * tempo) * 2;
        printf("%d\n", deslocamento);
    }
}