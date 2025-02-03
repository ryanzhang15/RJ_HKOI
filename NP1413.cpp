
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
typedef int _;
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
    
    str fileN = "bird";
    
    #define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    AC(); // good luck!
    
    return 0;
}



// ----- End of Template -----



constant maxn = 1E4+8;
constant maxm = 2E3+8;

_ n, m, t, x[maxn], y[maxn], l[maxn], h[maxn], dp[maxn][maxm], c, inf, s = 1E18;
bitset<maxn> v;

void AC() {
    
    memset(dp, 4, sizeof dp);
    inf = dp[0][0];
    
    n = read();
    m = read();
    t = read();
    for(_ i = 1; i <= n; ++i) {
        x[i] = read();
        y[i] = read();
        l[i] = 0;
        h[i] = m+1;
    }
    for(; t--; ) {
        c = read();
        v.set(c);
        l[c] = read();
        h[c] = read();
    }
    for(_ i = 1; i <= m; ++i) dp[0][i] = 0;
    for(_ i = 1; i <= n; ++i) {
        for(_ j = x[i]+1; j <= m+x[i]; ++j) dp[i][j] = min(dp[i-1][j-x[i]]+1, dp[i][j-x[i]]+1);
        for(_ j = m+1; j <= m+x[i]; ++j) dp[i][m] = min(dp[i][m], dp[i][j]);
        for(_ j = 1; j <= m-y[i]; ++j) dp[i][j] = min(dp[i][j], dp[i-1][j+y[i]]);
        for(_ j = 1; j <= l[i]; ++j) dp[i][j] = inf;
        for(_ j = h[i]; j <= m; ++j) dp[i][j] = inf;
    }
    for(_ j = 1; j <= n; ++j) s = min(s, dp[n][j]);
    if(s != inf) {
        writeln("1");
        writeln(s);
    } else {
        writeln("0");
        s = 0;
        for(_ i = 1; i <= n; ++i) {
            bool ok = false;
            for(_ j = 1; j <= m; ++j) if(dp[i][j] < inf) ok = true;
            if(!ok) break;
            if(v[i]) ++s;
        }
        writeln(s);
    }
    
    return;
}
