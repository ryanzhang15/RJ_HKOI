#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 2E2+8;

_ n, a[maxn][2];
_D dp[maxn][maxn];

_D dist(_ x1, _ y1, _ x2, _ y2);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld%lld", &a[i][0], &a[i][1]);
    for(_ i = 1; i <= n; ++i) for(_ j = i+1; j <= n; ++j) dp[i][j] = dp[j][i] = dist(a[i][0], a[i][1], a[j][0], a[j][1]);
    for(_ k = 1; k <= n; ++k) for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) if(dp[i][j] > dp[i][k] && dp[i][j] > dp[k][j]) dp[i][j] = max(dp[i][k], dp[k][j]);
    printf("%.3Lf\n", dp[1][2]);
    
    return 0;
}

_D dist(_ x1, _ y1, _ x2, _ y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
