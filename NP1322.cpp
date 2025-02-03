#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
_ n, a[maxn], dp[maxn][2];

int main() {
    
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    dp[1][0] = dp[1][1] = 1;
    for(_ i = 2; i <= n; ++i) if(a[i] == a[i-1]) {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
    } ef(a[i] > a[i-1]) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+1);
        dp[i][1] = dp[i-1][1];
    } else {
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+1);
        dp[i][0] = dp[i-1][0];
    }
    
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    
    return 0;
}
