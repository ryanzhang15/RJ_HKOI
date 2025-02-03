
/*
 they told me to cite my code so
 
 EVERYTHING WAS WRITTEN BY ME heheh
 
 sorry for ugly coding style
 deal with it
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



constant big = 1E3+1;
constant maxn = big+1;
_ n, m, q, t, cnt, a[maxn][maxn], h[maxn*maxn], f[maxn*maxn][2], p[maxn*maxn], x, y;

inline _ encode(_ x, _ y);
void AC() {
    
    n = read();
    m = read();
    q = read();
    t = min(read(), n*m);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) a[i][j] = read();
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) {
        if(a[i][j] > a[i-1][j] && a[i][j] > a[i+1][j] && a[i][j] > a[i][j-1] && a[i][j] > a[i][j+1]) f[encode(i, j)][0] = encode(i, j);
        ef(a[i-1][j] > a[i+1][j] && a[i-1][j] > a[i][j-1] && a[i-1][j] > a[i][j+1]) f[encode(i, j)][0] = encode(i-1, j);
        ef(a[i+1][j] > a[i-1][j] && a[i+1][j] > a[i][j-1] && a[i+1][j] > a[i][j+1]) f[encode(i, j)][0] = encode(i+1, j);
        ef(a[i][j-1] > a[i-1][j] && a[i][j-1] > a[i+1][j] && a[i][j-1] > a[i][j+1]) f[encode(i, j)][0] = encode(i, j-1);
        ef(a[i][j+1] > a[i-1][j] && a[i][j+1] > a[i+1][j] && a[i][j+1] > a[i][j-1]) f[encode(i, j)][0] = encode(i, j+1);
    }
    for(_ i = 1; i <= q; ++i) {
        x = read();
        y = read();
        p[i] = encode(x, y);
    }
    for(_ i = 0; i <= 20; ++i) {
        if(t & (1<<i)) for(_ i = 1; i <= q; ++i) p[i] = f[p[i]][0];
        for(_ j = 1; j <= n; ++j) for(_ k = 1; k <= m; ++k) f[encode(j, k)][1] = f[f[encode(j, k)][0]][0];
        for(_ j = 1; j <= n; ++j) for(_ k = 1; k <= m; ++k) f[encode(j, k)][0] = f[encode(j, k)][1];
    }
    for(_ i = 1; i <= q; ++i) {
        writesc(p[i]/big);
        writeln(p[i]%big);
    }
    
    return;
}

inline _ encode(_ x, _ y) {
    return x*big+y;
}


/*
5 5 300 3
1    198  2    3    4
199  55   6    7    8880
9    10   11   12   13
144  15   16   177  18
149  200  201  222  2522
*/
