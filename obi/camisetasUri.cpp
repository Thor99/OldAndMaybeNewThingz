#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct t_camisas{
    string nome, cor, tamanho;
};

bool cmp(t_camisas x, t_camisas y){
    // Primeira prioridade
    if(x.cor != y.cor){
        return x.cor < y.cor;
    }

    // Segunda prioridade
    if(x.tamanho != y.tamanho){
        return x.tamanho > y.tamanho;
    }

    // Terceira prioridade
    return x.nome < y.nome;
}

int main(){
    int N;
    int counter = 0;
    while(scanf("%d", &N) == 1 && N != 0){
        if(counter != 0){ // printar espaço entra dois testes, se não tiver sido o ultimo teste
            printf("\n");
        }

        t_camisas camisas[60];
        for(int i = 0; i < N; i++){
            cin.ignore(); // getline precisa disso antes de ser chamado, pra funcionar direito
            getline(cin, camisas[i].nome);
            cin >> camisas[i].cor >> camisas[i].tamanho;
        }

        sort(camisas, camisas + N, cmp);

        for(int i = 0; i < N; i++){
            cout << camisas[i].cor << " " << camisas[i].tamanho << " " << camisas[i].nome;
            printf("\n");
        }

        counter++;
    }
}