
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



constant maxn = 9+8;

_ n, st, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
bitset<maxn> a[maxn];
struct node {
    _ p, s;
};
queue<node> q;
char dr[4][10] = {"north", "south", "east", "west"};
unordered_map<_, _p> v;

void o(_ x);
_ encode(_ x, _ y);
void AC() {
    
    n = read();
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) if(gc() == 'O') a[i].set(j);
    else if(i != 1 && i != n && j != 1 && j != n) st |= (1LL<<encode(i, j));
    q.push((node){st, 0});
    for(; !q.empty(); q.pop()) {
        for(_ i = 0; i < 4; ++i) {
            _ t = q.front().p, x = 0;
            for(_ j = 2; j <= n-1; ++j) for(_ k = 2; k <= n-1; ++k) if(t & (1LL<<encode(j, k))) {
                _ nx = j + dx[i], ny = k + dy[i];
                if(a[nx][ny]) {
                    nx -= dx[i];
                    ny -= dy[i];
                }
                if(nx != 1 && nx != n && ny != 1 && ny != n) x |= (1LL<<encode(nx, ny));
            }
            if(v.count(x)) continue;
            v[x] = make_pair(t, i);
            if(!x) {
                o(x);
                leave
            }
            q.push((node){x, q.front().s+1});
        }
    }
        
    return;
}

_ encode(_ x, _ y) {
    return (x-2)*(n-2)+y-2;
}

void o(_ x) {
    if(x == st) return;
    o(v[x].first);
    writeln(dr[v[x].second]);
    return;
}
