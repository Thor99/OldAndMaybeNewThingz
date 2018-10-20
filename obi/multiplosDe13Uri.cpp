#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    long int ans = 0;
    int x, y;

    scanf("%d", &x);
    scanf("%d", &y);

    for(int i = min(x, y); i <= max(x, y); i++){
        if(i % 13 != 0){
            ans += i;
        }
    }

    printf("%ld\n", ans);
}