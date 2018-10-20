#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int valor;
        scanf("%d", &valor);

        if(valor == 0){
            printf("NULL\n");
        } else {
            if(valor % 2 == 0){
                printf("EVEN ");
            } else {
                printf("ODD ");   
            }
            
            if(valor > 0){
                printf("POSITIVE\n");
            } else {
                printf("NEGATIVE\n");
            }
        }
    }
}
