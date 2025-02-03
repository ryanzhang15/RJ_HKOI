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
    
    str fileN = "level";
    
    //#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    AC(); // good luck!
    
    return 0;
}



// ----- End of Template -----



constant maxn = 1E6+8;

struct coords {
    _ x, y;
} a[maxn];
_ s = 1E18, n, c;

bool cmpy(coords a, coords b);
bool cmpx(coords a, coords b);
void AC() {
    
    n = read();
    for(_ i = 1; i <= n; ++i) {
        a[i].x = read();
        a[i].y = read();
    }
    sort(a+1, a+1+n, cmpx);
    if(a[1].x == a[n].x) {
        c = a[n].y-a[1].y+1;
        if(c == 1) c = 2;
        c += !(c & 1);
        s = min(s, (c<<1)+1);
    } ef(a[n].x - a[1].x >= 2) {
        _ y = -1, mx = -1E18, mn = 1E18;
        bool ok = true;
        for(_ i = 1; i <= n; ++i) {
            mx = max(mx, a[i].y);
            mn = min(mn, a[i].y);
            if(a[i].x != a[1].x && a[i].x != a[n].x) {
                if(!~y) y = a[i].y;
                ef(y != a[i].y) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            if(!~y) {
                c = mx-mn+1;
                c += !(c & 1);
                s = min(s, (c<<1)+a[n].x-a[1].x-1);
            } ef(y && y > mx>>1) {
                c = max(1LL, max(mx-y, y-mn));
                s = min(s, (c<<2)+a[n].x-a[1].x+1);
            }
        }
    }
    sort(a+1, a+1+n, cmpy);
    if(a[1].y == a[n].y) {
        c = a[n].x-a[1].x+1;
        if(c == 1) c = 2;
        c += !(c & 1);
        s = min(s, (c<<1)+1);
    } ef(a[n].y - a[1].y >= 2) {
        _ x = -1, mx = -1E18, mn = 1E18;
        bool ok = true;
        for(_ i = 1; i <= n; ++i) {
            mx = max(mx, a[i].x);
            mn = min(mn, a[i].x);
            if(a[i].y != a[1].y && a[i].y != a[n].y) {
                if(!~x) x = a[i].x;
                ef(x != a[i].x) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            if(!~x) {
                c = mx-mn+1;
                c += !(c & 1);
                s = min(s, (c<<1)+a[n].y-a[1].y-1);
            } ef(x && x > mx>>1) {
                c = max(1LL, max(mx-x, x-mn));
                s = min(s, (c<<2)+a[n].y-a[1].y+1);
            }
        }
    }
    if(s == 1E18) s = ~0LL;
    writeln(s);
    
    return;
}

bool cmpx(coords a, coords b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool cmpy(coords a, coords b) {
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}
