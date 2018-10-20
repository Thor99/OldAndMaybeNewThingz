#include <cstdio>

int main(){
    int N;
    scanf("%d", &N);

    while(N--){
        double val;
        int counter = 0;
        scanf("%lf", &val);

        while(val > 1){
            val /= 2.0;
            counter++;
        }

        printf("%d dias\n", counter);
    }
}