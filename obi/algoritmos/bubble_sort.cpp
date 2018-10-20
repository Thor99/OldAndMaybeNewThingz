#include <cstdio>
#include <vector>

using namespace std;

/* Objetivo: Ordenar um array. Funcionamento: Percorremos o array, desde a primeira posição até a penúltima, e vemos se o elemento
atual é maior que o próximo elemento. Se for, fazemos um swap de seus valores e voltamos para i = 0. */

int main(){
    vector<int> vec;
    int nElementos;
    scanf("%d", &nElementos);

    for(int i = 0; i < nElementos; i++){
        int valor;
        scanf("%d", &valor);

        vec.push_back(valor);
    }

    // Bubble sort
    for(int i = 0; i < nElementos - 1; i++){
        if(vec[i] > vec[i + 1]){
            int aux = vec[i];
            vec[i] = vec[i + 1];
            vec[i + 1] = aux;
            i = -1; // O i++ vai fazer ele ir pra zero;
        }
    }

    // Vetor ordenado
    for(int i = 0; i < nElementos; i++){
        printf("%d ", vec[i]);
    }
}