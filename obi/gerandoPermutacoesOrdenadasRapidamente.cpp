#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);

	while(n--){
		string s;
		cin >> s;

		sort(s.begin(), s.end());
	    do{
	        cout << s << "\n";
	    } while (next_permutation(s.begin(), s.end()));

	    cout << "\n";
	}
}