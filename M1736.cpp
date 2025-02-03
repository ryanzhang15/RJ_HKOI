
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



constant maxn = 5E3+8;
constant mod = 1E9+7;

_ n, dp[maxn][3], l[maxn][3], r[maxn][3], t, p, s, sv;
char a[maxn];

void AC() {
    
    for(char ch = getchar(); ch != '\n'; ch = getchar()) a[++n] = ch;
    for(_ i = 1; i <= n; ++i) dp[i][0] = l[i][0] = r[i][0] = 1;
    t = 1;
    p = 0;
    s = 2;
    for(_ k = 1; k <= n; ++k, sv = p, p = t, t = s, s = sv) for(_ i = 1; i <= n; ++i) {
        if(i+k > n) continue;
        l[i][t] = l[i][p];
        r[i][t] = r[i+1][p];
        dp[i][t] = (l[i][p]+dp[i+1][s]+r[i+1][p])%mod;
        if(a[i] == a[i+k]) {
            l[i][t] = (l[i][t]+dp[i+1][s])%mod;
            r[i][t] = (r[i][t]+dp[i+1][s])%mod;
            dp[i][t] = (dp[i][t]+dp[i+1][s])%mod;
        }
    }
    writesc(dp[1][s]);
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    memset(dp, 0, sizeof dp);
    t = 1;
    p = 0;
    s = 2;
    for(_ k = 1; k <= n; ++k, sv = p, p = t, t = s, s = sv) for(_ i = 1; i <= n; ++i) {
        if(i+k > n) continue;
        l[i][t] = l[i][p];
        r[i][t] = r[i+1][p];
        dp[i][t] = (l[i][p]+dp[i+1][s]+r[i+1][p])%mod;
        if(a[i] == a[i+k]) {
            l[i][t] = (l[i][t]+dp[i+1][s]+1)%mod;
            r[i][t] = (r[i][t]+dp[i+1][s]+1)%mod;
            dp[i][t] = (dp[i][t]+dp[i+1][s]+1)%mod;
        }
    }
    writeln(dp[1][s]);
    
    return;
}

