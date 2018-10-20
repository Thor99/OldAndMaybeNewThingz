#include <cstdio>
#include <algorithm>

using namespace std;

/* Resumindo, para encontrar o MDC(a, b), supondo sem perda de generalidade que a >= b, verifico:

1. Se a é múltiplo de b, MDC(a,b)=b;

2. Se não, MDC(a,b)=MDC(b, r), onde r é o resto que a deixa na divisão por b. */

int mdc(int a, int b){
    if(max(a, b) % min(a, b) == 0){
        return min(a, b);
    } else {
        return mdc(min(a, b), max(a, b) % min(a, b));
    }
}

int main(){
    int nTests;
    scanf("%d", &nTests);

    for(int t = 0; t < nTests; t++){
        int x, y;
        scanf("%d %d", &x, &y);

        printf("%d\n", mdc(x, y));
    }
}