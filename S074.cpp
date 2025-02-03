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



constant maxn = 1E2+8;

_ n, m, d[maxn][maxn], e[maxn][maxn], sx, sy, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, ex, ey, ax, ay, s;
char a[maxn][maxn];
struct node {
    _ x, y;
};
queue<node> q;

void AC() {
    
    memset(d, 4, sizeof d);
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) {
        a[i][j] = gc();
        if(a[i][j] == 'E') {
            sx = i;
            sy = j;
        } ef(a[i][j] == 'X') {
            ex = i;
            ey = j;
        }
    }
    d[sx][sy] = 0;
    e[sx][sy] = 1;
    q.push((node){sx, sy});
    for(; !q.empty(); q.pop()) {
        node t = q.front();
        for(_ i = 0; i < 4; ++i) {
            _ nx = t.x + dx[i], ny = t.y + dy[i];
            if(a[nx][ny] == '#' || d[nx][ny] < d[t.x][t.y]+1) continue;
            if(d[nx][ny] == d[t.x][t.y]+1) e[nx][ny] += e[t.x][t.y];
            else {
                e[nx][ny] = e[t.x][t.y];
                d[nx][ny] = d[t.x][t.y] + 1;
                q.push((node){nx, ny});
            }
        }
    }
    ax = ex;
    ay = ey;
    s = d[ex][ey];
    q.push((node){ex, ey});
    for(; !q.empty(); q.pop()) {
        node t = q.front();
        for(_ i = 0; i < 4; ++i) {
            _ nx = t.x + dx[i], ny = t.y+dy[i];
            if(d[nx][ny] == 100000) continue;
            if(e[nx][ny] == e[ex][ey]) {
                q.push((node){nx, ny});
                if(d[nx][ny] < s) {
                    s = d[nx][ny];
                    ax = nx;
                    ay = ny;
                }
                d[nx][ny] = 100000;
            }
        }
    }
    a[ax][ay] = '*';
    for(_ i = 1; i <= n; ++i) writeln(a[i]+1);
    
    return;
}
