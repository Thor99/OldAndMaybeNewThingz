#include <iostream>

class Animal
{
public:
    virtual void Fala(){}; // Virtual não pode usar default
};

class Dog : public Animal
{
public:
    virtual void Fala() override{ std::cout << "au au\n"; }
};

class Cat: public Animal
{
public:
    virtual void Fala() override { std::cout << "miau\n"; }
};

/* Passos para funcionar polimorfismo (faz com que chame o método da classe que ela realmente é):
    - Tem que ser ponteiro
    - O método tem que ser VIRTUAl (obs: um pouco mais lento que o método normal)
        - Método virtual: Deve ser sobrescrito na nas classes derivadas
*/

void FazFalar(Animal* a)
{
    a->Fala();
}

int main(){
    Dog d;
    Cat c;
    Animal a;
    FazFalar(&d);
    FazFalar(&c);
    FazFalar(&a);
}

