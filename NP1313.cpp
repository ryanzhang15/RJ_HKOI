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

constant maxn = 5E5+8;
//constant maxn = 10;

struct node {
    _ u, v, w;
    bool operator < (const node &b) const {
        return w > b.w;
    }
} a[maxn];
struct node2 {
    _ to, w;
};

_ n, m, query, x, y, h[maxn], f[maxn][31], lg2[maxn], w[maxn][31], t[maxn];
bool vis[maxn];
queue<_> q;
vector<node2> g[maxn];

void kruskal();
_ find(_ x);
_ lca(_ x, _ y);
void bfs(_ s);
int main(int argc, char * argv[]) {
    
    freopen("truck.in", "r", stdin);
    freopen("truck.out", "w", stdout);
    
    /*
     This one's a little difficult
     but no biggie
     */
    
    scanf(_llin, &n, &m);
    for(_ i = 2; i <= n; ++i) lg2[i] = lg2[i>>1]+1;
    for(_ i = 1; i <= m; ++i) scanf(_lllin, &a[i].u, &a[i].v, &a[i].w);
    kruskal();
    for(_ i = 1; i <= n; ++i) if(!vis[i]) bfs(i);
    scanf(_lin, &query);
    for(; query--; ) {
        scanf(_llin, &x, &y);
        printf(fs(_l+"\n"), lca(x, y));
    }
    
    return 0;
}

void bfs(_ s) {
    q.push(s);
    vis[s] = true;
    for(; !q.empty(); q.pop())
        for(node2 i : g[q.front()]) {
            if(i.to == f[q.front()][0]) continue;
            vis[i.to] = true;
            h[i.to] = h[q.front()]+1;
            f[i.to][0] = q.front();
            w[i.to][0] = i.w;
            for(_ j = 1; j <= lg2[h[i.to]]; ++j) {
                f[i.to][j] = f[f[i.to][j-1]][j-1];
                w[i.to][j] = min(w[i.to][j-1], w[f[i.to][j-1]][j-1]);
            }
            if(!g[i.to].empty()) q.push(i.to);
        }
    return;
}

_ lca(_ x, _ y) {
    if(find(x) != find(y)) return -1;
    _ rv = 1E13;
    if(h[x] < h[y]) swap(x, y);
    for(; h[x] > h[y]; ) {
        rv = min(rv, w[x][lg2[h[x]-h[y]]]);
        x = f[x][lg2[h[x]-h[y]]];
    }
    if(x == y) return rv;
    for(_ k = lg2[h[x]]; k >= 0; --k) if(f[x][k] != f[y][k]) {
        rv = min(rv, min(w[x][k], w[y][k]));
        x = f[x][k];
        y = f[y][k];
    }
    rv = min(rv, min(w[x][0], w[y][0]));
    return rv;
}

_ find(_ x) {
    return t[x] == x ? x : t[x] = find(t[x]);
}

void kruskal() {
    sort(a+1, a+m+1);
    for(_ i = 1; i <= n; ++i) t[i] = i;
    for(_ i = 1; i <= m; ++i) if(find(a[i].u) != find(a[i].v)) {
        t[find(a[i].u)] = find(a[i].v);
        g[a[i].u].push_back({a[i].v, a[i].w});
        g[a[i].v].push_back({a[i].u, a[i].w});
    }
    return;
}
