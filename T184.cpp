
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



constant maxn = 60+8;

_ n, cnt, s = -1, d[maxn], e[maxn], o[maxn];
struct act {
    _ x, id;
    bool operator < (const act &b) const {
        return x > b.x;
    }
} a[maxn], b[maxn];
struct pr {
    _ x, ida, idb;
} c[maxn];
bitset<maxn> t, r, v;

void hackerland(_ x);
inline void AC() {

    n = read();
    for(_ i = 1; i <= n; ++i) {
        e[i] = a[i].x = read();
        a[i].id = i;
    }
    for(_ i = 1; i <= n-1; ++i) {
        d[i] = b[i].x = read();
        b[i].id = i;
    }
    sort(a+1, a+1+n);
    sort(b+1, b+n);
    for(_ i = 1; i <= n>>1; ++i) {
        c[++cnt].x = a[i].x-a[n-i+1].x;
        c[cnt].ida = a[i].id;
        c[cnt].idb = a[n-i+1].id;
    }
    hackerland(1);
    writeln(s);
    for(_ i = 1; i <= n; ++i) writesc(o[i]);
    clr();
    
    return;
}

void hackerland(_ x) {
    if(x > n) {
        r = t;
        for(_ i = 1; i+3 <= n-1; i += 3) if(t[i] && !t[i+3]) t.set(i+2);
        ef(t[i+3] && !t[i]) t.set(i+1);
        ef(!t[i] && !t[i+3]) t.set(d[i+1] > d[i+2] ? i+1 : i+2);
        if(!((n-1)%3)) {
            if(t[n-3]) t.set(n-1);
            else t.set(d[n-2] > d[n-1] ? n-2 : n-1);
        } ef((n-1)%3 == 2 && !t[n-2]) t.set(n-1);
        _ p = 1, cr = 0;
        for(_ i = 1; i <= n-1; ++i) if(t[b[i].id]) {
            cr += c[p].x*b[i].x;
            ++p;
        }
        if(cr > s) {
            s = cr;
            memset(o, 0, sizeof o);
            p = 1;
            v.reset();
            for(_ i = 1; i <= n-1; ++i) if(t[b[i].id]) {
                v.set(c[p].ida);
                v.set(c[p].idb);
                o[b[i].id] = c[p].idb;
                o[b[i].id+1] = c[p].ida;
                ++p;
            }
            p = 1;
            for(_ i = 1; i <= n; ++i) if(!o[i]) {
                for(; v[p]; ++p);
                o[i] = p;
                ++p;
            }
        }
        t = r;
        return;
    }
    hackerland(x+3);
    t.set(x);
    hackerland(x+3);
    t.reset(x);
    return;
}
