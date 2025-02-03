
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

    str fileN = "park";

    //#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxn = 1E3+8;
constant maxm = 5+8;
constant bad = 1E11;

_ n, a[maxn], l[maxm], s[maxm], x, y, z, b[maxm];
vector<_> t[maxn<<2];

void conv(_ &x);
_ query(_ L, _ R, _ l, _ r, _ c, _ pos);
void build(_ l, _ r, _ pos);
inline void AC() {
    
    //freopen("/Users/ryanzhang/Desktop/debug/data.in", "r", stdin);
    
    n = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(_ i = 1; i <= 5; ++i) l[i] = read();
    b[1] = l[1];
    b[2] = l[3];
    b[3] = l[5];
    x = min_element(b+1, b+4)-b;
    b[x] = bad;
    y = min_element(b+1, b+4)-b;
    b[y] = bad;
    z = min_element(b+1, b+4)-b;
    conv(x);
    conv(y);
    conv(z);
    build(1, n, 1);
    for(_ i = 2; i <= n; ++i) for(_ j = i+2; j <= n-1; ++j) {
        for(_ k = 1; k <= 5; ++k) s[k] = -bad;
        s[2] = a[i];
        s[4] = a[j];
        {
            _ mn = -bad;
            for(_ i = 1; i <= 5; ++i) if(l[i] < l[x]) mn = max(mn, s[i]);
            if(x == 1) s[x] = query(1, i-1, 1, n, mn, 1);
            ef(x == 3) s[x] = query(i+1, j-1, 1, n, mn, 1);
            else s[x] = query(j+1, n, 1, n, mn, 1);
        }
        {
            _ mn = -bad;
            for(_ i = 1; i <= 5; ++i) if(l[i] < l[y]) mn = max(mn, s[i]);
            if(y == 1) s[y] = query(1, i-1, 1, n, mn, 1);
            ef(y == 3) s[y] = query(i+1, j-1, 1, n, mn, 1);
            else s[y] = query(j+1, n, 1, n, mn, 1);
        }
        {
            _ mn = -bad;
            for(_ i = 1; i <= 5; ++i) if(l[i] < l[z]) mn = max(mn, s[i]);
            if(z == 1) s[z] = query(1, i-1, 1, n, mn, 1);
            ef(z == 3) s[z] = query(i+1, j-1, 1, n, mn, 1);
            else s[z] = query(j+1, n, 1, n, mn, 1);
        }
        bool ok = true;
        for(_ x = 1; x <= 5; ++x) for(_ y = 1; y <= 5; ++y) if(x != y && (s[x] == bad || (l[x] > l[y] && s[x] <= s[y]))) ok = false;
        if(ok) {
            for(_ i = 1; i <= 5; ++i) writesc(s[i]);
            clr();
            leave
        }
    }
    writeln(-1);
    
    return;
}

void build(_ l, _ r, _ pos) {
    for(_ i = l; i <= r; ++i) t[pos].push_back(a[i]);
    sort(t[pos].begin(), t[pos].end());
    if(l == r) return;
    _ md = (l+r)>>1;
    build(l, md, pos<<1);
    build(md+1, r, pos<<1|1);
    return;
}

_ query(_ L, _ R, _ l, _ r, _ c, _ pos) {
    if(L <= l && r <= R) {
        vector<_>::iterator itr = upper_bound(t[pos].begin(), t[pos].end(), c);
        if(itr == t[pos].end()) return bad;
        return *itr;
    }
    _ md = (l+r)>>1, rv = bad;
    if(L <= md) rv = min(rv, query(L, R, l, md, c, pos<<1));
    if(R > md) rv = min(rv, query(L, R, md+1, r, c, pos<<1|1));
    return rv;
}

void conv(_ &x) {
    if(x == 1) x = 1;
    ef(x == 2) x = 3;
    else x = 5;
    return;
}
