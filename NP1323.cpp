

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

    #define file_IO
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



constant maxn = 30+1;
_ n, m, qr, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, d[maxn][maxn], p[maxn*maxn*maxn], ex, ey, sx, sy, tx, ty;
bool a[maxn][maxn];
struct edge {
    _ to, cost;
};
vector<edge> g[maxn*maxn*maxn];
bitset<maxn*maxn*maxn> v;

void spfa(_ x, _ y);
void bfs(_ sx, _ sy, _ ax, _ ay, _ d);
_ cd(_ x, _ y);
inline void AC() {
        
    n = read();
    m = read();
    qr = read();
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) a[i][j] = read();
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) if(a[i][j]) for(_ k = 0; k < 4; ++k) if(a[i+dx[k]][j+dy[k]]) bfs(i+dx[k], j+dy[k], i, j, k);
    for(; qr--; ) {
        ex = read();
        ey = read();
        sx = read();
        sy = read();
        tx = read();
        ty = read();
        if(sx == tx && sy == ty) {
            writeln("0");
            continue;
        }
        bfs(ex, ey, sx, sy, -1);
        spfa(sx, sy);
        _ s = 1E11, cr = cd(tx, ty);
        for(_ i = 0; i < 4; ++i) s = min(s, p[cr+i]);
        if(s == 1E11) writeln("-1");
        else writeln(s);
    }
    
    return;
}

_ cd(_ x, _ y) {
    return ((x-1)*m+(y-1))<<2;
}

void bfs(_ sx, _ sy, _ ax, _ ay, _ t) {
    memset(d, 4, sizeof d);
    d[ax][ay] = -1E11;
    d[sx][sy] = 0;
    queue<_p> q;
    q.push(make_pair(sx, sy));
    for(; !q.empty(); q.pop()) {
        _p t = q.front();
        for(_ i = 0; i < 4; ++i) {
            _ nx = t.first+dx[i], ny = t.second+dy[i];
            if(a[nx][ny] && d[nx][ny] > d[t.first][t.second]+1) {
                d[nx][ny] = d[t.first][t.second]+1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    if(!~t) return;
    _ cr = cd(ax, ay);
    for(_ i = 0; i < 4; ++i) if(i != t) {
        _ nx = ax+dx[i], ny = ay+dy[i];
        if(d[nx][ny] < 1E11) g[cr+t].push_back((edge){cr+i, d[nx][ny]});
    }
    g[cr+t].push_back((edge){cd(sx, sy)+((t+2)&3), 1});
    return;
}

void spfa(_ x, _ y) {
    memset(p, 4, sizeof p);
    queue<_> q;
    for(_ i = 0; i < 4; ++i) {
        _ nx = x+dx[i], ny = y+dy[i];
        if(d[nx][ny] < 1E11) {
            _ cr = cd(x, y)+i;
            p[cr] = d[nx][ny];
            q.push(cr);
        }
    }
    for(; !q.empty(); q.pop()) {
        _ t = q.front();
        v.reset(t);
        for(edge i : g[t]) if(p[i.to] > p[t]+i.cost) {
            p[i.to] = p[t]+i.cost;
            if(!v[i.to]) {
                v.set(i.to);
                q.push(i.to);
            }
        }
    }
    return;
}
