#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, l, s = -1E18, cnt, mx1 = -1E18, mx2 = -1E18, mx3 = -1E18, c, d, e, x, y, z, mx;

struct edge {
	_ to, cost;
};
vector<edge> g[maxn];
bitset<maxn> v, go;

void dfs3(_ x, _ fa, _ d);
void dfs2(_ x, _ fa);
void dfs1(_ x, _ fa, _ d, _ &t);
void dream(_ x);
int main() {
	
	scanf("%lld%lld%lld", &n, &m, &l);
	for(; m--; ) {
		scanf("%lld%lld%lld", &x, &y, &z);
		++x;
		++y;
		g[x].push_back((edge){y, z});
		g[y].push_back((edge){x, z});
	}
	for(_ i = 1; i <= n; ++i) if(!v[i]) dream(i);
	s = max(s, max(mx1+mx2+l, mx2+mx3+(l<<1)));
	printf("%lld\n", s);
	
	return 0;
}

void dream(_ x) {
	mx = -1E18;
	dfs1(x, -1, 0, c);
	mx = -1E18;
	dfs1(c, -1, 0, d);
	s = max(s, mx);
	go.set(d);
	dfs2(c, -1);
	e = mx;
	dfs3(c, -1, 0);
	if(e >= mx1) {
		mx3 = mx2;
		mx2 = mx1;
		mx1 = e;
	} ef(e >= mx2) {
		mx3 = mx2;
		mx2 = e;
	} ef(e > mx3) mx3 = e;
	return;
}

void dfs1(_ x, _ fa, _ d, _ &t) {
	if(d > mx) {
		mx = d;
		t = x;
	}
	for(edge i : g[x]) if(i.to != fa) dfs1(i.to, x, d+i.cost, t);
	return;
}

void dfs2(_ x, _ fa) {
	v.set(x);
	for(edge i : g[x]) if(i.to != fa) {
		dfs2(i.to, x);
		if(go[i.to]) go.set(x);
	}
	return;
}

void dfs3(_ x, _ fa, _ d) {
	e = min(e, max(mx-d, d));
	for(edge i : g[x]) if(go[i.to] && i.to != fa) dfs3(i.to, x, d+i.cost);
	return;
}
