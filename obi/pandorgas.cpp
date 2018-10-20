#include <stdio.h>

using namespace std;

int main(){
    int tests, n1, n2;

    scanf("%d", &tests);

    for(int i = 0; i < tests; i++){
        scanf("%d %d", &n1, &n2);

        printf("%d cm2\n", (n1 * n2) / 2);
    }

    return 0;
}
