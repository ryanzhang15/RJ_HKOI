
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

inline void AC();
int main(int argc, char * argv[]) {
        
    #define file_IO
#ifdef file_IO
    str fileN = "treasure";
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    //#define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
    for(; tc--; ) AC(); // good luck!
#else
    AC(); // good luck!
#endif


    return 0;
}



// ----- End of Template -----



constant maxn = 20+8;

_ n, m, g[maxn][maxn], a[maxn], h[maxn], s = 1E11, x, y, z, per;
bitset<maxn> v;
_D sttemp, temp, stop, cool;

_ getT();
void anneal();
inline void AC() {
    
    /*
     Simulated Annealing Settings
     */
    
    sttemp = 6E3;
    per = 20;
    stop = 1E-11;
    cool = 0.995;
    
    /*
     end
     */
    
    srand((unsigned)time(NULL));
    
    memset(g, 4, sizeof g);
    
    n = read();
    if(n == 1) {
        writeln("0");
        leave
    }
    m = read();
    for(_ i = 1; i <= n; ++i) a[i] = i;
    
    for(; m--; ) {
        x = read();
        y = read();
        z = read();
        g[x][y] = g[y][x] = min(g[x][y], z);
    }
    for(; per--; ) anneal();
    writeln(s);
    
    return;
}

void anneal() {
    temp = sttemp;
    _ cb = 1E11;
    for(; temp >= stop; temp *= cool) {
        _ x = rand()%n+1, y = rand()%n+1;
        for(; x == y; ) {
            x = rand()%n+1;
            y = rand()%n+1;
        }
        swap(a[x], a[y]);
        _ t = getT();
        bool ok = false;
        if(t < cb) {
            ok = true;
            cb = t;
            if(t < s) s = t;
        } else {
            double delt = cb-t;
            if(exp(-delt/temp) > 1.L*rand()/RAND_MAX) ok = true;
        }
        if(ok) cb = t;
        else swap(a[x], a[y]);
    }
}

_ getT() {
    _ rv = 0;
    for(_ i = 1; i <= n; ++i) h[i] = 1;
    v.reset();
    v.set(a[1]);
    for(_ i = 2; i <= n; ++i) {
        _ cr = 1E11, dx = 0;
        for(_ j = 1; j <= n; ++j) if(v[j]) {
            if(h[j]*g[a[i]][j] < cr) {
                cr = h[j]*g[a[i]][j];
                dx = j;
            }
        }
        v.set(a[i]);
        h[a[i]] = h[dx]+1;
        rv += cr;
    }
    return rv;
}
