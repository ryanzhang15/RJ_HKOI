
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

const char untl = '\n';

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

inline bool gc(char &a) {
    char ch = getchar_unlocked();
    if(ch == '\r') ch = getchar_unlocked();
    if(ch == untl || ch == EOF) a = '\0';
    else a = ch;
    return ch != untl && ch != EOF;
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

    AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxn = 2E5+8;
constant maxlog = 17+8;

_ n, m, x, y, z, dp[3][maxn], fr[3][maxn], h[maxn], lg2[maxn], f[maxn][maxlog], d[maxn][maxlog], cx, cy, dst[maxn], sd[maxn];
struct edge {
    _ to, cost;
};
vector<edge> g[maxn];
queue<_> q;

_ reform(_ x, _ y);
_ lca(_ x, _ y);
void bfs();
void dfs(_ x, _ fa);
void city(_ x, _ fa);
inline void AC() {
    
    n = read();
    for(_ i = 2; i <= n; ++i) lg2 [i] = lg2[i>>1]+1;
    m = read();
    for(_ i = n; --i; ) {
        x = read();
        y = read();
        z = read();
        g[x].push_back((edge){y, z});
        g[y].push_back((edge){x, z});
    }
    city(1, -1);
    dfs(1, -1);
    bfs();
    for(; m--; ) {
        x = read();
        y = read();
        writeln(reform(x, y));
    }
    
    return;
}

void city(_ x, _ fa) {
    for(edge i : g[x]) if(i.to != fa) {
        dst[i.to] = dst[x] + i.cost;
        city(i.to, x);
        _ d = dp[0][i.to]+i.cost;
        if(d >= dp[0][x]) {
            dp[2][x] = dp[1][x];
            dp[1][x] = dp[0][x];
            fr[2][x] = fr[1][x];
            fr[1][x] = fr[0][x];
            dp[0][x] = d;
            fr[0][x] = i.to;
        } ef(d >= dp[1][x]) {
            dp[2][x] = dp[1][x];
            fr[2][x] = fr[1][x];
            dp[1][x] = d;
            fr[1][x] = i.to;
        } ef(d > dp[2][x]) {
            dp[2][x] = d;
            fr[2][x] = i.to;
        }
    }
    for(edge i : g[x]) if(i.to != fa) d[i.to][0] = fr[0][x] == i.to ? dp[1][x] : dp[0][x];
    return;
}

void dfs(_ x, _ fa) {
    for(edge i : g[x]) if(i.to != fa) {
        sd[i.to] = max(sd[x], fr[0][x] == i.to ? dp[1][x] : dp[0][x])+i.cost;
        dfs(i.to, x);
    }
    return;
}

void bfs() {
    q.push(1);
    for(; !q.empty(); q.pop()) for(edge i : g[q.front()]) {
        if(i.to == f[q.front()][0]) continue;
        h[i.to] = h[q.front()]+1;
        f[i.to][0] = q.front();
        for(_ j = 1; j <= lg2[h[i.to]]; ++j) {
            f[i.to][j] = f[f[i.to][j-1]][j-1];
            d[i.to][j] = max(d[i.to][j-1], d[f[i.to][j-1]][j-1]);
        }
        q.push(i.to);
    }
    return;
}

_ lca(_ x, _ y) {
    if(h[x] < h[y]) swap(x, y);
    _ sv = x;
    for(; h[x] != h[y]; ) x = f[x][lg2[h[x]-h[y]]];
    if(x == y) {
        _ rv = x;
        x = sv;
        for(_ k = lg2[h[x]]; k >= 0; --k) if(h[f[x][k]] > h[y]) x = f[x][k];
        cx = x;
        cy = -1;
        return rv;
    }
    for(_ k = lg2[h[x]]; k >= 0; --k) if(f[x][k] != f[y][k]) {
        x = f[x][k];
        y = f[y][k];
    }
    cx = x;
    cy = y;
    return f[x][0];
}

_ reform(_ x, _ y) {
    _ l = lca(x, y), rv = 0;
    if(fr[0][l] != cx && fr[0][l] != cy) rv = max(rv, dp[0][l]);
    ef(fr[1][l] != cx && fr[1][l] != cy) rv = max(rv, dp[1][l]);
    else rv = max(rv, dp[2][l]);
    if(l != x) rv = max(rv, dp[0][x]);
    if(l != y) rv = max(rv, dp[0][y]);
    if(l != 1) rv = max(rv, sd[l]);
    for(_ k = lg2[h[x]]; k >= 0; --k) if(h[f[x][k]] >= h[l]+1) {
        rv = max(rv, d[x][k]);
        x = f[x][k];
    }
    for(_ k = lg2[h[y]]; k >= 0; --k) if(h[f[y][k]] >= h[l]+1) {
        rv = max(rv, d[y][k]);
        y = f[y][k];
    }
    return rv;
}
 

