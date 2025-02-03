

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

#define v(x) vector<x >
#define v2(x) vector<vector<x > >
#define v3(x) vector<vector<vector<x > > >

#define ss(x) v(_)(x+8, 0)
#define ssz(type, x) v(type)(x+8, 0)
#define s2(x, y) v2(_)(x+8, v(_)(y+8, 0))
#define s2z(type, x, y) v2(type)(x+8, v(type)(y+8, 0))
#define s3(x, y, z) v3(_)(x+8, v2(_)(y+8, v(_)(z+8, 0)))
#define s3z(type, x, y, z) v3(type)(x+8, v2(type)(y+8, v(type)(z+8, 0)))

#define i(x) x::iterator

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef double _D;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

const char untl = '\n';

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

    //#define file_IO
#ifdef file_IO
    str fileN = "puzzle";
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    //#define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
    for(; tc--; ) AC(); // good luck!
#else
    AC(); // good luck!
#endif
    
    
    return 0;
}



// ----- End of Template -----



constant maxn = 1E5+8;

_ n, c[maxn];
v_ a, b;

v_ lis(v_ a, v_ st);
inline void AC() {

    if(getUp() == 'A') {
        n = read();
        for(; n--; ) a.push_back(read());
        a = lis(a, v_());
        _ bl = (a.size()-1)/1000+1;
        write(bitset<20>(bl).to_string().c_str());
        write(bitset<20>(a.size()).to_string().c_str());
        for(_ i = bl-1; i < a.size(); i += bl) b.push_back(a[i]);
        if(bl & a.size()) b.push_back(a.back());
        c[0] = b[0];
        for(_ i = 1; i < b.size(); ++i) c[i] = b[i]-b[i-1];
        for(_ i = 0; i < b.size(); ++i) if(c[i] < 1<<12) {
            write("0");
            write(bitset<12>(c[i]).to_string().c_str());
        } else {
            write("1");
            write(bitset<20>(c[i]).to_string().c_str());
        }
        clr();
    } else {
        n = read();
        for(_ i = n; i--; ) a.push_back(read());
        read();
        str t;
        for(_ i = 1; i <= 20; ++i) t += getDg();
        _ bl = bitset<20>(t).to_ulong();
        t.clear();
        for(_ i = 1; i <= 20; ++i) t += getDg();
        _ sz = bitset<20>(t).to_ulong();
        _ tp = (sz-1)/bl+1;
        _ rm = sz-tp*bl, l = 0;
        for(_ i = 1; i <= tp; ++i) {
            t.clear();
            _ c = 0;
            if(getDg() == '0') {
                for(_ j = 1; j <= 12; ++j) t += getDg();
                c = bitset<12>(t).to_ulong();
            } else {
                for(_ j = 1; j <= 20; ++j) t += getDg();
                c = bitset<20>(t).to_ulong();
            }
            for(_ j = c, k = i == tp && rm ? rm : bl; k --> 0; --j) b.push_back(j+l);
            l += c;
        }
        sort(b.begin(), b.end());
        writeln(lis(a, b).size());
    }
    
    
    return;
}

v_ lis(v_ a, v_ st) {
    v_ rv = st;
    for(_ i : a) {
        i(v_) it = lower_bound(rv.begin(), rv.end(), i);
        if(it == rv.end()) rv.push_back(i);
        else *it = i;
    }
    return rv;
}
