
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

inline void AC();
int main(int argc, char * argv[]) {

    str fileN = "angrybirds";

    #define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    AC(); // good luck!

    return 0;
}



// ----- End of Template -----



const double smol = 5E-8;

constant maxn = 18+8;
constant top = 262144;

_ n, l[maxn][maxn], lb[top<<2], dp[top<<2];
struct coords {
    _D x, y;
} a[maxn];
_D x, y;

void parabola(_D x1, _D y1, _D x2, _D y2);
inline void AC() {
    
    for(_ i = 0; i < top; ++i) for(; lb[i] <= 18 && (i & (1<<lb[i])); ) ++lb[i];
    for(_ t = read(); t--; ) {
        memset(l, 0, sizeof l);
        memset(dp, 4, sizeof dp);
        dp[0] = 0;
        n = read();
        read();
        for(_ i = 1; i <= n; ++i) scanf("%Lf%Lf", &a[i].x, &a[i].y);
        for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) if(abs(a[i].x-a[j].x) > smol) {
            parabola(a[i].x, a[i].y, a[j].x, a[j].y);
            if(x > -smol) continue;
            for(_ k = 1; k <= n; ++k) if(abs(x*a[k].x*a[k].x+y*a[k].x-a[k].y) < smol) l[i][j] |= (1<<(k-1));
        }
        for(_ i = 0; i < (1<<n); ++i) {
            _ c = (1<<lb[i]);
            dp[i|c] = min(dp[i|c], dp[i]+1);
            for(_ k = 1; k <= n; ++k) dp[i|l[lb[i]+1][k]] = min(dp[i|l[lb[i]+1][k]], dp[i]+1);
        }
        writeln(dp[(1<<n)-1]);
    }
    
    return;
}

void parabola(_D x1, _D y1, _D x2, _D y2) {
    x = ((y1/x1)-(y2/x2))/(x1-x2);
    y = y1/x1-x*x1;
    return;
}
