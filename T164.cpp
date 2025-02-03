
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

    AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxn = 200005;

_ n, m, d[maxn], p[maxn], x, y, f[maxn];
_D a[maxn], b[maxn], o[maxn], vl;
vector<_> g[maxn];

void II(_ x);
void feast(_ x);
void robos(_ x, _ fa);
inline void AC() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) d[i] = read();
    for(_ i = n; --i; ) {
        x = read();
        y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(_ i = 1; i <= n; ++i) {
        p[i] += d[i];
        for(_ j : g[i]) p[i] += d[j];
    }
    robos(1, 0);
    for(_ i = 1; i <= m; ++i) {
        x = read();
        scanf("%Lf", &vl);
        a[x] += vl*d[f[x]]/p[x];
        b[x] += vl*(1.L-(1.L*d[f[x]]/p[x]));
    }
    feast(1);
    II(1);
    for(_ i = 1; i <= n; ++i) printf("%.10Lf\n", o[i]);

    return;
}

void robos(_ x, _ fa) {
    f[x] = fa;
    for(_ i : g[x]) if(i != fa) robos(i, x);
    return;
}

void feast(_ x) {
    for(_ i : g[x]) if(i != f[x]) {
        feast(i);
        b[x] += a[i]*(p[x]-d[f[x]])/(p[x]-d[i]);
        b[i] -= a[i]*d[i]/(p[x]-d[i]);
        a[x] += a[i]*d[f[x]]/(p[x]-d[i]);
    }
    return;
}

void II(_ x) {
    o[x] += b[x]*d[x]/(p[x]-d[f[x]]);
    for(_ i : g[x]) if(i != f[x]) {
        b[i] += b[x]*d[i]/(p[x]-d[f[x]]);
        II(i);
    }
    return;
}

