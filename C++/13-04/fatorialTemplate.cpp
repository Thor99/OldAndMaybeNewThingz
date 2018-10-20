#include <cstdio>

/* Faremos um fatorial que será calculado em tempo de execução */

template<int N>
int fat()
{
  return N * fat<N-1>();
}

// Caso base
template<>
int fat<0>()
{
  return 1;
}

int main()
{
  printf("%d\n", fat<4>());
}
