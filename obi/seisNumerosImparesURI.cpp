#include <cstdio>

int main(){
    int n;
    int counter = 0;
    scanf("%d", &n);

    for(int i = n; ; i++){
        if(counter >= 6){
            break;
        }

        if(i % 2 != 0){
            printf("%d\n", i);
            counter++;
        }
    }
}