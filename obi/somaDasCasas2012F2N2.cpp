#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int nCasas, soma;
    vector<int> casas;
    scanf("%d", &nCasas);

    for(int i = 0; i < nCasas; i++){
        int val;
        scanf("%d", &val);

        casas.push_back(val);
    }

    scanf("%d", &soma);

    for(int i = 0;  i < nCasas; i++){
        vector<int>::iterator it = lower_bound(casas.begin(), casas.end(), soma - casas[i]);
        if(it != casas.end() && *it == soma - casas[i]){
            printf("%d %d\n", casas[i], *it);
            return 0;
        }
    }
}