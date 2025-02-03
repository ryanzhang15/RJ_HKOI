#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxk = 1E2+8;

_ n, m, k, head[maxn], c[maxn], z[maxn], cnt, x, y, zz, f[maxn], dp[maxk][maxk];
struct edge {
	_ from, to, cost, next;
} g[maxn<<1];

_ find(_ x);
void addEdge(_ x, _ y, _ z);
int main() {
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for(_ i = 1; i <= n; ++i) f[i] = i;
	for(_ i = 1; i <= k; ++i) scanf("%lld", &c[i]);
	_ p = 1;
	for(_ i = 1; i <= k; ++i) for(_ j = 1; j <= c[i]; ++j, ++p) z[p] = i;
	for(; m--; ) {
		scanf("%lld%lld%lld", &x, &y, &zz);
		addEdge(x, y, zz);
		addEdge(y, x, zz);
		if(!zz) {
			_ a = find(x), b = find(y);
			if(a != b) f[a] = b;
		}
	}
	//verify
	p = 1;
	for(_ i = 1; i <= k; ++i, ++p) for(_ j = 1; j <= c[i]-1; ++j, ++p) if(find(p) != find(p+1)) {
		puts("No");
		exit(0);
	}
	puts("Yes");
	memset(dp, 4, sizeof dp);
	for(_ i = 1; i <= cnt; ++i) if(z[g[i].from] != z[g[i].to]) dp[z[g[i].from]][z[g[i].to]] = min(dp[z[g[i].from]][z[g[i].to]], g[i].cost);
	for(_ i = 1; i <= k; ++i) dp[i][i] = 0;
	for(_ l = 1; l <= k; ++l) for(_ i = 1; i <= k; ++i) for(_ j = 1; j <= k; ++j) dp[i][j] = min(dp[i][j], dp[i][l] + dp[l][j]);
	for(_ i = 1; i <= k; ++i, putchar(10)) for(_ j = 1; j <= k; ++j) {
		if(dp[i][j] == dp[maxk-1][0]) printf("-1 ");
		else printf("%lld ", dp[i][j]);
	}
	
	return 0;
}

void addEdge(_ x, _ y, _ z) {
	g[++cnt].from = x;
	g[cnt].to = y;
	g[cnt].cost = z;
	g[cnt].next = head[x];
	head[x] = cnt;
	return;
}

_ find(_ x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}