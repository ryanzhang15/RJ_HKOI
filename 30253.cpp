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

constant maxn = 30+8;

_ n, dp[maxn][maxn];

_ C(_ x, _ y);
int main() {
    
    for(_ i = 0; i <= 30; ++i) dp[i][0] = dp[i][1] = dp[1][i] = 1;
    for(_ i = 2; i <= 30; ++i) for(_ j = 2; j <= 30; ++j) for(_ p = 0; p*i <= j; ++p) dp[i][j] += C(dp[i-1][i]+p-1, p) * dp[i-1][j-p*i];
    scanf("%lld", &n);
    printf("%lld\n", n == 1 ? 1 : (dp[n-1][n] << 1));
    
    return 0;
}

_ C(_ x, _ y) {
    _ rv = 1;
    for(_ i = x-y+1; i <= x; ++i) rv *= i;
    for(_ i = 1; i <= y; ++i) rv /= i;
    return rv;
}
