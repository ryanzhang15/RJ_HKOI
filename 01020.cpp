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

_ n, m, d, c, ans;
set<_> s;
map<_, _> x;

int main(int argc, char * argv []) {
    
    scanf(_llin, &n, &m);
    for(_ i = 1; i <= n; ++i) {
        scanf(_llin, &d, &c);
        if(s.find(c) == s.end()) {
            s.insert(c);
            x[c] = 1;
        } else x[c]++;
    }
    for(_ i = 1; i <= m; ++i) {
        scanf(_llin, &d, &c);
        if(s.find(c) != s.end()) ans += x[c];
    }
    
    printf(fs(_l+"\n"), ans);
    
    return 0;
}

