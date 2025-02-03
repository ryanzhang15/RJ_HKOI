#include <bits/stdc++.h>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5e4+8;
struct edge {
    _ to, cost, next;
} g[maxn<<1];
_ n, m, s, u[maxn], t[maxn], q[maxn], head[maxn], cnt, l, r = 1E8+8, md, x, y, z, c;

inline _ read();
inline void dfs(_ x, _ fa);
inline void addEdge(_ x, _ y, _ v);
int main() {
    
    freopen("track.in", "r", stdin);
    freopen("track.out", "w", stdout);
    
    n = read();
    m = read();
    for(_ i = 1; i <= n-1; ++i) {
        x = read();
        y = read();
        z = read();
        addEdge(x, y, z);
        addEdge(y, x, z);
    }
    
    for(; l <= r; ) {
        md = (l+r)>>1;
        c = 0;
        memset(t, 0, sizeof t);
        dfs(1, -1);
        if(c >= m) {
            s = md;
            l = md+1;
        } else r = md-1;
    }
    
    printf("%lld\n", s);
    
    return 0;
}

inline void addEdge(_ x, _ y, _ v) {
    g[++cnt].to = y;
    g[cnt].next = head[x];
    g[cnt].cost = v;
    head[x] = cnt;
    return;
}

inline void dfs(_ x, _ fa) {
    for(_ i = head[x]; i; i = g[i].next) if(g[i].to != fa) dfs(g[i].to, x);
    _ tail = 0;
    for(_ i = head[x]; i; i = g[i].next) if(g[i].to != fa) q[++tail] = u[g[i].to] + g[i].cost;
    sort(q+1, q+tail+1);
    for(_ i = tail; i >= 1 && q[i] >= md; --i) {
        --tail;
        ++c;
    }
    for(_ i = 1; i <= tail; ++i) {
        if(t[i] != x) {
            _ l = i+1, r = tail, af = tail+1;
            for(; l <= r; ) {
                _ mdd = (l+r)>>1;
                if(q[i] + q[mdd] >= md) {
                    af = mdd;
                    r = mdd-1;
                } else l = mdd+1;
            }
            for(; t[af] == x && af <= tail; ) ++af;
            if(af <= tail) {
                t[i] = t[af] = x;
                ++c;
            }
        }
    }
    u[x] = 0;
    for(_ i = tail; i >= 1; --i) if(t[i] != x) {
        u[x] = q[i];
        break;
    }
    return;
}

inline _ read() {
    _ x = 0;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = 10*x+ch-'0';
    return x;
}
