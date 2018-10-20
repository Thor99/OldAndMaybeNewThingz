#include <iostream>
#include <string>

using namespace std;

const char getCorrectChar(char c){
	if(c == 'A' || c == 'B' || c == 'C'){
		return '2';
	}

	else if(c == 'D' || c == 'E' || c == 'F'){
		return '3';
	}

	else if(c == 'G' || c == 'G' || c == 'I'){
		return '4';
	}

	else if(c == 'J' || c == 'K' || c == 'L'){
		return '5';
	}

	else if(c == 'J' || c == 'K' || c == 'L'){
		return '5';
	}

	else if(c == 'M' || c == 'N' || c == 'O'){
		return '6';
	}

	else if(c == 'P' || c == 'Q' || c == 'R' || c == 'S'){
		return '7';
	}

	else if(c == 'T' || c == 'U' || c == 'V'){
		return '8';
	}

	else if(c == 'W' || c == 'X' || c == 'Y' || c == 'Z'){
		return '9';
	}

	else {
		return c;
	}
} 


int main(){
	string telefone;

	cin >> telefone;

	for(int i = 0; i < telefone.length(); ++i){
		telefone[i] = getCorrectChar(telefone[i]); // Se for uma letra, troca o caractere pelo numero, senão, mantem o próprio
	}

	cout << telefone;
}