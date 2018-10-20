#include <iostream>

using namespace std;

class A
{
public:
    void f();
    virtual void g();
    virtual void h() = 0;
};

class B : public A
{
public:
    void f();
    virtual void g() override;
    virtual void h() override;
    /* Obrigatória a presença da implementação de h em B, pois o método na classe base é puramente virtual */
};

class C : public B
{
public:
    int f(); // Somente uma outra função, retorno é int, não void
};

void A::f()
{
    cout << "A::f()" << endl;
}

void A::g()
{
    cout << "A::g()" << endl;
}

void A::h()
{
    cout << "A::h()" << endl;
}

void B::f()
{
    cout << "B::f()" << endl;
}

void B::g()
{
    cout << "B::g()" << endl;
}

void B::h()
{
    cout << "B::h()" << endl;
}

int C::f()
{
    cout << "C::f()" << endl;
    return 1;
}

int main()
{
    B b;
    A* a = &b;
    C c;

    a->f();
    a->g();
    a->h();

    b.f();
    b.g();
    b.h();

    cout << c.f() << endl;
}