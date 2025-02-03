#include <cstdio>
#include <iostream>
#include <cstdlib>
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
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E2+8;
_0 n, a[maxn][maxn], dp[maxn][maxn][maxn][maxn], s;

int main(int argc, char * argv[]) {
    
    scanf("%d", &n);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= i; ++j) scanf("%d", &a[i][j]);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= i; ++j) for(_ k = 1; k <= n; ++k) for(_ l = 1; l <= k; ++l) {
        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i-1][j][k-1][l]);
        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i-1][j][k-1][l-1]);
        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i-1][j-1][k-1][l]);
        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i-1][j-1][k-1][l-1]);
        dp[i][j][k][l] += a[i][j];
        if(!(i == k && j == l)) dp[i][j][k][l] += a[k][l];
    }
    
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) s = max(s, dp[n][i][n][j]);
    printf("%d\n", s);
    
    return 0;
}

