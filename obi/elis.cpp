#include <cstdio>
#include <vector>

using namespace std;

int main(){
    vector<int> pilha;
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int valor;
        scanf("%d", &valor);

        vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), valor);

        if(it == pilha.end()){
            pilha.push_back(valor);
        }

        else{
            *it = valor;
        }
    }

    printf("%d\n", (int) pilha.size());
}