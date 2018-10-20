#include <iostream>
#include <string>

using namespace std;

// Se str[i] esta entre 'a' e 'z': str[i] =(str[i] - 65 + rotateThis) % 26 + 65;
// Se str[i] esta entre 'A' e 'Z': str[i] =(str[i] - 97 + rotateThis) % 26 + 97;

int main(){
	string str;
	int size, rotateThis;

	cin >> size;
	cin >> str;
	cin >> rotateThis;

	for(int i = 0; i < size; ++i){
		if(int(str[i]) >= 65 && str[i] <= 90){
			str[i] =(str[i] - 65 + rotateThis) % 26 + 65;
		}

		if(int(str[i]) >= 97 && str[i] <= 122){
			str[i] = (str[i] - 97 + rotateThis) % 26 + 97;
		}
	}

	cout << str << endl;
}