#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ d, d2, n, k, u[maxn], cnt, uc, t[maxn<<2], lz[maxn<<2], s;
struct wall {
	_ x, y;
	bool operator < (const wall &b) const {
		if(y != b.y) return y < b.y;
		return x > b.x;
	}
} a[maxn>>1];

_ query(_ L, _ R, _ l, _ r, _ pos);
void update(_ L, _ R, _ l, _ r, _ pos);
void pushDown(_ pos);
void pushUp(_ pos);
int main() {
	
	scanf("%lld%lld%lld%lld", &d, &d2, &n, &k);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld%lld%lld", &d, &a[i].x, &a[i].y);
		u[++cnt] = a[i].x;
		u[++cnt] = a[i].y;
	}
	sort(u+1, u+1+cnt);
	uc = unique(u+1, u+1+cnt)-u-1;
	for(_ i = 1; i <= n; ++i) {
		a[i].x = lower_bound(u+1, u+1+uc, a[i].x)-u;
		a[i].y = lower_bound(u+1, u+1+uc, a[i].y)-u;
	}
	sort(a+1, a+1+n);
	for(_ i = 1; i <= n; ++i) if(query(a[i].x, a[i].y, 1, uc, 1) <= k-1) {
		++s;
		update(a[i].x, a[i].y, 1, uc, 1);
	}
	printf("%lld\n", n-s);
	
	return 0;
}

void pushUp(_ pos) {
	t[pos] = max(t[pos<<1], t[pos<<1|1]);
	return;
}

void pushDown(_ pos) {
	t[pos<<1] += lz[pos];
	t[pos<<1|1] += lz[pos];
	lz[pos<<1] += lz[pos];
	lz[pos<<1|1] += lz[pos];
	lz[pos] = 0;
	return;
}

void update(_ L, _ R, _ l, _ r, _ pos) {
	if(L <= l && r <= R) {
		++t[pos];
		++lz[pos];
		return;
	}
	_ m = (l+r)>>1;
	if(lz[pos]) pushDown(pos);
	if(L <= m) update(L, R, l, m, pos<<1);
	if(R > m) update(L, R, m+1, r, pos<<1|1);
	pushUp(pos);
	return;
}

_ query(_ L, _ R, _ l, _ r, _ pos) {
	if(L <= l && r <= R) return t[pos];
	_ s = 0, m = (l+r)>>1;
	if(lz[pos]) pushDown(pos);
	if(L <= m) s = max(s, query(L, R, l, m, pos<<1));
	if(R > m) s = max(s, query(L, R, m+1, r, pos<<1|1));
	return s;
}


