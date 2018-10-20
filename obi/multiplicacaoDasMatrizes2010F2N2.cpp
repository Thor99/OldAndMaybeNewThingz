#include <cstdio>

int n, p, q, r, s, x, y, posL, posC;

int A(int i, int j){
    return (p * i + q * j) % x;
}

int B(int i, int j){
    return (r * i + s * j) % y;
}

int main()
{
    scanf("%d", &n);
    scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &x, &y);
    scanf("%d %d", &posL, &posC);

    long long resp = 0;
    for(int k = 1; k <= n; k++)
        resp += A(posL, k) * B(k, posC);

    printf("%lld\n", resp);
}
