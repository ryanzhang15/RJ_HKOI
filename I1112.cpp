#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, k, x, y, z, s = 1E11, c, sz[maxn], sn[maxn], pc;
struct edge {
	_ to, cost;
};
vector<edge> g[maxn];
bitset<maxn> v;
map<_, _> p;

void dfs2(_ x, _ fa, _ d, _ t);
void dfs1(_ x, _ fa, _ d, _ t);
void recur(_ x);
void centroid(_ x, _ fa);
int main() {
		
	sn[0] = 1E11;
	
	scanf("%lld%lld", &n, &k);
	pc = n;
	for(_ i = n; --i; ) {
		scanf("%lld%lld%lld", &x, &y, &z);
		g[x+1].push_back((edge){y+1, z});
		g[y+1].push_back((edge){x+1, z});
	}
	centroid(1, -1);
	recur(c);
	printf("%lld\n", s == 1E11 ? -1LL : s);
		
	return 0;
}

void centroid(_ x, _ fa) {
	sz[x] = 1;
	sn[x] = 0;
	for(edge i : g[x]) if(!v[i.to] && i.to != fa) {
		centroid(i.to, x);
		sz[x] += sz[i.to];
		sn[x] = max(sn[x], sz[i.to]);
	}
	sn[x] = max(sn[x], pc-sz[x]);
	if(sn[x] < sn[c]) c = x;
	return;
}

void recur(_ x) {
	v.set(x);
	p.clear();
	for(edge i : g[x]) if(!v[i.to]) {
		dfs1(i.to, x, 1, i.cost);
		dfs2(i.to, x, 1, i.cost);
	}
	for(edge i : g[x]) if(!v[i.to]) {
		c = 0;
		pc = sz[i.to];
		centroid(i.to, x);
		recur(c);
	}
	return;
}

void dfs1(_ x, _ fa, _ d, _ t) {
	if(p.count(k-t)) s = min(s, d+p[k-t]);
	if(t == k) s = min(s, d);
	for(edge i : g[x]) if(!v[i.to] && i.to != fa) dfs1(i.to, x, d+1, t+i.cost);
	return;
}

void dfs2(_ x, _ fa, _ d, _ t) {
	if(p.count(t)) p[t] = min(p[t], d);
	else p[t] = d;
	for(edge i : g[x]) if(!v[i.to] && i.to != fa) dfs2(i.to, x, d+1, t+i.cost);
	return;
}


