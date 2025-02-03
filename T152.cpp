
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



constant maxn = 1E5+8;

vector<_> in[maxn<<1], out[maxn<<1], a[maxn];
_ n, m, d[maxn<<1], cnt, t[maxn], c, s;

_ query(_ x);
void add(_ x, _ k);
void AC() {
    
    n = read();
    read();
    for(_ i = 1; i <= n; ++i) {
        a[i].push_back(read());
        d[++cnt] = a[i][0];
        a[i].push_back(read());
        m += a[i][1];
        for(_ j = a[i][1]; j--; ) {
            a[i].push_back(read());
            d[++cnt] = a[i].back();
        }
    }
    sort(d+1, d+1+cnt);
    cnt = unique(d+1, d+1+cnt)-d-1;
    for(_ i = 1; i <= n; ++i) {
        _ dx = lower_bound(d+1, d+1+cnt, a[i][0])-d;
        for(_ j = 2; j < a[i].size(); ++j) in[dx].push_back(lower_bound(d+1, d+1+cnt, a[i][j])-d);
    }
    for(_ i = 1; i <= cnt; ++i) {
        if(!out[i].empty()) {
            _ mn = 1E18;
            for(_ j : out[i]) mn = min(j, mn);
            s += query(c)-query(mn-1);
            for(_ j : out[i]) add(j, -1);
            s += query(c)-query(mn-1);
        }
        for(_ j : in[i]) {
            ++s;
            add(++c, 1);
            out[j].push_back(c);
        }
    }
    writeln(s);
    
    return;
}

void add(_ x, _ k) {
    for(; x <= m; x += x & -x) t[x] += k;
    return;
}

_ query(_ x) {
    _ rv = 0;
    for(; x; x -= x & -x) rv += t[x];
    return rv;
}
