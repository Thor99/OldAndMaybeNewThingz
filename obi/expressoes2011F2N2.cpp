#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int k = 0; k <= n; k++){
        stack<char> S;
        string str;
        getline(cin, str);

        int tam = str.size();

        for(int i = 0; i < tam; i++){
            if(S.empty()){
                S.push(str[i]);
            } else {
                if(str[i] == '{' || str[i] == '(' || str[i] == '['){
                    S.push(str[i]);
                } else {
                    if(str[i] == '}' && S.top() == '{'){
                        S.pop();
                    }

                    if(str[i] == ')' && S.top() == '('){
                        S.pop();
                    }

                    if(str[i] == ']' && S.top() == '['){
                        S.pop();
                    }
                }
            }
        }

        if(k != 0){
            if(S.size() == 0){
                cout << "S" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
}