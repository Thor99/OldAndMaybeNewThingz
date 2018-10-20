#include <cstdio>
#include <cmath>

using namespace std;

double fibonacci(int n){
    return (double) (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%.1lf\n", fibonacci(n));
}