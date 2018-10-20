#include <cstdio>

int main(){
    int N;
    scanf("%d", &N);

    (N % 2 == 0 && N > 2) ? printf("YES\n") : printf("NO\n");
}