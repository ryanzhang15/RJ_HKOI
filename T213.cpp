#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y);

using namespace std;

typedef int _;
typedef string str;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E6+8;

_ n, nn, a[maxn], p[maxn], f[maxn], sz[maxn], x, o[maxn], t[maxn<<2], lz[maxn<<2];
v_ g[maxn];

inline _ read();
inline _ query(_ l, _ r, _ c, _ pos);
inline void update(_ L, _ R, _ l, _ r, _ c, _ pos);
inline void dfs(_ x, _ fa);
int main() {

	n = read();
	for(_ i = 1; i <= n; ++i) p[i] = a[i] = read();
	sort(p+1, p+2+n);
	nn = unique(p+1, p+2+n)-p-1;
	for(_ i = 1; i <= n; ++i) g[read()].push_back(i);
	dfs(0, -1);
	for(_ i = 1; i <= n+1; ++i) {
		a[i] = lower_bound(p+1, p+1+nn, a[i])-p;
//		printf("updating %lld to %lld, vl %lld\n", 1LL, a[i], 1LL);
		update(1, a[i], 1, nn, 1, 1);
	}
//	printf("updating %lld to %lld, vl %lld\n", 1LL, 1LL, -n-1);
	update(1, 1, 1, nn, -n-1, 1);
	o[0] = 1;
	for(_ i = 1; i <= n; ++i) {
//		printf("i = %lld\n", i);
//		printf("updating %lld to %lld, vl %lld\n", 1LL, o[f[i]], sz[i]);
		update(1, o[f[i]], 1, nn, sz[i], 1);
		o[i] = query(1, nn, sz[i], 1);
//		printf("o[%lld] = %lld set to query at sz = %lld\n", i, o[i], sz[i]);
//		printf("updating %lld to %lld, vl %lld\n", 1LL, o[i], -sz[i]);
		update(1, o[i], 1, nn, -sz[i], 1);
	}
	for(_ i = 1; i <= n; ++i) printf("%d ", p[o[i]]);
	putchar(10);

	return 0;
}


inline void dfs(_ x, _ fa) {
	f[x] = fa;
	sz[x] = 1;
	for(_ i : g[x]) {
		dfs(i, x);
		sz[x] += sz[i];
	}
	return;
}

inline void pushUp(_ pos) {
	t[pos] = min(t[pos<<1], t[pos<<1|1]);
	return;
}

inline void pushDown(_ pos) {
	t[pos<<1] += lz[pos];
	t[pos<<1|1] += lz[pos];
	lz[pos<<1] += lz[pos];
	lz[pos<<1|1] += lz[pos];
	lz[pos] = 0;
	return;
}

inline void update(_ L, _ R, _ l, _ r, _ c, _ pos) {
	if(L <= l && r <= R) {
		t[pos] += c;
		lz[pos] += c;
		return;
	}
	_ md = (l+r)>>1;
	pushDown(pos);
	if(L <= md) update(L, R, l, md, c, pos<<1);
	if(R > md) update(L, R, md+1, r, c, pos<<1|1);
	pushUp(pos);
	return;
}

inline _ query(_ l, _ r, _ c, _ pos) {
//	printf("query at %lld to %lld, c = %lld, pos = %lld, t[lt] = %lld, t[rt] = %lld\n", l, r, c, pos, t[pos<<1], t[pos<<1|1]);
	if(l == r) return t[pos] >= c ? l : -1;
	_ md = (l+r)>>1;
	pushDown(pos);
	if(t[pos<<1] >= c) {
		_ ts = query(md+1, r, c, pos<<1|1);
		if(!~ts) return md;
		else return ts;
	} else return query(l, md, c, pos<<1);
//	if(t[pos<<1|1] >= c) return query(md+1, r, c, pos<<1|1);
//	else return query(l, md, c, pos<<1);
}

inline _ read() {
	char ch = getchar();
	_ x = 0;
	for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
	return x;
}
