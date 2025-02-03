
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

constant maxn = 2E6+8;

_ cnt, n, q, x, y, st[maxn], ed[maxn];
vector<_> g[maxn];

void dfs(_ x);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 0; i <= n-1; ++i) {
        scanf("%lld", &x);
        for(_ j = 1; j <= x; ++j) g[i].push_back(++cnt);
    }
    cnt = 0;
    dfs(0);
    scanf("%lld", &q);
    for(; q--; ) {
        scanf("%lld%lld", &x, &y);
        if(st[x] < st[y] && ed[x] > ed[y]) puts("Yes");
        else puts("No");
    }
    
    return 0;
}

void dfs(_ x) {
    st[x] = ++cnt;
    for(_ i = 0; i < g[x].size(); ++i) dfs(g[x][i]);
    ed[x] = ++cnt;
    return;
}
