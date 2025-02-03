
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



constant maxn = 2E4+8;

_ n, a[maxn], dp[maxn>>1][2][2], p[maxn>>1][2][2], s = 1E18, ci, cj;
str in;

void o(_ x, _ i, _ j);
void dec(str x);
void AC() {
    
    /*
80
01010011011101000110010101110000011010000110010101101110111111110100100001101111
00000011011001000110011100111000011010100111110101111110111101100100100001100111
    */
    
//    writeln("13\n0001110111000111111100110010011101011100");
//    leave
    
//    dec("1101011001");
//    leave
    
    memset(dp, 4, sizeof dp);
    
    n = read();
    for(_ i = 1; i <= n; ++i) a[i+1] = getDg()^48;
    dp[0][0][0] = 0;
    for(_ i = 1; i <= n>>1; ++i) for(_ j = 0; j <= 1; ++j) for(_ k = 0; k <= 1; ++k) for(_ l = 0; l <= 1; ++l) if(dp[i][l][k] > dp[i-1][k][j]+((l^k^j) != a[i<<1])+((j^l) != a[i<<1|1])) {
        dp[i][l][k] = dp[i-1][k][j]+((l^k^j) != a[i<<1])+((j^l) != a[i<<1|1]);
        p[i][l][k] = j;
    }
    for(_ i = 0; i <= 1; ++i) for(_ j = 0; j <= 1; ++j) if(dp[n>>1][i][j] < s) {
        s = dp[n>>1][i][j];
        ci = i;
        cj = j;
    }
    writeln(s);
    o(n>>1, ci, cj);
    clr();
    
    return;
}

void dec(str x) {
    writeln(x.size()<<1);
    _ mj_2 = 0, mj_1 = 0;
    for(char i : x) {
        i ^= 48;
        write(i^mj_1^mj_2);
        write(i^mj_2);
        mj_2 = mj_1;
        mj_1 = i;
    }
    clr();
    return;
}

void o(_ x, _ i, _ j) {
    if(x < 1) return;
    o(x-1, j, p[x][i][j]);
    write(i);
    return;
}
