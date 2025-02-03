#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 3E5+8;

_ n, m, p, q, x, y, o1[maxn], o2[maxn], d1[maxn], d2[maxn], c1 = 1E9, c2 = 1E9;
vector<_> g[maxn];

void dfs2(_ x, _ c);
void dfs1(_ x, _ c);
int main() {

#ifdef c8korz
	freopen("data.in", "r", stdin);
	freopen("c8k.out", "w", stdout);
#endif
	
	memset(o1, ~0, sizeof o1);
	memset(o2, ~0, sizeof o2);
	
	scanf("%lld%lld%lld", &n, &m, &p);
	++p;
	for(; m--; ) {
		scanf("%lld%lld", &x, &y);
		++x;
		++y;
		if(!~o1[x]) o1[x] = y;
		ef(!~o2[x]) o2[x] = y;
		if(!~o1[y]) o1[y] = x;
		ef(!~o2[y]) o2[y] = x;
	}
	for(_ i = 1; i <= n; ++i) {
		if(~o1[i]) g[o1[o1[i]] == i && ~o2[o1[i]] ? o1[i]+n : o1[i]].push_back(i);
		if(~o2[i]) g[o1[o2[i]] == i && ~o2[o2[i]] ? o2[i]+n : o2[i]].push_back(i+n);
	}
	dfs1(p, 1);
	dfs2(p+n, 1);
	scanf("%lld", &q);
	for(_ i = 1; i <= q; ++i) {
		scanf("%lld", &x);
		_ s = 0;
		for(_ j = 1; j <= n; ++j) {
			if(d1[j] && x >= d1[j]-1 && !((x-d1[j]+1)%c1)) ++s;
			if(d2[j] && x >= d2[j]-1 && !((x-d2[j]+1)%c2)) ++s;
		}
		printf("%lld\n", s);
	}
	
	return 0;
}

void dfs1(_ x, _ c) {
	if(d1[x]) {
		c1 = c-d1[x];
		return;
	}
	d1[x] = c;
	for(_ i : g[x]) dfs1(i, c+1);
	return;
}

void dfs2(_ x, _ c) {
	if(d2[x]) {
		c2 = c-d2[x];
		return;
	}
	d2[x] = c;
	for(_ i : g[x]) dfs2(i, c+1);
	return;
}

