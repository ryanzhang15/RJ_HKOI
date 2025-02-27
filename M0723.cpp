
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



_ n, a, b, c, d, s, x, y, N, A, B, C, D;
pair<_, _> o1, o2;

pair<_, _> func(_ a, _ b, _ c, _ d);
void exgcd(_ a, _ b);
_ gcd(_ a, _ b);
void AC() {

    N = n = read();
    A = a = read();
    b = read();
    C = c = read();
    d = read();
    o1 = func(a, b, c, d);
    n = N;
    o2 = func(b, a, d, c);
    if(o1.second > o2.second) {
        writesc(o2.first);
        writeln(o2.second);
    } ef(o1.second < o2.second) {
        writesc(o1.first);
        writeln(o1.second);
    } else {
        if(o1.first > o2.first) {
            writesc(o2.first);
            writeln(o2.second);
        } else {
            writesc(o1.first);
            writeln(o1.second);
        }
    }
    
    return;
}

_ gcd(_ a, _ b) {
    return !b ? a : gcd(b, a%b);
}

void exgcd(_ a, _ b) {
    if(!b) {
        x = 1;
        y = 0;
    } else {
        exgcd(b, a%b);
        _ sv = x;
        x = y;
        y = sv-a/b*y;
    }
    return;
}

pair<_, _> func(_ a, _ b, _ c, _ d) {
    _ s;
    a = ((a-b)%n+n)%n;
    b = ((c-d)%n+n)%n;
    s = a%gcd(b, n);
    c = s-a;
    d = gcd(b, n);
    b /= d;
    n /= d;
    c /= d;
    c = (c%n+n)%n;
    exgcd(b, n);
    x = (x%n+n)%n;
    c = (c*x)%n;
    return make_pair(c, s);
}
