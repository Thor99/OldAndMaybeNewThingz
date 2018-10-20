#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> vec;

    cout << vec.size() << endl; // Número de elementos no vetor.

    vec.push_back(5); // Insere 5 no vetor.

    // Itera pelos valores que estão dentro do vetor.
    for(auto valor : vec){
        cout << valor << endl;
    }

    // Itera pelos valores que estão dentro do vetor.
    // vec.begin() retorna um ponteiro pra o primeiro elemento de vec.
    // vec.end() retorna um ponteiro pra o primeiro elemento que está depois do ultimo elemento de vec.
    vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++){
        cout << *it << endl;
    }

    // Ao invés de fazer "vector<int>::iterator it", poderíamos fazer dentro do for: auto it = vec.begin();
    for(auto ite = vec.begin(); ite != vec.end(); ite++){
        cout << *ite << endl;
    }

    /* The resize() method (and passing argument to constructor is equivalent to that) will insert or delete appropriate
    number of elements to the vector to make it given size (it has optional second argument to specify their value). It will
    affect the size(), iteration will go over all those elements, push_back will insert after them and you can directly
    access them using the operator[]. */

    /* The reserve() method only allocates memory, but leaves it uninitialized. It only affects capacity(), but size() will
    be unchanged. There is no value for the objects, because nothing is added to the vector. If you then insert the elements,
    no reallocation will happen, because it was done in advance, but that's the only effect. */

    /* If you want an array of 1000 default items, use resize(). If you want an array to which you expect to insert 1000
    items and want to avoid a couple of allocations, use reserve(). */
}