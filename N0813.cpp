
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



constant maxn = 5E3+8;
constant maxe = 1E5+8;
constant big = 1E11;

_ n, m, s, t, head[maxn], lst[maxn], pre[maxn], d[maxn], x, y, z, zz, cnt = 1, mx, mn, fl[maxn], p, h[maxn];
struct edge {
    _ to, cost, dis, next;
} g[maxe];
bitset<maxn> v;
struct node {
    _ p, s;
    bool operator < (const node &b) const {
        return s > b.s;
    }
};
priority_queue<node> q;

bool dijkstra();
void addEdge(_ x, _ y, _ z, _ zz);
void AC() {

    n = read();
    m = read();
    t = n+1;
    s = n+2;
    for(_ i = 1; i <= n; ++i) {
        x = read();
        addEdge(i, i+1, big-x, 0);
        addEdge(i+1, i, 0, 0);
    }
    for(_ i = 1; i <= m; ++i) {
        x = read();
        y = read();
        z = read();
        addEdge(x, y+1, big, z);
        addEdge(y+1, x, 0, -z);
    }
    addEdge(s, 1, big, 0);
    addEdge(1, s, 0, 0);
    for(; dijkstra(); ) {
        mx += fl[t];
        mn += fl[t]*(d[t]-h[s]+h[t]);
        for(p = t; p != s; p = pre[p]) {
            g[lst[p]].cost -= fl[t];
            g[lst[p]^1].cost += fl[t];
        }
        for(_ i = 1; i <= n; ++i) h[i] += d[i];
    }
    writeln(mn);

    return;
}

void addEdge(_ x, _ y, _ z, _ zz) {
    g[++cnt].next = head[x];
    g[cnt].to = y;
    g[cnt].cost = z;
    g[cnt].dis = zz;
    head[x] = cnt;
    return;
}

bool dijkstra() {
    memset(d, 4, sizeof d);
    _ inf = d[0];
    memset(fl, 4, sizeof fl);
    v.reset();
    q.push((node){s, 0});
    d[s] = 0;
    for(; !q.empty(); ) {
        node t = q.top();
        q.pop();
        if(v[t.p]) continue;
        v.set(t.p);
        for(_ i = head[t.p]; i; i = g[i].next) if(g[i].cost > 0 && !v[g[i].to] && d[g[i].to] > d[t.p]+g[i].dis+h[t.p]-h[g[i].to]) {
            d[g[i].to] = d[t.p]+g[i].dis+h[t.p]-h[g[i].to];
            fl[g[i].to] = min(fl[t.p], g[i].cost);
            lst[g[i].to] = i;
            pre[g[i].to] = t.p;
            q.push((node){g[i].to, d[g[i].to]});
        }
    }
    return d[t] < inf;
}

