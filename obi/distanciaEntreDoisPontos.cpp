#include <cstdio>
#include <cmath>

int main(){
    double x1, y1, x2, y2;

    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);

    printf("%.4f\n", sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}