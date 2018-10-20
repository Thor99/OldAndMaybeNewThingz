#include <cstdio>
#include <map>

using namespace std;

int main(){
    map<int, int> mapa;
    int N;
    scanf("%d", &N);

    while(N--){
        int num;
        scanf("%d", &num);

        if(mapa.find(num) == mapa.end()){
            mapa[num] = 1;
        } else {
            mapa[num]++;
        }
    }

    for(map<int, int>::iterator it = mapa.begin(); it != mapa.end(); ++it){
        printf("%d aparece %d vez(es)\n", (*it).first, (*it).second);
    }
}