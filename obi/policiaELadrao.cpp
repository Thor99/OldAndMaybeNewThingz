#include <cstdio>
#include <vector>

using namespace std;

/* Transformo a matriz em uma lista de adjacencia, interligando os quadrados de valor 0. Chamo a DFS para o quadrado inicial,
e se em algum momento o dfs encontrar o quadrado final, quer dizer que a polícia consegue encontrar os ladrões */

vector<vector<int> > listAdj(26);
vector<int> vis(26);
bool achei = false;

void dfs(int v, int acharEsse){
    if(v == acharEsse){
        achei = true;
        return;
    }

    if(vis[v] == 1){
        return;
    }

    vis[v] = 1;

    int tam = listAdj[v].size();
    for(int i = 0; i < tam; i++){
        dfs(listAdj[v][i], acharEsse);
    }
}

int main(){
    int testes;
    scanf("%d", &testes);

    for(int t = 1; t <= testes; t++){
        int pos = 1;
        int matrizPos[5][5];
        bool conexo = true;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                int valor;
                scanf("%d", &valor);

                if(valor == 0){
                    matrizPos[i][j] = pos;
                    pos++;
                } else {
                    matrizPos[i][j] = -1;
                }
            }
        }

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(matrizPos[i][j] != -1){
                    if(matrizPos[i - 1][j] != -1 && i - 1 >= 0){
                        listAdj[matrizPos[i][j]].push_back(matrizPos[i - 1][j]);
                    }

                    if(matrizPos[i + 1][j] != -1 && i + 1 <= 4){
                        listAdj[matrizPos[i][j]].push_back(matrizPos[i + 1][j]);
                    }

                    if(matrizPos[i][j - 1] != -1 && j - 1 >= 0){
                        listAdj[matrizPos[i][j]].push_back(matrizPos[i][j - 1]);
                    }

                    if(matrizPos[i][j + 1] != -1 && j + 1 <= 4){
                        listAdj[matrizPos[i][j]].push_back(matrizPos[i][j + 1]);
                    }
                }
            }
        }

        fill(vis.begin(), vis.end(), 0);

        dfs(1, pos - 1);

        if(achei == true){
            printf("COPS\n");
        } else {
            printf("ROBBERS\n");
        }

        for(int i = 0; i < 26; i++){
            listAdj[i].clear();
            vis[i] = 0;
        }

        achei = false;
    }
}