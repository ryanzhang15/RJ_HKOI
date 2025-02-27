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

#define v(x) vector<x >
#define v2(x) vector<vector<x > >
#define v3(x) vector<vector<vector<x > > >

#define ss(x) v(_)(x+8, 0)
#define ssz(type, x) v(type)(x+8, 0)
#define s2(x, y) v2(_)(x+8, v(_)(y+8, 0))
#define s2z(type, x, y) v2(type)(x+8, v(type)(y+8, 0))
#define s3(x, y, z) v3(_)(x+8, v2(_)(y+8, v(_)(z+8, 0)))
#define s3z(type, x, y, z) v3(type)(x+8, v2(type)(y+8, v(type)(z+8, 0)))

#define i(x) x::iterator

#define pr(x, y) pair< x, y >
#define mp(x, y) make_pair(x, y)

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef double _D;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

const char untl = '\n';

//fastIO cos why not
inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline bool read(_ &x) {
    x = 0;
    _ f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    if(ch == '\r') ch = getchar();
    return ch != untl && ch != EOF;
}

inline char getDg() {
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
    return ch;
}

inline char getLw() {
    char ch = getchar();
    for(; !(ch >= 'a' && ch <= 'z'); ) ch = getchar();
    return ch;
}

inline char getUp() {
    char ch = getchar();
    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar();
    return ch;
}

inline char getLtr() {
    char ch = getchar();
    for(; !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ) ch = getchar();
    return ch;
}

inline char gc() {
    char ch = getchar();
    for(; ch == '\n' || ch == '\r' || ch == ' '; ) ch = getchar();
    return ch;
}

inline void write(_ x) {
    if(x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if(x > 9) write(x/10);
    putchar((x%10)^48);
    return;
}

inline void write(char const * a) {
    for(_ i = 0; a[i]; ++i) putchar(a[i]);
    return;
}

inline void clr() {
    putchar(10);
    return;
}

inline void spc() {
    putchar(32);
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

    //#define file_IO
#ifdef file_IO
    str fileN = "puzzle";
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    //#define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
    for(; tc--; ) AC(); // good luck!
#else
    AC(); // good luck!
#endif


    return 0;
}



// ----- End of Template -----



constant maxn = 2E5+8;
constant maxd = 2E3+8;

_ n, hf, ht, m, x, y, z, cnt, hv[maxn], f[maxn], d[maxd][maxd], ds[maxd][maxd], b[maxd], ts[maxn];
struct edge {
    _ to, cost;
} c;
v_ g[maxn];
v(pr(_, edge)) e;
queue<_> q;
bitset<maxd> v;

void dfs(_ x);
_ find(_ x);
inline void AC() {
    
    memset(d, 4, sizeof d);
    memset(b, 4, sizeof b);
    
    n = read();
    hf = read();
    ht = read();
    m = read();
    for(_ i = 1; i <= n; ++i) f[i] = i;
    for(; hf--; ) {
        x = read();
        y = read();
        f[find(x)] = find(y);
    }
    for(; ht--; ) {
        x = find(read());
        c.to = find(read());
        c.cost = read();
        g[x].push_back(c.to);
        g[c.to].push_back(x);
        e.push_back(mp(x, c));
    }
    dfs(find(1));
    for(_ i = 1; i <= cnt; ++i) d[i][i] = 0;
    for(pr(_, edge) &i : e) {
        i.first = hv[i.first];
        i.second.to = hv[i.second.to];
    }
    for(pr(_, edge) i : e) d[i.first][i.second.to] = d[i.second.to][i.first] = min(d[i.first][i.second.to], i.second.cost);
    for(_ k = 1; k <= cnt; ++k) for(_ i = 1; i <= cnt; ++i) for(_ j = 1; j <= cnt; ++j) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    memcpy(ds, d, sizeof d);
    for(; m--; ) {
        x = hv[find(read())];
        y = hv[find(read())];
        if(!x || !y) {
            read();
            continue;
        }
        z = d[x][y]-read();
        ds[x][y] = min(ds[x][y], z);
    }
    q.push(1);
    b[1] = 0;
    for(; !q.empty(); q.pop()) {
        _ t = q.front();
        v.reset(t);
        for(_ i = 1; i <= cnt; ++i) if(d[t][i] < 1E15 && b[i] > b[t]+ds[t][i]) {
            b[i] = b[t]+ds[t][i];
            if(!v[i]) {
                v.set(i);
                if(++ts[i] > 2000) {
                    writeln("YES");
                    leave
                }
                q.push(i);
            }
        }
    }
    writeln("NO");
    _ s = 0;
    for(_ i = 1; i <= cnt; ++i) s = max(s, -b[i]);
    writeln(s);
    
    return;
}

_ find(_ x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void dfs(_ x) {
    hv[x] = ++cnt;
    for(_ i : g[x]) if(!hv[i]) dfs(i);
    return;
}
