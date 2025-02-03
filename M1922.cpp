
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
#define RE exit(1);
#define WA writeln("lolthiscantbecorrectright?Imeanthisreallycantbethecorrectanswer"); exit(0);
#define TLE for(;;);

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef unsigned long long u_;
typedef long double _D;
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

    str fileN = "cells";

    //#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    AC();

    return 0;
}


// ----- End of Template -----



constant maxn = 1E5+8;
constant mod = 1E9+7;

_ n, a[maxn], p[maxn], f[maxn];

_ vl(_ l, _ r, _ t);
bool cmp(_ x, _ y);
_ recur(_ l, _ r);
void AC() {

    n = read();
    for(_ i = 1; i <= n; ++i) a[i] = read()%mod;
    for(_ i = 2; i <= n; ++i) {
        p[i] = (p[i-1]+read())%mod;
        f[i] = (f[i-1]+p[i])%mod;
    }
    writeln(recur(1, n));
    
    return;
}

bool cmp(_ x, _ y) {
    return a[x] > a[y];
}

_ vl(_ l, _ r, _ t) {
    if(t == 1) return (p[r]-p[l-1])%mod;
    return (f[r+t-1]-f[r-1])%mod-(f[l+t-2]-f[l-2])%mod;
}

_ recur(_ l, _ r) {
    if(l >= r) return 0;
    _ rv = 0, md, cl = l-1, cr = r+1;
    vector<_> c;
    for(_ i = l; i <= r; ++i) c.push_back(i);
    sort(c.begin(), c.end(), cmp);
    md = c.front();
    rv = (rv+recur(l, md-1)+recur(md+1, r))%mod;
    for(_ i : c) if(i < md) {
        if(i < cl) continue;
        rv = (rv+a[i]*a[md]%mod*vl(md-i+1, cr-i, i-cl))%mod;
        cl = i;
    } ef(i > md) {
        if(i > cr) continue;
        rv = (rv+a[i]*a[md]%mod*vl(i-md+1, i-cl, cr-i))%mod;
        cr = i;
    }
    return (rv+mod)%mod;
}
