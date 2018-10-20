#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int nJogadores, nRodadas;
    scanf("%d %d", &nJogadores, &nRodadas);
    vector<int> pontosPorJogador; // pontosPorJogador[i] = pontos do jogador i
    vector<int> vencedores;
    pontosPorJogador.push_back(0); // Jogador 0, não utilizado;

    for(int i = 0; i < nJogadores; i++){
        pontosPorJogador.push_back(0); // Todos começam com 0 pontos;
    }

    for(int i = 1; i <= nRodadas * nJogadores; i++){
        int pontuacao;
        scanf("%d", &pontuacao);

        if(i <= nJogadores){
            pontosPorJogador[i] += pontuacao;
        } else {
            if(i % nJogadores == 0){
                pontosPorJogador[nJogadores] += pontuacao;
            } else {
                pontosPorJogador[i % nJogadores] += pontuacao;
            }
        }
    }

    int maior = -1;
    for(int i = 1; i <= nJogadores; i++){
        if(pontosPorJogador[i] > maior){
            maior = pontosPorJogador[i];
        }
    }

    for(int i = 1; i <= nJogadores; i++){
        if(pontosPorJogador[i] == maior){
            vencedores.push_back(i);
        }
    }

    sort(vencedores.rbegin(), vencedores.rend()); // Vencedor de maior numero primeiro

    printf("%d\n", vencedores[0]);
}