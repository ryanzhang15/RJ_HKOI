
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



constant maxn = 4E2+8;
constant maxr = 4E4+8;

_ n, c, p, t[maxn][maxn], x, y, bg, ts, bs, g;
struct pos {
    _ x, y;
};
vector<_> tp, bt, a[maxn];
bitset<maxr> s, aaa, b;
_p dp[maxn];
bool cn[maxn], sl[maxn];

inline void recur(_ x);
inline pos mv(_ x, _ y);
inline _ operator + (const _ a[maxn][maxn], const pos b);
void AC() {
    
    n = read();

    a[1] = {1};
    a[8] = {25, 10, 48, 53, 60, 50, 44, 22, 29, 64, 1, 26, 56, 9, 6};
    a[11] = {113, 5, 117, 71, 107, 17, 74, 110, 68, 104, 101, 121, 1, 65, 40, 16, 8, 36, 20, 99, 33, 95, 61, 64, 43, 37};

    cn[1] = cn[8] = cn[11] = sl[1] = sl[8] = sl[11] = true;
    for(_ i = 1; i <= n; ++i) {
        if(cn[i]) continue;
        for(_ j = 2; j <= i && !cn[i]; j += 3) for(_ k = 1; k <= i && !cn[i]; k += 2) if(cn[j] && cn[k] && k+j+1 == i) {
            cn[i] = true;
            dp[i] = make_pair(j, k);
        }
    }
    
    recur(n);
    for(_ i : a[n]) writeln(i);
    
    return;
}

inline _ operator + (const _ a[maxn][maxn], const pos b) {
    if(b.x < 0 || b.y < 0 || b.x >= maxn || b.y >= maxn) return 0;
    return a[b.x][b.y];
}

inline pos mv(_ x, _ y) {
    return (pos){x, y};
}

inline void recur(_ x) {
    if(sl[x]) return;
    recur(dp[x].first);
    recur(dp[x].second);
    tp = a[dp[x].first];
    bt = a[dp[x].second];
    ts = dp[x].first;
    bs = dp[x].second;
    memset(t, 0, sizeof t);
    aaa.reset();
    b.reset();
    s.reset();
    _ n = x;
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= (i<<1)-1; ++j) t[i][j] = ++p;
    for(_ i : tp) aaa.set(i);
    for(_ i : bt) b.set(i);
    p = 0;
    for(_ i = 1; i <= ts; ++i) for(_ j = 1; j <= (i<<1)-1; ++j) {
        ++p;
        if(aaa[p]) s.set(p);
    }
    p = 0;
    for(_ i = ts+2; i <= n; ++i) for(_ j = 1; j <= ((i-ts-1)<<1)-1; ++j) {
        ++p;
        if(b[p]) s.set(t+mv(i, j));
    }
    p = 0;
    for(_ i = ts+2; i <= n; i += 2, p = 0) for(_ j = (((i-ts-1)<<1))+2; j <= (i<<1)-1; ++j) {
        ++p;
        if(p % 6 == 1 || p % 6 == 4) s.set(t+mv(i, j));
    }
    for(_ i = 1; i <= n*n; ++i) if(s[i]) a[n].push_back(i);
    sl[x] = true;
    return;
}
