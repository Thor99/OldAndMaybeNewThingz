#include <cstdio>

bool achou = false;

void start(int matrix[5][5], int i, int j){
    matrix[i][j] = 1; // Marca como visitado
    
    if(i == 4 && j == 4){
        achou = true;
        return;
    }

    if(matrix[i + 1][j] == 0 && i + 1 <= 4){
        start(matrix, i + 1, j);
    }

    if(matrix[i - 1][j] == 0 && i - 1 >= 0){
        start(matrix, i - 1, j);
    }

    if(matrix[i][j + 1] == 0 && j + 1 <= 4){
        start(matrix, i, j + 1);
    }

    if(matrix[i][j - 1] == 0 && j - 1 >= 0){
        start(matrix, i, j - 1);
    }
}

int main(){
    int testes;
    scanf("%d", &testes);

    while(testes--){
        int matriz[5][5];

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        start(matriz, 0, 0);

        if(achou){
            printf("COPS\n");
        } else {
            printf("ROBBERS\n");
        }

        achou = false;
    }
}