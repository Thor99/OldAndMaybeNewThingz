#include <cstdio>

template <typename T>
T Soma(T a, T b)
{
  return a + b;
}

template<>
int Soma(int a, int b)
{
  return 0;
}

int main()
{
  printf("%d\n", Soma(2, 3)); // Dois ints, chama a especialização do template e retorna 0
  printf("%lf\n", Soma(2.5, 3.5));
}
