
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

#include <unistd.h>


constant maxn = 2E5+8;

_ n, a[maxn], t[maxn<<2], lz[maxn<<2], ac = 1, nc;

_ query(_ p, _ l, _ r, _ pos);
void update(_ L, _ R, _ l, _ r, _ pos, _ k);
void pushDown(_ pos, _ ls, _ rs);
void pushUp(_ pos);
void AC() {
    
    n = read();
    for(_ i = 1; i <= n; ++i) nc += (a[i] = read());
    if(!nc) {
        writeln(-1);
        leave
    }
    update(1, 1, 1, n, 1, 1);
    for(_ i = 1; i <= n-1; ++i) {
        if(query(i, 1, n, 1) < a[i]) {
            writeln(-1);
            leave
        }
        _ c = query(i, 1, n, 1)-a[i];
        _ thr = i == n-1 ? c : min((nc-ac)/(n-i-1), c);
        ac += thr*(n-i-1);
        c -= thr;
        update(i+1, i+1, 1, n, 1, c);
        update(i+1, n, 1, n, 1, thr);
    }
    writeln(a[n]-query(n, 1, n, 1));
    
    return;
}

void pushUp(_ pos) {
    t[pos] = t[pos<<1]+t[pos<<1|1];
    return;
}

void pushDown(_ pos, _ ls, _ rs) {
    t[pos<<1] += lz[pos]*ls;
    t[pos<<1|1] += lz[pos]*rs;
    lz[pos<<1] += lz[pos];
    lz[pos<<1|1] += lz[pos];
    lz[pos] = 0;
    return;
}

void update(_ L, _ R, _ l, _ r, _ pos, _ k) {
    if(L <= l && r <= R) {
        t[pos] += k*(r-l+1);
        lz[pos] += k;
        return;
    }
    _ md = (l+r)>>1;
    if(lz[pos]) pushDown(pos, md-l+1, r-md);
    if(L <= md) update(L, R, l, md, pos<<1, k);
    if(R > md) update(L, R, md+1, r, pos<<1|1, k);
    pushUp(pos);
    return;
}

_ query(_ p, _ l, _ r, _ pos) {
    if(l == r) return t[pos];
    _ md = (l+r)>>1;
    if(lz[pos]) pushDown(pos, md-l+1, r-md);
    if(p <= md) return query(p, l, md, pos<<1);
    else return query(p, md+1, r, pos<<1|1);
}
