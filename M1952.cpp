
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

    str fileN = "rap";

    #define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxm = 1E5+8;
constant big = 5E8+1;

struct input {
    _ a, ox, oy, x, y, d;
} a[maxm];
_ n = 2E9, m, x, y, dx[maxm], dy[maxm], xc, yc;
int rt, cnt, bnt;
map<_p, _> sc;
map<_, _, greater<_> > st[4];
struct bignode {
    int ls, rs, rt;
} t[maxm*17];
struct node {
    int ls, rs;
    _ dt;
} s[maxm*290];

inline _ queryBig(_ XL, _ XR, _ YL, _ YR, _ l, _ r, _ pos);
inline _ querySmall(_ YL, _ YR, _ l, _ r, _ pos);
inline void updateBig(_ X, _ Y, _ c, _ l, _ r, int &pos);
inline void updateSmall(_ Y, _ c, _ l, _ r, int &pos);
inline void del(_ mp, _ x);
inline void ins(_ mp, _ x);
inline void AC() {
    
    n = 1E5+8;
    m = read();
    for(_ i = 1; i <= m; ++i) {
        a[i].a = read();
        x = read()+big;
        y = read()+big;
        a[i].ox = x-big;
        a[i].oy = y-big;
        if(a[i].a == 2) {
            a[i].x = x-y+(n>>1);
            a[i].y = x+y;
            continue;
        }
        if(a[i].a == 4) {
            a[i].x = x-big;
            a[i].y = y-big;
            continue;
        }
        a[i].d = read();
        a[i].x = x-y+(n>>1);
        a[i].y = x+y;
        if(a[i].a == 1) {
            dx[++xc] = a[i].x;
            dy[++yc] = a[i].y;
        }
    }
    sort(dx+1, dx+1+xc);
    sort(dy+1, dy+1+yc);
    xc = unique(dx+1, dx+1+xc)-dx-1;
    yc = unique(dy+1, dy+1+yc)-dy-1;
    for(_ i = 1; i <= m; ++i) if(a[i].a == 1 || a[i].a == 2) {
        a[i].x = lower_bound(dx+1, dx+1+xc, a[i].x)-dx;
        a[i].y = lower_bound(dy+1, dy+1+yc, a[i].y)-dy;
    }
    for(_ qr = 1; qr <= m; ++qr) if(a[qr].a == 1) {
        updateBig(a[qr].x, a[qr].y, a[qr].d, 1, n, rt);
        sc[make_pair(a[qr].x, a[qr].y)] = a[qr].d;
        ins(0, -a[qr].ox-a[qr].oy);
        ins(1, -a[qr].ox+a[qr].oy);
        ins(2, a[qr].ox-a[qr].oy);
        ins(3, a[qr].ox+a[qr].oy);
    } ef(a[qr].a == 2) {
        _ dl = sc[make_pair(a[qr].x, a[qr].y)];
        updateBig(a[qr].x, a[qr].y, -dl, 1, n, rt);
        del(0, -a[qr].ox-a[qr].oy);
        del(1, -a[qr].ox+a[qr].oy);
        del(2, a[qr].ox-a[qr].oy);
        del(3, a[qr].ox+a[qr].oy);
    } ef(a[qr].a == 3) writeln(queryBig(lower_bound(dx+1, dx+1+xc, a[qr].x-a[qr].d)-dx, upper_bound(dx+1, dx+1+xc, a[qr].x+a[qr].d)-dx-1, lower_bound(dy+1, dy+1+yc, a[qr].y-a[qr].d)-dy, upper_bound(dy+1, dy+1+yc, a[qr].y+a[qr].d)-dy-1, 1, n, rt));
    else writeln(max(max(st[0].begin() -> first+a[qr].x+a[qr].y, st[1].begin() -> first+a[qr].x-a[qr].y), max(st[2].begin() -> first-a[qr].x+a[qr].y, st[3].begin() -> first-a[qr].x-a[qr].y)));

    return;
}

inline void ins(_ mp, _ x) {
    if(!st[mp].count(x)) st[mp][x] = 1;
    else ++st[mp][x];
    return;
}

inline void del(_ mp, _ x) {
    if(!--st[mp][x]) st[mp].erase(x);
    return;
}

inline void updateSmall(_ Y, _ c, _ l, _ r, int &pos) {
    if(!pos) pos = ++cnt;
    s[pos].dt += c;
    if(l == r) return;
    _ md = (l+r)>>1;
    if(Y <= md) updateSmall(Y, c, l, md, s[pos].ls);
    else updateSmall(Y, c, md+1, r, s[pos].rs);
    return;
}

inline void updateBig(_ X, _ Y, _ c, _ l, _ r, int &pos) {
    if(!pos) pos = ++bnt;
    updateSmall(Y, c, 1, n, t[pos].rt);
    if(l == r) return;
    _ md = (l+r)>>1;
    if(X <= md) updateBig(X, Y, c, l, md, t[pos].ls);
    else updateBig(X, Y, c, md+1, r, t[pos].rs);
    return;
}

inline _ querySmall(_ YL, _ YR, _ l, _ r, _ pos) {
    if(!pos) return 0;
    if(YL <= l && r <= YR) return s[pos].dt;
    _ md = (l+r)>>1, rv = 0;
    if(YL <= md) rv += querySmall(YL, YR, l, md, s[pos].ls);
    if(YR > md) rv += querySmall(YL, YR, md+1, r, s[pos].rs);
    return rv;
}

inline _ queryBig(_ XL, _ XR, _ YL, _ YR, _ l, _ r, _ pos) {
    if(XL > XR || YL > YR) return 0;
    if(!pos) return 0;
    if(XL <= l && r <= XR) return querySmall(YL, YR, 1, n, t[pos].rt);
    _ md = (l+r)>>1, rv = 0;
    if(XL <= md) rv += queryBig(XL, XR, YL, YR, l, md, t[pos].ls);
    if(XR > md) rv += queryBig(XL, XR, YL, YR, md+1, r, t[pos].rs);
    return rv;
}

