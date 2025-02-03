#include <bits/stdc++.h>

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E2+8;
constant maxe = 8E3+8;

_ n, m, x, y, z, head[maxn], cnt, d[maxn];
struct edge {
    _ to, cost, next;
} g[maxe];
priority_queue<_p, vector<_p>, greater<_p> > q;

void addEdge(_ u, _ v, _ c);
int main() {
    
    memset(d, 4, sizeof d);
    scanf("%lld%lld", &n, &m);
    for(; m--; ) {
        scanf("%lld%lld%lld", &x, &y, &z);
        addEdge(x, y+n, z);
        addEdge(y, x+n, z);
        addEdge(y+n, x, (z/5)<<2);
        addEdge(x+n, y, (z/5)<<2);
        addEdge(x+(n<<1), y+(n<<1)+n, z);
        addEdge(y+(n<<1), x+(n<<1)+n, z);
        addEdge(x+(n<<1)+n, y+(n<<1), (z/5)<<2);
        addEdge(y+(n<<1)+n, x+(n<<1), (z/5)<<2);
        //big shade
    }
    addEdge(2, 2+(n<<1), 0);
    addEdge(2+n, 2+(n<<1)+n, 0);
    
    d[1] = 0;
    q.push(make_pair(0, 1));
    for(; !q.empty(); ) {
        _p p = q.top();
        q.pop();
        if(d[p.second] < p.first) continue;
        for(_ i = head[p.second]; i; i = g[i].next) if(d[g[i].to] > d[p.second] + g[i].cost) {
            d[g[i].to] = d[p.second] + g[i].cost;
            q.push(make_pair(d[g[i].to], g[i].to));
        }
    }
    
    printf("%lld\n%lld\n", min(d[2], d[2+n]), min(d[1+(n<<1)], d[1+(n<<1)+n]));
    
    return 0;
}

void addEdge(_ u, _ v, _ c) {
    g[++cnt].next = head[u];
    g[cnt].to = v;
    g[cnt].cost = c;
    head[u] = cnt;
    return;
}


