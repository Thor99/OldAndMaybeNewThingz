#include <iostream>
#include <string>

using namespace std;

int main(){
	int tam;
	int paineis = 0;
	string str;

	cin >> tam;
	cin >> str;

	for(int i = 0; i < tam; i++){
		if(str[i] == 'P'){
			paineis += 2;
		}

		else if(str[i] == 'C'){
			paineis += 2;
		}

		else if(str[i] == 'A'){
			paineis += 1;
		}

		else { // D
			paineis += 0;
		}
	}

	cout << paineis << endl;
}