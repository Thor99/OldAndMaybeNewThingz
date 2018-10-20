#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string strIni;
	string buf;
	vector<string> vec;

	getline(cin, strIni);

	stringstream ss(strIni);

	// Pega cada palavra separada por espaços da strIni e pusha no vec.
	while(ss >> buf){
        vec.push_back(buf);
	}

	int flag = 0;

	// Se voce tira uma letra, muda a lógica do programa. Isso é consultado pela flag
	for(int i = 0; i < vec.size(); ++i){
		for(int j = 0; j < vec[i].size(); ++j){
			if(flag % 2 == 0){
				if(j % 2 == 0){
					vec[i].erase(j, 1); // Remove 1 caractere na posição j
					flag += 1;
				}
			} else {
				if(j % 2 != 0){
					vec[i].erase(j, 1); // Remove 1 caractere na posição j
					flag += 1;
				}
			}
		}

		flag = 0;
	}

	for(int i = 0; i < vec.size(); ++i){
		cout << vec[i] << " ";
	}
}