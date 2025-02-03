
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

inline bool read(_ x) {
    x = 0;
    _ f = 1;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar_unlocked()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    return ch != untl && ch != EOF;
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

inline void writesc(_ x) {
    write(x);
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

struct node {
    _ s, p, c;
    bool operator < (const node &b) const {
        return s > b.s;
    }
};
priority_queue<node> q;
struct edge {
    _ to, cost;
};
vector<edge> g[maxn];
bitset<maxn> v;

_ n, m, k, c[maxn], d[maxn], a[maxn], x, y, z;

void AC() {
    
    memset(d, 4, sizeof d);
    n = read();
    m = read();
    k = read();
    for(_ i = 1; i <= k; ++i) {
        a[i] = read();
        c[a[i]] = i;
        q.push((node){0, a[i], a[i]});
    }
    for(_ i = 1; i <= m; ++i) {
        x = read();
        y = read();
        z = read();
        g[x].push_back((edge){y, z});
        g[y].push_back((edge){x, z});
    }
    for(; !q.empty(); ) {
        node t = q.top();
        q.pop();
        if(v[t.p] && t.s == d[t.p] && c[t.p] != c[t.c]) c[t.p] = 0;
        if(v[t.p]) continue;
        c[t.p] = c[t.c];
        d[t.p] = t.s;
        v.set(t.p);
        for(edge i : g[t.p]) q.push((node){t.s+i.cost, i.to, t.p});
    }
    for(_ i = 1; i <= n; ++i) writesc(c[i]);
    clr();
    
    return;
}
