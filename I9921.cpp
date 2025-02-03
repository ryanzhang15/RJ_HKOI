
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



constant maxn = 3E2+8;

_ n, m, st, ed, c[maxn], b[maxn], p[maxn], x, y, z, d[maxn], s[maxn], cnt;
char ch;
struct edge {
    _ to, cost;
};
vector<edge> g[maxn];
queue<_> q;
bitset<maxn> v;

void o(_ x);
void AC() {
    
    st = read();
    ed = read();
    n = read();
    for(_ i = 1; i <= n; ++i) d[i] = 100000;
    m = read();
    for(_ i = 1; i <= n; ++i) {
        ch = getUp();
        c[i] = read();
        b[i] = read();
        p[i] = read();
        if(ch == 'B') c[i] = b[i]-c[i];
        else c[i] = b[i]+p[i]-c[i];
    }
    for(; m--; ) {
        x = read();
        y = read();
        z = read();
        g[x].push_back((edge){y, z});
        g[y].push_back((edge){x, z});
    }
    q.push(st);
    d[st] = 0;
    for(; !q.empty(); q.pop()) {
        _ t = q.front();
        v.reset(t);
        for(edge i : g[t]) {
            x = 0;
            for(; d[i.to] > d[t] + x + i.cost; ) {
                y = (d[t]+c[t]+x) % (b[t]+p[t]);
                z = (d[t]+c[i.to]+x) % (b[i.to]+p[i.to]);
                if((y < b[t] && z < b[i.to]) || (y >= b[t] && z >= b[i.to])) break;
                else x += min(y < b[t] ? b[t]-y : b[t]+p[t]-y, z < b[i.to] ? b[i.to]-z : b[i.to]+p[i.to]-z);
            }
            if(d[i.to] > d[t] + x + i.cost) {
                d[i.to] = d[t] + x + i.cost;
                s[i.to] = t;
                if(!v[i.to]) {
                    v.set(i.to);
                    q.push(i.to);
                }
            }
        }
    }
    if(d[ed] > 1E4) writeln("0");
    else {
        writeln(d[ed]);
        o(ed);
        clr();
    }
    
    return;
}

void o(_ x) {
    if(x != st) o(s[x]);
    writesc(x);
    return;
}
