
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

void AC();
int main(int argc, char * argv[]) {
    
    str fileN = "";
    
    //#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    AC(); // good luck!
    
    return 0;
}



// ----- End of Template -----



constant maxn = 10+8;
constant maxd = 1E2+8;
constant mod = 1E9+7;

_ a[maxn], t, p[maxd], s, dp[maxn][maxd], fac[maxd];

_ countSum(_ x, _ y);
_ inv(_ x, _ p);
void AC() {
    
    p[0] = 1;
    for(_ i = 1; i <= 100; ++i) p[i] = (p[i-1]*10)%mod;
    fac[0] = 1;
    for(_ i = 1; i <= 100; ++i) fac[i] = (fac[i-1]*i)%mod;
    for(_ i = 1; i <= 9; ++i) t += (a[i] = read());
    for(_ i = 1; i <= 9; ++i) for(_ j = 1; j <= t; ++j) {
        s = (s+i*p[j-1]%mod*countSum(i, j)%mod)%mod;
    }
    writeln(s);
    
    return;
}

_ inv(_ x, _ p) {
    if(!p) return 1;
    _ c = inv(x, p>>1);
    c = (c*c)%mod;
    if(p & 1) c = (c*x)%mod;
    return c;
}

_ countSum(_ x, _ y) {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    --a[x];
    for(_ i = 1; i <= 9; ++i) for(_ j = 0; j <= t-1; ++j) for(_ k = 0; k <= a[i]; ++k) if(j >= k) dp[i][j] = (dp[i][j]+dp[i-1][j-k]*inv(fac[k], mod-2)%mod)%mod;
    _ rv = 0;
    for(_ i = y-1; i <= t-1; ++i) rv = (rv+fac[i]*dp[9][i]%mod)%mod;
    ++a[x];
    return rv;
}


