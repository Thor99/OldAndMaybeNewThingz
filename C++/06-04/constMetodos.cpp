#include <cstdio>

class X
{
  public:
    int f();
    int f() const;
  private:
    int m_x = 0;
};

int X::f()
{
  return m_x++;
}

int X::f() const
{
  return m_x;
}

int main()
{
  X x;
  const X cx;

  printf("Metodo constante: %d\n", cx.f());
  printf("Metodo constante: %d\n", cx.f());

  printf("Metodo nao constante: %d\n", x.f());
  printf("Metodo nao constante: %d\n", x.f());
}
