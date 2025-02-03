#include <cstdio>
#include <bitset>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E4+8;

_ n, m, a[maxn], x, y, d, s, sd, head[maxn], cnt;
struct edge {
    _ to, next;
} g[maxn<<1];
bitset<maxn> b;

inline void addEdge(_ x, _ y);
inline _ read();
inline void dfs2(_ x, _ fa, _ d);
inline void dfs1(_ x, _ fa, _ dpth);
int main() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n-1; ++i) {
        x = read();
        y = read();
        addEdge(x, y);
        addEdge(y, x);
    }
    for(_ i = 1; i <= m; ++i) {
        x = read();
        b.flip(x);
    }
    dfs1(1, -1, 0);
    dfs2(1, -1, d);
    
    printf("%lld %lld\n", s, sd);
    
    return 0;
}

inline void dfs1(_ x, _ fa, _ dpth) {
    for(_ i = head[x]; i; i = g[i].next) if(g[i].to != fa) {
        dfs1(g[i].to, x, dpth+1);
        a[x] += a[g[i].to];
    }
    if(b[x]) {
        ++a[x];
        d += dpth;
    }
    return;
}

inline void dfs2(_ x, _ fa, _ d) {
    if(d > sd) {
        sd = d;
        s = x;
    }
    for(_ i = head[x]; i; i = g[i].next) if(g[i].to != fa) dfs2(g[i].to, x, d-(a[g[i].to]<<1)+m);
    return;
}

inline _ read() {
    register _ x = 0; register char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}

inline void addEdge(_ x, _ y) {
    g[++cnt].next = head[x];
    g[cnt].to = y;
    head[x] = cnt;
    return;
}
