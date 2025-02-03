
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
    
    AC();
    
    return 0;
}



// ----- End of Template -----



constant maxn = 2E5+8;

_ n, m, a[maxn], b[maxn], f[maxn], sz[maxn], lf[maxn], d[maxn], mx, dx, o[maxn], p = 1, sm, cnt, x, y;
struct query {
    _ l, r, id;
    bool operator < (const query &b) const {
        return r-l < b.r-b.l;
    }
} q[maxn>>1];

_ find(_ x);
bool cmp(_ x, _ y);
void AC() {
    
    n = read();
    for(_ i = 1; i <= n; ++i) a[i] = a[i+n] = read();
    for(_ i = 1; i <= n; ++i) b[i] = b[i+n] = read();
    for(_ i = 1; i <= n; ++i) sm += a[i];
    d[1] = lf[1] = f[1] = 1;
    sz[1] = a[1];
    for(_ i = 2; i <= n<<1; ++i) {
        lf[i] = lf[i-1]+a[i-1];
        d[i] = f[i] = i;
        sz[i] = a[i];
    }
    sort(d+1, d+1+(n<<1), cmp);
    m = read();
    for(_ i = 1; i <= m; ++i) {
        x = read();
        y = read();
        if(y-x+1 >= sm) o[i] = 1;
        else {
            q[++cnt].l = x;
            q[cnt].r = y;
            q[cnt].id = i;
        }
    }
    sort(q+1, q+1+cnt);
    for(_ i = 1; i <= n<<1; ++i) {
        if(d[i] != 1) {
            _ tx = find(d[i]-1), ty = find(d[i]);
            if(tx != ty && b[tx] <= b[ty]) {
                f[tx] = ty;
                sz[ty] += sz[tx];
                lf[ty] = lf[tx];
                b[ty] = max(b[ty], b[tx]);
            }
        }
        if(d[i] != n<<1) {
            _ tx = find(d[i]+1), ty = find(d[i]);
            if(tx != ty && b[tx] <= b[ty]) {
                f[tx] = ty;
                sz[ty] += sz[tx];
                b[ty] = max(b[ty], b[tx]);
            }
        }
        if(sz[find(d[i])] > mx) {
            mx = sz[find(d[i])];
            dx = lf[find(d[i])];
        }
        for(; p <= cnt && q[p].r-q[p].l+1 <= mx; ++p) {
            o[q[p].id] = ((dx-q[p].l)%sm+sm)%sm;
            if(!o[q[p].id]) o[q[p].id] = sm;
        }
    }
    for(_ i = 1; i <= m; ++i) writeln(o[i]);
    
    return;
}

bool cmp(_ x, _ y) {
    return b[x] < b[y];
}

_ find(_ x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
