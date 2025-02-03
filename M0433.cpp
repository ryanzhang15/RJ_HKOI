
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
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef double _D;
typedef const long long constant;

constant maxn = 15+8;
_ n, m, k, x, c[maxn];
_D ts[maxn];
vector<_> s[maxn];
bitset<maxn> o;

void dfs(_ x);
int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &k);
        for(; k--; ) {
            scanf("%lld", &x);
            if(i != n) s[i].push_back(x);
            else o.set(x);
        }
    }
    dfs(1);
    puts("Impossible");
    
    return 0;
}

void dfs(_ x) {
    if(x > m) {
        for(_ i = 1; i <= max(n, m); ++i) c[i] = ts[i] = 0;
        for(_ i = 1; i <= n; ++i) for(_ j = 0; j < s[i].size(); ++j) ++c[s[i][j]];
        for(_ i = 1; i <= n; ++i) for(_ j = 0; j < s[i].size(); ++j) ts[i] += 10000000.0/sqrt(c[s[i][j]]);
        for(_ i = 1; i <= n-1; ++i) if(ts[i] >= ts[n]) return;
        printf("%lu\n", s[n].size()-o.count());
        for(_ i = 0; i < s[n].size(); ++i) if(!o[s[n][i]]) printf("%lld ", s[n][i]);
        putchar(10);
        exit(0);
    }
    if(!o[x]) dfs(x+1);
    s[n].push_back(x);
    dfs(x+1);
    s[n].pop_back();
    return;
}
