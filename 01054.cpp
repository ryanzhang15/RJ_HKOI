#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E2+8;

_ n, a[maxn], dp[maxn][maxn];

_ recur(_ l, _ r);
int main() {
	
	memset(dp, 4, sizeof dp);
	scanf("%lld", &n);
	for(_ i = 1; i <= n+1; ++i) scanf("%lld", &a[i]);
	printf("%lld\n", recur(1, n));
	
	return 0;
}

_ recur(_ l, _ r) {
	if(l == r) return 0;
	ef(dp[l][r] != dp[101][101]) return dp[l][r];
	for(_ k = l; k <= r-1; ++k) dp[l][r] = min(dp[l][r], recur(l, k) + recur(k+1, r) + a[l]*a[k+1]*a[r+1]);
	return dp[l][r];
}
