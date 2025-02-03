#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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

constant maxn = 5E4+8;
//constant maxn = 6;
constant mod = 1E9+7;
_ n, m, x, y, h[maxn], s = 1, head[maxn], cnt;
bool v[maxn];

struct edge {
    _ v, next;
} g[maxn<<2];

inline void add(_ u, _ v);
inline void dfs(_ x, _ f);
int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    for(; m--; ) {
        scanf(_llin, &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    printf(fs(_l+"\n"), s);
    
    return 0;
}

inline void dfs(_ x, _ f) {
    h[x] = h[f]+1;
    for(register _ i = head[x]; i; i = g[i].next) if(g[i].v != f && !v[g[i].v]) {
        if(h[g[i].v]) s = (s * (h[x]-h[g[i].v]+1))%mod;
        else {
            dfs(g[i].v, x);
            v[g[i].v] = true;
        }
    }
    return;
}

inline void add(_ u, _ v) {
    g[++cnt].next = head[u];
    g[cnt].v = v;
    head[u] = cnt;
    return;
}
