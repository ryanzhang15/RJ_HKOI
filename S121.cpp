#pragma G++ optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma G++ target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
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
typedef long double _D;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

const char untl = '\n';

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

inline bool gc(char &a) {
    char ch = getchar_unlocked();
    if(ch == '\r') ch = getchar_unlocked();
    if(ch == untl || ch == EOF) a = '\0';
    else a = ch;
    return ch != untl && ch != EOF;
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

    AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxn = 5E5+8;

_ n, m, a[maxn], mx[maxn], f[maxn], g[maxn], dp1[maxn], dp2[maxn], s = 1E11;
bool v[maxn];

void code();
inline void AC() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(_ i = 1; i <= m; ++i) v[read()] = true;
    code();
    memset(mx, 0, sizeof mx);
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    memset(dp1, 0, sizeof dp1);
    memset(dp2, 0, sizeof dp2);
    for(_ i = 1; i <= n; ++i) v[i] = !v[i];
    code();
    writeln(s);
    
    return;
}

void code() {
    for(_ i = 1; i <= n; ++i) f[i] = v[i] ? a[i]+f[i-1] : f[i-1];
    for(_ i = 1; i <= n; ++i) g[i] = v[i] ? g[i-1] : a[i]+g[i-1];
    for(_ i = 1; i <= n; ++i) if(v[i]) {
        mx[i] = max(mx[i-1], g[i]-f[i-1]);
        dp1[i] = g[i]-mx[i];
    } else mx[i] = mx[i-1];
    memset(mx, 0, sizeof mx);
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    for(_ i = n; i >= 1; --i) f[i] = v[i] ? a[i]+f[i+1] : f[i+1];
    for(_ i = n; i >= 1; --i) g[i] = v[i] ? g[i+1] : a[i]+g[i+1];
    for(_ i = n; i >= 1; --i) if(v[i]) {
        mx[i] = max(mx[i+1], g[i]-f[i+1]);
        dp2[i] = g[i]-mx[i];
    } else mx[i] = mx[i+1];
    for(_ i = 1; i <= n; ++i) if(v[i]) s = min(s, dp1[i]+dp2[i]);
    return;
}
