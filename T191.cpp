
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
typedef long double _D;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

char untl = '\n';

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

    str fileN = "";

    //#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    //#define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
#else
    _ tc = 1;
#endif
    
    for(; tc--; ) AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxn = 1E6+8;
constant mod = 1E9+7;

_ n, a[maxn], c, l[maxn], fc[maxn], iv[maxn], dp[maxn], sz[maxn];
char r[maxn];
vector<_> g[maxn];
bitset<maxn> rt;

void cards(_ x);
void distributing(_ x);
_ inv(_ x, _ p);
inline void AC() {

    n = read();
    for(_ i = 1; i <= n; ++i) r[i] = gc();
    for(_ i = 1; i <= n; ++i) {
        a[i] = read();
        if(r[i] == 'F') c += a[i];
        else --c;
    }
    if(c > 0) {
        puts("0");
        leave
    }
    fc[1] = iv[1] = 1;
    for(_ i = 2; i <= n; ++i) fc[i] = fc[i-1]*i%mod;
    for(_ i = 1; i <= n; ++i) iv[i] = inv(fc[i], mod-2);
    for(_ i = 1; i <= n; ++i) if(r[i] == 'F' && !l[i]) distributing(i);
    for(_ i = 1; i <= n; ++i) if(r[i] == 'F' && !rt[i]) g[0].push_back(i);
    cards(0);
    writeln(dp[0]);
    
    return;
}

_ inv(_ x, _ p) {
    if(!p) return 1;
    _ c = inv(x, p>>1);
    c = c*c%mod;
    if(p & 1) c = c*x%mod;
    return c;
}

void distributing(_ x) {
    if(l[x]) return;
    _ p = x%n+1, c = a[x];
    for(; c; ) if(r[p] == 'F') {
        g[x].push_back(p);
        rt.set(p);
        distributing(p);
        p = (p+l[p]-1)%n+1;
    } else {
        --c;
        p = p%n+1;
    }
    l[x] = (p-x+n)%n;
    return;
}

void cards(_ x) {
    dp[x] = 1;
    sz[x] = 1;
    if(!g[x].size()) return;
    for(_ i : g[x]) {
        cards(i);
        sz[x] += sz[i];
        dp[x] = dp[x]*dp[i]%mod;
        dp[x] = dp[x]*iv[sz[i]]%mod;
    }
    dp[x] = dp[x]*fc[sz[x]-1]%mod;
    return;
}




