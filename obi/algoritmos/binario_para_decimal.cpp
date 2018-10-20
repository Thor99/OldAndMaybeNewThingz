#include <cstdio>

int main(){
    long long int bin, dec=0, rem, num, base=1;
    scanf("%lld", &num);

    bin = num;

    while(num > 0){
        rem = num % 10;
        dec = dec + rem * base;
        base = base * 2;
        num = num / 10;
    }

    printf("%lld\n", dec);
}