#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin, str);

    if(str.size() <= 140){
        cout << "TWEET\n";
    } else {
        cout << "MUTE\n";
    }
}