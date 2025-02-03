#pragma G++ optimize("Ofast");

#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 3E3+8;

_ n, m, t, a[maxn], dp[maxn][maxn];

int main() {

#ifdef c8korz
	freopen("data.in", "r", stdin);
	freopen("c8k.out", "w", stdout);
#endif

	memset(dp, 4, sizeof dp);
	scanf("%lld%lld%lld", &n, &m, &t);
	for(_ i = 1; i <= n-1; ++i) scanf("%lld", &a[i]);
	dp[1][m] = 0;
	for(_ i = 1; i <= n; ++i) {
		if(i != 1) {
			for(_ j = 1; j <= m; ++j) dp[i][j] = dp[i-1][j-1]+j-1;
			dp[i][m] = min(dp[i][m], dp[i-1][m]+m);
		}
		deque<_> q;
		for(_ j = 0; j <= min(m, a[i]-1); ++j) {
			for(; !q.empty() && dp[i][q.back()] >= dp[i][j]; ) q.pop_back();
			q.push_back(j);
		}
		for(_ j = 0; j <= m; ++j) {
			if(j+a[i] <= m) {
				for(; !q.empty() && dp[i][q.back()] >= dp[i][j+a[i]]; ) q.pop_back();
				q.push_back(j+a[i]);
			}
			dp[i][j] = min(dp[i][j], dp[i][q.front()]+t);
		}
	}
	_ mn = 1E11;
	for(_ i = 0; i <= m; ++i) mn = min(mn, dp[n][i]);
	printf("%lld\n", mn);
	
	return 0;
}

