#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 50+8;

_ n, d[maxn*maxn], mn, p[maxn*maxn], s, e, ps[maxn*maxn], pi[maxn*maxn];
str a[maxn];
struct edge {
    _ to, cost, sw, id;
};
vector<edge> g[maxn*maxn];
struct node {
    _ d, u;
    bool operator < (const node &b) const {
        return d > b.d;
    }
};
priority_queue<node> q;

void dijkstra(_ s);
void addEdge(_ u, _ v, _ w, _ sw, _ id);
_ fetch(_ x, _ d);
int main() {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    memset(d, 4, sizeof d);
    cin >> n;
    for(_ i = 1; i <= n; ++i) cin >> a[i];
    s = fetch(n+1, 0);
    for(_ i = 1; i <= n; ++i) for(_ d = 0; d <= a[i].size(); ++d) for(_ j = 1; j <= n; ++j) {
        if(a[j].size() <= d) {
            if(a[j] == a[i].substr(a[i].size()-d, a[j].size())) {
                addEdge(fetch(i, d), fetch(i, d-a[j].size()), a[j].size(), 0, j);
                if(d == a[i].size() && i != j) addEdge(s, fetch(i, d-a[j].size()), a[j].size()+d, 0, j);
            }
        } else {
            if(a[j].substr(0, d) == a[i].substr(a[i].size()-d, d)) addEdge(fetch(i, d), fetch(j, a[j].size()-d), a[j].size(), 1, j);
        }
    }
    
    mn = d[0];
    dijkstra(s);
    for(_ i = 1; i <= n; ++i) if(d[fetch(i, 0)] < mn) {
        mn = d[fetch(i, 0)];
        e = fetch(i, 0);
    }
    if(mn > 1E9) cout << 0 << endl;
    else {
        cout << (mn>>1) << endl;
        stack<_> out;
        _ c = 0, ci;
        for(; ; e = p[e]) {
            c ^= ps[e];
            if(!c) out.push(pi[e]);
            if(e == s) {
                if(!(c^1)) out.push(ci);
                break;
            }
            ci = (e-1)/51;
        }
        for(; !out.empty(); out.pop()) cout << a[out.top()];
        cout << endl;
    }
    
    return 0;
}

_ fetch(_ x, _ d) {
    return x*51+d+1;
}

void addEdge(_ u, _ v, _ w, _ sw, _ id) {
    g[u].push_back((edge){v, w, sw, id});
    return;
}

void dijkstra(_ s) {
    q.push((node){0, s});
    d[s] = 0;
    for(; !q.empty(); ) {
        node x = q.top();
        q.pop();
        if(d[x.u] != x.d) continue;
        for(_ i = 0; i < g[x.u].size(); ++i) {
            if(d[g[x.u][i].to] > d[x.u] + g[x.u][i].cost) {
                d[g[x.u][i].to] = d[x.u] + g[x.u][i].cost;
                p[g[x.u][i].to] = x.u;
                ps[g[x.u][i].to] = g[x.u][i].sw;
                pi[g[x.u][i].to] = g[x.u][i].id;
                q.push((node){d[g[x.u][i].to], g[x.u][i].to});
            }
        }
    }
    return;
}


