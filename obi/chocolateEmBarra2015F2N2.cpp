#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int x1, y1, x2, y2;
    scanf("%d", &N);
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);

    if((min(x1, x2) <= N/2 && max(x1, x2) > N/2) || (min(y1, y2) <= N/2 && max(y1, y2) > N/2)){
        printf("S\n");
    } else {
        printf("N\n");
    }

}