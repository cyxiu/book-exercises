#include "Str.h"
#include <vector>

using namespace std;

int main() {
    /*
    vector<char> vecchar = {'a', 'b', 'e'};
    vector<int> vecint = {1, 2, 3};

    Str a(vecchar.begin(), vecchar.end());
    a.print();
    Str b(vecint.begin(), vecint.end());
    b.print();
    Str c("Hello!");
    c.print();

    //what does conversion from int to char do?
    char chhh = 3;
    cout << '+' << chhh << '+' << endl;
    */

    Str s1;
    s1.print();
    Str s2(4, 's');
    s2.print();
    Str s3("s3abcd");  //these two are equivalent!! BOTH initialization. operator= is NOT called.
    s3.print();
    Str s4 = "s4efgh";  //these two are equivalent!! BOTH initialization. operator= is NOT called.
    s4.print();
    Str s5;
    s5 = s4;        //this should call default constructor and call synthesized oper= which calls oper= of Vec.
    s5.print();
    cout << s5.size() << endl;
    const Str s6(s3.begin(), s3.end());
    s6.print();
    cout << ("s6[3] = ") << (s6[3]) << endl;
    s4 += s3;
    s4.print();
    if (!s1) cout << "s1 empty" << endl;
    if (s2) cout << "s2 not empty" << endl;
    if (s3 < s4) cout << "s3 < s4 " << endl;
    cout << "s3+s4:  " << (s3 + s4) << endl;
    //Str temp = s2 + "s2+temp";
    cout << (s2 + "+s2    , then ") << ("s3+" + s3) << endl;

    return 0;

}
