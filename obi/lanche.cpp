#include <cstdio>

int main(){
    int codigo;
    float quant;
    scanf("%d %f", &codigo, &quant);

    if(codigo == 1){
        printf("Total: R$ %.2f\n", quant * 4);
    } else if(codigo == 2){
        printf("Total: R$ %.2f\n", quant * 4.50);
    } else if(codigo == 3){
        printf("Total: R$ %.2f\n", quant * 5);
    } else if(codigo == 4){
        printf("Total: R$ %.2f\n", quant * 2);
    } else {
        printf("Total: R$ %.2f\n", quant * 1.50);
    }
}