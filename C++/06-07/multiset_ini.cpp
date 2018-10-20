#include <iostream>
#include <set>

using namespace std;

/*
- Valores podem se repetir
*/

int main(){
    multiset<int> conji;
    conji.insert(1);
    conji.insert(1);

    for(auto it = conji.begin(); it != conji.end(); ++it){
        cout << *it << endl;
    }
}