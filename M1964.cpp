#pragma G++ optimize("Ofast")

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

inline void AC();
int main(int argc, char * argv[]) {

    //#define file_IO
#ifdef file_IO
    str fileN = "";
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



// ----- End of Template -----



constant maxn = 1E6+8;

map<_, _> d;
v_ a[maxn], b[maxn];
_ n, m, x, cnt, s, rs[maxn], bs[maxn], rc[maxn], bc[maxn], dp[maxn];

_ inject(vector<_> &a, vector<_> &b);
inline void AC() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) {
        x = read();
        _ c = d.count(x) ? d[x] : d[x] = ++cnt;
        a[c].push_back(i);
    }
    for(_ i = 1; i <= m; ++i) {
        x = read();
        _ c = d.count(x) ? d[x] : d[x] = ++cnt;
        b[c].push_back(i);
    }
    for(_ i = 1; i <= cnt; ++i) s += inject(a[i], b[i]);
    writeln(s);
    
    return;
}

_ inject(vector<_> &a, vector<_> &b) {
    if(a.size() > b.size()) {
        writeln(-1);
        leave
    }
    v(_p) c;
    _ p1 = 0, p2 = 0;
    c.push_back(make_pair(0, 0));
    for(; p1 < a.size() || p2 < b.size(); ) {
        if(p1 >= a.size()) c.push_back(make_pair(1, b[p2++]));
        ef(p2 >= b.size()) c.push_back(make_pair(0, a[p1++]));
        ef(a[p1] <= b[p2]) c.push_back(make_pair(0, a[p1++]));
        else c.push_back(make_pair(1, b[p2++]));
    }
    map<_, _> l;
    l[0] = 0;
    for(_ i = 1; i < c.size(); ++i) {
        if(c[i].first == 1) {
            bs[i] = bs[i-1]+c[i].second;
            rs[i] = rs[i-1];
            bc[i] = bc[i-1]+1;
            rc[i] = rc[i-1];
        } else {
            bs[i] = bs[i-1];
            rs[i] = rs[i-1]+c[i].second;
            bc[i] = bc[i-1];
            rc[i] = rc[i-1]+1;
        }
        if(!l.count(bc[i]-rc[i])) {
            if(!c[i].first) dp[i] = 1E11;
            else dp[i] = dp[i-1];
        } else {
            _ x = l[bc[i]-rc[i]];
            dp[i] = dp[x]+abs(rs[i]-rs[x]-bs[i]+bs[x]);
        }
        if(c[i].first == 1) dp[i] = min(dp[i], dp[i-1]);
        l[bc[i]-rc[i]] = i;
    }
    return dp[c.size()-1];
}
