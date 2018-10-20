#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int soma = 0;    
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    if(x == y){
        printf("0\n");
    } else {
        for(int i = min(x, y) + 1; i < max(x, y); i++){
            if(i % 2 != 0){
                soma += i;
            }
        }
    }

    printf("%d\n", soma);
}
