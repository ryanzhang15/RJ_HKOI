
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



constant maxm = 8E4+8;

struct input {
    _ a, x, y, d;
} a[maxm];
_ d[maxm*50], t[maxm*50], cnt, n, m, x, y;

_ query(_ x, _ y);
void AC() {

    n = read()<<1;
    m = read();
    for(_ i = 1; i <= m; ++i) {
        a[i].a = read();
        x = read();
        y = read();
        a[i].d = read();
        a[i].x = x-y+(n>>1);
        a[i].y = x+y;
        if(a[i].a == 1) for(_ j = a[i].x; j <= n; j += j & -j) for(_ k = a[i].y; k <= n; k += k & -k) d[++cnt] = j*n+k;
    }
    sort(d+1, d+1+cnt);
    cnt = unique(d+1, d+1+cnt)-d-1;
    for(_ qr = 1; qr <= m; ++qr) if(a[qr].a == 1) for(_ i = a[qr].x; i <= n; i += i & -i) for(_ j = a[qr].y; j <= n; j += j & -j) t[lower_bound(d+1, d+1+cnt, i*n+j)-d] += a[qr].d;
    else writeln(query(min(n, a[qr].x+a[qr].d), min(n, a[qr].y+a[qr].d))-query(max(0LL, a[qr].x-a[qr].d-1), min(n, a[qr].y+a[qr].d))-query(min(n, a[qr].x+a[qr].d), max(0LL, a[qr].y-a[qr].d-1))+query(max(0LL, a[qr].x-a[qr].d-1), max(0LL, a[qr].y-a[qr].d-1)));

    return;
}

_ query(_ x, _ y) {
    _ rv = 0;
    for(_ i = x; i; i -= i & -i) for(_ j = y; j; j -= j & -j) {
        _ p = lower_bound(d+1, d+1+cnt, i*n+j)-d;
        if(d[p] == i*n+j) rv += t[p];
    }
    return rv;
}
