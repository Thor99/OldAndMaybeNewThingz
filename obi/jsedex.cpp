#include <stdio.h>

using namespace std;

int main(){
    int diameter, height, width, depth;

    scanf("%d", &diameter);
    scanf("%d %d %d", &height, &width, &depth);

    if(diameter <= height && diameter <= width && diameter <= depth){
        printf("S");
    } else {
        printf("N");
    }

    return 0;
}
