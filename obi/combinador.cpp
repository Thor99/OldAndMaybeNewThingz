#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;

    for(int k = 0; k < N; k++){
        string str1;
        string str2;
        string strfinal;

        cin >> str1 >> str2;

        if(str1.size() == str2.size()){
            for(int i = 0; i < str1.size(); i++){
                strfinal += str1[i];
                strfinal += str2[i];
            }
        }

        else if(str1.size() > str2.size()){
            for(int i = 0; i < str2.size(); i++){
                strfinal += str1[i];
                strfinal += str2[i];
            }

            for(int i = str2.size(); i < str1.size(); i++){
                strfinal += str1[i];
            }
        }

        else { // str2.size() > str1.size()
            for(int i = 0; i < str1.size(); i++){
                strfinal += str1[i];
                strfinal += str2[i];
            }

            for(int i = str1.size(); i < str2.size(); i++){
                strfinal += str2[i];
            }
        }

        cout << strfinal << endl;
    }
}