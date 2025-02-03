#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

str msg;
signed char d[30], t;
_ c, k, rd[300];
bool on;

str decrypt(str r, _ key);
int main(int argc, char * argv[]) {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cin >> c;
    d[c] = ' ';
    rd[' '] = c;
    for(char i = 'A'; i <= 'Z'; ++i) {
        cin >> c;
        d[c] = i;
        rd[i] = c;
    }
    cin >> noskipws;
    for(; cin >> t; ) {
        if(t >= 'A' && t <= 'Z') on = true;
        if(t >= '0' && t <= '9') {
            for(; cin.peek() >= '0' && cin.peek() <= '9' ; cin >> t) k = (k*10)+t-'0';
            k = (k*10)+t-'0';
            on = false;
            for(str::iterator i = msg.end()-1; *i == ' ' || *i == '\n'; i = msg.end()-1) msg.pop_back();
            msg = decrypt(msg, k);
            cout << '[' << msg << ']' << endl;
            k = 0;
            msg.clear();
        }
        if(on) msg.push_back(t);
    }
    
    
    return 0;
}

str decrypt(str r, _ key) {
    for(char &i : r) i = d[(((rd[i]-key)%27)+27)%27];
    return r;
}
