//for Q 2-1 2 3 4

#include <iostream>
#include <string>
using namespace std;

int main(){
    string name;
    cout << "Name?";
    cin >> name;
    int hpad;
    int vpad;
    cout << "vertical pad?";
    cin >> vpad;
    cout << "horizontal pad?";
    cin >> hpad;

    const int rows = 2 * vpad + 3;
    const string greeting = "Hello, " + name + "!";
    const string::size_type cols = greeting.size() + 2 * hpad + 2;
    //int c = 0;
    string::size_type c;    //use type specified by class

    for (int r = 0; r < rows; r++){
        c = 0;
        while (c < cols){
            if (c == 0 || c == cols - 1 || r == 0 || r == rows - 1) {
                cout << "*";
                c++;
            }
            else if (c == 1){
                if (r == vpad + 1){
                    string spaces(hpad, ' ');
                    //cout << string spaces(hpad, " ");
                    cout << spaces;
                    cout << greeting;
                    //cout << string spaces(hpad, " ");
                    cout << spaces;
                }
                else {
                    //cout << string spaces(cols - 2, " ");
                    string spaces(cols - 2, ' ');
                    cout << spaces;
                }
                c += cols - 2;
            }
        }
        cout << endl;
    }

    return 0;
    
}
