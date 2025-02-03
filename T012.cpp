#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxm = 2E4+8;
constant maxn = 30+8;

_ n, m, a[maxn], dp[500][maxm], v[] = {0, 1, 2, 3, 4, 8, 10, 13, 20, 25, 31, 40, 50, 100, 200, 240, 480, 500}; // 1 ~ 17

int main() {
	
	memset(dp, 4, sizeof dp);
	
	scanf("%lld%lld", &m, &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	dp[0][0] = 0;
	for(_ i = 1; ; ++i) {
		for(_ j = 1; j <= 17; ++j) for(_ k = v[j]; k <= m; ++k) dp[i][k] = min(dp[i][k], dp[i-1][k-v[j]] + (v[j] != a[i]));
		if(dp[i][m] < 1E10) {
			printf("%lld\n", dp[i][m]);
			break;
		}
	}
	
	return 0;
}
