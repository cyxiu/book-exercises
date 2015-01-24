#include <map>
#include <string>

using namespace std;

int main() {
    map<int, string> m;
    //map<int, string>::iterator v = back_inserter(m);
    //map<int, string>::iterator v = inserter(m, m.end());
    insert_iterator<map<int, string> > v = inserter(m, m.end());
    back_insert_iterator<map<int, string> > v2 = back_inserter(m);

    return 1;

}
