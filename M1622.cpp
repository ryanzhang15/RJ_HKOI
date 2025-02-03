

/*
 template by c8kbf
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
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E6+8;

_ n, m, a[maxn], s, st, ed, d[maxn];
struct edge {
    _ to, cost;
};
vector<edge> g[maxn];
struct node {
    _ p, s;
    bool operator < (const node &b) const {
        return s > b.s;
    }
};
priority_queue<node> q;

_ f(_ x, _ y);
int main() {
    //freopen("/Users/ryanzhang/Desktop/debug/data.in", "r", stdin);

    memset(d, 17, sizeof d);

    scanf("%lld%lld", &n, &m);

    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) scanf("%lld", &a[f(i, j)]);
    for(_ i = 1; i <= n-1; ++i) for(_ j = 1; j <= m; ++j) s += a[f(i, j)]>>2;
    for(_ i = 1; i <= m; ++i) s += a[f(n, i)]>>1;
    st = f(n+1, m);
    ed = f(n+2, m);
    for(_ i = 1; i <= m; ++i) g[st].push_back((edge){f(1, i), n == 1 ? a[f(1, i)]>>1 : 3*(a[f(1, i)]>>2)});
    for(_ i = 1; i+1 <= n; ++i) for(_ j = 1; j <= m; ++j) {
        g[f(i, j)].push_back((edge){f(i+1, j), i+1 == n ? a[f(i+1, j)]>>1 : 3*(a[f(i+1, j)]>>2)});
        g[f(i+1, j)].push_back((edge){f(i, j), 0});
    }
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j+1 <= m; ++j) {
        g[f(i, j)].push_back((edge){f(i, j+1), i == n ? 0 : a[f(i, j+1)]>>2});
        g[f(i, j+1)].push_back((edge){f(i, j), i == n ? 0 : a[f(i, j)]>>2});
    }
    for(_ j = 1; j <= m; ++j) g[f(n, j)].push_back((edge){ed, 0});
    d[st] = 0;
    q.push((node){st, 0});
    for(; !q.empty(); ) {
        node t = q.top();
        q.pop();
        if(d[t.p] != t.s) continue;
        for(edge i : g[t.p]) if(d[i.to] > d[t.p] + i.cost) {
            d[i.to] = d[t.p] + i.cost;
            q.push((node){i.to, d[i.to]});
        }
    }
    printf("%lld\n", d[ed]+s);

    return 0;
}

_ f(_ x, _ y) {
    return x*(m+1)+y;
}
