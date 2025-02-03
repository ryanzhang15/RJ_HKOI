#pragma G++ optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma G++ target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <cstdio>
#include <cmath>
#include <bitset>

#define ef else if
using namespace std;

typedef int _;
typedef unsigned long long u_;
typedef long double _D;
typedef const long long constant;

constant maxn = 10800000+8;
constant maxe = 21000000+8;

int head[maxn], n, m, t, st, ed, h[30008][370], cc, d[maxn];
struct edge {
    int tocost, next;
} g[maxe];
bitset<70> u[70];

inline int read();
inline void addEdge(int x, int y, int z);
int main() {
    
    register int l = 0, r = 0;
    
    n = read();
    m = read();
    cc = n-1;
    t = min(60, (int)sqrt(n));
    for(register int c = 1, x, y; c <= m; ++c) {
        x = read();
        y = read();
        if(c == 1) st = x;
        ef(c == 2) ed = x;
        if(y <= t) {
            register int md = x%y;
            if(!u[md][y]) {
                u[md].set(y);
                for(register int i = md; i < n; i += y) {
                    addEdge(h[i][y] = ++cc, i, 0);
                    if(i > md) {
                        addEdge(h[i][y], h[i-y][y], 1);
                        addEdge(h[i-y][y], h[i][y], 1);
                    }
                }
            }
            addEdge(x, h[x][y], 0);
        } else {
            register int tp = ++cc;
            register int pt = tp;
            addEdge(x, cc, 0);
            for(register int i = x-y, j = 1; i >= 0; i -= y, ++j) {
                addEdge(pt, ++cc, 1);
                addEdge(cc, i, 0);
                pt = cc;
            }
            pt = tp;
            for(register int i = x+y, j = 1; i < n; i += y, ++j) {
                addEdge(pt, ++cc, 1);
                addEdge(cc, i, 0);
                pt = cc;
            }
        }
    }
    int * q = h[0];
    d[st] = 1;
    q[r++] = st;
    while(l != r) {
        register int t = q[l++];
        if(l == 10800000) l = 0; 
        if(t == ed) break;
        for(register int i = head[t], v, w; i; i = g[i].next) {
            v = g[i].tocost>>1, w = g[i].tocost & 1;
            if(d[v]) continue;
            d[v] = d[t]+w;
            if(w) q[r++] = v;
            else {
                if(--l < 0) l = 10800000-1;
                q[l] = v;
            }
        }
    }
    printf("%d\n", d[ed]-1);
    
    return 0;
}

inline void addEdge(int x, int y, int z) {
    static int cnt = 0;
    g[++cnt].tocost = (y<<1)+z;
    g[cnt].next = head[x];
    head[x] = cnt;
    return;
}

inline int read() {
    int x = 0; 
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}
