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
    
    //#define file_IO
#ifdef file_IO
    str fileN = "";
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



constant maxn = 80+8;
constant maxk = 384+8;

v_ r, g, b;
_ a[maxn][maxn], o[maxn][maxn], c1[maxn*maxn][maxk], c2[maxn*maxn][maxk], c3[maxn*maxn][maxk], p[maxn*maxn][maxk][3], c[maxn*maxn][maxk][4], n, u, d, k, cnt;
bool v[maxn][maxn], v1[maxn][maxn], gd[maxn][maxn];

_ dv(_ x, _ y);
void fillTri(_ x, _ y, _ cl, _ c1, _ c2, _ c3);
void fillVec(_ x, _ y, _ cl);
inline void AC() {
    
    memset(p, 4, sizeof p);
    memset(c, 4, sizeof c);
    
    n = read();
    u = read();
    d = read();
    k = read();
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= i; ++j) a[i][j] = read();
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= i; ++j) if(!v[i][j]) {
        r.clear();
        g.clear();
        b.clear();
        fillVec(i, j, 1);
        if(r.empty() || b.empty() || g.empty()) {
            o[i][j] = a[i][j];
            continue;
        } else gd[i][j] = true;
        ++cnt;
        for(_ i = 1; i <= 384; ++i) {
            for(_ j : r) c1[cnt][i] += dv(j, i);
            for(_ j : g) c2[cnt][i] += dv(j, i);
            for(_ j : b) c3[cnt][i] += dv(j, i);
        }
        for(_ i = 1; i <= 384; ++i) for(_ j = 1; i+j <= 384; ++j) if(p[cnt][i+j][0] > c1[cnt][i]+c2[cnt][j]) {
            p[cnt][i+j][0] = c1[cnt][i]+c2[cnt][j];
            p[cnt][i+j][1] = i;
            p[cnt][i+j][2] = j;
        }
        for(_ i = 1; i <= 384; ++i) for(_ j = 1; i+j <= 384; ++j) if(c[cnt][i+j][0] > p[cnt][i][0]+c3[cnt][j]) {
            c[cnt][i+j][0] = p[cnt][i][0]+c3[cnt][j];
            c[cnt][i+j][1] = p[cnt][i][1];
            c[cnt][i+j][2] = p[cnt][i][2];
            c[cnt][i+j][3] = j;
        }
    }
    _ mn = 1E11, dx = -1;
    for(_ i = 1; i <= 384; ++i) {
        unsigned long long cr = 0;
        for(_ j = 1; j <= cnt; ++j) cr += c[j][i][0];
        if(cr < mn) {
            mn = cr;
            dx = i;
        }
    }
    cnt = 0;
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= i; ++j) if(gd[i][j]) {
        ++cnt;
        fillTri(i, j, 1, c[cnt][dx][1], c[cnt][dx][2], c[cnt][dx][3]);
    }
    writeln(mn);
    for(_ i = 1; i <= n; ++i, clr()) for(_ j = 1; j <= i; ++j) writesc(o[i][j]);
    
    return;
}

void fillVec(_ x, _ y, _ cl) {
    if(x > n || y > x || v[x][y]) return;
    v[x][y] = true;
    if(cl == 1) r.push_back(a[x][y]);
    ef(cl == 2) g.push_back(a[x][y]);
    else b.push_back(a[x][y]);
    if(cl == 1) {
        fillVec(x+k, y, 2);
        fillVec(x+k, y+k, 3);
    } ef(cl == 2) {
        fillVec(x+k, y, 3);
        fillVec(x+k, y+k, 1);
    } else {
        fillVec(x+k, y, 1);
        fillVec(x+k, y+k, 2);
    }
    return;
}

void fillTri(_ x, _ y, _ cl, _ c1, _ c2, _ c3) {
    if(x > n || y > x || v1[x][y]) return;
    v1[x][y] = true;
    if(cl == 1) o[x][y] = c1;
    ef(cl == 2) o[x][y] = c2;
    else o[x][y] = c3;
    if(cl == 1) {
        fillTri(x+k, y, 2, c1, c2, c3);
        fillTri(x+k, y+k, 3, c1, c2, c3);
    } ef(cl == 2) {
        fillTri(x+k, y, 3, c1, c2, c3);
        fillTri(x+k, y+k, 1, c1, c2, c3);
    } else {
        fillTri(x+k, y, 1, c1, c2, c3);
        fillTri(x+k, y+k, 2, c1, c2, c3);
    }
    return;
}

_ dv(_ x, _ y) {
    if(x == y) return 0;
    if(x > y) return (x-y)*d;
    return (y-x)*u;
}




