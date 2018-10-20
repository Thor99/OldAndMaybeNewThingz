#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* lower_bound(vector.begin(), vector.end(), n) retorna um iterador apontando para o primeiro elemento que seja maior
ou igual a n. O valor do iterador é o valor desse elemento. */

/* upper_bound(vector.begin(), vector.end(), n) retorna um iterador apontando para o primeiro elemento que seja maior
que n. O valor do iterador é o valor desse elemento. */

int main(){
    vector<int> vec;

    // {1, 1, 1, 1, 2, 3, 4, 5}
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    sort(vec.begin(), vec.end());

    vector<int>::iterator low = lower_bound(vec.begin(), vec.end(), 3); // Retorna 3
    vector<int>::iterator up = upper_bound(vec.begin(), vec.end(), 3); // Retorna 4

    cout << *low << " " << *up << endl;

    vector<int> vec2;

    // {3, 10, 12, 13, 14, 15}
    vec2.push_back(3);
    vec2.push_back(10);
    vec2.push_back(11);
    vec2.push_back(12);
    vec2.push_back(13);
    vec2.push_back(14);
    vec2.push_back(15);

    sort(vec2.begin(), vec2.end());

    vector<int>::iterator low2 = lower_bound(vec2.begin(), vec2.end(), 3); // Retorna 3
    vector<int>::iterator up2 = upper_bound(vec2.begin(), vec2.end(), 3); // Retorna 10

    cout << *low2 << " " << *up2 << endl;

}