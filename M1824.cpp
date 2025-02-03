#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxm = 3E5+8;

_ n, m, a[maxn], f[maxn], s, c, l;
struct edge {
	_ from, to, cost;
	bool operator < (const edge &b) const {
		return cost < b.cost;
	}
} g[maxm];

_ find(_ x);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i <= m; ++i) scanf("%lld%lld%lld", &g[i].from, &g[i].to, &g[i].cost);
	for(_ i = 1; i <= n; ++i) f[i] = i;
	l = n-1;
	sort(g+1, g+1+m);
	for(_ i = 1; i <= m; ++i) if(find(g[i].from) != find(g[i].to)) {
		s += g[i].cost;
		f[find(g[i].from)] = find(g[i].to);
		--l;
	}
	if(l) s = 1E18;
	for(_ i = m+1, j = 1; j <= n; ++i, ++j) g[i] = (edge){j, n+1, a[j]};
	for(_ i = 1; i <= n+1; ++i) f[i] = i;
	sort(g+1, g+1+m+n);
	for(_ i = 1; i <= m+n; ++i) if(find(g[i].from) != find(g[i].to)) {
		c += g[i].cost;
		f[find(g[i].from)] = find(g[i].to);
	}
	printf("%lld\n", min(c, s));
	
	return 0;
}

_ find(_ x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}