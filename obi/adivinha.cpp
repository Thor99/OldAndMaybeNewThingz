#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int testes;
    scanf("%d", &testes);

    while(testes--){
        /* vector de pairs, que guarda o módulo da diferença entre o número qeu o aluno chutou e o número secreto, e posição
        do aluno */
        vector<pair<int, int> > alunos; // (diferença(abs(chute - numeroSecreto)), posicao)
        int quantAlunos, numeroSecreto;
        scanf("%d %d", &quantAlunos, &numeroSecreto);

        for(int pos = 1; pos <= quantAlunos; pos++){
            int guess;
            scanf("%d", &guess);

            alunos.push_back(make_pair(abs(numeroSecreto - guess), pos));
        }

        // Sort pela diferença (se for 0, acertou. Se for um, chegou perto...) e também pela posição, se houver empate
        sort(alunos.begin(), alunos.end());

        printf("%d\n", alunos[0].second);
    }
}