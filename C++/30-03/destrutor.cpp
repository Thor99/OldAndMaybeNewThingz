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
	Teste teste1;
	{Teste teste2;} // Variável morre no término das chaves, que é um novo escopo
	std::cout << "print\n"; // Irá printar isto antes de dtor do teste1, pois o destrutor só é executado ao finalizar o programa
}
