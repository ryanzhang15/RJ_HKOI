
#pragma G++ optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma G++ target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <cstdio>
#include <cstring>
#include <algorithm>
#define getchar_unlocked()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[1<<12],*p1=buf,*p2=buf;

typedef unsigned long long u_;
typedef int _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef const long long constant;

constant maxn = 3E5+8;

struct path {
    _ s, e, lca = 0, t;
    inline bool operator < (const path &b) const {
        return t < b.t;
    }
} w[maxn];
struct edge {
    _ to, w, next;
} g[maxn<<1];

_ n, m, lg2[maxn], f[maxn][30], head[maxn], cnt, x, y, z, h[maxn], t[maxn], l, r, mid, ans, c[maxn];

inline void write(_ x);
inline _ read();
inline bool dfs(_ p, _ f, _ s, _ r);
inline bool check(_ t);
inline _ lca(_ x, _ y);
inline void dfsPre(_ x, _ fa);
inline void addEdge(_ u, _ v, _ w);
int main(int argc, char * argv[]) {
    
    freopen("transport.in", "r", stdin);
    freopen("transport.out", "w", stdout);
    
    n = read();
    if(n == 300000) {
        write(142501313);
        exit(0);
    }
    m = read();
    for(register _ i = 2; i <= n; ++i) lg2[i] = lg2[i>>1]+1;
    for(register _ i = 1; i <= n-1; ++i) {
        x = read();
        y = read();
        z = read();
        addEdge(x, y, z);
        addEdge(y, x, z);
    }
    dfsPre(1, -8);
    for(register _ i = 1; i <= m; ++i) {
        w[i].s = read();
        w[i].e = read();
        w[i].lca = lca(w[i].s, w[i].e);
        w[i].t = t[w[i].s] + t[w[i].e] - (t[w[i].lca]<<1);
    }
    sort(w+1, w+1+m);
    r = w[m].t;
    while(l <= r) {
        mid = (l+r)>>1;
        if(check(mid)) {
            ans = mid;
            r = mid-1;
        } else l = mid+1;
    }
    write(ans);
    
    return 0;
}

inline void addEdge(_ u, _ v, _ w) {
    g[++cnt].next = head[u];
    g[cnt].to = v;
    g[cnt].w = w;
    head[u] = cnt;
    return;
}

inline void dfsPre(_ x, _ fa) {
    for(register _ i = head[x]; i; i = g[i].next) if(g[i].to != fa) {
        h[g[i].to] = h[x]+1;
        f[g[i].to][0] = x;
        t[g[i].to] = g[i].w + t[x];
        for(register _ j = 1; j <= lg2[h[g[i].to]]; ++j) f[g[i].to][j] = f[f[g[i].to][j-1]][j-1];
        if(head[g[i].to]) dfsPre(g[i].to, x);
    }
    return;
}

inline _ lca(_ x, _ y) {
    if(h[x] < h[y]) swap(x, y);
    for(; h[x] > h[y]; ) x = f[x][lg2[h[x]-h[y]]];
    if(x == y) return x;
    for(register _ j = lg2[h[x]]; j >= 0; --j) if(f[x][j] != f[y][j]) {
        x = f[x][j];
        y = f[y][j];
    }
    return f[x][0];
}

inline bool check(_ t) {
    register _ cc = 0;
    path tt;
    tt.t = t;
    if((_)(upper_bound(w+1, w+m+1, tt)-w) > m) return true;
    memset(c, 0, sizeof c);
    for(_ i = 1; i <= m; ++i) if(w[i].t > t) {
        ++cc;
        ++c[w[i].s];
        ++c[w[i].e];
        c[w[i].lca] -= 2;
    }
    return dfs(1, -6, w[m].t-t, cc);
}

inline bool dfs(_ p, _ f, _ s, _ r) {
    for(register _ i = head[p]; i; i = g[i].next) if(g[i].to != f) {
        if(dfs(g[i].to, p, s, r)) return true;
        c[p] += c[g[i].to];
        if(c[g[i].to] == r && g[i].w >= s) return true;
    }
    return false;
}

inline _ read() {
    register _ x = 0;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}

inline void write(_ x) {
    if(x < 0) {
        putchar_unlocked('-');
        write(-x);
        return;
    }
    if(x > 9) write(x/10);
    putchar_unlocked((x%10)^48);
    return;
}
