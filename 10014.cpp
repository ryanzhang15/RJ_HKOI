#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E4+8;

_ n, m, a[maxn], dp[maxn], p[maxn];

int main() {
    
    scanf("%lld%lld", &m, &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= n; ++i) p[i] = p[i-1]+a[i];
    memset(dp, 4, sizeof dp);
    dp[0] = 0;
    for(_ i = 1; i <= n; ++i) for(_ j = i-1; j >= 0; --j) {
        _ t = m - p[i] + p[j] - i + j + 1;
        if(t >= 0) dp[i] = min(dp[i], dp[j]+t*t);
        else break;
    }
    printf("%lld\n", dp[n]);
    
    return 0;
}
