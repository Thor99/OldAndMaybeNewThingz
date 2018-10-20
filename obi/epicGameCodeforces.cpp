#include <cstdio>
#include <algorithm>

using namespace std;

int mdc(int a, int b){
    int maior = max(a, b);
    int menor = min(a, b);

    if(maior % menor == 0){
        return menor;
    }

    return mdc(menor, maior % menor);
}

int main(){
    int fixSimon, fixAntiSimon, remains;
    int jogadas = 1;
    scanf("%d %d %d", &fixSimon, &fixAntiSimon, &remains);

    while(true){
        if(jogadas % 2 != 0){ // Simon
            // Simon loss
            if(remains < mdc(fixSimon, remains)){
                printf("1\n");
                break;
            } else {
                remains -= mdc(fixSimon, remains);

                if(remains == 0){ // Simon wins
                    printf("0\n");
                    break;
                }
            }
        } else { // Antisimon
            // Antisimon loss
            if(remains < mdc(fixAntiSimon, remains)){
                printf("0\n");
                break;
            } else {
                remains -= mdc(fixAntiSimon, remains);

                if(remains == 0){ // Antisimon wins
                    printf("1\n");
                    break;
                }
            }
        }
        jogadas++;
    }
}
