#include <cstdio>

int main(){
    int harmed = 0;
    int total, n1, n2, n3, n4;
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);
    scanf("%d", &total);

    for(int i = 1; i<= total; i++){
        if(i % n1 == 0 || i % n2 == 0 || i % n3 == 0 || i % n4 == 0){
            harmed++;
        }
    }

    printf("%d\n", harmed);
}