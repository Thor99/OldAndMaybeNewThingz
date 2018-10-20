#include <cstdio>

int main()
{
    int x; // Variável pra apontar
    int& r = x; // Ponteiro para x
    r = 5; // Não precisamos usar *r = 5

    printf("%d\n", r);
}
