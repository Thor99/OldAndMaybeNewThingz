#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int nStops;
    int remaining = 0;
    int minCapacity = 0;
    scanf("%d", &nStops);

    while(nStops--){
        int out, in;
        scanf("%d %d", &out, &in);

        remaining -= out;
        remaining += in;

        minCapacity = max(minCapacity, remaining);
    }

    printf("%d\n", minCapacity);
}