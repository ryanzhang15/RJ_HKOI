
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

    str fileN = "park";

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



#define gr {l = md+1; continue;}
#define gl {r = md-1; continue;}

_ w, d, x[5], y[5], z[5], l, r, md;
struct hs {
    _ v, p;
    void init() {
        v = 0;
        p = 1;
        return;
    }
    _ value(_ x) {
        return v+x*p;
    }
    void flip() {
        p *= -1;
        return;
    }
    void setv(_ x) {
        v = x;
        return;
    }
} a[10];

inline void AC() {
    
    for(_ i = 1; i <= 6; ++i) a[i].init();
    w = read();
    d = read();
    for(_ i = 1; i <= 3; ++i) x[i] = read();
    for(_ i = 1; i <= 3; ++i) y[i] = read();
    for(_ i = 1; i <= 3; ++i) z[i] = read();
    if(x[2] + y[2] + z[2] != x[3] + y[3] + z[3]) {
        writeln("Impossible");
        leave
    }
    a[2].flip();
    a[2].setv(x[2]);
    a[3].setv(z[3]-x[2]);
    a[4].flip();
    a[4].setv(y[2]-z[3]+x[2]);
    a[5].setv(x[3]-y[2]+z[3]-x[2]);
    a[6].flip();
    a[6].setv(z[2]-x[3]+y[2]-z[3]+x[2]);
    for(_ g1 = 1; g1 <= 3; ++g1) for(_ g2 = 1; g2 <= 3; ++g2) for(_ g3 = 1; g3 <= 3; ++g3) {
        {
            _ a = 0, b = 0, c = 0;
            if(g1 == 1) a += w;
            ef(g1 == 2) {
                a += d;
                b += d;
            } else b += w;
            if(g2 == 1) a += w;
            ef(g2 == 2) {
                a += d;
                c += d;
            } else c += w;
            if(g3 == 1) b += w;
            ef(g3 == 2) {
                b += d;
                c += d;
            } else c += w;
            if(a != x[1] || b != y[1] || c != z[1]) continue;
        }
        l = 0;
        r = x[2];
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(a[1].value(md) < 0) gr;
            if(a[1].value(md) > x[2]) gl;
            if(a[2].value(md) < 0) gl;
            if(a[3].value(md) < 0) gr;
            if(a[3].value(md) > y[2]) gl;
            if(a[4].value(md) < 0) gl;
            if(a[4].value(md) > y[2]) gr;
            if(a[5].value(md) < 0) gr;
            if(a[5].value(md) > z[2]) gl;
            if(a[6].value(md) < 0) gl;
            if(a[6].value(md) > z[2]) gr;
            if(g1 == 1) {
                if(a[1].value(md) <= a[4].value(md)) gr;
            } ef(g1 == 2) {
                if(a[1].value(md) < a[4].value(md)) gr;
                if(a[1].value(md) > a[4].value(md)) gl;
            } else {
                if(a[1].value(md) >= a[4].value(md)) gl;
            }
            if(g2 == 1) {
                if(a[2].value(md) <= a[5].value(md)) gl;
            } ef(g2 == 2) {
                if(a[2].value(md) < a[5].value(md)) gl;
                if(a[2].value(md) > a[5].value(md)) gr;
            } else {
                if(a[2].value(md) >= a[5].value(md)) gr;
            }
            if(g3 == 1) {
                if(a[3].value(md) <= a[6].value(md)) gr;
            } ef(g3 == 2) {
                if(a[3].value(md) < a[6].value(md)) gr;
                if(a[3].value(md) > a[6].value(md)) gl;
            } else {
                if(a[3].value(md) >= a[6].value(md)) gl;
            }
            writesc("Alpha");
            writesc(a[1].value(md));
            writesc("-");
            writesc(a[4].value(md));
            writeln("Beta");
            writesc("Alpha");
            writesc(a[2].value(md));
            writesc("-");
            writesc(a[5].value(md));
            writeln("Gamma");
            writesc("Beta");
            writesc(a[3].value(md));
            writesc("-");
            writesc(a[6].value(md));
            writeln("Gamma");
            leave
        }
    }
    writeln("Impossible");
    
    return;
}

