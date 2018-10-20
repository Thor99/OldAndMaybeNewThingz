#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool checkIsTriangle(float a, float b, float c){
    if(abs(a - b) < c && c < a + b && abs(b - c) < a && a < b + c && abs(c - a) < b && b < c + a){
        return true;
    }

    return false;
}

int main(){
    float a, b, c;

    scanf("%f %f %f", &a, &b, &c);

    if(checkIsTriangle(a, b, c) == true){
        printf("Perimetro = %.1f\n", a + b + c);
    } else {
        printf("Area = %.1f\n", ((a + b) / 2) * c);
    }

    return 0;
}
