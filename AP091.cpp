
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



constant maxn = 15E2+8;

_ n, m, k, p[maxn][maxn], br[maxn][maxn], bl[maxn][maxn], tr[maxn][maxn], tl[maxn][maxn], r[maxn], c[maxn], s;

void AC() {
    
    n = read();
    m = read();
    k = read();
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) p[i][j] = read();
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) p[i][j] += p[i][j-1];
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) p[i][j] += p[i-1][j];
    for(_ i = k; i <= n; ++i) for(_ j = k; j <= m; ++j) br[i][j] = max(max(br[i-1][j], br[i][j-1]), p[i][j]-p[i-k][j]-p[i][j-k]+p[i-k][j-k]);
    for(_ i = k; i <= n; ++i) for(_ j = m-k+1; j >= 1; --j) bl[i][j] = max(max(bl[i-1][j], bl[i][j+1]), p[i][j+k-1]-p[i][j-1]-p[i-k][j+k-1]+p[i-k][j-1]);
    for(_ i = n-k+1; i >= 1; --i) for(_ j = k; j <= m; ++j) tr[i][j] = max(max(tr[i+1][j], tr[i][j-1]), p[i+k-1][j]-p[i-1][j]-p[i+k-1][j-k]+p[i-1][j-k]);
    for(_ i = n-k+1; i >= 1; --i) for(_ j = m-k+1; j >= 1; --j) tl[i][j] = max(max(tl[i+1][j], tl[i][j+1]), p[i+k-1][j+k-1]-p[i-1][j+k-1]-p[i+k-1][j-1]+p[i-1][j-1]);
    for(_ i = k; i <= n; ++i) for(_ j = k; j <= m; ++j) {
        r[i] = max(r[i], p[i][j]-p[i-k][j]-p[i][j-k]+p[i-k][j-k]);
        c[j] = max(c[j], p[i][j]-p[i-k][j]-p[i][j-k]+p[i-k][j-k]);
    }
    {
        _ mx = 0;
        for(_ i = k; i <= n; ++i) {
            mx = max(mx, r[i]);
            _ mx2 = 0;
            for(_ j = i+k; j+k <= n; ++j) {
                mx2 = max(mx2, r[j]);
                s = max(s, mx+mx2+tl[j+1][1]);
            }
        }
    }
    {
        _ mx = 0;
        for(_ i = k; i <= m; ++i) {
            mx = max(mx, c[i]);
            _ mx2 = 0;
            for(_ j = i+k; j+k <= m; ++j) {
                mx2 = max(mx2, c[j]);
                s = max(s, mx+mx2+tl[1][j+1]);
            }
        }
    }
    for(_ i = k; i+k <= n; ++i) for(_ j = k; j+k <= m; ++j) s = max(s, max(max(br[i][j]+bl[i][j+1]+tl[i+1][1], bl[i][j+1]+tl[i+1][j+1]+tr[1][j]), max(bl[i][1]+tr[i+1][j]+tl[i+1][j+1], tl[1][j+1]+br[i][j]+tr[i+1][j])));
    writeln(s);
    return;
}

