#include <iostream>

// Estamos criando tudo no mesmo arquivo e sem .h só pra testar e pá

class Teste
{
	public:
	
		Teste();
		~Teste();
};

Teste::Teste()
{
	std::cout << "ctor\n";
}

Teste::~Teste()
{
	std::cout << "dtor\n";
}

int main(){
	/*
	Teste teste1;
	Teste* x2 = new Teste; // Ele não executará o dtor ao fim do programa, pois para desconstruir ele, tem que dar o "delete"
	std::cout << "FIM\n"; 
	*/
	
	/*
	Teste teste1;
	Teste* teste2 = new Teste;
	std::cout << "FIM\n"; 
	delete teste2; // Printará o dtor, pois ele será desconstruido
	*/
	
	Teste t1[3]; // Printa 3 ctor
	Teste* t2 = new Teste[3]; // Printa 3 ctor
	delete[] t2; // Printa 3 dtor
	// Ao fim do programa, printa 3 dtor do t1
}
