#include <stdio.h>

struct Ponto
{
  float x;
  float y;
  float Soma()
  {
    return x + y;
  }
};

int main()
{
  Ponto p;
  p.x = 1.5;
  p.y = 2.5;
  printf("%f\n", p.Soma());

  return 0;
}