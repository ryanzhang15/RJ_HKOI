
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
//
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
typedef int _0;
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

inline void writeln(char a) { //pascal vibes
    write(a);
    clr();
    return;
}

inline void writeln(_p a, char const * b = " ") {
    write(a, b);
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

inline void writesc(char a) {
    write(a);
    spc();
    return;
}

inline void writesc(_p a, char const * b = " ") {
    write(a);
    spc();
    return;
}

#define usemode1
#ifdef usemode1

inline void AC();
int main(int argc, char * argv[]) {

//    #define file_IO
#ifdef file_IO
    str fileN = "ball";
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



constant maxn = 1E6+8;

char a[maxn];
_ n, m = 122, b[maxn], c[maxn], sa[maxn], d[maxn], f[maxn], s, mx = -9E18, ht[maxn], rk[maxn], r[maxn];
multiset<_> st[maxn];
v(_p) o;

_ find(_ x);
bool cmp(_ x, _ y);
inline void AC() {

    n = read();
    read(a+1);
    for(_ i = 1; i <= n; ++i) {
        st[i].insert(read());
        b[i] = a[i];
        ++c[b[i]];
        f[i] = i;
    }
    for(_ i = 2; i <= m; ++i) c[i] += c[i-1];
    for(_ i = n; i >= 1; --i) sa[c[b[i]]--] = i;
    for(_ i = 1; i <= n; i <<= 1) {
        _ cnt = 0;
        for(_ j = n-i+1; j <= n; ++j) d[++cnt] = j;
        for(_ j = 1; j <= n; ++j) if(sa[j] > i) d[++cnt] = sa[j]-i;
        for(_ j = 1; j <= m; ++j) c[j] = 0;
        for(_ j = 1; j <= n; ++j) ++c[b[j]];
        for(_ j = 2; j <= m; ++j) c[j] += c[j-1];
        for(_ j = n; j >= 1; --j) {
            sa[c[b[d[j]]]--] = d[j];
            d[j] = 0;
        }
        swap(b, d);
        b[sa[1]] = 1;
        cnt = 1;
        for(_ j = 2; j <= n; ++j) b[sa[j]] = (d[sa[j]] == d[sa[j-1]] && d[sa[j]+i] == d[sa[j-1]+i] ? cnt : ++cnt);
        if(cnt == n) break;
        m = cnt;
    }
    _ cnt = 0;
    for(_ i = 1; i <= n; ++i) rk[sa[i]] = i;
    for(_ i = 1; i <= n; ++i) if(rk[i] != 1) {
        if(cnt) --cnt;
        _ p = sa[rk[i]-1];
        for(; p+cnt <= n && i+cnt <= n && a[i+cnt] == a[p+cnt]; ) ++cnt;
        ht[rk[i]] = cnt;
    }
    for(_ i = 1; i <= n; ++i) r[i] = i;
    sort(r+1, r+1+n, cmp);
    _ p = 1;
    for(_ i = n-1; i >= 0; --i) {
        for(; ht[r[p]] == i && p <= n; ++p) {
            if(r[p] == 1) continue;
            _ x = find(sa[r[p]]), y = find(sa[r[p]-1]);
            if(x == y) continue;
            if(st[x].size() > st[y].size()) swap(x, y);
            _ ta = st[x].size(), tb = st[y].size();
            s -= (ta*(ta-1))>>1;
            s -= (tb*(tb-1))>>1;
            s += ((ta+tb)*(ta+tb-1))>>1;
            f[x] = y;
            for(_ i : st[x]) st[y].insert(i);
            i(set<_>) it = st[y].begin(), ita;
            ita = it;
            ++it;
            mx = max(mx, *it**ita);
            it = st[y].end();
            --it;
            ita = it;
            --it;
            mx = max(mx, *it**ita);
        }
        o.push_back(mp(s, !s ? 0 : mx));
    }
    reverse(o.begin(), o.end());
    for(_p i : o) writeln(i);
    
    
    return;
}

bool cmp(_ x, _ y) {
    return ht[x] > ht[y];
}

_ find(_ x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void dbg() {
    for(_ i = 1; i <= 10; ++i) writesc(find(i));
    clr();
    for(_ i = 1; i <= 10; ++i) writesc((_)st[find(i)].size());
    clr();
    return;
}

#else

#ifndef EVAL



#endif

#endif

