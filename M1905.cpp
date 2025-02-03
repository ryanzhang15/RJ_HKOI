
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


constant mod = 1E9+7;
constant inv = 166666668;

struct matrix {
    _ n, m, data[6][6] = {{0}};
} x, y;
_ o[6];

str n;
_ m;

inline str sub(str a, str b);
inline matrix matrSmol(matrix x, _ p);
inline matrix mult(matrix a, matrix b);
void AC() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(char i : n) m = (m*10+(i^48))%((_)1E9+6);
    x.n = 2;
    x.m = 2;
    y.n = 2;
    y.m = 1;
    x.data[1][1] = 2*inv;
    x.data[1][2] = 4*inv;
    x.data[2][1] = inv;
    x.data[2][2] = 5*inv;
    for(_ i = 1; i <= 5; ++i) y.data[i][1] = inv;
    y.data[1][1] += inv;
    x = matrSmol(x, (m+(_)1E9+5)%((_)1E9+6));
    y = mult(x, y);
    for(_ i = 1; i <= 5; ++i) o[i] = y.data[2][1];
    o[!((n.back()^48)%5) ? 5 : ((n.back()^48)%5)] = y.data[1][1];
    for(_ i = 1; i <= 5; ++i) writeln(o[i]);
    
    return;
}

inline matrix mult(matrix a, matrix b) {
    matrix rv;
    rv.n = 2;
    rv.m = 2;
    for(_ i = 1; i <= a.n; ++i) for(_ j = 1; j <= b.m; ++j) for(_ k = 1; k <= a.m; ++k) rv.data[i][j] = (rv.data[i][j]+(long long)a.data[i][k]*b.data[k][j]%mod)%mod;
    return rv;
}

inline matrix matrSmol(matrix x, _ p) {
    matrix c;
    if(!p) {
        c.n = x.n;
        c.m = x.m;
        for(_ i = 1; i <= c.n; ++i) c.data[i][i] = 1;
        return c;
    }
    c = matrSmol(x, p>>1);
    c = mult(c, c);
    if(p & 1) c = mult(c, x);
    return c;
}

inline str sub(str a, str b) {
    vector<_> av, bv;
    long long al = a.length(), bl = b.length();
    for(_ i = 0; i < al; i++) av.push_back(a[al - i - 1] - '0');
    for(_ i = 0; i < bl; i++) bv.push_back(b[bl - i - 1] - '0');
    for(_ i = 0; i < bl; i++) {
        av[i] -= bv[i];
        if(av[i] < 0) {
            av[i] += 10;
            --av[i+1];
        }
    }
    for(long long i = bl; i < al; ++i) if(av[i] < 0) {
        av[i] += 10;
        --av[i+1];
    }
    bool flag = false;
    str res;
    for(long long  i = al - 1; i >= 0; i--) {
        if(av[i]) flag = true;
        if(flag) res += av[i]^48;
    }
    return res;
}

