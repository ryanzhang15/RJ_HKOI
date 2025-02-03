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

constant maxn = 25E3+8;

map<_, _> t, f;
set<_> e;
bitset<maxn> v;
vector<_> g[maxn];
_ n, m, a, b, c, s;

int main(int argc, char * argv []) {
    
    scanf(_llin, &n, &m);
    for(_ i = 1; i <= n; ++i) {
        scanf(_llin, &a, &b);
        if(e.find(b) == e.end()) {
            e.insert(b);
            t[b] = ++c;
            f[c] = b;
        }
        g[t[b]].push_back(a);
    }
    
    for(_ i = 1; i <= m; ++i) {
        scanf(_llin, &a, &b);
        if(e.find(b) != e.end()) {
            for(_ j : g[t[b]]) printf(fs(_l+" "+_l+" "+_l+"\n"), j, b, a);
            v[t[b]] = true;
        }
    }
    
    for(_ i = 1; i <= c; ++i) for(_ j : g[i]) if(~v[i]) printf(fs(_l+" "+_l+" null\n"), j, f[i]);
        
    return 0;
}

