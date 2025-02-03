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
#include <queue>
#include <list>
#include <set>

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

str t;
set<str> s;
_ n, l, r;

int main(int argc, char * argv[]) {
    
    getline(cin, t);
    n = t.length();
    for(_ i = 0; i < n; ++i) {
        l = r = i;
        while(l >= 0 && r < n && t[l] == t[r]) {
            s.insert(t.substr(l, r-l+1));
            ++r;
            --l;
        }
        if(i+1 < n && t[i] == t[i+1]) {
            r = i+1;
            l = i;
            while(l >= 0 && r < n && t[l] == t[r]) {
                s.insert(t.substr(l, r-l+1));
                ++r;
                --l;
            }
        }
    }
    cout << "The string '" << t << "' contains " << s.size() << " palindromes." << endl;
    
    return 0;
}
