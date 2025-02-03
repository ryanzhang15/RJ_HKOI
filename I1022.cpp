
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

constant maxn = 1E6+8;

_ n, a[maxn], x, y, s = 1E18, dx;
vector<_> g[maxn];

void dfs2(_ x, _ fa, _ c);
void dfs1(_ x, _ fa);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 0; i <= n-1; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= n-1; ++i) {
        scanf("%lld%lld", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(0, -99);
    dfs2(0, -99, 0);
    printf("%lld\n", dx);
    
    return 0;
}

void dfs1(_ x, _ fa) {
    for(_ i = 0; i < g[x].size(); ++i) if(g[x][i] != fa) {
        dfs1(g[x][i], x);
        a[x] += a[g[x][i]];
    }
    return;
}

void dfs2(_ x, _ fa, _ c) {
    _ t = c;
    for(_ i = 0; i < g[x].size(); ++i) if(g[x][i] != fa) {
        dfs2(g[x][i], x, c+a[x]-a[g[x][i]]);
        t = max(t, a[g[x][i]]);
    }
    if(t < s) {
        s = t;
        dx = x;
    }
    return;
}
