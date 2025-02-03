
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;
constant inf = 1E12;

_ n, cnt;
struct outPut {
    _ a, b, c, d;
    bool operator < (const outPut &x) const {
        if(a+c != x.a+x.c) return a+c < x.a+x.c;
        if(b != x.b) return b < x.b;
        if(a == x.a) return d < x.d;
        if(a > x.a) return b < x.d;
        return d < x.b;
    }
} m1, m2, co;
struct _p {
    _ f, s;
    bool empty() {
        return !(f|s);
    }
} c[maxn];
struct node {
    _ p, s;
};
vector<_> g[maxn];
queue<node> q;
bitset<maxn> v;
str cnd;

void bfs2(_ x);
void bfs1(_ x);
_p mp(_ a, _ b);
int main() {
    
    scanf("%lld", &n);
    m1 = m2 = (outPut){inf, inf, inf, inf};
    for(_ j = 0; j <= 9; ++j) {
        bfs1(j);
        for(_ i = 1; i <= 9; ++i) if(i != j) bfs2(i);
    }
    for(_ i = 1; i <= m1.a; ++i) cnd += m1.b^48;
    for(_ i = 1; i <= m1.c; ++i) cnd += m1.d^48;
    if(cnd == to_string(n)) m1 = m2;
    printf("%lld: %lld %lld %lld %lld\n", n, m1.a, m1.b, m1.c, m1.d);
    
    return 0;
}

_p mp(_ a, _ b) {
    return (_p){a, b};
}

void bfs1(_ x) {
    for(_ i = 0; i <= n-1; ++i) g[i].clear();
    memset(c, 0, sizeof c);
    for(_ i = 0; i <= n-1; ++i) g[(i*10+x)%n].push_back(i);
    for(; !q.empty(); ) q.pop();
    q.push({0, 0});
    for(; !q.empty(); q.pop()) {
        node t = q.front();
        for(_ i = 0; i < g[t.p].size(); ++i) if(c[g[t.p][i]].empty()) {
            c[g[t.p][i]] = mp(x, t.s+1);
            q.push((node){g[t.p][i], t.s+1});
        }
    }
    return;
}

void bfs2(_ x) {
    v.reset();
    node t = (node){x%n, 1};
    v.set(x%n);
    for(;;) {
        if(!c[t.p].empty()) {
            co = (outPut){t.s, x, c[t.p].s, c[t.p].f};
            if(co < m1) {
                m2 = m1;
                m1 = co;
            } ef(co < m2) m2 = co;
        }
        _ nxt = (t.p*10+x)%n;
        if(!v[nxt]) {
            v.set(nxt);
            t = (node){nxt, t.s+1};
        } else break;
    }
}
