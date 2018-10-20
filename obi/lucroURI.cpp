#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/* Kadane com um vetor de lucros, sendo lucro = receita - custo. */

int main(){
    int nDias;

    while(scanf("%d", &nDias) != EOF){
        vector<int> lucroPorDia;
        vector<int> best;
        int maxDinheiro;
        int custo;

        scanf("%d", &custo);

        for(int i = 0; i < nDias; i++){
            int receita;
            scanf("%d", &receita);

            lucroPorDia.push_back(receita - custo);
        }

        best.push_back(lucroPorDia[0]);
        maxDinheiro = best[0];

        for(int i = 1; i < lucroPorDia.size(); i++){
            best.push_back(max(lucroPorDia[i], lucroPorDia[i] + best[i - 1]));
            maxDinheiro = max(maxDinheiro, best[i]);
        }

        if(maxDinheiro <= 0){
            printf("0\n");
        } else {
            printf("%d\n", maxDinheiro);
        }
    }
}