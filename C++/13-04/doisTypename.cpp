#include <cstdio>

template <typename T1, typename T2>

T1 Soma(T1 a, T2 b)
{
  return a + b;
}

int main()
{
  printf("%d\n", Soma(2, 3.6)); // Retorno é int, então converterá o double pra int
}
