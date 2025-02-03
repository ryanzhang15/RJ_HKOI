
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

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef long double _D;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

char untl = '\n';

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
    str fileN = "call";
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



constant maxn = 1E5+8;
constant mod = 998244353;

_ n, m, a[maxn], t[maxn], ml[maxn], b[maxn], p[maxn], c[maxn], in[maxn];
v_ g[maxn], h[maxn];
queue<_> q;

inline void AC() {
    
    n = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    m = read();
    ml[0] = 1;
    for(_ i = 1; i <= m; ++i) {
        t[i] = read();
        ml[i] = 1;
        if(t[i] == 1) {
            p[i] = read();
            b[i] = read();
        } ef(t[i] == 2) ml[i] = read();
        else for(_ j = read(); j--; ) {
            _ x = read();
            g[i].push_back(x);
            h[x].push_back(i);
        }
    }
    c[0] = 1;
    for(_ i = read(); i--; ) {
        _ x = read();
        g[0].push_back(x);
        h[x].push_back(0);
    }
    for(_ i = 0; i <= m; ++i) reverse(g[i].begin(), g[i].end());
    for(_ i = 0; i <= m; ++i) if(!(in[i] = g[i].size())) q.push(i);
    for(; !q.empty(); q.pop()) {
        _ t = q.front();
        for(_ i : h[t]) {
            ml[i] = ml[i]*ml[t]%mod;
            if(!--in[i]) q.push(i);
        }
    }
    for(_ i = 0; i <= m; ++i) if(!(in[i] = h[i].size())) q.push(i);
    for(; !q.empty(); q.pop()) {
        _ t = q.front(), cr = 1;
        for(_ i : g[t]) {
            c[i] = (c[i]+c[t]*cr)%mod;
            cr = cr*ml[i]%mod;
            if(!--in[i]) q.push(i);
        }
    }
    for(_ i = 1; i <= n; ++i) a[i] = a[i]*ml[0]%mod;
    for(_ i = 1; i <= m; ++i) if(t[i] == 1) a[p[i]] = (a[p[i]]+c[i]*b[i])%mod;
    for(_ i = 1; i <= n; ++i) writesc(a[i]);
    clr();
    
    return;
}

