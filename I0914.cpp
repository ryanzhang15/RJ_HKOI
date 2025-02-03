
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 50+8;
_ n, m, a[maxn][maxn], dp[maxn][maxn][maxn][maxn];

_ recur(_ w, _ x, _ y, _ z);
int main(int argc, char * argv[]) {
    
    memset(dp, ~0, sizeof dp);
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) scanf("%lld", &a[i][j]);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) a[i][j] += a[i-1][j];
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) a[i][j] += a[i][j-1];
    printf("%lld\n", recur(1, 1, n, m));
    
    return 0;
}

_ recur(_ w, _ x, _ y, _ z) {
    if(~dp[w][x][y][z]) return dp[w][x][y][z];
    if(w == y && x == z) return 0;
    _ rv = 1E18, t = a[y][z]-a[w-1][z]-a[y][x-1]+a[w-1][x-1];
    for(_ i = w; i <= y-1; ++i) rv = min(rv, recur(w, x, i, z)+recur(i+1, x, y, z));
    for(_ i = x; i <= z-1; ++i) rv = min(rv, recur(w, x, y, i)+recur(w, i+1, y, z));
    return dp[w][x][y][z] = rv+t;
}
