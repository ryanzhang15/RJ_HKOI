
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
#define RE exit(1);
#define WA writeln("lolthiscantbecorrectright?Imeanthisreallycantbethecorrectanswer"); exit(0);
#define TLE for(;;);

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

    str fileN = "cells";

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
constant maxlog = maxn*50;

_ n, q, a[maxn], x, y, z, t[maxlog][2], rd[maxlog], vl[maxlog], sz[maxlog], c[maxlog], cnt, rt[maxn<<2], l;
queue<_> pl;

void addNode(_ l, _ r, _ pos, _ x, _ k);
void deleteNode(_ l, _ r, _ pos, _ x, _ k);
_ countUpr(_ L, _ R, _ l, _ r, _ pos, _ k);
_ countLwr(_ L, _ R, _ l, _ r, _ pos, _ k);
void build(_ l, _ r, _ pos);
_ rnkUp(_ p, _ x);
_ rnkLw(_ p, _ x);
void del(_ &p, _ x);
void insert(_ &p, _ x);
void rotate(_ &p, _ d);
void pushUp(_ p);
_ newNode(_ x);
void AC() {
    
    n = read();
    q = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    build(1, n, 1);
    for(_ i = 1; i <= n; ++i) {
        if(i > 1) l += countUpr(1, i-1, 1, n, 1, a[i]);
        if(i < n) l += countLwr(i+1, n, 1, n, 1, a[i]);
    }
    l >>= 1;
    writeln(l);
    for(; q--; ) {
        x = read();
        y = read();
        z = read();
        x = (x*l+y-1)%n+1;
        if(x > 1) l -= countUpr(1, x-1, 1, n, 1, a[x]);
        if(x < n) l -= countLwr(x+1, n, 1, n, 1, a[x]);
        deleteNode(1, n, 1, x, a[x]);
        a[x] = z;
        addNode(1, n, 1, x, a[x]);
        if(x > 1) l += countUpr(1, x-1, 1, n, 1, a[x]);
        if(x < n) l += countLwr(x+1, n, 1, n, 1, a[x]);
        writeln(l);
    }
    
    return;
}

_ newNode(_ x) {
    _ dx;
    if(pl.empty()) dx = ++cnt;
    else {
        dx = pl.front();
        pl.pop();
    }
    vl[dx] = x;
    rd[dx] = rand();
    sz[dx] = c[dx] = 1;
    return dx;
}

void pushUp(_ p) {
    sz[p] = sz[t[p][0]] + sz[t[p][1]] + c[p];
    return;
}

void rotate(_ &p, _ d) {
    _ k = t[p][d^1];
    t[p][d^1] = t[k][d];
    t[k][d] = p;
    pushUp(p);
    pushUp(k);
    p = k;
    return;
}

void insert(_ &p, _ x) {
    if(!p) {
        p = newNode(x);
        return;
    }
    if(vl[p] == x) {
        ++sz[p];
        ++c[p];
        return;
    }
    _ d = x > vl[p];
    insert(t[p][d], x);
    if(rd[p] < rd[t[p][d]]) rotate(p, d^1);
    pushUp(p);
    return;
}

void del(_ &p, _ x) {
    if(!p) return;
    if(x < vl[p]) del(t[p][0], x);
    ef(x > vl[p]) del(t[p][1], x);
    else {
        if(!(t[p][0] | t[p][1])) {
            --sz[p];
            if(!--c[p]) {
                pl.push(p);
                p = 0;
            }
        } ef(t[p][0] && !t[p][1]) {
            rotate(p, 1);
            del(t[p][1], x);
        } ef(!t[p][0] && t[p][1]) {
            rotate(p, 0);
            del(t[p][0], x);
        } else {
            _ d = rd[t[p][0]] > rd[t[p][1]];
            rotate(p, d);
            del(t[p][d], x);
        }
    }
    pushUp(p);
}

_ rnkLw(_ p, _ x) {
    if(!p) return 0;
    ef(vl[p] == x) return sz[t[p][0]];
    ef(vl[p] < x) return sz[t[p][0]] + c[p] + rnkLw(t[p][1], x);
    else return rnkLw(t[p][0], x);
}

_ rnkUp(_ p, _ x) {
    if(!p) return 0;
    ef(vl[p] == x) return sz[t[p][1]];
    ef(vl[p] > x) return sz[t[p][1]] + c[p] + rnkUp(t[p][0], x);
    else return rnkUp(t[p][1], x);
}

void build(_ l, _ r, _ pos) {
    for(_ i = l; i <= r; ++i) insert(rt[pos], a[i]);
    if(l == r) return;
    _ md = (l+r)>>1;
    build(l, md, pos<<1);
    build(md+1, r, pos<<1|1);
    return;
}

_ countLwr(_ L, _ R, _ l, _ r, _ pos, _ k) {
    if(L <= l && r <= R) return rnkLw(rt[pos], k);
    _ rv = 0, md = (l+r)>>1;
    if(L <= md) rv += countLwr(L, R, l, md, pos<<1, k);
    if(R > md) rv += countLwr(L, R, md+1, r, pos<<1|1, k);
    return rv;
}

_ countUpr(_ L, _ R, _ l, _ r, _ pos, _ k) {
    if(L <= l && r <= R) return rnkUp(rt[pos], k);
    _ rv = 0, md = (l+r)>>1;
    if(L <= md) rv += countUpr(L, R, l, md, pos<<1, k);
    if(R > md) rv += countUpr(L, R, md+1, r, pos<<1|1, k);
    return rv;
}

void deleteNode(_ l, _ r, _ pos, _ x, _ k) {
    del(rt[pos], k);
    if(l == r) return;
    _ md = (l+r)>>1;
    if(x <= md) deleteNode(l, md, pos<<1, x, k);
    else deleteNode(md+1, r, pos<<1|1, x, k);
    return;
}

void addNode(_ l, _ r, _ pos, _ x, _ k) {
    insert(rt[pos], k);
    if(l == r) return;
    _ md = (l+r)>>1;
    if(x <= md) addNode(l, md, pos<<1, x, k);
    else addNode(md+1, r, pos<<1|1, x, k);
    return;
}
