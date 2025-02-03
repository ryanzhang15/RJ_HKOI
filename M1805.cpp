
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
#include <thread>
#include <chrono>

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



constant big = 2E3;
constant maxn = big+8;

_ n, m, x, t, f[maxn<<1][maxn], g[maxn<<1][maxn], s = 1E18;
bool a[maxn][maxn];

void AC() {
    
    n = read();
    m = read();
    x = read();
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) {
        t += (a[i][j] = (getDg() == '1'));
        f[i-j+big][j] += a[i][j];
        g[i+j][j] += a[i][j];
    }
    for(_ i = 1; i <= (big<<1); ++i) for(_ j = 1; j <= m; ++j) {
        f[i][j] += f[i][j-1];
        g[i][j] += g[i][j-1];
    }
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) if(i-x >= 1 && j-(x<<1) >= 1 && i+(x<<1) <= n && j+(x<<1) <= m) {
        _ o = 0;
        o += f[i-j+big][j]-f[i-j+big][j-x-1];
        o += f[i-(x<<1)-j+big][j+(x<<1)]-f[i-(x<<1)-j+big][j+x-1];
        o += f[i-j+(x<<1)+big][j]-f[i-j+(x<<1)+big][j-(x<<1)-1];
        o += g[i+j-(x<<1)][j-x-1]-g[i+j-(x<<1)][j-(x<<1)];
        o += g[i+j][j+x-1]-g[i+j][j];
        o += g[i+j+(x<<1)][j+(x<<1)-1]-g[i+j+(x<<1)][j];
        s = min(s, (x<<3)+t-(o<<1));
    }
    writeln(s);
    
    return;
}

/*
10 10 2
0010001000
0101010100
1000100010
0100000100
0010001000
0001010000
0000100000
0000000000
0000000000
0000000000
 */
