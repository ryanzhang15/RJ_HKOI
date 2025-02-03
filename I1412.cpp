
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



constant maxn = 2E6+8;

_ n, m, mx[maxn<<2], mn[maxn<<2], o, l, r, k, t[maxn];

void extract(_ l, _ r, _ pos);
void update(_ L, _ R, _ c, _ l, _ r, _ pos, _ o);
void pushDown(_ pos);
void AC() {
    
    memset(mn, 4, sizeof mn);
    
    n = read();
    m = read();
    for(; m--; ) {
        o = read();
        l = read();
        r = read();
        k = read();
        update(l+1, r+1, k, 1, n, 1, o);
    }
    extract(1, n, 1);
    for(_ i = 1; i <= n; ++i) writeln(t[i]);
    
    return;
}

void pushDown(_ pos) {
    mn[pos<<1] = max(mn[pos<<1], mx[pos]);
    mx[pos<<1] = max(mx[pos<<1], mx[pos]);
    mn[pos<<1|1] = max(mn[pos<<1|1], mx[pos]);
    mx[pos<<1|1] = max(mx[pos<<1|1], mx[pos]);
    mn[pos<<1] = min(mn[pos<<1], mn[pos]);
    mx[pos<<1] = min(mx[pos<<1], mn[pos]);
    mn[pos<<1|1] = min(mn[pos<<1|1], mn[pos]);
    mx[pos<<1|1] = min(mx[pos<<1|1], mn[pos]);
    mx[pos] = 0;
    mn[pos] = 1E11;
    return;
}

void update(_ L, _ R, _ c, _ l, _ r, _ pos, _ o) {
    if(L <= l && r <= R) {
        if(o == 1) {
            mn[pos] = max(mn[pos], c);
            mx[pos] = max(mx[pos], c);
        } else {
            mn[pos] = min(mn[pos], c);
            mx[pos] = min(mx[pos], c);
        }
        return;
    }
    _ md = (l+r)>>1;
    pushDown(pos);
    if(L <= md) update(L, R, c, l, md, pos<<1, o);
    if(R > md) update(L, R, c, md+1, r, pos<<1|1, o);
    return;
}

void extract(_ l, _ r, _ pos) {
    if(l == r) {
        t[l] = mx[pos];
        return;
    }
    _ md = (l+r)>>1;
    pushDown(pos);
    extract(l, md, pos<<1);
    extract(md+1, r, pos<<1|1);
    return;
}
