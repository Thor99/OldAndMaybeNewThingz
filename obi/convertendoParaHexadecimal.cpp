#include <iostream>
#include <string>
#include <algorithm>
#include <sstream> 

using namespace std;

int main(){
	stringstream ss;
	int valor;

	cin >> valor;

	ss << hex << valor; 
	string res(ss.str());

	transform(res.begin(), res.end(), res.begin(), ::toupper);

	cout << res << endl;
}