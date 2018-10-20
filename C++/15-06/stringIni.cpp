#include <iostream>
#include <string>

using namespace std;

int main(){
    string str = "hello";
    str += " world";

    // Itera sobre a string
    for(auto it = str.begin(); it != str.end(); it++){
        cout << *it << endl;
    }

    // Comparação de string
    if(str == "hello world"){
        cout << "iguallll" << endl;
    }
}