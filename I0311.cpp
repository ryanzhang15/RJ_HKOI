#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E2+8;
constant maxm = 6E3+8;

_ n, m, sz, f[maxn], we, s;
bool cn;
struct edge {
	_ from, to, cost;
} c, a[maxm];

void sOrT();
bool kruskal();
_ find(_ x);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(; m--; ) {
		scanf("%lld%lld%lld", &c.from, &c.to, &c.cost);
		if(cn && c.cost > we) printf("%lld\n", s);
		else {
			sOrT();
			if(!kruskal()) puts("-1");
			else printf("%lld\n", s);
		}
	}
	
	return 0;
}

_ find(_ x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

bool kruskal() {
	s = 0;
	_ t = 0;
	for(_ i = 1; i <= n; ++i) f[i] = i;
	for(_ i = 1; i <= sz; ++i) if(find(a[i].from) != find(a[i].to)) {
		f[find(a[i].from)] = find(a[i].to);
		s += a[i].cost;
		we = a[i].cost;
		if(++t == n-1) return cn = true;
	}
	return false;
}

void sOrT() {
	_ p;
	for(p = sz; p >= 1; --p) if(a[p].cost <= c.cost) break;
	for(_ i = sz; i >= p+1; --i) a[i+1] = a[i];
	a[++p] = c;
	++sz;
	return;
}