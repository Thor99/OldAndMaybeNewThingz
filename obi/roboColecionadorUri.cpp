#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

char orient;
int nLinhas, nColunas, nInstrucoes;
int startI, startJ;
int figurinhas = 0;

void jogar(char mat[100][100], char comando){
    if(comando == 'E'){
        if(orient == 'N'){
            orient = 'O';
        }

        else if(orient == 'S'){
            orient = 'L';
        }

        else if(orient == 'L'){
            orient = 'N';
        }

        else { // Orient: O
            orient = 'S';
        }
    }

    else if(comando == 'D'){
        if(orient == 'N'){
            orient = 'L';
        }

        else if(orient == 'S'){
            orient = 'O';
        }

        else if(orient == 'L'){
            orient = 'S';
        }

        else { // Orient: O
            orient = 'N';
        }
    }

    else { // comando: F
        if(orient == 'N'){
            // Se não ficar paralisado
            if(startI - 1 >= 0 && mat[startI - 1][startJ] != '#'){
                if(mat[startI - 1][startJ] == '*'){
                    figurinhas++;
                    mat[startI - 1][startJ] = '.';
                }

                startI = startI - 1;
            }
        }

        else if(orient == 'S'){
            // Se não ficar paralisado
            if(startI + 1 < nLinhas && mat[startI + 1][startJ] != '#'){
                if(mat[startI + 1][startJ] == '*'){
                    figurinhas++;
                    mat[startI + 1][startJ] = '.';
                }

                startI = startI + 1;
            }
        }

        else if(orient == 'L'){
            // Se não ficar paralisado
            if(startJ + 1 < nColunas && mat[startI][startJ + 1] != '#'){
                if(mat[startI][startJ + 1] == '*'){
                    figurinhas++;
                    mat[startI][startJ + 1] = '.';
                }

                startJ = startJ + 1;
            }
        }

        else { // Orient: O
            // Se não ficar paralisado
            if(startJ - 1 >= 0 && mat[startI][startJ - 1] != '#'){
                if(mat[startI][startJ - 1] == '*'){
                    figurinhas++;
                    mat[startI][startJ - 1] = '.';
                }

                startJ = startJ - 1;
            }
        }
    }
}

int main(){
    while(scanf("%d %d %d", &nLinhas, &nColunas, &nInstrucoes) == 3 && nLinhas != 0){
        char matriz[100][100];
        string instrucoes;

        for(int i = 0; i < nLinhas; i++){
            for(int j = 0; j < nColunas; j++){
                char casa;
                scanf(" %c", &casa);
                matriz[i][j] = casa;

                if(casa == 'N' || casa == 'S' || casa == 'L' || casa == 'O'){
                    startI = i;
                    startJ = j;

                    orient = casa;
                }
            }
        }

        cin >> instrucoes;
        for(int i = 0; i < nInstrucoes; i++){
            jogar(matriz, instrucoes[i]);
        }

        printf("%d\n", figurinhas);

        figurinhas = 0;
    }
}