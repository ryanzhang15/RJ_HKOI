#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 16+8;

_ n, m, r, c, a[maxn][maxn], s[maxn], t, dp[maxn][maxn], cc[maxn], d[maxn][maxn], o = 1E11;

void dfs(_ x);
void f2();
void f1();
int main() {
	
	freopen("submatrix.in", "r", stdin);
	freopen("submatrix.out", "w", stdout);
	
	scanf("%lld%lld%lld%lld", &n, &m, &r, &c);
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) scanf("%lld", &a[i][j]);
	dfs(1);
	printf("%lld\n", o);
	
	return 0;
}

void f1() {
	memset(cc, 0, sizeof cc);
	memset(d, 0, sizeof d);
	for(_ i = 1; i <= m; ++i) for(_ j = 1; j < r; ++j) cc[i] += abs(a[s[j+1]][i]-a[s[j]][i]);
	for(_ i = 2; i <= m; ++i) for(_ j = 1; j < i; ++j) for(_ k = 1; k <= r; ++k) d[i][j] += abs(a[s[k]][i]-a[s[k]][j]);
	return;
}

void f2() {
	memset(dp, 4, sizeof dp);
	for(_ i = 1; i <= m; ++i) for(_ j = 1; j <= min(i, c); ++j) {
		if(j == 1) dp[i][j] = cc[i];
		ef(i == j) dp[i][j] = dp[i-1][j-1]+cc[i]+d[i][j-1];
		else for(_ k = j-1; k < i; ++k) dp[i][j] = min(dp[i][j], dp[k][j-1]+cc[i]+d[i][k]);
		if(j == c) o = min(o, dp[i][c]);
	}
	return;
}

void dfs(_ x) {
	if(x > n) {
		if(t < r) return;
		f1();
		f2();
		return;
	}
	dfs(x+1);
	if(t < r) {
		s[++t] = x;
		dfs(x+1);
		--t;
	}
	return;
}

