#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, q, s, a[maxn], cnt, l[maxn], r[maxn], x, y, t[maxn];
vector<_> g[maxn], h[maxn], p[maxn];

_ Bsearch(_ nh, _ x);
_ bSearch(_ nh, _ x);
_ query();
void dfs(_ x, _ t);
int main() {
	
	freopen("propagation.in", "r", stdin);
	freopen("propagation.out", "w", stdout);
	
	scanf("%lld%lld", &n, &q);
	for(_ i = 0; i < n; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i < n; ++i) {
		scanf("%lld", &x);
		g[x].push_back(i);
	}
	dfs(0, 0);
	for(; q--; ) {
		scanf("%lld%lld", &x, &y);
		x = (x+s)%n;
		s = query();
		printf("%lld\n", s);
	}
	
	return 0;
}

void dfs(_ x, _ t) {
	l[x] = ++cnt;
	h[t].push_back(cnt);
	if(p[t].empty()) p[t].push_back(a[x]);
	else p[t].push_back(p[t].back()+a[x]);
	::t[x] = t;
	for(_ i : g[x]) dfs(i, t+1);
	r[x] = cnt;
	return;
}

_ query() {
	_ nh = t[x]+y;
	if(nh >= n || h[nh].empty() || h[nh].back() < l[x]) return 0;
 	return bSearch(nh, r[x])-Bsearch(nh, l[x]);
}

_ Bsearch(_ nh, _ x) {
	_ l = 0, r = h[nh].size()-1, s = 0, md;
	for(; l <= r; ) {
		md = (l+r)>>1;
		if(h[nh][md] < x) {
			s = p[nh][md];
			l = md+1;
		} else r = md-1;
	}
	return s;
}

_ bSearch(_ nh, _ x) {
	_ l = 0, r = h[nh].size()-1, s = 0, md;
	for(; l <= r; ) {
		md = (l+r)>>1;
		if(h[nh][md] <= x) {
			s = p[nh][md];
			l = md+1;
		} else r = md-1;
	}
	return s;
}


