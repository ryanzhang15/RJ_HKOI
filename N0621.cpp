
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
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 6E4+8;
constant maxe = 6E5+8;

_ n, m, s, t, head[maxn], cnt = 1, x, y, z, o, d[maxn], cur[maxn];
struct edge {
    _ to, cost, next;
} g[maxe];
queue<_> q;

_ dfs(_ x, _ a);
bool bfs();
void addEdge(_ x, _ y, _ z);
int main() {
    
    scanf("%lld%lld", &n, &m);
    s = n+m+1;
    t = n+m+2;
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &x);
        addEdge(i, t, x);
        addEdge(t, i, 0);
    }
    for(_ i = n+1; i <= n+m; ++i) {
        scanf("%lld%lld%lld", &x, &y, &z);
        addEdge(i, x, 1E18);
        addEdge(x, i, 0);
        addEdge(i, y, 1E18);
        addEdge(y, i, 0);
        addEdge(s, i, z);
        addEdge(i, s, 0);
        o += z;
    }
    for(; bfs(); ) o -= dfs(s, 1E18);
    printf("%lld\n", o);
    
    return 0;
}

void addEdge(_ x, _ y, _ z) {
    g[++cnt].next = head[x];
    g[cnt].to = y;
    g[cnt].cost = z;
    head[x] = cnt;
    return;
}

bool bfs() {
    memset(d, 0, sizeof d);
    q.push(s);
    d[s] = 1;
    for(; !q.empty(); q.pop()) {
        _ u = q.front();
        cur[u] = head[u];
        for(_ i = head[u]; i; i = g[i].next) {
            _ v = g[i].to;
            if(g[i].cost && !d[v]) {
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
    return !!d[t];
}

_ dfs(_ x, _ a) {
    if(x == t) return a;
    _ rv = 0;
    for(_ &i = cur[x]; i; i = g[i].next) {
        _ v = g[i].to;
        if(g[i].cost && d[v] == d[x]+1) {
            _ cr = dfs(v, min(g[i].cost, a));
            g[i].cost -= cr;
            g[i^1].cost += cr;
            a -= cr;
            rv += cr;
            if(!a) break;
        }
    }
    if(!rv) d[x] = 0;
    return rv;
}
