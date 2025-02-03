#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxm = 2E2+8;
constant maxn = 260+8;
constant maxl = 30+8;

_ n, dsc, l, rg[maxn][maxn], a[maxl], d[maxm][maxm], c[maxm], t[maxm][maxn], s = 1E18;
vector<_> g[maxn];

void addWall(_ x, _ y, _ r);
int main() {
	
	memset(d, 4, sizeof d);
	scanf("%lld%lld%lld", &n, &dsc, &l);
	for(_ i = 1; i <= l; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &c[i]);
		for(_ j = 1; j <= c[i]; ++j) scanf("%lld", &t[i][j]);
		for(_ j = 1; j <= c[i]; ++j) g[t[i][j]].push_back(i);
		t[i][c[i]+1] = t[i][1];
		for(_ j = 1; j <= c[i]; ++j) addWall(t[i][j], t[i][j+1], i);
	}
	for(_ i = 1; i <= n; ++i) d[i][i] = 0;
	for(_ k = 1; k <= n; ++k) for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
	for(_ i = 1; i <= n; ++i) {
		_ th = 0;
		for(_ j = 1; j <= l; ++j) {
			_ cr = 1E18;
			for(_ k = 0; k < g[a[j]].size(); ++k) cr = min(cr, d[g[a[j]][k]][i]);
			th += cr;
		}
		s = min(s, th);
	}
	printf("%lld\n", s);
	
	return 0;
}

void addWall(_ x, _ y, _ r) {
	if(rg[x][y]) d[rg[x][y]][r] = d[r][rg[x][y]] = 1;
	else rg[x][y] = rg[y][x] = r;
	return;
}