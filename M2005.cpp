
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
        
    //#define file_IO
#ifdef file_IO
    str fileN = "";
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



constant big = 2E4;
constant bad = -11333412583;
constant maxn = (big<<1)+8;

struct segSet {
    vector<_p> dt;
    inline void insert(_ l, _ r) {
        dt.push_back(make_pair(l, r));
    }
    inline _ count() {
        _ rv = 0;
        sort(dt.begin(), dt.end());
        for(_ i = 0; i < dt.size(); ++i) {
            _ l = dt[i].first, r = dt[i].second;
            for(; i+1 < dt.size() && dt[i+1].first <= r; ++i) r = max(r, dt[i+1].second);
            rv += r-l+1;
        }
        return rv;
    }
} a[maxn];
_ n, d;
struct coords {
    _ x, y;
} b[13];

inline void addSeg(coords x, coords y);
inline _D dst(coords x, coords y, coords h);
inline _D dist(coords x, coords y);
inline void AC() {
    
    n = read()+1;
    d = read();
    for(_ i = 1; i <= n; ++i) {
        b[i].x = read();
        b[i].y = read();
    }
    for(_ i = 1; i <= n-1; ++i) addSeg(b[i], b[i+1]);
    _ s = 0;
    for(_ i = -big; i <= big; ++i) s += a[i+big].count();
    writeln(s);
    
    return;
}

inline _D dist(coords x, coords y) {
    return sqrt(1.L*(x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}

inline _D dst(coords x, coords y, coords h) {
    if(x.x == y.x) {
        _ ty = x.y, by = y.y;
        if(ty < by) swap(ty, by);
        if(h.y >= by && h.y <= ty) return abs(x.x-h.x);
        return min(dist(x, h), dist(y, h));
    }
    if(x.y == y.y) {
        _ tx = x.x, bx = y.x;
        if(tx < bx) swap(tx, bx);
        if(h.x >= bx && h.x <= tx) return abs(x.y-h.y);
        return min(dist(x, h), dist(y, h));
    }
    _D m1, b1, m2, b2, nx;
    m1 = 1.L*(x.y-y.y)/(x.x-y.x);
    b1 = x.y-m1*x.x;
    m2 = -1.L/m1;
    b2 = h.y-m2*h.x;
    _ tx = x.x, bx = y.x;
    if(tx < bx) swap(tx, bx);
    nx = (b2-b1)/(m1-m2);
    nx = nx;
    if(nx >= bx && nx <= tx) {
        _D ny = m1*nx+b1;
        return sqrt(1.L*(nx-h.x)*(nx-h.x)+(ny-h.y)*(ny-h.y));
    }
    return min(dist(x, h), dist(y, h));
}

inline void addSeg(coords x, coords y) {
    _ lb, rb, l, r, md;
    for(_ i = -big; i <= big; ++i) {
        lb = rb = bad;
        l = -big;
        r = big;
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(dst(x, y, (coords){md, i}) <= d) {
                lb = md;
                r = md-1;
            } else {
                if(dst(x, y, (coords){md-1, i}) <= dst(x, y, (coords){md, i})) r = md-1;
                else l = md+1;
            }
        }
        l = -big;
        r = big;
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(dst(x, y, (coords){md, i}) <= d) {
                rb = md;
                l = md+1;
            } else {
                if(dst(x, y, (coords){md-1, i}) <= dst(x, y, (coords){md, i})) r = md-1;
                else l = md+1;
            }
        }
        if(lb == bad || rb == bad) continue;
        a[i+big].insert(lb, rb);
    }
    return;
}






