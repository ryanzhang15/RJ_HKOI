#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxm = 4E3+8;

_ n, m, cnt, x, y, c, nd = 4E3+3, d[maxm];
struct edge {
    _ from, to, cost;
} a[maxm];
vector<_> g[maxm];
struct node {
    _ dst, u;
    bool operator < (const node &b) const {
        return dst > b.dst;
    }
};
priority_queue<node> q;

void addEdge(_ x, _ y, _ c);
int main() {
    
    scanf("%lld%lld", &n, &m);
    for(; m--; ) {
        scanf("%lld%lld%lld", &x, &y, &c);
        addEdge(x, y, c);
        addEdge(y, x, c);
    }
    for(_ i = 1; i <= cnt; ++i) for(_ j = 1; j <= cnt; ++j) if(i != j && a[i].to == a[j].from && a[i].cost >= a[j].cost) g[i].push_back(j);
    //dijkstra
    memset(d, 4, sizeof d);
    d[0] = 0;
    q.push((node){0, 0});
    for(; !q.empty(); ) {
        node u = q.top();
        q.pop();
        if(u.dst != d[u.u]) continue;
        for(_ i = 0; i < g[u.u].size(); ++i) if(d[g[u.u][i]] > d[u.u] + a[u.u].cost) {
            d[g[u.u][i]] = d[u.u] + a[u.u].cost;
            q.push((node){d[g[u.u][i]], g[u.u][i]});
        }
    }
    
    printf("%lld\n", d[nd]);
    
    return 0;
}

void addEdge(_ x, _ y, _ c) {
    a[++cnt].from = x;
    a[cnt].to = y;
    a[cnt].cost = c;
    if(x == 1) g[0].push_back(cnt);
    if(y == n) g[cnt].push_back(nd);
    return;
}
