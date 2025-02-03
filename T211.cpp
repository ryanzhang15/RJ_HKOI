
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



s(_p) a, b;
_ n, ca, cb, sva, svb, x, y;
_p na, nb, sa, sb;

void judge();
void way();
void snow();
void meet(_p & ac, _p & bc);
void yesf();
inline void AC() {
    
    n = read();
    sva = ca = read();
    svb = cb = read();
    x = read();
    y = read();
    na.second = x-1;
    na.first = n-na.second-1;
    nb.first = y-1;
    nb.second = n-nb.first-1;
    if(na.first && nb.first && ca) {
        sa = na;
        sb = nb;
        snow();
    }
    na = sa;
    nb = sb;
    ca = sva;
    cb = svb;
    a.clear();
    b.clear();
    if(na.second && nb.second && cb) way();
    no(7);
    
    return;
}

void yesf() {
    yes(7);
    writeln((_)a.size());
    for(_p i : a) writeln(i);
    writeln((_)b.size());
    for(_p i : b) writeln(i);
#ifndef ONLINE_JUDGE
    judge();
#endif
    leave
}

void meet(_p & ac, _p & bc) {
    if(ac.second < bc.second) {
        b.insert(ac);
        b.insert(bc);
        cb -= 2;
        ++ac.first;
        ++ac.second;
        ++bc.first;
        --na.second;
        --nb.second;
    } else {
        a.insert(ac);
        a.insert(bc);
        ca -= 2;
        ++ac.first;
        ++bc.first;
        ++bc.second;
        --na.first;
        --nb.first;
    }
    return;
}

void snow() {
    _p ac = mp(2, 1), bc = mp(2, 2);
    a.insert(mp(1, 1));
    --na.first;
    --nb.first;
    --ca;
    _ pa = max(0LL, na.first+nb.first-ca), pb = max(0LL, na.second+nb.second-cb);
    if(pa+pb) meet(ac, bc);
    for(;;) if(pa && na.first && nb.first && (pa+pb == 1 || (na.second-pb >= 1 && nb.second-pb >= 1))) {
        if(ac.first+2 > n) return;
        --na.first;
        --nb.first;
        a.insert(ac);
        --ca;
        ++ac.first;
        ++bc.first;
        ++bc.second;
        --pa;
        if(pa+pb) meet(ac, bc);
        if(ca < 0 || cb < 0) return;
    } ef(pb && na.second && nb.second && (pa+pb == 1 || (na.first-pa >= 1 && nb.first-pa >= 1))) {
        if(ac.first+2 > n) return;
        --na.second;
        --nb.second;
        b.insert(ac);
        --cb;
        ++ac.first;
        ++ac.second;
        ++bc.first;
        --pb;
        if(pa+pb) meet(ac, bc);
        if(ca < 0 || cb < 0) return;
    } else break;
    if(pa+pb) return;
    bool md = ac.second > bc.second;
    for(; ac.first < n; ) {
        if(md) {
            if(na.second) {
                b.insert(ac);
                ++ac.first;
                ++ac.second;
                --na.second;
            } else {
                a.insert(ac);
                ++ac.first;
                --na.first;
            }
            if(nb.second) {
                b.insert(bc);
                ++bc.first;
                --nb.second;
            } else {
                a.insert(bc);
                ++bc.first;
                ++bc.second;
                --nb.first;
            }
        } else {
            for(; ac.first < n; ) {
                if(na.first) {
                    a.insert(ac);
                    ++ac.first;
                    --na.first;
                } else {
                    b.insert(ac);
                    ++ac.first;
                    ++ac.second;
                    --na.second;
                }
                if(nb.first) {
                    a.insert(bc);
                    ++bc.first;
                    ++bc.second;
                    --nb.first;
                } else {
                    b.insert(bc);
                    ++bc.first;
                    --nb.second;
                }
            }
        }
    }
    yesf();
}

void way() {
    _p ac = mp(2, 2), bc = mp(2, 1);
    b.insert(mp(1, 1));
    --na.second;
    --nb.second;
    --cb;
    _ pa = max(0LL, na.first+nb.first-ca), pb = max(0LL, na.second+nb.second-cb);
    if(pa+pb) meet(ac, bc);
    for(;;) if(pa && na.first && nb.first && (pa+pb == 1 || (na.second-pb >= 1 && nb.second-pb >= 1))) {
        if(ac.first+2 > n) return;
        --na.first;
        --nb.first;
        a.insert(ac);
        --ca;
        ++ac.first;
        ++bc.first;
        ++bc.second;
        --pa;
        if(pa+pb) meet(ac, bc);
        if(ca < 0 || cb < 0) return;
    } ef(pb && na.second && nb.second && (pa+pb == 1 || (na.first-pa >= 1 && nb.first-pa >= 1))) {
        if(ac.first+2 > n) return;
        --na.second;
        --nb.second;
        b.insert(ac);
        --cb;
        ++ac.first;
        ++ac.second;
        ++bc.first;
        --pb;
        if(pa+pb) meet(ac, bc);
        if(ca < 0 || cb < 0) return;
    } else break;
    if(pa+pb) return;
    bool md = ac.second > bc.second;
    for(; ac.first < n; ) {
        if(md) {
            if(na.second) {
                b.insert(ac);
                ++ac.first;
                ++ac.second;
                --na.second;
            } else {
                a.insert(ac);
                ++ac.first;
                --na.first;
            }
            if(nb.second) {
                b.insert(bc);
                ++bc.first;
                --nb.second;
            } else {
                a.insert(bc);
                ++bc.first;
                ++bc.second;
                --nb.first;
            }
        } else {
            for(; ac.first < n; ) {
                if(na.first) {
                    a.insert(ac);
                    ++ac.first;
                    --na.first;
                } else {
                    b.insert(ac);
                    ++ac.first;
                    ++ac.second;
                    --na.second;
                }
                if(nb.first) {
                    a.insert(bc);
                    ++bc.first;
                    ++bc.second;
                    --nb.first;
                } else {
                    b.insert(bc);
                    ++bc.first;
                    --nb.second;
                }
            }
        }
    }
    yesf();
}

void judge() {
    for(_p i : a) if(b.count(i)) {
        writeln("ERROR: TWO CHECKPOINTS ON ONE SQUARE.");
        leave
    }
    _p p = mp(1, 1);
    for(; p.first != n; ++p.first) {
        if(b.count(p)) ++p.second;
        ef(!a.count(p)) {
            writeln("ERROR: NO CHECKPOINT ON REQUIRED SQUARE. (ALICE)");
            leave
        }
    }
    if(p.second != x) {
        writeln("ERROR: ALICE DID NOT ARRIVE.");
        writesc("Expected:");
        write(x);
        writesc(", found:");
        writeln(p.second);
        leave
    }
    p = mp(1, 1);
    for(; p.first != n; ++p.first) {
        if(a.count(p)) ++p.second;
        ef(!b.count(p)) {
            writeln("ERROR: NO CHECKPOINT ON REQUIRED SQUARE. (BOB)");
            leave
        }
    }
    if(p.second != y) {
        writeln("ERROR: BOB DID NOT ARRIVE.");
        writesc("Expected:");
        write(y);
        writesc(", found:");
        writeln(p.second);
        leave
    }
    writeln("GOOD, ANSWER CORRECT.");
    return;
}
