#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

bool space(char c){
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);
}

vector<string> split(const string& str){
    vector<string> ret;
    typedef string::const_iterator iter;

    iter i = str.begin();
    while (i != str.end()) {
        i = find_if(i, str.end(), not_space);

        if (i != str.end()) {
            iter j = find_if(i, str.end(), space);
            ret.push_back(string(i, j));
            i = j;
        }
    }
    return ret;
}

bool is_palindrome(const string& s) {
    return equal(s.begin(), s.end(), s.rbegin());
}


bool not_url_char(char c) {
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
    return find_if(b, e, not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";
    typedef string::const_iterator iter;
    iter i = b;
    //invariant: no urls in [b, i)
    while((i = search(i, e, sep.begin(), sep.end())) != e) {
        if (i != b && i + sep.size() != e) {
            iter beg = i;
            //invariant: *beg is the : in "// or an alpha. 
            while (beg != b && isalpha(beg[-1])) {
                beg--;
            }
            if (beg != i && !not_url_char(i[sep.size()])) {
                return beg;
            }
        }
        i += sep.size();
    }
    return e;
}

vector<string> find_urls(const string& s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    
    while(b != e) {
        b = url_beg(b, e);
        if (b != e) {
            iter after = url_end(b, e);
            ret.push_back(string(b, after));
            b = after;
        }
    }
    return ret;
}

int main(){
    typedef vector<string>::const_iterator vsit;

    // to test find_urls
    string ur = "   ://sdaf fjwo fsd :/ sda:// http://test.com flaje234-00  f://a.net fjoie3902";
    vector<string> urls = find_urls(ur);
    for (vsit i = urls.begin(); i != urls.end(); i++) {
        cout << *i << endl;
    }

    cout << endl;

    vector<string> words = split(ur);
    for (vsit i = words.begin(); i != words.end(); i++) {
        cout << *i << endl;
    }

    return 0;

}
