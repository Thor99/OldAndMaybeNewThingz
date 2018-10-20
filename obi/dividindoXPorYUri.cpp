#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);

    while(n--){
        float x, y;
        scanf("%f %f", &x, &y);

        if(y == 0){
            printf("divisao impossivel\n");
        } else {
            printf("%.1f\n", x / y);
        }
    }
}