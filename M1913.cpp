
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
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 5E5+8;
//constant maxn = 10;

_ n, m, t, sz[maxn], f[maxn<<1], c[maxn], r[maxn];
priority_queue<_p> q[maxn];
bitset<maxn<<1 > o;
vector<_> g[maxn];

void dfs(_ x);
int main() {
    
    scanf("%lld%lld%lld", &n, &m, &t);
    for(_ i = 1; i <= n+m; ++i) scanf("%lld", &f[i]);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &c[i]);
    c[0] = 1E18;
    for(_ i = 1; i <= m; ++i) scanf("%lld", &r[i]);
    for(_ i = 1; i <= n+m; ++i) g[f[i]].push_back(i);
    for(_ i = n+1; i <= n+m; ++i) {
        sz[f[i]] += r[i-n];
        q[f[i]].push(mp(r[i-n], i));
    }
    dfs(0);
    printf("%lld\n", (_)q[0].size());
    for(_ i = n+1; i <= n+m; ++i) if(!o[i]) printf("%lld ", i);
    putchar(10);
    
    return 0;
}

void dfs(_ x) {
    for(_ i = 0; i < g[x].size(); ++i) if(g[x][i] <= n) {
        dfs(g[x][i]);
        sz[x] += sz[g[x][i]];
        if(q[x].size() < q[g[x][i]].size()) swap(q[x], q[g[x][i]]);
        for(; !q[g[x][i]].empty(); q[g[x][i]].pop()) q[x].push(q[g[x][i]].top());
    }
    for(; sz[x] > c[x]; ) {
        _p t = q[x].top();
        q[x].pop();
        o.set(t.second);
        sz[x] -= t.first;
    }
    return;
}
