//#include <bits/stdc++.h>
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

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E4+8;
constant maxlg = 15;
constant maxe = 1E5+8;

struct edge {
    _ u, v, c;
    bool operator < (const edge &b) const {
        return c < b.c;
    }
} e[maxe], e2[maxe];
struct sedge {
    _ to, cost;
};
vector<sedge> g[maxn];
_ n, m, qu, t[maxn], lg2[maxn], f[maxn][maxlg], w[maxn][maxlg], h[maxn], ind, nv;
queue<_> q;

_ lca(_ x, _ y);
void bfs();
_ find(_ x);
int main() {
    
    scanf("%lld%lld%lld", &n, &m, &qu);
    for(_ i = 2; i <= n; ++i) lg2[i] = lg2[i>>1]+1;
    for(_ i = 1; i <= m; ++i) scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].c);
    memcpy(e2, e, sizeof e);
    sort(e+1, e+1+m);
    for(_ i = 1; i <= n; ++i) t[i] = i;
    for(_ i = 1; i <= m; ++i) {
        _ u = find(e[i].u), v = find(e[i].v);
        if(u != v) {
            g[e[i].u].push_back((sedge){e[i].v, e[i].c});
            g[e[i].v].push_back((sedge){e[i].u, e[i].c});
            t[u] = v;
        }
    }
    bfs();
    for(; qu--; ) {
        scanf("%lld%lld", &ind, &nv);
        //printf("%lld\n", lca(e2[ind].u, e2[ind].v));
        puts(lca(e2[ind].u, e2[ind].v) >= nv ? "Yes" : "No");
    }
    
    return 0;
}

_ find(_ x) {
    return t[x] == x ? x : t[x] = find(t[x]);
}

void bfs() {
    q.push(1);
    for(; !q.empty(); q.pop()) for(_ i = 0; i < g[q.front()].size(); ++i) {
        sedge c = g[q.front()][i];
        if(c.to == f[q.front()][0]) continue;
        h[c.to] = h[q.front()]+1;
        f[c.to][0] = q.front();
        w[c.to][0] = c.cost;
        for(_ j = 1; j <= lg2[h[c.to]]; ++j) {
            f[c.to][j] = f[f[c.to][j-1]][j-1];
            w[c.to][j] = max(w[c.to][j-1], w[f[c.to][j-1]][j-1]);
        }
        q.push(c.to);
    }
    return;
}

_ lca(_ x, _ y) {
    _ rv = -1E13;
    if(h[x] < h[y]) swap(x, y);
    for(; h[x] > h[y]; ) {
        rv = max(rv, w[x][lg2[h[x]-h[y]]]);
        x = f[x][lg2[h[x]-h[y]]];
    }
    if(x == y) return rv;
    for(_ k = lg2[h[x]]; k >= 0; --k) if(f[x][k] != f[y][k]) {
        rv = max(rv, max(w[x][k], w[y][k]));
        x = f[x][k];
        y = f[y][k];
    }
    rv = max(rv, max(w[x][0], w[y][0]));
    return rv;
}
