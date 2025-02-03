
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
//
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
typedef __int128 _;
typedef int _0;
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

inline void read(char * a, v(char) tl = {' ', '\n', '\r', '\t', '\0', EOF}, v(char) skp = {' ', '\n', '\r', '\t'}) {
    char ch = getchar();
    for(; count(skp.begin(), skp.end(), ch); ) ch = getchar();
    for(; !count(tl.begin(), tl.end(), ch); ch = getchar()) {
        *a = ch;
        ++a;
    }
    *a = '\0';
    return;
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

inline void write(char ch) {
    putchar(ch);
    return;
}

inline void write(_p a, char const * b = " ") {
    write(a.first);
    write(b);
    write(a.second);
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

inline void writeln(char a) { //pascal vibes
    write(a);
    clr();
    return;
}

inline void writeln(_p a, char const * b = " ") {
    write(a, b);
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

inline void writesc(char a) {
    write(a);
    spc();
    return;
}

inline void writesc(_p a, char const * b = " ") {
    write(a);
    spc();
    return;
}

#define usemode1
#ifdef usemode1

inline void AC();
int main(int argc, char * argv[]) {

//    #define file_IO
#ifdef file_IO
    str fileN = "ball";
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

//    #define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
    for(; tc--; ) AC(); // good luck!
#else
    AC(); // good luck!
#endif

    return 0;
}

// ----- End of Template -----



constant maxn = 40+8;

_ x, y, z, xa, ya, xb, yb, lb, rb, ub, db, d[maxn], cnt, nw = -8E18;
struct node {
    _ x, y, tx, ty;
    bool c;
} a[maxn];
struct edge {
    _ to, cost;
};
v(edge) g[maxn];
queue<_> q;
bitset<maxn> v;

_ abs(_ x) {return x < 0 ? -x : x;}
void an(_ x, _ y, _ tx, _ ty, bool c);
inline void AC() {
    
    memset(d, 4, sizeof d);
    
    x = read();
    y = read();
    z = read();
    xa = read();
    ya = read();
    xb = read();
    yb = read();
    if(xa > xb) {
        swap(xa, xb);
        swap(ya, yb);
    }
    v_ ix = {xa, xa/x*x, xa/x*x+x, xb/x*x, xb/x*x+x, xb}, iy = {ya, ya/y*y, ya/y*y+y, yb/y*y, yb/y*y+y, yb};
    for(_ i : ix) for(_ j : iy) an(i, j, !(i%x) ? i : -1, !(j%y) ? j : -1, !(i%x) && !(j%y));
    for(_ i = 1; i <= cnt; ++i) for(_ j = i+1; j <= cnt; ++j) {
        _ c = -1;
        if((a[i].c && a[j].c) || a[i].tx == a[j].tx || a[i].ty == a[j].ty) c = abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
        else c = z*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
        g[i].push_back((edge){j, c});
        g[j].push_back((edge){i, c});
    }
    q.push(1);
    v.set(1);
    d[1] = 0;
    for(; !q.empty(); ) {
        _ t = q.front();
        q.pop();
        v.reset(t);
        for(edge i : g[t]) if(d[i.to] > d[t]+i.cost) {
            d[i.to] = d[t]+i.cost;
            if(!v[i.to]) {
                q.push(i.to);
                v.set(i.to);
            }
        }
    }
    writeln(d[cnt]);
    
    return;
}

void an(_ x, _ y, _ tx, _ ty, bool c) {
    a[++cnt] = (node){x, y, ~tx ? tx : --nw, ~ty ? ty : --nw, c};
    return;
}

#else

#ifndef EVAL



#endif

#endif

