
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
#include <functional>

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

inline bool read(_ & x, v(char) tl = {'\n', EOF}) {
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

inline void read(vector<reference_wrapper<_> > a) {
    for(_ & i : a) i = read();
    return;
}

inline void read(_p & x) {
    x.first = read();
    x.second = read();
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

inline void write(v_ a, char const * b = " ") {
    bool fs = false;
    for(_ i : a) {
        if(!fs) fs = true;
        else write(b);
        write(i);
    }
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

inline void writeln(v_ a, char const * b = " ") {
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
//int main(int argc, char * argv[]) {
//
////    #define file_IO
//#ifdef file_IO
//    str fileN = "";
//    freopen((fileN+".in").c_str(), "r", stdin);
//    freopen((fileN+".out").c_str(), "w", stdout);
//#endif
//
////    #define multiple_testcases
//#ifdef multiple_testcases
//    _ tc = read();
//    for(; tc--; ) AC(); // good luck!
//#else
//    AC(); // good luck!
//#endif
//
//    return 0;
//}

// ----- End of Template -----




struct pr {
    _ a = 1, l = 1;
    void operator ++ () {
        if(a == 9) {
            ++l;
            a = 1;
        } else ++a;
        return;
    }
    bool operator == (const pr &b) const {
        return a == b.a && l == b.l;
    }
    
};
v_ a, b;
_ tn[20];

bool sme(v_ a, v_ b, _ x, _ y);
inline void AC() {
    
    tn[0] = 1;
    for(_ i = 1; i <= 18; ++i) tn[i] = tn[i-1]*10;
    
    a = v_(10);
    for(_ i = 1; i <= 9; ++i) a[i] = read();
    for(pr i; i.l <= 18; ++i) {
        b = v_(10);
        _ sa = tn[i.l-1]-1;
        for(pr j = i; j.l <= 18; ++j) {
            ++b[j.a];
            _ sb = tn[j.l-1]-1;
            if(i == j) {
                if(sme(a, b, i.a, i.a) && b[i.a] <= a[i.a] && b[i.a]+sa >= a[i.a]) {
                    writeln(mp(tn[i.l-1]*(i.a+1)-1-a[i.a]+b[i.a], tn[i.l-1]*(i.a+1)-1));
                    return;
                }
            } ef(i.a == j.a) {
                if(sme(a, b, i.a, j.a) && b[i.a] <= a[i.a] && b[i.a]+sa+sb >= a[i.a]) {
                    if(b[i.a]+sa >= a[i.a]) writeln(mp(tn[i.l-1]*(i.a+1)-1-a[i.a]+b[i.a], tn[j.l-1]*j.a));
                    else writeln(mp(tn[i.l-1]*(i.a+1)-1-sa, tn[j.l-1]*j.a+a[i.a]-b[i.a]-sa));
                    return;
                }
            } else {
                if(sme(a, b, i.a, j.a) && b[i.a] <= a[i.a] && b[j.a] <= a[j.a] && b[i.a]+sa >= a[i.a] && b[j.a]+sb >= a[j.a]) {
                    writeln(mp(tn[i.l-1]*(i.a+1)-1-a[i.a]+b[i.a], tn[j.l-1]*j.a+a[j.a]-b[j.a]));
                    return;
                }
            }
            if(!(j == i)) b[j.a] += sb;
        }
    }
    writeln(mp(-1, -1));
 
    return;
}

bool sme(v_ a, v_ b, _ x, _ y) {
    for(_ i = 1; i <= 9; ++i) if(i != x && i != y && a[i] != b[i]) return false;
    return true;
}

std::pair<long long, long long> find_segment(std::vector<long long> A) {
    tn[0] = 1;
    for(_ i = 1; i <= 18; ++i) tn[i] = tn[i-1]*10;
    
    a = v_(10);
    for(_ i = 1; i <= 9; ++i) a[i] = A[i-1];
    for(pr i; i.l <= 18; ++i) {
        b = v_(10);
        _ sa = tn[i.l-1]-1;
        for(pr j = i; j.l <= 18; ++j) {
            ++b[j.a];
            _ sb = tn[j.l-1]-1;
            if(i == j) {
                if(sme(a, b, i.a, i.a) && b[i.a] <= a[i.a] && b[i.a]+sa >= a[i.a]) {
                    return (mp(tn[i.l-1]*(i.a+1)-1-a[i.a]+b[i.a], tn[i.l-1]*(i.a+1)-1));
                }
            } ef(i.a == j.a) {
                if(sme(a, b, i.a, j.a) && b[i.a] <= a[i.a] && b[i.a]+sa+sb >= a[i.a]) {
                    if(b[i.a]+sa >= a[i.a]) return (mp(tn[i.l-1]*(i.a+1)-1-a[i.a]+b[i.a], tn[j.l-1]*j.a));
                    else return (mp(tn[i.l-1]*(i.a+1)-1-sa, tn[j.l-1]*j.a+a[i.a]-b[i.a]-sa));
                }
            } else {
                if(sme(a, b, i.a, j.a) && b[i.a] <= a[i.a] && b[j.a] <= a[j.a] && b[i.a]+sa >= a[i.a] && b[j.a]+sb >= a[j.a]) {
                    return (mp(tn[i.l-1]*(i.a+1)-1-a[i.a]+b[i.a], tn[j.l-1]*j.a+a[j.a]-b[j.a]));
                }
            }
            if(!(j == i)) b[j.a] += sb;
        }
    }
    return mp(-1, -1);
}
