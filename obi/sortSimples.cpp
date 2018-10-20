#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> ordenado;
    vector<int> normal;

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    normal.push_back(a);
    normal.push_back(b);
    normal.push_back(c);
    ordenado.push_back(a);
    ordenado.push_back(b);
    ordenado.push_back(c);

    sort(ordenado.begin(), ordenado.end());

    for(int i = 0; i < 3; i++){
        printf("%d\n", ordenado[i]);
    }

    printf("\n");

    for(int i = 0; i < 3; i++){
        printf("%d\n", normal[i]);
    }
}