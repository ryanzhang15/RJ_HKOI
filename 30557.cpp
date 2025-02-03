#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E2+8;

_ n, head[maxn], d[maxn], c[maxn], cnt, x, a[maxn], x1;
bool v[maxn];
struct edge {
    _ to, next;
} g[maxn*maxn];

void addEdge(_ x, _ y);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld%lld", &a[i], &x);
        for(; x--; ) {
            scanf("%lld", &x1);
            addEdge(i, x1);
        }
    }
    d[1] = 100;
    queue<_> q;
    q.push(1);
    for(; !q.empty(); q.pop()) {
        _ u = q.front();
        if(u == n) break;
        v[u] = false;
        ++c[u];
        for(_ i = head[u]; i; i = g[i].next) if(c[g[i].to] <= 100*n && d[g[i].to] < d[u] + a[g[i].to]) {
            d[g[i].to] = d[u] + a[g[i].to];
            if(!v[g[i].to]) {
                v[g[i].to] = true;
                q.push(g[i].to);
            }
        }
    }
    if(d[n] > 0) puts("winnable");
    else puts("hopeless");
    
    return 0;
}

void addEdge(_ x, _ y) {
    g[++cnt].next = head[x];
    g[cnt].to = y;
    head[x] = cnt;
    return;
}
