
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
typedef long long _;
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

    #define file_IO
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



constant maxn = 50+8;

_ n, m, a[maxn];
v_ g[maxn];
v(_p) o;

void sp(_ x, _ y);
_ sz(_ x);
_ cnt(_ x, _ y);
_ tp(_ x);
void mv(_ x, _ y);
inline void AC() {

    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) for(_ j = m; j--; ) g[i].push_back(read());
    for(_ i = 1; i <= n+1; ++i) a[i] = i;
    for(_ i = n; i >= 3; --i) {
        {
            _ t = cnt(1, i);
            for(_ k = t; k--; ) mv(i, i+1);
            for(; ~tp(1); ) mv(1, tp(1) == i ? i : i+1);
            for(_ k = m-t; k--; ) mv(i+1, 1);
            for(; ~tp(2); ) mv(2, tp(2) != i && sz(1) < m ? 1 : i+1);
        }
        sp(2, i+1);
        sp(1, i);
        for(_ j = 1; j <= i-1; ++j) {
            _ t = cnt(j, i);
            for(_ k = t; k--; ) mv(i, i+1);
            for(; ~tp(j); ) mv(j, tp(j) == i ? i : i+1);
            sp(i, j);
            sp(i+1, i);
        }
        for(_ j = 1; j <= i-1; ++j) for(; tp(j) == i; ) mv(j, i+1);
        _ p = 1;
        for(; ~tp(i); ) {
            for(; sz(p) == m; ) ++p;
            mv(i, p);
        }
    }
    {
        _ t = cnt(1, 1);
        for(_ i = t; i--; ) mv(2, 3);
        for(; ~tp(1); ) mv(1, tp(1) == 1 ? 2 : 3);
        for(_ i = t; i--; ) mv(2, 1);
        for(_ i = m-t; i--; ) mv(3, 1);
        for(; ~tp(3); ) mv(3, 2);
        for(; tp(1) == 2; ) mv(1, 3);
        for(; ~tp(2); ) mv(2, tp(2) == 1 ? 1 : 3);
    }
    writeln((_)o.size());
    for(_p i : o) writeln(i);

    return;
}

void mv(_ x, _ y) {
    o.push_back(mp(a[x], a[y]));
    g[a[y]].push_back(g[a[x]].back());
    g[a[x]].pop_back();
    return;
}

_ tp(_ x) {
    if(g[a[x]].empty()) return -1;
    return g[a[x]].back();
}

_ cnt(_ x, _ y) {
    return count(g[a[x]].begin(), g[a[x]].end(), y);
}

_ sz(_ x) {
    return g[a[x]].size();
}

void sp(_ x, _ y) {
    swap(a[x], a[y]);
}


#else

#ifndef EVAL



#endif

#endif

