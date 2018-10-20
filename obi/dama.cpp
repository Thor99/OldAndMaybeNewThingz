#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int x1, y1, x2, y2;

    while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == 4 && (x1 + y1 + x2 + y2) != 0){
        int movimentos;

        if(abs(y2 - y1) == abs(x2 - x1) && x2 != x1 && y2 != y1){ // Mesma diagonal
            movimentos = 1;
        }

        else if(y2 == y1 && x2 != x1){ // Mesma horizontal
            movimentos = 1;
        }

        else if(x2 == x1 && y2 != y1){ // Mesma vertical
            movimentos = 1;
        }

        else if(x2 == x1 && y2 == y1){ // Mesma posição
            movimentos = 0;
        }

        else { // Nenhum dos casos acima
            movimentos = 2;
        }

        printf("%d\n", movimentos);
    }
}