#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> digitos;
    int n;
    scanf("%d", &n);

    while(true){
        digitos.push_back(n % 2);

        if(n/2 == 0){
            break;
        } else {
            n = n / 2;
        }
    }

    // Binário é construido a partir do último resto
    reverse(digitos.begin(), digitos.end());

    // Itera pelos dígitos
    int tam = digitos.size();
    for(int i = 0; i < tam; i++){
        printf("%d", digitos[i]);
    }

    printf("\n");
}