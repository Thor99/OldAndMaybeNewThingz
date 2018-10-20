#include <cstdio>
#include <cmath>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = (b * b) - (4 * a * c);

    if(a == 0){
        printf("Impossivel calcular\n");
    } else {
        if(delta < 0){
            printf("Impossivel calcular\n");
        } else {
            double r1 = (-b + sqrt(delta)) / (2 * a);
            double r2 = (-b - sqrt(delta)) / (2 * a);

            printf("R1 = %.5f\n", r1);
            printf("R2 = %.5f\n", r2);
        }
    }
}