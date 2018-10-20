#include <cstdio>

int main(){
    long int telescopio;
    int counter = 0;
    int nEstrelas;
    scanf("%ld", &telescopio);
    scanf("%d", &nEstrelas);

    for(int i = 0; i < nEstrelas; i++){
        long int estrela;
        scanf("%ld", &estrela);

        if(estrela * telescopio >= 40000000){
            counter++;
        }
    }

    printf("%d\n", counter);
}