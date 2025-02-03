
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



constant maxn = 5E5+8;

_ n, t[maxn][2], rd[maxn], vl[maxn], sz[maxn], c[maxn], cnt = 1, b, x, rt = 1;

inline _ rnk(_ p, _ x);
void del(_ &p, _ x);
inline void insert(_ &p, _ x);
inline void rotate(_ &p, _ d);
inline void pushUp(_ p);
inline _ newNode(_ x);
void AC() {
        
    n = read();
    for(_ i = 1; i <= n; ++i) {
        x = read();
        b += x;
        insert(rt, b);
        writeln(b = rnk(rt, b));
    }
    
    return;
}

inline _ newNode(_ x) {
    vl[++cnt] = x;
    rd[cnt] = rand();
    sz[cnt] = c[cnt] = 1;
    return cnt;
}

inline void pushUp(_ p) {
    sz[p] = sz[t[p][0]] + sz[t[p][1]] + c[p];
    return;
}

inline void rotate(_ &p, _ d) {
    _ k = t[p][d^1];
    t[p][d^1] = t[k][d];
    t[k][d] = p;
    pushUp(p);
    pushUp(k);
    p = k;
    return;
}

inline void insert(_ &p, _ x) {
    if(!p) {
        p = newNode(x);
        return;
    }
    if(vl[p] == x) {
        ++sz[p];
        ++c[p];
        return;
    }
    _ d = x > vl[p];
    insert(t[p][d], x);
    if(rd[p] < rd[t[p][d]]) rotate(p, d^1);
    pushUp(p);
    return;
}

void del(_ &p, _ x) {
    if(!p) return;
    if(x < vl[p]) del(t[p][0], x);
    ef(x > vl[p]) del(t[p][1], x);
    else {
        if(!(t[p][0] | t[p][1])) {
            --sz[p];
            if(!--c[p]) p = 0;
        } ef(t[p][0] && !t[p][1]) {
            rotate(p, 1);
            del(t[p][1], x);
        } ef(!t[p][0] && t[p][1]) {
            rotate(p, 0);
            del(t[p][0], x);
        } else {
            _ d = rd[t[p][0]] > rd[t[p][1]];
            rotate(p, d);
            del(t[p][d], x);
        }
    }
    pushUp(p);
    return;
}

inline _ rnk(_ p, _ x) {
    if(!p) return 0;
    ef(vl[p] == x) return sz[t[p][0]]+1;
    ef(vl[p] < x) return sz[t[p][0]] + c[p] + rnk(t[p][1], x);
    else return rnk(t[p][0], x);
}
