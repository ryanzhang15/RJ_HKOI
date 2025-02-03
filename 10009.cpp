
/*
 they told me to cite my code so
 
 EVERYTHING WAS WRITTEN BY ME heheh
 
 sorry for ugly coding style
 deal with it
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



constant maxn = 19+8;

_ s, x, a[maxn], b[maxn], p[maxn][5] = {{}, {1, 8, 11}, {1, 7, 12}, {1, 6, 13}, {2, 9, 11}, {2, 8, 12}, {2, 7, 13}, {2, 6, 14}, {3, 10, 11}, {3, 9, 12}, {3, 8, 13}, {3, 7, 14}, {3, 6, 15}, {4, 10, 12}, {4, 9, 13}, {4, 8, 14}, {4, 7, 15}, {5, 10, 13}, {5, 9, 14}, {5, 8, 15}}, d[maxn][5] = {{}, {}, {}, {1}, {}, {}, {}, {2}, {11}, {}, {}, {}, {3, 6}, {12}, {}, {}, {4, 7}, {10, 13}, {9, 14}, {5, 8, 15}}, head;
struct node {
    bool k;
    _ n, p;
} l[maxn];

void recur(_ x);
void AC() {
    
    for(_ i = 1; i <= 19; ++i) l[i].k = true;
    for(_ i = 1; i <= 18; ++i) l[i].n = i+1;
    for(_ i = 2; i <= 19; ++i) l[i].p = i-1;
    head = 1;
    for(_ i = 1; i <= 19; ++i) {
        x = read();
        for(_ j = 0; j < 3; ++j) a[p[i][j]] += x;
    }
    recur(1);
    writeln(s);
    
    return;
}

void recur(_ x) {
    if(x > 19) {
        ++s;
        return;
    }
    if(d[x][0]) {
        _ k = a[d[x][0]] - b[d[x][0]];
        if(k > 19 || !l[k].k) return;
        for(_ i = 1; d[x][i]; ++i) if(a[d[x][i]] - b[d[x][i]] != k) return;
        for(_ j = 0; j < 3; ++j) if(b[p[x][j]] + k > a[p[x][j]]) return;
        for(_ j = 0; j < 3; ++j) b[p[x][j]] += k;
        l[k].k = false;
        if(k == head) {
            head = l[k].n;
            recur(x+1);
            head = k;
        } else {
            l[l[k].p].n = l[k].n;
            l[l[k].n].p = l[k].p;
            recur(x+1);
            l[l[k].p].n = k;
            l[l[k].n].p = k;
        }
        l[k].k = true;
        for(_ j = 0; j < 3; ++j) b[p[x][j]] -= k;
    } else for(_ i = head; i; i = l[i].n) {
        bool ok = true;
        for(_ j = 0; ok && j < 3; ++j) if(b[p[x][j]] + i >= a[p[x][j]]) ok = false;
        if(!ok) continue;
        for(_ j = 0; j < 3; ++j) b[p[x][j]] += i;
        l[i].k = false;
        if(i == head) {
            head = l[i].n;
            recur(x+1);
            head = i;
        } else {
            l[l[i].p].n = l[i].n;
            l[l[i].n].p = l[i].p;
            recur(x+1);
            l[l[i].p].n = i;
            l[l[i].n].p = i;
        }
        l[i].k = true;
        for(_ j = 0; j < 3; ++j) b[p[x][j]] -= i;
    }
    return;
}
