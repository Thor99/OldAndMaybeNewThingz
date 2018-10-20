#include <iostream>

class Animal
{
public:
    virtual void Fala() = 0;
    /* Puramente virtual: Método tem que ser obrigatoriamente sobrescrito nas classes derivadas. Classe não poderá ser
    instanciada diretamente . Basta ter um método desse tipo para a classe não poder ser instanciada*/
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
    FazFalar(&d);
    FazFalar(&c);
}

