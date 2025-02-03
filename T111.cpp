
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

constant maxn = 900+8;
constant maxq = 2E5+888;
constant maxe = maxn*maxn*8+888;
constant maxnsq = maxn*maxn+888;

struct edge {
    _ from, to, cost;
    bool operator < (const edge &b) const {
        return cost < b.cost;
    }
} g[maxe];
struct query {
    _ v, id;
    bool operator < (const query &b) const {
        return v < b.v;
    }
} qr[maxq];
struct output {
    _ a;
    unsigned long long b;
} o[maxq];
_ a[maxn][maxn], n, q, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, c, cnt, f[maxnsq], p;
unsigned long long sz[maxnsq], mx;

_ findd(_ x);
_ encode(_ x, _ y);
int main() {
    
    scanf("%lld%lld", &n, &q);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) scanf("%lld", &a[i][j]);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) for(_ k = 0; k < 4; ++k) {
        _ nx = i + dx[k];
        _ ny = j + dy[k];
        if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
        g[++cnt] = (edge){encode(i, j), encode(nx, ny), abs(a[i][j]-a[nx][ny])};
    }
    sort(g+1, g+1+cnt);
    for(_ i = 1; i <= q; ++i) {
        scanf("%lld", &qr[i].v);
        qr[i].id = i;
    }
    sort(qr+1, qr+1+q);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) f[encode(i, j)] = encode(i, j);
    c = n*n;
    p = 1;
    for(_ i = 1; i <= cnt; ++i) {
        for(; p <= q && g[i].cost > qr[p].v; ++p) o[qr[p].id] = (output){c, mx};
        _ x = findd(g[i].from), y = findd(g[i].to);
        if(x != y) {
            sz[y] += sz[x] + g[i].cost;
            mx = max(mx, sz[y]);
            f[x] = y;
            --c;
        }
    }
    for(; p <= q; ++p) o[qr[p].id] = o[qr[p-1].id];
    for(_ i = 1; i <= q; ++i) printf("%lld %llu\n", o[i].a, o[i].b);
    
    return 0;
}

_ encode(_ x, _ y) {
    return x*n+y;
}

_ findd(_ x) {
    return f[x] == x ? x : f[x] = findd(f[x]);
}
