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

constant maxn = 1E6+8;
//constant maxn = 10;
vector<_> p[1000], g[maxn];
_ a[maxn], n, m, c, t;
bool v[maxn];

void climb(_ p);
int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &a[1]);
    p[a[1]].push_back(1);
    v[1] = true;
    for(_ i = 2; i <= n; ++i) {
        scanf(_llin, &a[i], &c);
        p[a[i]].push_back(i);
        g[c].push_back(i);
        v[i] = true;
    }

    scanf(_lin, &m);
    for(; m--; ) {
        scanf(_lin, &c);
        if(p[c].empty()) {
            putchar('0');
            putchar(10);
            continue;
        }
        t = 0;
        for(_ i : p[c]) if(v[i]) {
            climb(i);
            v[i] = false;
        }
        printf(fs(_l+"\n"), t);
        p[c].clear();
    }
    
    return 0;
}

void climb(_ p) {
    ++t;
    v[p] = false;
    for(_ i : g[p]) if(v[i]) climb(i);
    return;
}
