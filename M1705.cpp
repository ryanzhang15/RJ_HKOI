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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxg = 60+8;
constant maxn = maxg*maxg+8;
constant maxe = maxn*4;
constant big = 12000;
constant maxd = big+8;

_ n, m, k, a[maxg][maxg], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, head[maxn], cnt, d[maxn][maxn], s, sx, sy, ex, ey;
struct edge {
    _ to, cost, next;
} g[maxe];
queue<_> q[maxd];
bitset<maxn> v;

inline void betterDijkstra(_ st);
inline void addEdge(_ x, _ y, _ z);
inline _ encode(_ x, _ y);
int main() {
    
    memset(d, 4, sizeof d);
    scanf("%lld%lld%lld", &n, &m, &k);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) scanf("%lld", &a[i][j]);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) for(_ k = 0; k < 4; ++k) {
        _ nx = i + dx[k];
        _ ny = j + dy[k];
        if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
        addEdge(encode(i, j), encode(nx, ny), a[nx][ny]);
    }
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) betterDijkstra(encode(i, j));
    scanf("%lld%lld", &sx, &sy);
    s += a[sx][sy];
    for(; k--; ) {
        scanf("%lld%lld", &ex, &ey);
        s += d[encode(sx, sy)][encode(ex, ey)];
        sx = ex;
        sy = ey;
    }
    printf("%lld\n", s);
    
    return 0;
}

inline _ encode(_ x, _ y) {
    return x*max(n, m)+y;
}

inline void addEdge(_ x, _ y, _ z) {
    g[++cnt].next = head[x];
    g[cnt].to = y;
    g[cnt].cost = z;
    head[x] = cnt;
    return;
}

inline void betterDijkstra(_ st) { //ok, spfa doesn't work :(
    d[st][st] = 0;
    q[0].push(st);
    v.reset();
    _ p = 0;
    for(; p <= big; ++p) for(; !q[p].empty(); q[p].pop()) {
        _ t = q[p].front();
        if(v[t]) continue;
        v.set(t);
        for(_ i = head[t]; i; i = g[i].next) if(d[st][g[i].to] > d[st][t] + g[i].cost) {
            d[st][g[i].to] = d[st][t] + g[i].cost;
            q[d[st][g[i].to]].push(g[i].to);
        }
    }
    return;
}
