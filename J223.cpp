
/*
 template by c8kbf
 */

// macOS doesn't have <bits/++.h> (shame)
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

#define q(x) queue<x >
#define dq(x) deque<x >
#define s(x) set<x >
#define st(x) stack<x >
#define ms(x) multiset<x >
#define m(x, y) map<x , y >
#define b(x) bitset<x >
#define l(x) list<x >

#define ss(x) v(_)(x+8, 0)
#define ssz(type, x) v(type)(x+8, 0)
#define s2(x, y) v2(_)(x+8, v(_)(y+8, 0))
#define s2z(type, x, y) v2(type)(x+8, v(type)(y+8, 0))
#define s3(x, y, z) v3(_)(x+8, v2(_)(y+8, v(_)(z+8, 0)))
#define s3z(type, x, y, z) v3(type)(x+8, v2(type)(y+8, v(type)(z+8, 0)))
#define rd(a, sz) for(_ i = 1; i <= sz; ++i) a[i] = read();
#define wr(a, sz) for(_ i = 1; i <= sz; ++i) writesc(a[i]); clr();

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
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

//fastIO cos why not
inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline bool read(_ &x, v(char) tl = {'\n', EOF}) {
    x = 0;
    _ f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    if(ch == '\r') ch = getchar();
    return !count(tl.begin(), tl.end(), ch);
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

inline void read(str & a, v(char) tl = {' ', '\n', '\r', '\t', '\0', EOF}, v(char) skp = {' ', '\n', '\r', '\t'}) {
    a.clear();
    char ch = getchar();
    for(; count(skp.begin(), skp.end(), ch); ) ch = getchar();
    for(; !count(tl.begin(), tl.end(), ch); ch = getchar()) a += ch;
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

inline void write(_0 x) {
    write((_)x);
    return;
}

inline void write(char const * a) {
    for(_ i = 0; a[i]; ++i) putchar(a[i]);
    return;
}

inline void write(const str a) {
    write(a.c_str());
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

inline void flsh(bool nl = true) {
    if(nl) clr();
    fflush(stdout);
    return;
}

inline void spc() {
    putchar(32);
    return;
}

template <class tp>
inline void writeln(tp x) {
    write(x);
    clr();
}

inline void writeln(_p a, char const * b = " ") {
    write(a, b);
    clr();
    return;
}

template <class tp>
inline void writesc(tp x) {
    write(x);
    spc();
}

inline void writesc(_p a, char const * b = " ") {
    write(a);
    spc();
    return;
}

template <class tp>
inline void writeflsh(tp x, bool nl = true) {
    write(x);
    flsh(nl);
}

inline void writeflsh(_p a, char const * b = " ", bool nl = true) {
    write(a, b);
    flsh(nl);
    return;
}

inline void yes(_ a = 1) {
    write(a & 1 ? 'Y' : 'y');
    write(a & 2 ? 'E' : 'e');
    write(a & 4 ? 'S' : 's');
    clr();
    return;
}

inline void no(_ a = 1) {
    write(a & 1 ? 'N' : 'n');
    write(a & 2 ? 'O' : 'o');
    clr();
    return;
}

//loop systems
inline v_ rg(_ r, _ l = 1, _ d = 1) {
    v_ rv;
    for(_ i = l; i <= r; i += d) rv.push_back(i);
    return rv;
}

inline v_ dg(_ r, _ l = 1, _ d = -1) {
    v_ rv;
    for(_ i = r; i >= l; i += d) rv.push_back(i);
    return rv;
}

inline void AC();
int main(int argc, char * argv[]) {

//    #define file_IO
#ifdef file_IO
    str fileN = "";
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



constant big = 100;

struct mon {
    _ x, y, z;
    _ sm() {
        return x*5+y*2+z;
    }
    void write() {
        writesc(z);
        writesc(y);
        writeln(x);
        return;
    }
} a, oa, ob, pa, pb, sv;
_ x, y, s;
char fs;

void upd(_ x, mon a, mon b, char ns);
mon chg(_ x);
inline void AC() {
    
    a.z = read();
    a.y = read();
    a.x = read();
    sv = a;
    x = read();
    y = read();
    if(a.sm() < x+y) {
        writeln("Impossible");
        return;
    }
    writeln("Possible");
    s = 2;
    fs = 'A';
    oa = a;
    ob = chg(a.sm()-x);
    _ va = max(0LL, a.x-big);
    if(va & 1) ++va;
    a.x -= va;
    va >>= 1;
    _ mn = min((x-100)/10, va);
    mn = max(mn, 0LL);
    x -= mn*10;
    pa.x += mn*2;
    va -= mn;
    mn = min((y-100)/10, va);
    mn = max(mn, 0LL);
    y -= mn*10;
    pb.x += mn*2;
    for(_ i = 0; i <= a.x; ++i) for(_ j = 0; j <= a.x-i; ++j) {
        _ tx = x-i*5, ty = y-j*5;
        if((tx < 0 && ty < 0) || tx+ty > a.y*2+a.z) continue;
        _ nd = (tx&1)+(ty&1), ca = a.y, cb = a.z;
        mon ta = pa, tb = pb;
        ta.x += i;
        tb.x += j;
        if(!tx && !ty) upd(0, ta, tb, 'A');
        ef(!tx && ty < 0) {
            if(s > 1) upd(1, ta, tb, 'A');
        } ef(tx < 0 && !ty) {
            if(s > 1) upd(1, ta, tb, 'A');
        } ef(!tx && ty > 0) {
            _ c = (ty & 1) && !a.z;
            if(s > c) {
                if(c) tb.y = a.y;
                else {
                    tb.y = min(a.y, ty>>1);
                    tb.z = ty-(tb.y<<1);
                }
                upd(c, ta, tb, 'A');
            }
        } ef(tx > 0 && !ty) {
            _ c = (tx & 1) && !a.z;
            if(s > c) {
                if(c) ta.y = a.y;
                else {
                    ta.y = min(a.y, tx>>1);
                    ta.z = tx-(ta.y<<1);
                }
                upd(c, ta, tb, 'B');
            }
        } ef(tx > 0 && ty > 0) {
            _ c;
            if(cb >= 2 || (nd == 1 && cb == 1) || !nd) c = 0;
            else c = 1;
            if(s > c) {
                if(c) {
                    if(nd == 2) {
                        ta.y = (tx+1)>>1;
                        tb.y = ty>>1;
                        tb.z = 1;
                        upd(c, ta, tb, 'A');
                    } ef(tx & 1) {
                        ta.y = (tx+1)>>1;
                        tb.y = ty>>1;
                        upd(c, ta, tb, 'B');
                    } ef(ty & 1) {
                        ta.y = tx>>1;
                        tb.y = (ty+1)>>1;
                        upd(c, ta, tb, 'A');
                    }
                } else {
                    ta.y = min(ca, tx>>1);
                    ta.z = tx-(ta.y<<1);
                    ca -= ta.y;
                    tb.y = min(ca, ty>>1);
                    tb.z = ty-(tb.y<<1);
                    upd(c, ta, tb, 'A');
                }
            }
        } ef(tx > 0 && ty < 0) {
            if(s > 1) {
                mon ts = chg(-ty);
                ca += ts.y;
                cb += ts.z;
                if((tx & 1) && !cb) continue;
                if(ca*2+cb < tx) continue;
                ta.y = min(ca, tx>>1);
                ta.z = tx-(ta.y<<1);
                upd(1, ta, tb, 'B');
            }
        } ef(tx < 0 && ty > 0) {
            if(s > 1) {
                mon ts = chg(-tx);
                ca += ts.y;
                cb += ts.z;
                if((ty & 1) && !cb) continue;
                if(ca*2+cb < ty) continue;
                tb.y = min(ca, ty>>1);
                tb.z = ty-(tb.y<<1);
                upd(1, ta, tb, 'A');
            }
        }
    }
    writeln(s);
    writeln(fs);
    oa.write();
    ob.write();
    
    return;
}

mon chg(_ x) {
    mon rv;
    rv.x = x/5;
    rv.y = (x%5)/2;
    rv.z = (x%5)%2;
    return rv;
}

void upd(_ x, mon a, mon b, char ns) {
    if(x >= s) return;
    s = x;
    oa = a;
    ob = b;
    fs = ns;
    return;
}
