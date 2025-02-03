
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



constant maxn = 1E4+8;

_ t[maxn][130], d, n, v[maxn], cnt, e[maxn], f[maxn];
vector<_> g[maxn];
char ch;
queue<_> p;
struct node {
    _ p, c, s;
};
queue<node> q;

void dfs(_ x);
void make();
void AC() {
    
    memset(v, ~0, sizeof v);
    d = read();
    n = read();
    for(_ i = 1; i <= n; ++i) make();
    p.push(0);
    for(; !p.empty(); p.pop()) for(_ i = 'A'; i <= 'z'; i = i == 'Z' ? 'a' : i+1) if(t[p.front()][i]) {
        p.push(t[p.front()][i]);
        if(p.front()) f[t[p.front()][i]] = t[f[p.front()]][i];
    } else t[p.front()][i] = t[f[p.front()]][i];
    for(_ i = 1; i <= cnt; ++i) g[f[i]].push_back(i);
    dfs(0);
    q.push((node){0, 0, 0});
    for(; ; q.pop()) {
        node u = q.front();
        if(v[u.p] > u.c) continue;
        for(_ i = 'A'; i <= 'z'; i = i == 'Z' ? 'a' : i+1) {
            _ to = t[u.p][i];
            if(!to || v[to] >= u.c+e[to]) continue;
            if(u.c+e[to] >= d) {
                writeln(u.s+1);
                leave
            }
            v[to] = u.c+e[to];
            q.push((node){to, u.c+e[to], u.s+1});
        }
    }
    
    return;
}

void make() {
    for(ch = getchar_unlocked(); !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ) ch = getchar_unlocked();
    _ p = 0;
    for(; (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); ch = getchar_unlocked()) {
        if(!t[p][ch]) t[p][ch] = ++cnt;
        p = t[p][ch];
    }
    ++e[p];
    return;
}

void dfs(_ x) {
    for(_ i : g[x]) {
        e[i] += e[x];
        dfs(i);
    }
    return;
}
