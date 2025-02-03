
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



_ n, m, o;
vector<_p> a, b, c, d;

void recur(_ L, _ R, _ l, _ r);
_p gp();
void AC() {
    
    n = read();
    m = read();
    for(; n--; ) a.push_back(gp());
    for(; m--; ) b.push_back(gp());
    sort(a.begin(), a.end(), greater<_p>());
    sort(b.begin(), b.end());
    for(_p i : a) {
        for(; !c.empty() && c.rbegin() -> second >= i.second; ) c.pop_back();
        c.push_back(i);
    }
    for(_p i : b) {
        for(; !d.empty() && d.rbegin() -> second <= i.second; ) d.pop_back();
        d.push_back(i);
    }
    reverse(c.begin(), c.end());
    recur(0, c.size()-1, 0, d.size()-1);
    writeln(o);
    
    return;
}

_p gp() {
    _ x = read();
    _ y = read();
    return make_pair(y, x);
}

void recur(_ L, _ R, _ l, _ r) {
    if(L > R) return;
    _ md = (L+R)>>1, s = -1E18, dx = -1;
    for(_ i = l; i <= r; ++i) {
        _ x = (d[i].first-c[md].first)*(d[i].second-c[md].second);
        if(d[i].first < c[md].first && d[i].second < c[md].second) x = -1E18;
        if(x > s) {
            s = x;
            dx = i;
        }
    }
    o = max(o, s);
    recur(L, md-1, l, dx);
    recur(md+1, R, dx, r);
    return;
}
