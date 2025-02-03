#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E3+8;

_ n, x, a[maxn], b[maxn], dp[maxn][maxn];

int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &b[i]);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) {
        if(a[i] >= b[j]) dp[i][j] = dp[i-1][j-1]+1+(a[i]>b[j]);
        dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
    }
    printf("%lld\n", dp[n][n]-n);
    
    return 0;
}
