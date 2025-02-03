
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
typedef long double _D;
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

inline void AC();
int main(int argc, char * argv[]) {

    str fileN = "park";

    #define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxn = 1E5+8;
constant maxk = 50+8;

_ n, m, k, p, x, y, z, d[maxn], dp[maxn][maxk], s, r;
struct edge {
    _ to, cost;
};
vector<edge> g[maxn], h[maxn];
bitset<maxn> v[maxk];
queue<_> q;

_ park(_ x, _ r);
inline void AC() {
        
    for(_ t = read(); t--; ) {
        n = read();
        m = read();
        k = read();
        p = read();
        memset(d, 4, sizeof d);
        memset(dp, ~0, sizeof dp);
        for(_ i = 1; i <= n; ++i) {
            g[i].clear();
            h[i].clear();
        }
        for(; m--; ) {
            x = read();
            y = read();
            z = read();
            g[x].push_back((edge){y, z});
            h[y].push_back((edge){x, z});
        }
        q.push(1);
        d[1] = 0;
        for(; !q.empty(); q.pop()) {
            _ t = q.front();
            v[0].reset(t);
            for(edge i : g[t]) if(d[i.to] > d[t]+i.cost) {
                d[i.to] = d[t]+i.cost;
                if(!v[0][i.to]) {
                    v[0].set(i.to);
                    q.push(i.to);
                }
            }
        }
        s = 0;
        for(_ i = 0; i <= k; ++i) {
            x = park(n, i);
            if(!~x) {
                s = -1;
                break;
            }
            s = (s+x)%p;
        }
        writeln(s);
    }
    
    return;
}

_ park(_ x, _ r) {
    if(r < 0) return 0;
    if(v[r][x]) return -1;
    if(~dp[x][r]) return dp[x][r];
    v[r].set(x);
    _ rv = 0;
    for(edge i : h[x]) {
        _ cr = park(i.to, d[x]-d[i.to]-i.cost+r);
        if(!~cr) {
            v[r].reset(x);
            return cr;
        }
        rv = (rv+cr)%p;
    }
    if(x == 1 && !r) ++rv;
    v[r].reset(x);
    return dp[x][r] = rv;
}
