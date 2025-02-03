

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
#include <random>
#include <numeric>

#define ef else if

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 2E5+8;
constant maxp = 1E4+8;

_ n, m, x, y, head[maxn][2], cnt[2], s, e, d[maxn];
struct edge {
    _ to, next;
} g[maxn][2];
bitset<maxp> re, c;
queue<_> q;

void addEdge(_ x, _ y, _ c);
int main() {
    
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    memset(d, ~0, sizeof d);
    scanf("%lld%lld", &n, &m);
    for(; m--; ) {
        scanf("%lld%lld", &x, &y);
        addEdge(x, y, 0);
        addEdge(y, x, 1);
    }
    scanf("%lld%lld", &s, &e);
    q.push(e);
    re.flip(e);
    for(; !q.empty(); q.pop()) for(_ i = head[q.front()][1]; i; i = g[i][1].next) if(!re[g[i][1].to]) {
        re.flip(g[i][1].to);
        q.push(g[i][1].to);
    }
    for(_ i = 1; i <= n; ++i) {
        bool fg = re[i];
        for(_ j = head[i][0]; j && fg; j = g[j][0].next) fg = fg && re[g[j][0].to];
        c[i] = fg;
    }
    if(c[s]) {
        q.push(s);
        d[s] = 0;
    }
    for(; !q.empty(); q.pop()) for(_ i = head[q.front()][0]; i; i = g[i][0].next) if(!~d[g[i][0].to] && c[g[i][0].to]) {
        d[g[i][0].to] = d[q.front()]+1;
        q.push(g[i][0].to);
    }
    printf("%lld\n", d[e]);
    
    return 0;
}

void addEdge(_ x, _ y, _ c) {
    g[++cnt[c]][c].next = head[x][c];
    g[cnt[c]][c].to = y;
    head[x][c] = cnt[c];
    return;
}
