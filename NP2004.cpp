//#include <bits/stdc++.h>
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

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;
_ n, m, a[maxn][maxn], dp[maxn][maxn][2];

_ dfs(_ x, _ y, _ f);
int main() {
    
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    
    memset(dp, (1<<7)^(1<<6), sizeof dp);
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) scanf("%lld", &a[i][j]);
    dp[1][1][0] = dp[1][1][1] = a[1][1];
    printf("%lld\n", dfs(n, m, 1));
    
    return 0;
}

_ dfs(_ x, _ y, _ f) {
    if(x <= 0 || y <= 0 || x > n || y > m) return -1E12;
    ef(dp[x][y][f] > -1E12) return dp[x][y][f];
    dp[x][y][f] = max(dfs(x, y-1, 0), dfs(x, y-1, 1));
    if(!f) dp[x][y][f] = max(dp[x][y][f], dfs(x+1, y, 0));
    else dp[x][y][f] = max(dp[x][y][f], dfs(x-1, y, 1));
    return dp[x][y][f] = dp[x][y][f] + a[x][y];
}
