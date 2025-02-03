
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

    str fileN = "expr";

    #define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxn = 1E6+8;

char strm[maxn];
_ n, g[maxn][2], cnt, x, y, t;
bool a[maxn], p[maxn], o[maxn], e[maxn];
stack<_> s;

void ion(_ x);
bool express(_ x, _ flp);
void retrv();
_ c(bool num = false);
inline void AC() {

    fgets(strm+1, sizeof strm / sizeof(char), stdin);
    cnt = n = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(_ t = c(); t != 10; t = c()) if(t == 'x') s.push(c(true));
    ef(t == '&') {
        retrv();
        e[cnt] = true;
        g[cnt][0] = x;
        g[cnt][1] = y;
    } ef(t == '|') {
        retrv();
        g[cnt][0] = x;
        g[cnt][1] = y;
    } else p[s.top()] = !p[s.top()];
    t = express(cnt, p[cnt]);
    ion(cnt);
    for(_ i = read(); i--; ) writeln(o[read()] ? t : !t);

    return;
}

_ c(bool num) {
    static int dx = 0;
    for(; strm[dx+1] == 32; ) ++dx;
    if(num) {
        _ rv = 0;
        ++dx;
        for(; strm[dx] >= '0' && strm[dx] <= '9'; ++dx) rv = (rv<<3)+(rv<<1)+(strm[dx]^48);
        return rv;
    }
    return strm[++dx];
}

void retrv() {
    x = s.top();
    s.pop();
    y = s.top();
    s.pop();
    s.push(++cnt);
    return;
}

bool express(_ x, _ flp) {
    a[x] ^= flp;
    e[x] ^= flp;
    if(x <= n) return a[x];
    _ z = express(g[x][0], flp^p[g[x][0]]);
    _ y = express(g[x][1], flp^p[g[x][1]]);
    if(e[x]) {
        o[g[x][0]] |= !y;
        o[g[x][1]] |= !z;
        return z & y;
    } else {
        o[g[x][0]] |= y;
        o[g[x][1]] |= z;
        return z | y;
    }
}

void ion(_ x) {
    if(x <= n) return;
    for(_ i = 0; i <= 1; ++i) {
        o[g[x][i]] |= o[x];
        ion(g[x][i]);
    }
    return;
}
