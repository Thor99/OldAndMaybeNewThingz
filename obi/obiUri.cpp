#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		string str;
		cin >> str;

		if(i == N - 1){
				if(str.size() == 3 && str[0] == 'O' && str[1] == 'B'){
				cout << "OBI\n";
			}

			else if(str.size() == 3 && str[0] == 'U' && str[1] == 'R'){
				cout << "URI\n";
			}

			else {
				cout << str << "\n";
			}
		} else {
			if(str.size() == 3 && str[0] == 'O' && str[1] == 'B'){
				cout << "OBI ";
			}

			else if(str.size() == 3 && str[0] == 'U' && str[1] == 'R'){
				cout << "URI ";
			}

			else {
				cout << str << " ";
			}
		}
	}
}