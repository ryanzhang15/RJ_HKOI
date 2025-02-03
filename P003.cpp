#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;

_ n, m, dfn[maxn], low[maxn], c[maxn], cnum, cnt, x, y, o;
vector<_> g[maxn], G[maxn];
stack<_> s;
bitset<maxn> v;

void dfs(_ x, _ fa);
void tarjan(_ x, _ fa);
void paint(_ x);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(; m--; ) {
		scanf("%lld%lld", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	tarjan(1, -1);
	v.reset();
	for(_ i = 1; i <= n; ++i) for(_ j : g[i]) if(c[i] != c[j]) {
		G[c[i]].push_back(c[j]);
		G[c[j]].push_back(c[i]);
	}
	dfs(1, -1);
	printf("%lld\n", (o+1)>>1);
	
	return 0;
}

void paint(_ x) {
	s.pop();
	c[x] = cnum;
	v.reset(x);
	return;
}

void tarjan(_ x, _ fa) {
	dfn[x] = low[x] = ++cnt;
	s.push(x);
	v.set(x);
	for(_ i : g[x]) if(i != fa) {
		if(!dfn[i]) {
			tarjan(i, x);
			low[x] = min(low[x], low[i]);
		} else if(v[i]) low[x] = min(low[x], dfn[i]);
	}
	if(low[x] == dfn[x]) {
		++cnum;
		for(; !s.empty() && s.top() != x; ) paint(s.top());
		paint(x);
	}
	return;
}

void dfs(_ x, _ fa) {
	v.set(x);
	_ c = !!~fa;
	for(_ i : G[x]) if(i != fa && !v[i]) {
		++c;
		dfs(i, x);
	}
	if(c == 1) ++o;
	return;
}