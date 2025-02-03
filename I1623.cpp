
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



constant maxn = 1E5+8;

_ n, m, k, l, r = 1E11, md, s = 1E15, dp[maxn], c[maxn];
struct coords {
    _ x, y;
    bool operator < (const coords &b) const {
        if(y != b.y) return y < b.y;
        return x > b.x;
    }
} a[maxn];
stack<coords> t;
deque<_> q;

bool srt(coords a, coords b);
_ vl(_ pt, _ sl);
bool cmp(_ x, _ y, _ z);
bool check();
void AC() {

    n = read();
    m = read();
    k = read();
    for(_ i = 1; i <= n; ++i) {
        a[i].x = read();
        a[i].y = read();
        if(a[i].x > a[i].y) swap(a[i].x, a[i].y);
    }
    sort(a+1, a+1+n);
    for(_ i = 1; i <= n; ++i) {
        for(; t.size() && t.top().x >= a[i].x; ) t.pop();
        t.push(a[i]);
    }
    n = t.size();
    for(_ i = n; i >= 1; --i) {
        a[i] = t.top();
        t.pop();
    }
    sort(a+1, a+1+n, srt);
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(check()) {
            s = md;
            r = md-1;
        } else l = md+1;
    }
    md = s;
    check();
    s = dp[n]-md*k;
    writeln(s);

    return;
}

bool check() {
    q.clear();
    q.push_back(0);
    for(_ i = 1; i <= n; ++i) {
        for(; q.size() >= 2 && vl(q[0], i) > vl(q[1], i); ) q.pop_front();
        dp[i] = vl(q.front(), i)+(a[i].y+2)*a[i].y+md+1;
        c[i] = c[q.front()]+1;
        for(; q.size() >= 2 && cmp(q[q.size()-2], q[q.size()-1], i); ) q.pop_back();
        q.push_back(i);
    }
    return c[n] <= k;
}

bool cmp(_ x, _ y, _ z) {
    _ xx = a[x+1].x, xy = dp[x]+a[x+1].x*a[x+1].x-2*a[x+1].x-max(0LL, (a[x].y-a[x+1].x+1))*(a[x].y-a[x+1].x+1), yx = a[y+1].x, yy = dp[y]+a[y+1].x*a[y+1].x-2*a[y+1].x-max(0LL, (a[y].y-a[y+1].x+1))*(a[y].y-a[y+1].x+1), zx = a[z+1].x, zy = dp[z]+a[z+1].x*a[z+1].x-2*a[z+1].x-max(0LL, (a[z].y-a[z+1].x+1))*(a[z].y-a[z+1].x+1);
    if(!x) xy = dp[x]+a[x+1].x*a[x+1].x-2*a[x+1].x;
    if(!y) yy = dp[y]+a[y+1].x*a[y+1].x-2*a[y+1].x;
    if(!z) zy = dp[z]+a[z+1].x*a[z+1].x-2*a[z+1].x;
    return (yx-xx)*(zy-yy) < (yy-xy)*(zx-yx);
}

_ vl(_ pt, _ sl) {
    return -2*a[sl].y*a[pt+1].x+dp[pt]+a[pt+1].x*a[pt+1].x-2*a[pt+1].x-(!pt ? 0 : max(0LL, (a[pt].y-a[pt+1].x+1))*(a[pt].y-a[pt+1].x+1));
}

bool srt(coords a, coords b) {
    return a.x < b.x;
}

