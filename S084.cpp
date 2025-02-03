
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



const _D smol = 1E-5;

struct coords {
    _ x, y;
    bool operator < (const coords &b) const {
        if(x != b.x) return x < b.x;
        return y < b.y;
    }
    bool operator == (const coords &b) const {
        return x == b.x && y == b.y;
    }
} x, y;
set<coords> a, b, c;
_ gcd(_ a, _ b);
struct line {
    _ t, b;
    _D c, xx;
    _D evalX(_ x) {
        return 1.L*t/b*x+c;
    }
    _D evalY(_ y) {
        if(!b) return xx;
        return 1.L*b/t*(y-c);
    }
    void reduce() {
        if(!b) {
            t = 1;
            return;
        }
        bool ng = false;
        if(t & (1LL<<63)) ng = !ng;
        if(b & (1LL<<63)) ng = !ng;
        t = abs(t);
        b = abs(b);
        _ g = gcd(t, b);
        t /= g;
        b /= g;
        if(ng) t *= -1;
        return;
    }
} l;
_ n;

bool gud(coords t);
inline void AC() {
    
    n = read();
    x.x = read();
    x.y = read();
    y.x = read();
    y.y = read();
    l.b = x.y-y.y;
    l.t = y.x-x.x;
    if(x.y == y.y) l.xx = (1.L*x.x+y.x)/2;
    else l.c = (1.L*x.y+y.y)/2.L-1.L*l.t/l.b*(1.L*x.x+y.x)/2.L;
    l.reduce();
    if(abs(l.t) < abs(l.b)) {
        _ st = 1;
        for(; st <= n; ++st) {
            _D c = l.evalX(st);
            if((l.t < 0 ? ceil(c) <= n : floor(c) > 0)) break;
        }
        --st;
        st = max(st, 1LL);
        for(_ i = st; i <= n; ++i) {
            _D c = l.evalX(i);
            bool dun = false;
            if((l.t < 0 ? floor(c) <= 0 : ceil(c > n))) dun = true;
            if(abs(c-round(c)) < smol) {
                coords d = (coords){i, (_)round(c)};
                if(gud(d)) ::c.insert(d);
            }
            coords tp = (coords){i, (_)(abs(c-round(c)) < smol ? round(c)-1 : floor(c))}, bt = (coords){i, (_)(abs(c-round(c)) < smol ? round(c)+1 : ceil(c))};
            if(x.y < y.y) {
                if(gud(tp)) a.insert(tp);
                if(gud(bt)) b.insert(bt);
            } else {
                if(gud(tp)) b.insert(tp);
                if(gud(bt)) a.insert(bt);
            }
            if(dun) break;
        }
    } else {
        _ st = 1;
        for(; st <= n; ++st) {
            _D c = l.evalY(st);
            if((l.t < 0 ? ceil(c) <= n : floor(c) > 0)) break;
        }
        --st;
        st = max(st, 1LL);
        for(_ i = st; i <= n; ++i) {
            _D c = l.evalY(i);
            bool dun = false;
            if((l.t < 0 ? floor(c) <= 0 : ceil(c > n))) dun = true;
            if(abs(c-round(c)) < smol) {
                coords d = (coords){(_)round(c), i};
                if(gud(d)) ::c.insert(d);
            }
            coords tp = (coords){(_)(abs(c-round(c)) < smol ? round(c)-1 : floor(c)), i}, bt = (coords){(_)(abs(c-round(c)) < smol ? round(c)+1 : ceil(c)), i};
            if(x.x < y.x) {
                if(gud(tp)) a.insert(tp);
                if(gud(bt)) b.insert(bt);
            } else {
                if(gud(tp)) b.insert(tp);
                if(gud(bt)) a.insert(bt);
            }
            if(dun) break;
        }
    }
    writeln(a.size());
    for(coords i : a) {
        writesc(i.x);
        writeln(i.y);
    }
    writeln(b.size());
    for(coords i : b) {
        writesc(i.x);
        writeln(i.y);
    }
    writeln(c.size());
    for(coords i : c) {
        writesc(i.x);
        writeln(i.y);
    }
    
    return;
}

_ gcd(_ a, _ b) {
    return !b ? a : gcd(b, a%b);
}

bool gud(coords t) {
    return !(t == x) && !(t == y) && t.x >= 1 && t.x <= n && t.y >= 1 && t.y <= n;
}
