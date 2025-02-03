
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

#define v(x) vector<x >
#define v2(x) vector<vector<x > >
#define v3(x) vector<vector<vector<x > > >

#define ss(x) v(_)(x+8, 0)
#define ssz(type, x) v(type)(x+8, 0)
#define s2(x, y) v2(_)(x+8, v(_)(y+8, 0))
#define s2z(type, x, y) v2(type)(x+8, v(type)(y+8, 0))
#define s3(x, y, z) v3(_)(x+8, v2(_)(y+8, v(_)(z+8, 0)))
#define s3z(type, x, y, z) v3(type)(x+8, v2(type)(y+8, v(type)(z+8, 0)))

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef long double _D;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
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
constant maxn = (1<<20)+8;
constant big = 123;
char a[maxn];
_ b[maxn], p[maxn];
int n, t[maxn][27], tg[27], c[maxn], d[maxn], cr;
inline void AC();
int main(int argc, char * argv[]) {
        
    str fileN = "string";

    #define file_IO
#ifdef file_IO
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    #define multiple_testcases
#ifdef multiple_testcases
    p[0] = 1;
    for(register _ i = 1; i <= maxn-8; ++i) p[i] = p[i-1]*big;
    _ tc = read();
    for(; tc--; ) AC(); // good luck!
#else
    AC(); // good luck!
#endif


    return 0;
}



// ----- End of Template -----




inline _ hsh(_ l, _ r);
inline void AC() {
    
    for(_ i = 0; i < 26; ++i) tg[i] = 0;
    n = 0;
    for(char ch = getchar(); ch >= 'a' && ch <= 'z'; ch = getchar()) a[++n] = ch;
    cr = 0;
    for(register _ i = 1; i <= n; ++i) {
        if(++tg[a[i]-'a'] & 1) ++cr;
        else --cr;
        c[i] = cr;
    }
    for(_ i = 1; i <= n; ++i) {
        for(_ j = 0; j <= 26; ++j) t[i][j] = t[i-1][j];
        for(_ j = c[i]; j <= 26; ++j) ++t[i][j];
    }
    for(_ i = 0; i < 26; ++i) tg[i] = 0;
    cr = 0;
    for(register _ i = n; i >= 1; --i) {
        if(++tg[a[i]-'a'] & 1) ++cr;
        else --cr;
        d[i] = cr;
    }
    register _ rl = big;
    for(register _ i = 1; i <= n; ++i, rl *= big) b[i] = (a[i]-'a')*rl+b[i-1];
    _ s = 0;
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j*i <= n; ++j) {
        _ l = (j-1)*i+1, r = j*i;
        if(r >= n || hsh(1, i) != hsh(l, r)) break;
        s += t[i-1][d[r+1]];
    }
    writeln(s);
    
    return;
}

inline _ hsh(_ l, _ r) {
    return p[n-l+1]*(b[r]-b[l-1]);
}


