
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



constant maxn = 1E5+8;

_ n, m, x, y, cnt, head[maxn], dfn[maxn], low[maxn], c[maxn], cnum, dfc, sz[maxn], ed[maxn], vtx;
struct edge {
    _ from, to, next;
} g[maxn<<1];
set<_p> st;
bitset<maxn> v;
set<_> G[maxn];
stack<_> s;

void tarjan(_ x, _ fa);
void paint(_ x);
void dfs(_ x);
void addEdge(_ x, _ y);
void no();
void AC() {

    n = read();
    m = read();
    for(; m--; ) {
        x = read();
        y = read();
        if(x == y || st.count(make_pair(x, y))) no();
        st.insert(make_pair(x, y));
        st.insert(make_pair(y, x));
        addEdge(x, y);
        addEdge(y, x);
    }
    dfs(1);
    if(v.count() != n) no();
    v.reset();
    tarjan(1, -1);
    for(_ i = 1; i <= n; ++i) for(_ j = head[i]; j; j = g[j].next) if(c[i] != c[g[j].to]) {
        G[c[i]].insert(c[g[j].to]);
        G[c[g[j].to]].insert(c[i]);
    }
    for(_ i = 1; i <= cnt; i += 2) if(c[g[i].from] == c[g[i].to]) ++ed[c[g[i].from]];
    for(_ i = 1; i <= cnum; ++i) if(sz[i] > 1 && ed[i] != sz[i]) no();
    for(_ i = 1; i <= cnum; ++i) if(sz[i] == 1 && G[i].size() >= 3) {
        if(vtx) no();
        vtx = i;
    } ef(sz[i] > 1 && G[i].size() > 1) no();
    if(!vtx) no();
    for(_ i : G[vtx]) if(sz[i] > 1) no();
    writeln("Yes");
    
    return;
}

void no() {
    writeln("No");
    exit(0);
}

void addEdge(_ x, _ y) {
    g[++cnt].from = x;
    g[cnt].to = y;
    g[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void dfs(_ x) {
    v.set(x);
    for(_ i = head[x]; i; i = g[i].next) if(!v[g[i].to]) dfs(g[i].to);
    return;
}

void paint(_ x) {
    s.pop();
    c[x] = cnum;
    ++sz[cnum];
    v.reset(x);
    return;
}

void tarjan(_ x, _ fa) {
    dfn[x] = low[x] = ++dfc;
    s.push(x);
    v.set(x);
    for(_ i = head[x]; i; i = g[i].next) if(g[i].to != fa) {
        if(!dfn[g[i].to]) {
            tarjan(g[i].to, x);
            low[x] = min(low[x], low[g[i].to]);
        } else if(v[g[i].to]) low[x] = min(low[x], dfn[g[i].to]);
    }
    if(low[x] == dfn[x]) {
        ++cnum;
        for(; !s.empty() && s.top() != x; ) paint(s.top());
        paint(x);
    }
    return;
}
