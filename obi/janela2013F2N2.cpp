#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> janela(600);
    fill(janela.begin(), janela.end(), 0);
    int f1, f2, f3, soma=0;
    scanf("%d %d %d", &f1, &f2, &f3);

    for(int i = f1; i <= f1 + 199; i++){
        janela[i] = 1;
    }

    for(int i = f2; i <= f2 + 199; i++){
        janela[i] = 1;
    }

    for(int i = f3; i <= f3 + 199; i++){
        janela[i] = 1;
    }

    for(int i = 0; i < 600; i++){
        if(janela[i] == 0){
            soma += 100;
        }
    }

    printf("%d\n", soma);
}