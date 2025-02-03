
/*
 the c8kbf template
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

void AC();
int main(int argc, char * argv[]) {
    
    str fileN = "";
    
    //#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    AC();
    
    return 0;
}



// ----- End of Template -----



constant maxn = 2E5+8;
const double prec = 5E9;

struct _D {
    long double data;
};
bool operator == (const _D &a, const _D &b) {
    return round((long double)a.data*prec) == round((long double)b.data*prec);
}
long double operator ~ (const _D &a) {
    return round((long double)a.data*100)/100;
}
bool operator != (const _D &a, const _D &b) {
    return !(a == b);
}
bool operator < (const _D &a, const _D &b) {
    return round((long double)a.data*prec) < round((long double)b.data*prec);
}
bool operator > (const _D &a, const _D &b) {
    return round((long double)a.data*prec) > round((long double)b.data*prec);
}
_D operator * (const _D &a, const _D &b) {
    return (_D){a.data*b.data};
}
_D operator + (const _D &a, const _D &b) {
    return (_D){a.data+b.data};
}
_D operator - (const _D &a, const _D &b) {
    return (_D){a.data-b.data};
}
_D operator / (const _D &a, const _D &b) {
    return (_D){a.data/b.data};
}
_D abs(const _D &a) {
    return (_D){abs(a.data)};
}

struct line {
    bool ext, vrt, pt;
    _D x, y, ya, yb, xa, xb, m, b;
} a[maxn], p[maxn], t[maxn], kp;
const line null = (line){false, false, false, 0, 0, 0, 0, 0, 0, 0, 0};
struct pkg {
    _ a, b, c, d;
};
_ n;

pkg makePkg();
void operator |= (line &a, const line &b);
line operator | (const line &a, const line &b);
void operator *= (line &a, const pkg &b);
line operator ^ (line a, line b);
bool operator != (const line &a, const line &b);
bool operator == (const line &a, const line &b);
void AC() {
    
    n = read();
    if(n == 1) {
        writeln("uncertain");
        leave
    }
    for(_ i = 1; i <= n; ++i) a[i] *= makePkg();
    p[1] = a[1];
    for(_ i = 2; i <= n; ++i) p[i] = p[i-1]^a[i];
    t[n] = a[n];
    for(_ i = n-1; i >= 1; --i) t[i] = t[i+1]^a[i];
    kp |= p[n-1];
    kp |= t[2];
    for(_ i = 2; i <= n-1; ++i) kp |= p[i-1]^t[i+1];
    if(!kp.ext) writeln("impossible");
    else printf("%.2Lf %.2Lf\n", ~kp.x, ~kp.y);
    
    return;
}

bool operator == (const line &a, const line &b) {
    if(!a.ext) return !b.ext;
    if(a.vrt) {
        if(!b.vrt) return false;
        return a.x == b.x && a.ya == b.ya && a.yb == b.yb;
    }
    if(a.pt) return b.pt && a.x == b.x && a.y == b.y;
    if(!b.ext || b.vrt || b.pt) return false;
    return a.m == b.m && a.b == b.b && a.xa == b.xa && a.xb == b.xb;
}

bool operator != (const line &a, const line &b) {
    return !(a == b);
}

line operator ^ (line a, line b) {
    line rv = null;
    if(!a.ext || !b.ext) return null;
    if(a.pt && b.pt) {
        if(a != b) return null;
        return a;
    }
    if(a.vrt && b.vrt) {
        if(a.x != b.x || max(a.ya, b.ya) > min(a.yb, b.yb)) return null;
        rv.ext = true;
        if(max(a.ya, b.ya) == min(a.yb, b.yb)) {
            rv.pt = true;
            rv.x = a.x;
            rv.y = max(a.ya, b.ya);
            return rv;
        }
        rv.vrt = true;
        rv.x = a.x;
        rv.ya = max(a.ya, b.ya);
        rv.yb = min(a.yb, b.yb);
        return rv;
    }
    if((a.pt && b.vrt) || (a.vrt && b.pt)) {
        if(b.pt) swap(a, b);
        if(a.x != b.x || a.y < b.ya || a.y > b.yb) return null;
        return a;
    }
    if(a.pt || b.pt) {
        if(b.pt) swap(a, b);
        if(a.x < b.xa || a.x > b.xb || a.x*b.m+b.b != a.y) return null;
        return a;
    }
    if(a.vrt || b.vrt) {
        if(b.vrt) swap(a, b);
        rv.ext = true;
        rv.pt = true;
        rv.x = a.x;
        rv.y = b.m*a.x+b.b;
        if(rv.x < b.xa || rv.x > b.xb || rv.y < a.ya || rv.y > a.yb) return null;
        return rv;
    }
    if(a.m == b.m) {
        if(a.b != b.b || max(a.xa, b.xa) > min(a.xb, b.xb)) return null;
        rv.ext = true;
        if(max(a.xa, b.xa) == min(a.xb, b.xb)) {
            rv.pt = true;
            rv.x = max(a.xa, b.xa);
            rv.y = a.m*rv.x+a.b;
            return rv;
        }
        rv.m = a.m;
        rv.b = b.b;
        rv.xa = max(a.xa, b.xa);
        rv.xb = min(a.xb, b.xb);
        return rv;
    }
    rv.ext = true;
    rv.pt = true;
    if(abs(a.m-b.m) < (_D){0.000001L}) return null;
    rv.x = (b.b-a.b)/(a.m-b.m);
    rv.y = a.m*rv.x+a.b;
    if(rv.x < a.xa || rv.x < b.xa || rv.x > a.xb || rv.x > b.xb) return null;
    return rv;
}

void operator *= (line &a, const pkg &b) {
    a.ext = true;
    if(b.a == b.c && b.b == b.d) {
        a.pt = true;
        a.x.data = b.a;
        a.y.data = b.b;
        return;
    }
    if(b.a == b.c) {
        a.vrt = true;
        a.x.data = b.a;
        a.ya.data = min(b.b, b.d);
        a.yb.data = max(b.b, b.d);
        return;
    }
    a.xa.data = min(b.a, b.c);
    a.xb.data = max(b.a, b.c);
    a.m.data = 1.L*(b.b-b.d)/(b.a-b.c);
    a.b.data = b.b-a.m.data*b.a;
    return;
}

line operator | (const line &a, const line &b) {
    if(!a.ext && !b.ext) return null;
    if(!b.ext) return a;
    if(!b.pt) {
        writeln("uncertain");
        leave
    }
    if(!a.ext) return b;
    if(a != b) {
        writeln("uncertain");
        leave
    }
    return a;
}

void operator |= (line &a, const line &b) {
    a = a | b;
    return;
}

pkg makePkg() {
    _ a, b, c, d;
    a = read();
    b = read();
    c = read();
    d = read();
    return (pkg){a, b, c, d};
}

