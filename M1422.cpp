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



constant maxn = 4E5+8;
_ n, m, a[maxn], h[maxn], tr[maxn], x, y, z, cnt, st[maxn], ed[maxn];
bool isS[maxn];
struct segtree {
    _ n, t[maxn<<2], lz[maxn<<2], m;
    void init(_ x, _ y) {
        n = x;
        m = y;
        return;
    }
    void pushUp(_ pos) {
        t[pos] = t[pos<<1] + t[pos<<1|1];
        return;
    }
    void build(_ l, _ r, _ pos) {
        if(l == r) {
            t[pos] = (h[tr[l]] & 1) == m && isS[l] ? a[tr[l]] : 0;
            return;
        }
        _ md = (l+r)>>1;
        build(l, md, pos<<1);
        build(md+1, r, pos<<1|1);
        pushUp(pos);
        return;
    }
    void pushDown(_ pos, _ ls, _ rs) {
        lz[pos<<1] += lz[pos];
        lz[pos<<1|1] += lz[pos];
        t[pos<<1] += lz[pos]*ls;
        t[pos<<1|1] += lz[pos]*rs;
        lz[pos] = 0;
        return;
    }
    void update(_ L, _ R, _ c, _ l, _ r, _ pos) {
        if(L <= l && r <= R) {
            t[pos] += c * (l-r+1);
            lz[pos] += c;
            return;
        }
        _ md = (l+r)>>1;
        if(lz[pos]) pushDown(pos, md-l+1, r-md);
        if(L <= md) update(L, R, c, l, md, pos<<1);
        if(R > md) update(L, R, c, md+1, r, pos<<1|1);
        pushUp(pos);
        return;
    }
    _ query(_ p, _ l, _ r, _ pos) {
        if(l == p && r == p) return t[pos];
        _ md = (l+r)>>1;
        if(lz[pos]) pushDown(pos, md-l+1, r-md);
        if(p <= md) return query(p, l, md, pos<<1);
        else return query(p, md+1, r, pos<<1|1);
    }
} e, o;
vector<_> g[maxn];

void dfs(_ x, _ fa);
void AC() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(_ i = 1; i <= n-1; ++i) {
        x = read();
        y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    e.init(cnt, 0);
    o.init(cnt, 1);
    e.build(1, cnt, 1);
    o.build(1, cnt, 1);
    for(; m--; ) {
        x = read();
        y = read();
        if(x == 1) {
            z = read();
            if(h[y] & 1) {
                o.update(st[y], ed[y], z, 1, cnt, 1);
                e.update(st[y], ed[y], -z, 1, cnt, 1);
            } else {
                e.update(st[y], ed[y], z, 1, cnt, 1);
                o.update(st[y], ed[y], -z, 1, cnt, 1);
            }
        } else writeln((h[y] & 1) ? o.query(st[y], 1, cnt, 1) : e.query(st[y], 1, cnt, 1));
    }
    
    return;
}

void dfs(_ x, _ fa) {
    tr[++cnt] = x;
    isS[cnt] = true;
    st[x] = cnt;
    h[x] = h[fa]+1;
    for(_ i : g[x]) if(i != fa) dfs(i, x);
    tr[++cnt] = x;
    ed[x] = cnt;
    return;
}
