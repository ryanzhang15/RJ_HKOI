
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
typedef __int128 _;
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




inline _D slp(_p a, _p b);
inline _D cross(_p a, _p b, _p c);

struct convexHull {
    
    typedef pair<_p, _D> ptsl;
    typedef pair<_D, _p> slpt;
    s(ptsl) pt;
    s(slpt) ln;
    
    inline convexHull(_ st) {
        _p pa = mp(0, 1E36), pb = mp(st, 0);
        _D sl = slp(pa, pb);
        pt.insert(mp(pa, sl));
        pt.insert(mp(pb, 1E36));
        ln.insert(mp(sl, pa));
        ln.insert(mp(1E36, pb));
    }
    
    inline void addNode(_p x) {
        i(s(ptsl)) ia = pt.upper_bound(mp(x, -1E11));
        i(s(ptsl)) ib = ia;
        --ia;
        ptsl pa = *ia;
        pt.erase(ia);
        pt.insert(mp(pa.first, slp(pa.first, x)));
        pt.insert(mp(x, slp(x, ib -> first)));
        ln.erase(mp(pa.second, pa.first));
        ln.insert(mp(slp(pa.first, x), pa.first));
        ln.insert(mp(slp(x, ib -> first), x));
        return;
    }
    
    inline void add(_p x) {
        i(s(ptsl)) ia = pt.upper_bound(mp(mp(x.first, -1E11), -1E11)), ib, ic, id;
        if(ia == pt.end()) return;
        ic = ia;
        --ic;
        if(cross(ia -> first, x, ic -> first) >= 0) return;
        ib = ia;
        ++ib;
        for(; ib != pt.end(); ia = ib, ++ib) if(cross(x, ia -> first, ib -> first) <= 0) {
            ln.erase(mp(ia -> second, ia -> first));
            pt.erase(ia);
        } else break;
        if(ic != pt.begin()) {
            id = ic;
            --id;
            for(;;) if(cross(x, ic -> first, id -> first) >= 0) {
                ln.erase(mp(ic -> second, ic -> first));
                pt.erase(ic);
                if(id == pt.begin()) break;
                ic = id;
                --id;
            } else break;
        }
        addNode(x);
        return;
    }
    
    inline _ query(_p x) {
        i(s(slpt)) it = ln.upper_bound(mp(-x.first, mp(-1E11, -1E11)));
        if(it == ln.end()) --it;
        return x.first*it -> second.first+it -> second.second+x.second;
    }
    
};

_ n, ca, cb, s, op, x, y;
char ch;

inline void AC() {
    
    n = read();
    ca = read();
    cb = read();
    convexHull ha(ca);
    convexHull hb(cb);
    s = ca*cb;
    for(; n--; ) {
        op = read();
        if(op == 1) {
            ch = getUp();
            x = read();
            y = read();
            if(ch == 'A') {
                ha.add(mp(x, y));
                s = min(s, hb.query(mp(x, y)));
            } else {
                hb.add(mp(x, y));
                s = min(s, ha.query(mp(x, y)));
            }
        } else writeln(s);
    }
    
    return;
}

inline _D slp(_p a, _p b) {
    return 1.L*(b.second-a.second)/(b.first-a.first);
}

inline _D cross(_p a, _p b, _p c) {
    return 1.L*(b.first-a.first)*(c.second-b.second)-1.L*(b.second-a.second)*(c.first-b.first);
}
 
