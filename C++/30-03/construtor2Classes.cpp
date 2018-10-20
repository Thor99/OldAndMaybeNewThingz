#include <iostream>

class TesteX
{
	public:
		TesteX(int x);
};

class TesteY
{
	public:
		TesteY();
	private:
		TesteX m_t1;
		TesteX m_t2;
};

TesteX::TesteX(int x){
	std::cout << x << std::endl;
}

TesteY::TesteY() :
	m_t1(0),
	m_t2(1)
	// Isso é uma lista de inicialização (tudo desde os dois pontos até a abertura de chaves)
{
	// É um construtor, não faremos nada.
} 

int main(){
	TesteY y; // Chama o construtor de X, que printa o valor que a variável recebe
}
