#include <cstdio>

template <typename T>

T Soma(T a, T b)
{
  return a + b;
}

int main()
{
  printf("%d\n", Soma(2, 3));
  printf("%lf\n", Soma(2.5, 3.7));
  printf("%f\n", Soma(2.1f, 3.9f));
  printf("%d\n", Soma<int>(2.1f, 3.9f)); // Irá converter de float pra int
}
