
#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <numeric>

#define ef else if

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 2E3+8;
constant maxe = 6E4+8;

_ n, k, m, dp[maxn][maxn];
struct edge {
    _ x, y, w;
} g[maxe];

int main() {
    
    memset(dp, 4, sizeof dp);
    
    scanf("%lld%lld%lld", &n, &k, &m);
    dp[0][0] = 0;
    for(_ i = 1; i <= (m<<1)-1; i += 2) {
        scanf("%lld%lld%lld", &g[i].x, &g[i].y, &g[i].w);
        g[i+1].w = g[i].w;
        g[i+1].x = g[i].y;
        g[i+1].y = g[i].x;
    }
    for(_ i = 0; i <= k-1; ++i) for(_ j = 1; j <= (m<<1); ++j) dp[g[j].x][i+1] = min(dp[g[j].x][i+1], dp[g[j].y][i]+g[j].w);
    printf("%lld\n", dp[n-1][k] == dp[maxn-1][1] ? (_)-1 : dp[n-1][k]);
    
    return 0;
}

