
#include <cstdio>
#include <iostream>
#include <cstdlib>
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

constant maxn = 1E3+8;

_ N, m, c, px, py, a, b;
set<_, greater<_> > n[maxn], w[maxn];
set<_> s[maxn], e[maxn];
char t;

int main(int argc, char * argv[]) {
    
    scanf(_lllin, &N, &m, &c);
    for(_ i = 1; i <= m; ++i) {
        n[i].insert(0);
        s[i].insert(N+1);
    }
    for(_ i = 1; i <= N; ++i) {
        e[i].insert(m+1);
        w[i].insert(0);
    }
    for(_ i = 1; i <= N; ++i) {
        getchar();
        for(_ j = 1; j <= m; ++j) if(getchar() == '#') {
            n[j].insert(i);
            e[i].insert(j);
            s[j].insert(i);
            w[i].insert(j);
        }
    }
    
    scanf(_llin, &px, &py);
    getchar();
    for(; c--; ) {
        t = getchar();
        if(t == 'N') {
            b = *n[py].lower_bound(px);
            a += px-b-1;
            px = b+1;
        } else if(t == 'E') {
            b = *e[px].lower_bound(py);
            a += b-py-1;
            py = b-1;
        } else if(t == 'S') {
            b = *s[py].lower_bound(px);
            a += b-px-1;
            px = b-1;
        } else {
            b = *w[px].lower_bound(py);
            a += py-b-1;
            py = b+1;
        }
    }
    
    printf(fs(_l+"\n"), a);
    
    return 0;
}
