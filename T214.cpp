
/*
ID: ryanjzh1
LANG: C++11
TASK: skidesign
 */

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

#ifndef ONLINE_JUDGE

inline void AC();
int main(int argc, char * argv[]) {

    //#define file_IO
#ifdef file_IO
    str fileN = "skidesign";
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    //#define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
    for(; tc--; ) AC(); // good luck!
#else
    AC(); // good luck!
#endif


    return 0;
}

#endif

// ----- End of Template -----

#ifndef ONLINE_JUDGE

constant maxn = 1E3+8;

_p a[maxn];
_ n, st[maxn];

#endif

typedef pair<int, int> why;

vector<why> analyze_monsters(int N);
vector<_> surrender(_ D);

_ gcd(_ a, _ b) {
    return !b ? a : gcd(b, a%b);
}

vector<why> analyze_monsters(int N) {
    _ n = N;
    vector<why> rv(n);
    vector<_> a = surrender(0), b = surrender(2639867630399), c = surrender(486292387647392);
    for(_ i = 0; i < n; ++i) {
        _ da = abs(b[i]-a[i]), db = abs(c[i]-a[i]), oa = b[i]-a[i];
        for(_ j = 1; j <= 100; ++j) {
            _ ta = 2639867630399/j, tb = 486292387647392/j;
            if(ta/gcd(ta, tb) == da/gcd(da, db) && tb/gcd(ta, tb) == db/gcd(da, db)) {
                rv[i].second = j;
                rv[i].first = oa/(2639867630399/rv[i].second);
                break;
            }
        }
    }
    return rv;
}

#ifndef ONLINE_JUDGE

vector<_> surrender(_ D) {
    v_ rv = ss(n);
    for(_ i = 0; i < n; ++i) rv[i] = st[i]+(D/a[i+1].second)*a[i+1].first;
    return rv;
}

inline void AC() {
    
    srand((unsigned)time(NULL));
    
    for(;;) {
        n = 1E3;
    for(_ i = 1; i <= n; ++i) {
        st[i] = 1LL*rand()*rand()%100000000000000000+1;
        //st[i] = read();
        a[i] = mp(rand()%1000+1, rand()%100+1);
        if(rand() & 1) a[i].first *= -1;
        //a[i].first = read();
        //a[i].second = read();
    }
    v(_p) s = analyze_monsters(n);
    for(_ i = 1; i <= n; ++i) if(a[i] != s[i-1]) {
        writeln("WRONG!");
        writeln(i);
        writesc(a[i].first);
        writeln(a[i].second);
        writesc(s[i-1].first);
        writeln(s[i-1].second);
        leave
    }
    writeln("OK.");
    }
    return;
}

#endif
