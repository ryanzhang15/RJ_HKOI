
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



constant maxn = 2E5+8;

_ a[maxn], b[maxn], d[maxn], p[maxn], f[maxn], g[maxn], n, m, l, r, md, s, cnt;
struct swp {
    _ x, y;
} c[maxn*3], o[maxn*3];

bool check();
void AC() {
    
    n = read();
    for(_ i = 1; i <= n; ++i) a[i] = read()+1;
    m = read();
    for(_ i = 1; i <= m; ++i) {
        c[i].x = read()+1;
        c[i].y = read()+1;
    }
    r = m;
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(check()) {
            s = md;
            r = md-1;
        } else l = md+1;
    }
    md = s;
    check();
    writeln(cnt);
    for(_ i = 1; i <= cnt; ++i) {
        if(o[i].x > o[i].y) swap(o[i].x, o[i].y);
        writesc(o[i].x);
        writeln(o[i].y);
    }
    
    return;
}

bool check() {
    for(_ i = 1; i <= n; ++i) d[i] = i;
    for(_ i = 1; i <= md; ++i) swap(d[c[i].x], d[c[i].y]);
    for(_ i = 1; i <= n; ++i) p[a[i]] = i;
    for(_ i = 1; i <= n; ++i) f[i] = a[i];
    for(_ i = 1; i <= n; ++i) b[i] = i;
    for(_ i = 1; i <= n; ++i) g[i] = i;
    _ cr = 1;
    cnt = 0;
    for(; cr <= n && p[cr] == b[d[cr]]; ) ++cr;
    for(_ i = 1; i <= md; ++i) {
        swap(b[g[c[i].x]], b[g[c[i].y]]);
        swap(p[f[c[i].x]], p[f[c[i].y]]);
        swap(f[c[i].x], f[c[i].y]);
        swap(g[c[i].x], g[c[i].y]);
        if(cr > n) o[++cnt] = (swp){0, 0};
        else {
            _ sv = f[b[d[cr]]];
            swap(f[p[cr]], f[b[d[cr]]]);
            o[++cnt] = (swp){p[cr]-1, p[sv]-1};
            swap(p[cr], p[sv]);
            for(; cr <= n && p[cr] == b[d[cr]]; ) ++cr;
        }
    }
    
    return cr > n;
}
