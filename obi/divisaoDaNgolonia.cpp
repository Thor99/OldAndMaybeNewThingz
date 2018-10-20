#include <cstdio>

int main(){
    int nConsultas;
    while(scanf("%d", &nConsultas) == 1 && nConsultas != 0){
        int divisorX, divisorY;
        scanf("%d %d", &divisorX, &divisorY);

        for(int i = 0; i < nConsultas; i++){
            int X, Y;
            scanf("%d %d", &X, &Y);

            if(X == divisorX || Y == divisorY){ // Divisa
                printf("divisa\n");
            }

            else if(X > divisorX && Y > divisorY){ // Primeiro quadrante
                printf("NE\n");
            }

            else if(X < divisorX && Y > divisorY){ // Segundo quadrante
                printf("NO\n");
            }

            else if(X < divisorX && Y < divisorY){ // Terceiro quadrante
                printf("SO\n");
            }

            else { // Quarto quadrante
                printf("SE\n");
            }
        }
    }
}