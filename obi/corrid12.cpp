#include <stdio.h>

using namespace std;

int main() {
    int pretendMeters, laneLength;

    scanf("%d %d", &pretendMeters, &laneLength);

    if(pretendMeters > laneLength){
        printf("%d\n", pretendMeters % laneLength);
    } else {
        printf("%d\n", pretendMeters);
    }
    
    return 0;
}
