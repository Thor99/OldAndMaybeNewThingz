#include <cstdio>

int main(){
    int N;
    int in = 0, out = 0;

    scanf("%d", &N);

    while(N--){
        int val;
        scanf("%d", &val);

        if(val >= 10 && val <= 20){
            in++;
        } else {
            out++;
        }
    }

    printf("%d in\n", in);
    printf("%d out\n", out);
}