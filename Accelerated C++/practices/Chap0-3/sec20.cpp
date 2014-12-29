#include <iostream>
#include <string>
using namespace std;

int main(){
    string name;
    cout << "Name?";
    cin >> name;
    int pad = 3;

    int rows = 2 * pad + 3;
    string greeting = "Hello, " + name + "!";
    string::size_type cols = greeting.size() + 2 * pad + 2;
    //int c = 0;
    string::size_type c;    //use type specified by class

    for (int r = 0; r < rows; r++){
        c = 0;
        while (c < cols){
            if (r == pad + 1 && c == pad + 1){
                cout << greeting;
                c += greeting.size();
            }
            else {
                if (c == 0 || c == cols - 1 || r == 0 || r == rows - 1) {
                    cout << "*";
                }
                else {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }

    return 0;
    
}
