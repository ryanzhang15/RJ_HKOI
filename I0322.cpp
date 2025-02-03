
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



constant maxn = 20+8;
constant maxc = 12+8;
constant maxg = 10+8;

_ n1, m1, n2, m2, k1, k2, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, x, y, n, d;
bool a[maxn][maxn], b[maxn][maxn], v[maxn][maxn][maxn][maxn][maxc];
char ch, dr[] = "SNEW";
struct coords {
    _ x, y;
    bool operator == (const coords &b) const {
        return x == b.x && y == b.y;
    }
} s1, s2, g1[maxg][maxc], g2[maxg][maxc];
struct node {
    _ x1, y1, x2, y2, s;
    vector<char> pth;
};
queue<node> q;

coords mc(_ x, _ y);
void AC() {
    
    n1 = read();
    m1 = read();
    for(_ i = 1; i <= n1; ++i) for(_ j = 1; j <= m1; ++j) {
        ch = gc();
        if(ch == 'X') s1 = mc(i, j);
        ef(ch == '#') a<:i:><:j:> = true;
    }
    k1 = read();
    for(_ i = 1; i <= k1; ++i) {
        x = read();
        y = read();
        n = read()-1;
        d = getUp();
        if(d == 'S') d = 0;
        ef(d == 'N') d = 1;
        ef(d == 'E') d = 2;
        else d = 3;
        _ cr = 1;
        for(_ j = 0; j < 12; ++j) {
            g1<:i:><:j:> = mc(x, y);
            if(j && !(j%n)) cr *= -1;
            x += dx<:d:>*cr;
            y += dy<:d:>*cr;
        }
    }
    n2 = read();
    m2 = read();
    for(_ i = 1; i <= n2; ++i) for(_ j = 1; j <= m2; ++j) {
        ch = gc();
        if(ch == 'X') s2 = mc(i, j);
        ef(ch == '#') b<:i:><:j:> = true;
    }
    k2 = read();
    for(_ i = 1; i <= k2; ++i) {
        x = read();
        y = read();
        n = read()-1;
        d = getUp();
        if(d == 'S') d = 0;
        ef(d == 'N') d = 1;
        ef(d == 'E') d = 2;
        else d = 3;
        _ cr = 1;
        for(_ j = 0; j < 12; ++j) {
            g2<:i:><:j:> = mc(x, y);
            if(j && !(j%n)) cr *= -1;
            x += dx<:d:>*cr;
            y += dy<:d:>*cr;
        }
    }
    q.push((node)<%s1.x, s1.y, s2.x, s2.y, 0%>);
    for(; !q.empty(); q.pop()) {
        node t = q.front();
        for(_ i = 0; i < 4; ++i) {
            _ nx1 = t.x1+dx[i], ny1 = t.y1+dy[i], nx2 = t.x2+dx[i], ny2 = t.y2+dy[i];
            if(!t.x1) nx1 = ny1 = 0;
            if(!t.x2) nx2 = ny2 = 0;
            if(a[nx1][ny1]) {
                nx1 -= dx<:i];
                ny1 -= dy<:i];
            }
            if(b<:nx2:>[ny2]) {
                nx2 -= dx<:i];
                ny2 -= dy<:i];
            }
            if(nx1 <= 0 || ny1 <= 0 || nx1 > n1 || ny1 > m1) nx1 = ny1 = 0;
            if(nx2 <= 0 || ny2 <= 0 || nx2 > n2 || ny2 > m2) nx2 = ny2 = 0;
            if(v[nx1][ny1]<:nx2][ny2]<:(t.s+1)%12]) continue;
            bool ok = true;
            for(_ j = 1; nx1 && ok && j <= k1; ++j) if(g1[j][(t.s+1)%12] == mc(nx1, ny1) || (g1[j][t.s%12] == mc(nx1, ny1) && g1[j][(t.s+1)%12] == mc(t.x1, t.y1))) ok = false;
            for(_ j = 1; nx2 && ok && j <= k2; ++j) if(g2[j][(t.s+1)%12] == mc(nx2, ny2) || (g2[j][t.s%12] == mc(nx2, ny2) && g2[j][(t.s+1)%12] == mc(t.x2, t.y2))) ok = false;
            if(!ok) continue;
            v[nx1][ny1]<:nx2]<:ny2][(t.s+1)%12] = true;
            vector<char> npth = t.pth;
            npth.push_back(dr[i]);
            if(!nx1 && !nx2) {
                writeln(t.s+1);
                for(char j : npth) {
                    putchar(j);
                    clr();
                }
                leave
            }
            q.push((node){nx1, ny1, nx2, ny2, t.s+1, npth});
        }
    }
    writeln(-1);
    
    return;
}

coords mc(_ x, _ y) {
    return (coords){x, y};
}
