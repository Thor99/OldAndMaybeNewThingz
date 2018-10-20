#include <cstdio>
#include <set>

using namespace std;

int main(){
    int nCartasAl, nCartasBea;

    while(scanf("%d %d", &nCartasAl, &nCartasBea) == 2 && (nCartasAl + nCartasBea) != 0){
        long long int resp;
        long long int nCartasSemRepeticaoAlicia;
        long long int nCartasSemRepeticaoBeatriz;
        set<int> cartasSemRepeticao;
        set<int> cartasSemRepeticaoAlicia;
        set<int> cartasSemRepeticaoBeatriz;

        for(int i = 0; i < nCartasAl; i++){
            int valor;
            scanf("%d", &valor);

            cartasSemRepeticaoAlicia.insert(valor);
            cartasSemRepeticao.insert(valor);
        }

        for(int i = 0; i < nCartasBea; i++){
            int valor;
            scanf("%d", &valor);

            cartasSemRepeticaoBeatriz.insert(valor);
            cartasSemRepeticao.insert(valor);
        }


        // cartasSemRepeticao guarda o conjunto de cartas que não se repetem ao unir o conjunto da alicia com o da beatriz
        // cartasSemRepeticaoAlicia guarda o conjunto de cartas que não se repetem no conjunto da alicia
        // cartasSemRepeticaoBeatriz guarda o conjunto de cartas que não se repetem no conjunto da beatriz

        /* A resposta será o tamanho do conjunto cartasSemRepeticao - o maior tamanho entre o conjunto cartasSemRepeticaoAlicia e o
        conjunto cartasSemRepeticaoBeatriz */

        /* Usamos max pois o número de cartas que sai da mão de uma tem que ser igual o numero de cartas que sai da mão da outra.
        Ou seja, se usassemos min seria como se uma jogadora desse mais carta que a outra. */
        resp = cartasSemRepeticao.size() - max(cartasSemRepeticaoAlicia.size(), cartasSemRepeticaoBeatriz.size());

        if(resp <= 0){
            printf("0\n");
        } else {
            printf("%lld\n", resp);
        }
    }
}