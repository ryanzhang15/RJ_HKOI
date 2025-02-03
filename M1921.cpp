#pragma G++ optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma G++ target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
/*
 the c8kbf template
 */

// macOS doesn't have <bits/stdc++.h> (shame)
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <bitset>

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

const char untl = '\n';

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

inline bool gc(char &a) {
    char ch = getchar_unlocked();
    if(ch == '\r') ch = getchar_unlocked();
    if(ch == untl || ch == EOF) a = '\0';
    else a = ch;
    return ch != untl && ch != EOF;
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

    AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant mod = 1E9+7;
constant maxn = 256+8;

struct matrix {
    vector<vector<_> > data;
    _ n, m;
    inline void init(_ x, _ y) {
        n = x;
        m = y;
        data = vector<vector<_> >(n+1, vector<_>(m+1, 0));
        return;
    }
} x, y;

_ n, m, cnt, mp[maxn];
bitset<8> v;
bool bd[maxn];

inline void matrFill(const bitset<8> st, const _ x);
inline bitset<8> rev(const bitset<8> b);
inline void fillMap(const _ x);
inline matrix matrExp(const matrix x, const _ p);
inline matrix mult(const matrix a, const matrix b);
inline void AC() {
    
    n = read();
    m = read();
    fillMap(0);
    x.init(cnt, cnt);
    y.init(cnt, 1);
    for(_ c = 0; c < 1<<n; ++c) if(!bd[c]) matrFill(c, 0);
    for(_ i = 1; i <= cnt; ++i) y.data[i][1] = x.data[i][1];
    x = matrExp(x, m-1);
    y = mult(x, y);
    writeln(y.data[1][1]);
    
    return;
}

inline matrix mult(const matrix a, const matrix b) {
    matrix rv;
    rv.init(a.n, b.m);
    for(_ i = 1; i <= a.n; ++i) for(_ j = 1; j <= b.m; ++j) for(_ k = 1; k <= a.m; ++k) {
        rv.data[i][j] = rv.data[i][j]+a.data[i][k]*b.data[k][j];
        if(rv.data[i][j] > 7E18) rv.data[i][j] %= mod;
    }
    for(_ i = 1; i <= a.n; ++i) for(_ j = 1; j <= b.m; ++j) rv.data[i][j] %= mod;
    return rv;
}

inline matrix matrExp(const matrix x, const _ p) {
    if(p <= 1) return x;
    matrix c = matrExp(x, p>>1);
    c = mult(c, c);
    if(p & 1) c = mult(c, x);
    return c;
}

inline void fillMap(const _ x) {
    if(x >= n) {
        bitset<8> c = rev(v);
        if(mp[c.to_ulong()]) {
            mp[v.to_ulong()] = mp[c.to_ulong()];
            bd[v.to_ulong()] = true;
        }
        else mp[v.to_ulong()] = ++cnt;
        return;
    }
    fillMap(x+1);
    v.set(x);
    fillMap(x+1);
    v.reset(x);
    return;
}

inline bitset<8> rev(const bitset<8> b) {
    bitset<8> rv;
    for(_ i = 0; i < n; ++i) if(b[i]) rv.set(n-i-1);
    return rv;
}

inline void matrFill(const bitset<8> st, _ x) {
    if(x >= n) {
        ++::x.data[mp[v.to_ulong()]][mp[st.to_ulong()]];
        return;
    }
    if(st[x]) {
        matrFill(st, x+1);
        return;
    }
    if(x < n-1 && !v[x] && !v[x+1]) {
        v.set(x);
        v.set(x+1);
        matrFill(st, x+1);
        v.reset(x);
        v.reset(x+1);
    }
    if(x >= 1 && !v[x] && !v[x-1]) {
        v.set(x);
        v.set(x-1);
        matrFill(st, x+1);
        v.reset(x);
        v.reset(x-1);
    }
    if(x < n-1 && !st[x+1] && !v[x]) {
        v.set(x);
        matrFill(st, x+2);
        v.reset(x);
    }
    if(x < n-1 && !st[x+1] && !v[x+1]) {
        v.set(x+1);
        matrFill(st, x+2);
        v.reset(x+1);
    }
    return;
}
