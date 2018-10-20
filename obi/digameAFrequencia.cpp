#include <iostream>
#include <algorithm>

using namespace std;

struct number_info {
    int value;
    int amount = 0;
};

bool comp(number_info a, number_info b) {
    if (a.amount == b.amount) {
        return a.value > b.value;
    }

    return a.amount < b.amount;
}

int main() {
    string word; bool newline = 0;

    while(cin >> word) {
        number_info vet[128];

        for (int i = word.size(); i >= 0; i--) {
            vet[word[i] - 32].value = word[i];
            vet[word[i] - 32].amount++;
        }

        sort(vet, vet + 128, comp);

        if (!newline) {
            newline = 1;
        } else {
            cout << endl;
        }

        for (int i = 0; i < 128; i++) {
            if (vet[i].amount > 0) {
                cout << vet[i].value << " " << vet[i].amount << endl;
            }
        }
    }
}