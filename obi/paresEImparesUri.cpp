#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    vector<int> pares;
    vector<int> impares;
    scanf("%d", &N);

    while(N--){
        int valor;
        scanf("%d", &valor);

        if(valor % 2 == 0){
            pares.push_back(valor);
        } else {
            impares.push_back(valor);
        }
    }

    // Sort crescente
    sort(pares.begin(), pares.end());

    // Sort decrescente
    sort(impares.rbegin(), impares.rend());

    int paresSize = pares.size();
    int imparesSize = impares.size();

    for(int i = 0; i < paresSize; i++){
        printf("%d\n", pares[i]);
    }

    for(int i = 0; i < imparesSize; i++){
        printf("%d\n", impares[i]);
    }
}