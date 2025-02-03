
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
typedef int _;
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



constant maxm = 20+8;
constant maxw = 100+8;

_ n, m, dx[] = {1, -1, 0}, dy[] = {1, -1, 0}, dz[] = {1, -1, 0};
str w[maxw];
char a[maxm][maxm][maxm];
struct pos {
    _ x, y, z;
};
vector<pos> g[300];
struct node {
    _ x, y, z, s, cdx, cdy, cdz, sx, sy, sz;
};
queue<node> q;
bool v[maxm][maxm][maxm][maxm][5][5][5];

void AC() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) {
        cin >> w[i];
        w[i] = " " + w[i];
    }
    for(_ i = 1; i <= m; ++i) for(_ j = 1; j <= m; ++j) for(_ k = 1; k <= m; ++k) {
        a[i][j][k] = getLtr();
        g[a[i][j][k]].push_back((pos){i, j, k});
    }
    for(_ ts = 1; ts <= n; ++ts) {
        for(pos j : g[w[ts][1]]) {
            q.push((node){j.x, j.y, j.z, 1, -1, -1, -1, j.x, j.y, j.z});
            v[j.x][j.y][j.z][1][j.x][j.y][j.z] = true;
        }
        for(; !q.empty(); q.pop()) {
            node t = q.front();
            if(t.s == 1) {
                bool ok = true;
                for(_ i = 0; ok && i < 3; ++i) for(_ j = 0; ok && j < 3; ++j) for(_ k = 0; ok && k < 3; ++k) if(i+j+k != 6) {
                    t = q.front();
                    if(a[t.x+dx[i]][t.y+dy[j]][t.z+dz[k]] == w[ts][t.s+1]) {
                        t.cdx = dx[i];
                        t.cdy = dy[j];
                        t.cdz = dz[k];
                        t.sx = t.x-dx[i];
                        t.sy = t.y-dy[j];
                        t.sz = t.z-dz[k];
                        if(t.s+1 == w[ts].size()-1) {
                            char o;
                            if(t.sx <= 0 || t.sy <= 0 || t.sz <= 0 || t.sx > m || t.sy > m || t.sz > m) o = a[t.x+t.cdx+t.cdx][t.y+t.cdy+t.cdy][t.z+t.cdz+t.cdz];
                            else o = a[t.sx][t.sy][t.sz];
                            putchar_unlocked(o);
                            ok = false;
                        //} ef(!v[t.x+t.cdx][t.y+t.cdy][t.z+t.cdz][t.s+1][t.cdx+1][t.cdy+1][t.cdz+1]) {
                        }else{
                            v[t.x+t.cdx][t.y+t.cdy][t.z+t.cdz][t.s+1][t.cdx+1][t.cdy+1][t.cdz+1] = true;
                            q.push((node){t.x+t.cdx, t.y+t.cdy, t.z+t.cdz, t.s+1, t.cdx, t.cdy, t.cdz, t.sx, t.sy, t.sz});
                        }
                    }
                }
                if(!ok) break;
            } else if(a[t.x+t.cdx][t.y+t.cdy][t.z+t.cdz] == w[ts][t.s+1]) {
                if(t.s+1 == w[ts].size()-1) {
                    char o;
                    if(t.sx <= 0 || t.sy <= 0 || t.sz <= 0 || t.sx > m || t.sy > m || t.sz > m) o = a[t.x+t.cdx+t.cdx][t.y+t.cdy+t.cdy][t.z+t.cdz+t.cdz];
                    else o = a[t.sx][t.sy][t.sz];
                    putchar_unlocked(o);
                    break;
                } //ef(!v[t.x+t.cdx][t.y+t.cdy][t.z+t.cdz][t.s+1][t.cdx+1][t.cdy+1][t.cdz+1]) {
                else{
                    v[t.x+t.cdx][t.y+t.cdy][t.z+t.cdz][t.s+1][t.cdx+1][t.cdy+1][t.cdz+1] = true;
                    q.push((node){t.x+t.cdx, t.y+t.cdy, t.z+t.cdz, t.s+1, t.cdx, t.cdy, t.cdz, t.sx, t.sy, t.sz});
                }
            }
        }
        for(; !q.empty(); ) q.pop();
    }
    clr();
    
    return;
}


