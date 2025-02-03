
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

constant maxn = 2E5+8;

_ n, m, x, y, v[maxn], cnt;
vector<_> g[maxn];

void dfs(_ x, _ f);
int main() {
    
    scanf("%lld%lld", &n, &m);
    if(!m) {
        puts("1");
        exit(0);
    }
    for(; m--; ) {
        scanf("%lld%lld", &x, &y);
        g[y].push_back(x);
        g[x].push_back(y);
    }
    for(_ i = 1; i <= n; ++i) if(!v[i]) dfs(i, 0);

    puts("2");
    
    return 0;
}

void dfs(_ x, _ f) {
    v[x] = v[f]+1;
    for(_ i = 0; i < g[x].size(); ++i) if(g[x][i] != f) {
        if(v[g[x][i]] && !((v[x] - v[g[x][i]]) & 1)) {
            puts("3");
            exit(0);
        }
        if(!v[g[x][i]]) dfs(g[x][i], x);
    }
    return;
    
}
