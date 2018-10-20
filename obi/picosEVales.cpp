#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int tam;
    vector<int> alturas;
    scanf("%d", &tam);

    for(int i = 0; i < tam; i++){
        int alt;
        scanf("%d", &alt);
        alturas.push_back(alt);
    }

    if(alturas[0] < alturas[1]){
        for(int i = 1; i < tam - 1; i++){
            if(i % 2 == 0){
                if(alturas[i] >= alturas[i + 1]){
                    printf("0\n");
                    return 0;
                }
            } else {
                if(alturas[i] <= alturas[i + 1]){
                    printf("0\n");
                    return 0;
                }
            }
        }
    }

    else if(alturas[0] > alturas[1]){
        for(int i = 1; i < tam - 1; i++){
            if(i % 2 == 0){
                if(alturas[i] <= alturas[i + 1]){
                    printf("0\n");
                    return 0;
                }
            } else {
                if(alturas[i] >= alturas[i + 1]){
                    printf("0\n");
                    return 0;
                }
            }
        }
    }

    else {
        printf("0\n");
        return 0;
    }

    printf("1\n");
}