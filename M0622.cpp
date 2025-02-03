#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <bitset>

#include <algorithm>
#include <numeric>

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 5E4+8;

struct edge {
    _ to, cost;
};
vector<edge> g[maxn];
_ n, c[maxn], a, b, s;

void dfs(_ x, _ cr);
inline _ read();
int main() {
    
    n = read();
    for(_ i = 1; i <= n; ++i) {
        a = read();
        b = read();
        if(!b) b = -1;
        g[i].push_back((edge){a, b});
        g[a].push_back((edge){i, b});
    }
    for(_ i = 1; i <= n; ++i) if(!c[i]) {
        c[i] = 1;
        a = b = 0;
        dfs(i, 1);
        s += max(a, b);
    }
    printf("%lld\n", s);
    
    return 0;
}

inline _ read() {
    _ x = 0;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}

void dfs(_ x, _ cr) {
    if(~cr) ++a;
    else ++b;
    for(_ i = 0; i < g[x].size(); ++i) {
        if(c[g[x][i].to]) {
            if(c[g[x][i].to] != cr * g[x][i].cost) {
                puts("-1");
                exit(0);
            }
            continue;
        }
        c[g[x][i].to] = cr * g[x][i].cost;
        dfs(g[x][i].to, cr * g[x][i].cost);
    }
    return;
}
