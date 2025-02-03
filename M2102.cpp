
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
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline bool read(_ &x) {
    x = 0;
    _ f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    if(ch == '\r') ch = getchar();
    return ch != untl && ch != EOF;
}

inline char getDg() {
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
    return ch;
}

inline char getLw() {
    char ch = getchar();
    for(; !(ch >= 'a' && ch <= 'z'); ) ch = getchar();
    return ch;
}

inline char getUp() {
    char ch = getchar();
    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar();
    return ch;
}

inline char getLtr() {
    char ch = getchar();
    for(; !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ) ch = getchar();
    return ch;
}

inline char gc() {
    char ch = getchar();
    for(; ch == '\n' || ch == '\r' || ch == ' '; ) ch = getchar();
    return ch;
}

inline void write(_ x) {
    if(x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if(x > 9) write(x/10);
    putchar((x%10)^48);
    return;
}

inline void write(char const * a) {
    for(_ i = 0; a[i]; ++i) putchar(a[i]);
    return;
}

inline void clr() {
    putchar(10);
    return;
}

inline void spc() {
    putchar(32);
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

    str fileN = "";

    //#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    //#define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
#else
    _ tc = 1;
#endif
    
    for(; tc--; ) AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxin = 5E6+8;

_ n, cnt, sz, p;
char buf[maxin];
_D st, o, b, v;
struct shipment {
    _ a, b;
    _D c;
} cr;

inline shipment getShipment();
inline void AC() {
    
    n = read();
    for(;;) {
        char ch = getchar();
        if(ch == '\n') {
            ++cnt;
            if(cnt == n) break;
            continue;
        }
        buf[++sz] = ch;
    }
    for(;;) {
        cr = getShipment();
        if(!~cr.a) break;
        if(cr.a == 1) st = cr.c;
        ef(cr.a == 2) b = cr.b;
        ef(cr.a == 3) v = cr.b;
        else o += 240.L/(b*v)*cr.b;
    }
    printf("%.10Lf\n", st+o);
    
    return;
}

inline shipment getShipment() {
    shipment rv;
    rv.a = -1;
    ++p;
    if(p > sz) return rv;
    if(buf[p] == '&') {
        rv.a = 1;
        rv.c = 0;
        ++p;
        for(; buf[p] >= '0' && buf[p] <= '9'; ++p) rv.c = rv.c*10+(buf[p]^48);
        if(buf[p] != '.') {
            --p;
            return rv;
        }
        _D ts = 0.1;
        ++p;
        for(; buf[p] >= '0' && buf[p] <= '9'; ts /= 10, ++p) rv.c += ts*(buf[p]^48);
        --p;
    } ef(buf[p] == '(') {
        rv.a = 2;
        rv.b = 0;
        ++p;
        for(; buf[p] != ')'; ++p) rv.b = (rv.b<<3)+(rv.b<<1)+(buf[p]^48);
    } ef(buf[p] == '{') {
        rv.a = 3;
        rv.b = 0;
        ++p;
        for(; buf[p] != '}'; ++p) rv.b = (rv.b<<3)+(rv.b<<1)+(buf[p]^48);
    } else {
        rv.a = 4;
        rv.b = 0;
        for(;;) {
            if(p > sz) break;
            if(buf[p] >= '1' && buf[p] <= '8') {
                ++rv.b;
                p += 2;
            } ef(buf[p] == ',') {
                ++rv.b;
                ++p;
            } ef(buf[p] == '[') {
                ++rv.b;
                for(; buf[p] != ']'; ) ++p;
                p += 2;
            } else {
                --p;
                break;
            }
        }
    }
    return rv;
}

