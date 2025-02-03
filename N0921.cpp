
/*
 template by c8kbf
 */

// macOS doesn't have <bits/stdc++.h> (shame)
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
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#include <random>

//dont worry bout me, i'm not high
#define ef else if
#define leave exit(0);

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef long double _D;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

char untl = '\n';

//fastIO cos why not
inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar_unlocked()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline bool read(_ &x) {
    x = 0;
    _ f = 1;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar_unlocked()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    if(ch == '\r') ch = getchar_unlocked();
    return ch != untl && ch != EOF;
}

inline char getDg() {
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    return ch;
}

inline char getLw() {
    char ch = getchar_unlocked();
    for(; !(ch >= 'a' && ch <= 'z'); ) ch = getchar_unlocked();
    return ch;
}

inline char getUp() {
    char ch = getchar_unlocked();
    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar_unlocked();
    return ch;
}

inline char getLtr() {
    char ch = getchar_unlocked();
    for(; !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ) ch = getchar_unlocked();
    return ch;
}

inline char gc() {
    char ch = getchar_unlocked();
    for(; ch == '\n' || ch == '\r' || ch == ' '; ) ch = getchar_unlocked();
    return ch;
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

inline void write(char const * a) {
    for(_ i = 0; a[i]; ++i) putchar_unlocked(a[i]);
    return;
}

inline void clr() {
    putchar_unlocked(10);
    return;
}

inline void spc() {
    putchar_unlocked(32);
    return;
}

inline void writeln(_ x) { //pascal vibes
    write(x);
    clr();
    return;
}

inline void writeln(char const * a) { //pascal vibes
    write(a);
    clr();
    return;
}

inline void writesc(_ x) {
    write(x);
    spc();
    return;
}

inline void writesc(char const * a) {
    write(a);
    spc();
    return;
}

inline void AC();
int main(int argc, char * argv[]) {

    str fileN = "";

    //#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    //#define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
#else
    _ tc = 1;
#endif
    
    for(; tc--; ) AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxn = 5E3+8;
constant maxe = 5E5+8;

_ n, m, s, t, head[maxn], cnt = 1, x, y, z, o, d[maxn], cur[maxn], a[maxn], in[maxn];
struct edge {
    _ to, cost, next;
} g[maxe];
queue<_> q;
vector<_> h[maxn];
bitset<maxn> v;

_ dfs(_ x, _ a);
bool bfs();
void addEdge(_ x, _ y, _ z);
_ conv(_ x, _ y);
inline void AC() {
    
    n = read();
    m = read();
    s = 1;
    t = 2;
    for(_ i = 0; i < n; ++i) for(_ j = 0; j < m; ++j) {
        a[conv(i, j)] = read();
        z = read();
        for(; z--; ) {
            x = read();
            y = read();
            h[conv(i, j)].push_back(conv(x, y));
            ++in[conv(x, y)];
        }
        if(j <= m-2) {
            h[conv(i, j+1)].push_back(conv(i, j));
            ++in[conv(i, j)];
        }
    }
    for(_ i = 0; i < n; ++i) for(_ j = 0; j < m; ++j) if(!in[conv(i, j)]) q.push(conv(i, j));
    for(; !q.empty(); q.pop()) {
        _ t = q.front();
        v.set(t);
        for(_ i : h[t]) if(!--in[i]) q.push(i);
    }
    for(_ i = 0; i < n; ++i) for(_ j = 0; j < m; ++j) if(v[conv(i, j)]) {
        if(a[conv(i, j)] > 0) {
            addEdge(s, conv(i, j), a[conv(i, j)]);
            addEdge(conv(i, j), s, 0);
            o += a[conv(i, j)];
        } else {
            addEdge(conv(i, j), t, -a[conv(i, j)]);
            addEdge(t, conv(i, j), 0);
        }
        for(_ k : h[conv(i, j)]) if(v[k]) {
            addEdge(k, conv(i, j), 1E11);
            addEdge(conv(i, j), k, 0);
        }
    }
    for(; bfs(); ) o -= dfs(s, 1E18);
    writeln(max(0LL, o));
    
    return;
}

_ conv(_ x, _ y) {
    return x*m+y+5;
}

void addEdge(_ x, _ y, _ z) {
    g[++cnt].next = head[x];
    g[cnt].to = y;
    g[cnt].cost = z;
    head[x] = cnt;
    return;
}

bool bfs() {
    memset(d, 0, sizeof d);
    q.push(s);
    d[s] = 1;
    for(; !q.empty(); q.pop()) {
        _ u = q.front();
        cur[u] = head[u];
        for(_ i = head[u]; i; i = g[i].next) {
            _ v = g[i].to;
            if(g[i].cost && !d[v]) {
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
    return !!d[t];
}

_ dfs(_ x, _ a) {
    if(x == t) return a;
    _ rv = 0;
    for(_ &i = cur[x]; i; i = g[i].next) {
        _ v = g[i].to;
        if(g[i].cost && d[v] == d[x]+1) {
            _ cr = dfs(v, min(g[i].cost, a));
            g[i].cost -= cr;
            g[i^1].cost += cr;
            a -= cr;
            rv += cr;
            if(!a) break;
        }
    }
    if(!rv) d[x] = 0;
    return rv;
}
