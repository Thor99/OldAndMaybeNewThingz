#include <stdio.h>

void f()
{
    printf("f()\n");
}

void f(int x)
{
    printf("f(int)\n");
}

void f(float x)
{
    printf("f(float)\n");
}

int main()
{
    f(3);
    f();
    f(3.5f);
}
