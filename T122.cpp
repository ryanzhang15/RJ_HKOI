#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
constant srt = 320;
constant maxq = 5E5+8;

_ n, b[maxn], c[maxn], a[maxn], d[maxn], o[maxq], q;
struct qr {
	_ a, b, id;
	bool operator < (const qr &y) const {
		return b < y.b;
	}
} t;
vector<qr> g[srt+8];

int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &b[i]);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	for(_ i = 1; i <= n; ++i) a[i] = b[i]-c[i];
	for(_ i = 1; i <= n; ++i) d[i] = (a[i] += a[i-1]);
	d[n+1] = 0;
	sort(d+1, d+2+n);
	_ nn = unique(d+1, d+2+n)-d-1;
	for(_ i = 0; i <= n; ++i) a[i] = lower_bound(d+1, d+1+nn, a[i])-d;
	scanf("%lld", &q);
	for(_ i = 1; i <= q; ++i) {
		scanf("%lld%lld", &t.a, &t.b);
		t.id = i;
		--t.a;
		g[(_)sqrt(t.a)].push_back(t);
	}
	for(_ i = 0; i <= srt; ++i) {
		if(g[i].empty()) continue;
		sort(g[i].begin(), g[i].end());
		memset(c, 0, sizeof c);
		_ t = 0;
		for(_ j = g[i][0].a; j <= g[i][0].b; ++j) t += c[a[j]]++;
		o[g[i][0].id] = t;
		for(_ j = 1; j < g[i].size(); ++j) {
			for(_ k = g[i][j-1].b+1; k <= g[i][j].b; ++k) t += c[a[k]]++;
			if(g[i][j].a > g[i][j-1].a) for(_ k = g[i][j-1].a; k <= g[i][j].a-1; ++k) t -= --c[a[k]];
			else for(_ k = g[i][j-1].a-1; k >= g[i][j].a; --k) t += c[a[k]]++;
			o[g[i][j].id] = t; 
		}
	}
	for(_ i = 1; i <= q; ++i) printf("%lld\n", o[i]);
	
	return 0;
}