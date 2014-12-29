#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <cstdlib>
#include <time.h>

using namespace std;

void wordcount() {
    string s;
    map<string, int> counters;
    while(cin >> s) {
        counters[s]++;
    }

    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    ///for problem 7-1
    map<int, vector<string> > counters2;
    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); it++) {
        counters2[it->second].push_back(it->first);
    }
    for (map<int, vector<string> >::const_iterator it = counters2.begin(); it != counters2.end(); it++) {
        cout << it->first << " ";
        for (vector<string>::const_iterator i = it->second.begin(); i != it->second.end(); i++) {
            cout << *i << ' ';
        }
        cout << endl;
    }
}

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

map<string, vector<int> > xref(istream&in, vector<string> find_words(const string&) = split) {
    int linenum = 0;
    string line;
    map<string, vector<int> > ret;

    while(getline(in, line)) {
        ++linenum;
        vector<string> words = find_words(line);

        for (vector<string>::const_iterator it = words.begin(); it != words.end(); it++) {
            //ret[*it].push_back(linenum);
            //for problem 7-3
            vector<int>& vlinum = ret[*it];
            if (find(vlinum.begin(), vlinum.end(), linenum) == vlinum.end()) {
                vlinum.push_back(linenum);
            }
        }
    }
    //cout << in.bad() <<endl;
    //cout << in.eof() <<endl;
    in.clear(); //clear() won't resuce cin from EOF (i.e. Ctrl-D)
                // and there is no way of terminating getline without an EOF.......
    //cout << in.bad() <<endl;
    //cout << in.eof() <<endl;
    int s;
    cin >> s;
    return ret;
}

void testxref() {
    map<string, vector<int> > ref = xref(cin);
    for (map<string, vector<int> >::const_iterator it = ref.begin(); it != ref.end(); it++) {
        cout << it->first << " on lines:";
        string output = "    ";
        for (vector<int>::const_iterator i = (it->second).begin(); i != it->second.end(); i++) {
            //cout << *i << ',';
            //for problem 7-4
            output += to_string(*i);
            output += ", ";
            if (output.size() > 50) {
                cout << output << endl;
                output = "     ";
            }
        }
        //for problem 7-4
        cout << output << endl;
        cout << endl;
    }
}

typedef vector<string> Rule;
typedef vector<Rule> Rule_coll;
typedef map<string, Rule_coll> Grammar;

Grammar read_grammar() {
    Grammar ret = {
                    {"<noun>", {
                        {"cat",}, {"dog",}, {"table"}, 
                        }
                    },
                    {"<noun-phrase>", {
                        {"<noun>",}, {"<adjective>", "<noun>"}, {"<adjective>", "<adjective>", "<noun>"},
                        }
                    },
                    {"<adjective>", {
                        {"large",}, {"brown"}, {"absurd"},
                        }
                    },
                    {"<verb>", {
                        {"jumps",}, {"sits"}, {"yells"},
                        }
                    },
                    {"<location>", {
                        {"on the stairs",}, {"under the sky"}, {"wherever it wants"},
                        }
                    },
                    {"<sentence>", {
                        {"the", "<noun-phrase>", "<verb>", "<location>"}, {"the fucking", "<noun-phrase>", "is fucking", "<adjective>"}, 
                        }
                    }
                  };

    string line;
    Rule words;

    //cout << "what the f????" << endl;
    while (getline(cin, line)) {
        if (words.size() >= 2) {
            words = split(line);
            ret[words[0]].push_back(
                Rule(++(words.begin()), words.end()));
        }
    }
    return ret;
}


bool bracketed(const string& s) {
    return !s.empty() && s[0] == '<' && s[s.size()-1] == '>';
}

int nrand(int n) {
    if (n<=0 || n > RAND_MAX) {
        throw domain_error("nrand out of range");
    }
    const int bucket_size = RAND_MAX / n;
    int r;

    do {
        r = rand() / bucket_size;
    }
    while (r >= n);
    return r;
}

//for problem 7-9
int largerand(int n) {
    static int rm = RAND_MAX;
    // for testing
    //rm = 10;
    if (n <= 0) {
        throw domain_error("negative");
    }
    if (n <= rm) {
        return nrand(n);
    }
    else {
        int q = n/rm;
        //cout << q << endl;
        //int r = n%rm;
        int res;
        do {
            int qrand = largerand(q+1);
            int rrand = nrand(rm);
            //wrong: would not be uniform
            //int rrand = nrand(r);
            res = qrand*rm + rrand;
        }
        while (res >= n);
        return res;
    }
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret) {
    if (!bracketed(word)) {
        return ret.push_back(word);
    }
    else {
        Grammar::const_iterator it = g.find(word);
        if (it == g.end()) {
            throw logic_error("no such rule");
        }
        const Rule_coll& c = it->second;

        const Rule& r = c[nrand(c.size())];

        for (Rule::const_iterator i = r.begin(); i != r.end(); i++) {
            gen_aux(g, *i, ret);
        }
    }
}

//for problem 7-6
void gen_aux_stack(const Grammar& g, const string& firstword, vector<string>& ret) {
    vector<string> stack;
    string word;
    //push the first one in
    stack.push_back(firstword);
    //invariants stack has all unprocessed words, ret has unwound words of all processed words.
    while (!stack.empty()) {
        word = stack.end()[-1];
        stack.erase(--stack.end());
        Grammar::const_iterator it = g.find(word);
        if (!bracketed(word)) {
            ret.push_back(word);
        }
        else if (it == g.end()) {
            throw logic_error("no such rule");
        }
        else {
            const Rule_coll& c = it->second;

            const Rule& r = c[nrand(c.size())];

            for (Rule::const_iterator i = r.begin(); i != r.end(); i++) {
                stack.push_back(*i);
            }
        }
    }
}

vector<string> gen_sentence(const Grammar& g) {
    vector<string> ret;
    //for problem 7-6
    //gen_aux(g, "<sentence>", ret);
    gen_aux_stack(g, "<sentence>", ret);
    return ret;
}

void gra() {
    srand(time(NULL));
    while (true) {
        vector<string> sentence = gen_sentence(read_grammar());
        //for (vector<string>::const_iterator i = sentence.begin(); i != sentence.end(); i++) {
        //for problem 7.6
        for (vector<string>::const_reverse_iterator i = sentence.rbegin(); i != sentence.rend(); i++) {
            cout << *i << ' ';
        }
        cout << endl;
    }
}

int main() {
    //wordcount();
    //testxref();
    //gra();


    // test largerand()
    srand(time(NULL)); 
    rand();     //it seems that you must run rand once to make it really set with the new seed.
    int n = 20;
    vector<int> freq(n, 0);
    int i = 0;
    while (i<1000000) {
        int t = largerand(n);
        //int t = nrand(n);
        freq[t]++;
        i++;
    }
    for (auto it = freq.begin(); it != freq.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
