#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 2E3+8;
constant maxv = 3E2+8;

_ n, m, v, e, x, y, z, c[maxn], d[maxn], f[maxn][maxn];
_D dp[maxn][maxn][2], p[maxn], s; 

int main() {
	
	freopen("classroom.in", "r", stdin);
	freopen("classroom.out", "w", stdout);
	
	scanf("%lld%lld%lld%lld", &n, &m, &v, &e);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &d[i]);
	for(_ i = 1; i <= n; ++i) scanf("%Lf", &p[i]);
	memset(f, 4, sizeof f);
	for(; e--; ) {
		scanf("%lld%lld%lld", &x, &y, &z);
		f[x][y] = f[y][x] = min(f[x][y], z);
	}
	for(_ k = 1; k <= v; ++k) for(_ i = 1; i <= v; ++i) for(_ j = 1; j <= v; ++j) f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
	for(_ i = 1; i <= v; ++i) f[i][i] = 0;
	for(_ i = 1; i <= n; ++i) for(_ j = 0; j <= m; ++j) dp[i][j][0] = dp[i][j][1] = 1E9;
	dp[1][0][0] = dp[1][1][1] = 0;
	for(_ i = 2; i <= n; ++i) {
		_ ub = min(i, m);
		for(_ j = 0; j <= ub; ++j) {
			dp[i][j][0] = min(dp[i-1][j][0]+f[c[i-1]][c[i]], dp[i-1][j][1]+p[i-1]*f[d[i-1]][c[i]]+(1.0-p[i-1])*f[c[i-1]][c[i]]);
			if(j) dp[i][j][1] = min(dp[i-1][j-1][0]+p[i]*f[c[i-1]][d[i]]+(1.0-p[i])*f[c[i-1]][c[i]], dp[i-1][j-1][1]+(1.0-p[i])*(1.0-p[i-1])*f[c[i-1]][c[i]]+p[i]*(1.0-p[i-1])*f[c[i-1]][d[i]]+(1.0-p[i])*(p[i-1])*f[d[i-1]][c[i]]+p[i]*p[i-1]*f[d[i-1]][d[i]]);
		}
	}
	s = LDBL_MAX;
	for(_ i = 0; i <= m; ++i) s = min(s, min(dp[n][i][0], dp[n][i][1]));
	printf("%.2Lf", s);
	
	return 0;
}