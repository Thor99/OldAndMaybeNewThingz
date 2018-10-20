#include <cstdio>

int main(){
    int rooms;
    int can = 0;
    scanf("%d", &rooms);

    while(rooms--){
        int remains, capacity;
        scanf("%d %d", &remains, &capacity);

        if(capacity - remains >= 2){
            can++;
        }
    }

    printf("%d\n", can);
}