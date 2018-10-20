#include <cstdio>

template <int N>

int Soma(int x)
{
  return x + N;
}

int main()
{
  printf("%d\n", Soma<3>(3));
}
