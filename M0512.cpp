
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 4E4+8;

_ n, x, y, d[maxn];
vector<_> g[maxn];
bitset<maxn> u;
priority_queue<_, vector<_>, greater<_> > q;

int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n-1; ++i) {
        scanf("%lld%lld", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        ++d[x];
        ++d[y];
    }
    for(_ i = 1; i <= n; ++i) if(d[i] == 1) q.push(i);
    for(_ i = 1; i <= n-1; ++i) {
        _ t = q.top();
        q.pop();
        _ k;
        for(_ j = 0; j < g[t].size(); ++j) if(!u[g[t][j]]) {
            k = g[t][j];
            break;
        }
        printf("%lld\n", k);
        u.flip(t);
        for(_ j = 0; j < g[t].size(); ++j) if(--d[g[t][j]] == 1) q.push(g[t][j]);
    }
    
    return 0;
}
