
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



constant maxn = 40+8;
constant maxs = 1E2+8;
constant maxl = 10+8;

_ n, x, k, t[maxn], d[maxs][maxn][maxl][maxl], s = 1E18;
struct ticket {
    _ c;
    vector<_> p;
} a[maxn];
vector<_> g[maxs], o;
bool v[maxs][maxn][maxl][maxl], b[maxs][maxn][maxl][maxl];
struct node {
    _ c, t, l, p;
    bool operator == (const node &b) const {
        return c == b.c && t == b.t && l == b.l && p == b.p;
    }
} p[maxs][maxn][maxl][maxl], dx;
queue<node> q;

void out(node c);
void AC() {
    
    memset(d, 4, sizeof d);
    
    n = read();
    read();
    for(_ i = 1; i <= n; ++i) {
        a[i].c = read();
        k = read();
        for(; k--; ) {
            x = read();
            a[i].p.push_back(x);
        }
        g[a[i].p[0]].push_back(i);
    }
    k = read();
    for(_ i = 1; i <= k; ++i) t[i] = read();
    q.push((node){t[1], 0, 0, 1});
    d[t[1]][0][0][1] = 0;
    for(; !q.empty(); q.pop()) {
        node c = q.front();
        v[c.c][c.t][c.l][c.p] = false;
        if(c.t && c.l != a[c.t].p.size()-1 && d[a[c.t].p[c.l+1]][c.t][c.l+1][c.p+(a[c.t].p[c.l+1]==t[c.p+1])] > d[c.c][c.t][c.l][c.p]) {
            d[a[c.t].p[c.l+1]][c.t][c.l+1][c.p+(a[c.t].p[c.l+1]==t[c.p+1])] = d[c.c][c.t][c.l][c.p];
            p[a[c.t].p[c.l+1]][c.t][c.l+1][c.p+(a[c.t].p[c.l+1]==t[c.p+1])] = (node){c.c, c.t, c.l, c.p};
            b[a[c.t].p[c.l+1]][c.t][c.l+1][c.p+(a[c.t].p[c.l+1]==t[c.p+1])] = false;
            if(c.p+(a[c.t].p[c.l+1]==t[c.p+1]) == k) {
                if(d[a[c.t].p[c.l+1]][c.t][c.l+1][c.p+(a[c.t].p[c.l+1]==t[c.p+1])] < s) {
                    s = d[a[c.t].p[c.l+1]][c.t][c.l+1][c.p+(a[c.t].p[c.l+1]==t[c.p+1])];
                    dx = (node){a[c.t].p[c.l+1], c.t, c.l+1, c.p+(a[c.t].p[c.l+1]==t[c.p+1])};
                }
            } ef(!v[a[c.t].p[c.l+1]][c.t][c.l+1][c.p+(a[c.t].p[c.l+1]==t[c.p+1])]) {
                v[a[c.t].p[c.l+1]][c.t][c.l+1][c.p+(a[c.t].p[c.l+1]==t[c.p+1])] = true;
                q.push((node){a[c.t].p[c.l+1], c.t, c.l+1, c.p+(a[c.t].p[c.l+1]==t[c.p+1])});
            }
        }
        for(_ i : g[c.c]) if(d[c.c][i][0][c.p] > d[c.c][c.t][c.l][c.p]+a[i].c) {
            d[c.c][i][0][c.p] = d[c.c][c.t][c.l][c.p]+a[i].c;
            p[c.c][i][0][c.p] = (node){c.c, c.t, c.l, c.p};
            b[c.c][i][0][c.p] = true;
            if(!v[c.c][i][0][c.p]) {
                v[c.c][i][0][c.p] = true;
                q.push((node){c.c, i, 0, c.p});
            }
        }
    }
    writeln(s);
    out(dx);
    for(_ i : o) writesc(i);
    clr();
    
    return;
}

void out(node c) {
    if(c == (node){t[1], 0, 0, 1}) return;
    out(p[c.c][c.t][c.l][c.p]);
    if(b[c.c][c.t][c.l][c.p]) o.push_back(c.t);
    return;
}
/*
3 4
300 3 1 3 4
200 2 1 2
30 2 2 3
2 1 3
 */
