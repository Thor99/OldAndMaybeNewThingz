#include <cstdio>
#define MAX 100001

int pai[MAX], quantidade[MAX], peso[MAX];

int find(int x){
    if(pai[x] == x){
        return x;
    }

    return pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y){
        return;
    }

    if(peso[x] < peso[y]){
        pai[x] = y;
        quantidade[y] += quantidade[x];
    }

    else if(peso[x] > peso[y]){
        pai[y] = x;
        quantidade[x] += quantidade[y];
    }

    else {
        pai[x] = y;
        peso[y]++;

        quantidade[y] += quantidade[x];
    }
}

int main(){
    int nPeople, nQueries;
    scanf("%d %d", &nPeople, &nQueries);

    for(int i = 1; i <= nPeople; i++){
        pai[i] = i;
        quantidade[i] = 1;
    }

    for(int i = 0; i < nQueries; i++){
        char operacao;
        int el1, el2;
        scanf(" %c", &operacao);

        if(operacao == 'M'){
            scanf("%d %d", &el1, &el2);
            join(el1, el2);
        } else {
            scanf("%d", &el1);
            el1 = find(el1);
            printf("%d\n", quantidade[el1]);
        }
    }
}