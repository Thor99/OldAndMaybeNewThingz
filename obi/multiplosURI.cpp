#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    
    if(max(a, b) % min(a, b) == 0){
        printf("Sao Multiplos\n");
    } else {
        printf("Nao sao Multiplos\n");
    }
}