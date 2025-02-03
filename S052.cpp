
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
#include <thread>
#include <chrono>

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



constant maxn = 3E4+8;

struct line {
    _ x1, y1, x2, y2;
    bool d;
} h[maxn], v[maxn];
_ n, px, py, x, y, c1, c2, l = -3E4+1, r = 3E4+1, md, fx, fy;

char check();
void AC() {
    
    n = read();
    for(_ i = n; i--; px = x, py = y) {
        x = read();
        y = read();
        if(i == n-1) {
            fx = x;
            fy = y;
            continue;
        }
        if(y == py) h[++c1] = (line){min(x, px), y, max(x, px), py};
        else v[++c2] = (line){x, min(y, py), px, max(y, py), py > y};
    }
    if(y == fy) h[++c1] = (line){min(x, fx), y, max(x, fx), fy};
    else v[++c2] = (line){x, min(y, fy), px, max(y, fy), fy > y};
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(check() == '>') r = md-1;
        else l = md+1;
    }
    
    return;
}

char check() {
    _ ls = 0, rs = 0;
    for(_ i = 1; i <= c1; ++i) {
        if(h[i].x2 <= md) ls += h[i].x2-h[i].x1;
        ef(h[i].x1 >= md) rs += h[i].x2-h[i].x1;
        else {
            ls += md-h[i].x1;
            rs += h[i].x2-md;
        }
    }
    for(_ i = 1; i <= c2; ++i) {
        if(v[i].x1 < md) ls += v[i].y2-v[i].y1;
        ef(v[i].x1 > md) rs += v[i].y2-v[i].y1;
        else {
            if(v[i].d) rs += v[i].y2-v[i].y1;
            else ls += v[i].y2-v[i].y1;
        }
    }
    if(ls == rs) {
        writeln(md);
        leave
    }
    if(ls > rs) return '>';
    return '<';
}
