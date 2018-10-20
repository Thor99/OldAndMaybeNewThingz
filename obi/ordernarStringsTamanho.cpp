#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        vector<pair<int, string> > palavras; // Tamanho, str
        string line;
        int count = 0;
        while(getline(cin, line)){
            istringstream linestream(line);
            string word;
            while (linestream >> word)
            {
              palavras.push_back(make_pair(word.size(), word));
            }

            if(count == 1){
                break;
            }
            
            count++;
        }

        sort(palavras.rbegin(), palavras.rend());

        for(int k = 0; k < palavras.size(); k++){
            cout << palavras[k].second << " ";
        }

        printf("\n");
    }
}