#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        string rajesh;
        string sheldon;

        cin >> rajesh >> sheldon;

        if(rajesh == "pedra"){

            if(sheldon == "pedra"){
                cout << "empate" << endl;
            }

            else if(sheldon == "papel"){
                cout << "sheldon" << endl;
            }

            else if(sheldon == "tesoura"){
                cout << "rajesh" << endl;
            }

            else if(sheldon == "lagarto"){
                cout << "rajesh" << endl;
            }

            else if(sheldon == "spock"){
                cout << "sheldon" << endl;
            }
        }

        else if(rajesh == "papel"){

            if(sheldon == "pedra"){
                cout << "rajesh" << endl;
            }

            else if(sheldon == "papel"){
                cout << "empate" << endl;
            }

            else if(sheldon == "tesoura"){
                cout << "sheldon" << endl;
            }

            else if(sheldon == "lagarto"){
                cout << "sheldon" << endl;
            }

            else if(sheldon == "spock"){
                cout << "rajesh" << endl;
            }
        }

        else if(rajesh == "tesoura"){

            if(sheldon == "pedra"){
                cout << "sheldon" << endl;
            }

            else if(sheldon == "papel"){
                cout << "rajesh" << endl;
            }

            else if(sheldon == "tesoura"){
                cout << "empate" << endl;
            }

            else if(sheldon == "lagarto"){
                cout << "rajesh" << endl;
            }

            else if(sheldon == "spock"){
                cout << "sheldon" << endl;
            }
        }

        else if(rajesh == "lagarto"){

            if(sheldon == "pedra"){
                cout << "sheldon" << endl;
            }

            else if(sheldon == "papel"){
                cout << "rajesh" << endl;
            }

            else if(sheldon == "tesoura"){
                cout << "sheldon" << endl;
            }

            else if(sheldon == "lagarto"){
                cout << "empate" << endl;
            }

            else if(sheldon == "spock"){
                cout << "rajesh" << endl;
            }
        }

        else if(rajesh == "spock"){

            if(sheldon == "pedra"){
                cout << "rajesh" << endl;
            }

            else if(sheldon == "papel"){
                cout << "sheldon" << endl;
            }

            else if(sheldon == "tesoura"){
                cout << "rajesh" << endl;
            }

            else if(sheldon == "lagarto"){
                cout << "sheldon" << endl;
            }

            else if(sheldon == "spock"){
                cout << "empate" << endl;
            }
        }
    }
}