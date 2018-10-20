#include <stdio.h>

using namespace std;

int main(){
    float n1, n2, dis1, dis2, v1, v2;

    scanf("%f %f %f", &n1, &dis1, &v1);
    scanf("%f %f %f", &n2, &dis2, &v2);

    // t = delta s / delta v;

    if(dis1 / v1 < dis2 / v2){
        printf("%.0f\n", n1);
    } else{
        printf("%.0f\n", n2);
    }

    return 0;
}
