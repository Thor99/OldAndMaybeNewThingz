#include <cstdio>
#define MAX 100100 // Máximo de bancos é 100.000

int pai[MAX];
int peso[MAX];
int nBancos, nOperacoes;

int find(int x){
    if(pai[x] == x){
        return x;
    } else {
        return pai[x] = find(pai[x]);
    }
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y){
        return;
    }

    if(peso[x] < peso[y]){
        pai[x] = y;
    }

    if(peso[x] > peso[y]){
        pai[y] = x;
    }

    if(peso[x] == peso[y]){
        pai[x] = y;
        peso[y]++;
    }
}

int main(){
    scanf("%d %d", &nBancos, &nOperacoes);

    char operacao;
    int b1, b2;

    for(int i = 1; i <= nBancos; i++){
        pai[i] = i;
    }

    for(int i = 0; i < nOperacoes; i++){
        scanf(" %c %d %d", &operacao, &b1, &b2);

        if(operacao == 'F'){
            join(b1, b2);
        } else {
            if(find(b1) == find(b2)){
                printf("S\n");
            } else {
                printf("N\n");
            }
        }
    }
}