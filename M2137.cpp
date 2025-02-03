#include <bits/stdc++.h>
#define ef else if
#define i(x) x::iterator
#define mp(x, y) make_pair(x, y)
#define v(x) vector<x > 

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

typedef long long ll;

constant maxn = 5E3+8;
constant maxm = 50+8;

_ n, m, d[maxn][maxm], a[maxm], b[maxm][maxm], s = 9E18;
struct edge {
    _ to, cost, p;
};
v(edge) g[maxn];
struct node {
    _ x, y, d;
    bool operator < (const node &b) const {
        return d > b.d;
    }
};
priority_queue<node> q;

int main() {

//#define file_IO
#ifdef file_IO
    freopen("data.in", "r", stdin);
#endif

    memset(d, 4, sizeof d);

    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= m; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= m; ++i) for(_ j = 1; j <= m; ++j) scanf("%lld", &b[i][j]);
    for(_ i = 1; i <= m; ++i) for(_ j = 1; j <= a[i]; ++j) {
        _ x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        g[x].push_back((edge){y, z, i});
        g[y].push_back((edge){x, z, i});
    }
    q.push((node){1, 0, 0});
    d[1][0] = 0;
    for(; !q.empty(); ) {
        node t = q.top();
        q.pop();
        if(d[t.x][t.y] != t.d) continue;
        for(edge i : g[t.x]) if(d[i.to][i.p] > d[t.x][t.y]+max(0LL, i.cost-b[t.y][i.p])) {
            d[i.to][i.p] = d[t.x][t.y]+max(0LL, i.cost-b[t.y][i.p]);
            q.push((node){i.to, i.p, d[i.to][i.p]});
        }
    }
    for(_ i = 0; i <= m; ++i) {
        s = min(s, d[n][i]);
        //printf("for %lld, d[n][i] == %lld\n", i, d[n][i]);
    }
    printf("%lld\n", s);

    return 0;
}