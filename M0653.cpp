#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

struct sl {
	_ l, r, h, mk;
	bool operator < (const sl &b) const {
		if(h != b.h) return h < b.h;
		return mk > b.mk;
	}
} a[maxn<<1];
_ n, i1, i2, i3, i4, t[maxn<<4], x[maxn<<1], ln[maxn<<4], nn, s, cnt;

void update(_ L, _ R, _ l, _ r, _ c, _ pos);
void pushUp(_ pos, _ l, _ r);
int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld%lld%lld%lld", &i1, &i2, &i3, &i4);
		_ mn = min(i1, i3), mx = max(i1, i3);
		i1 = mn;
		i3 = mx;
		mn = min(i2, i4);
		mx = max(i2, i4);
		i2 = mn;
		i4 = mx;
		x[++cnt] = i1;
		x[++cnt] = i3;
		a[cnt-1] = (sl){i1, i3, i2, 1};
		a[cnt] = (sl){i1, i3, i4, -1};
	}
	n <<= 1;
	sort(a+1, a+1+n);
	sort(x+1, x+1+n);
	nn = unique(x+1, x+1+n)-x-1;
	for(_ i = 1; i <= n; ++i) {
		a[i].l = lower_bound(x+1, x+1+nn, a[i].l)-x;
		a[i].r = lower_bound(x+1, x+1+nn, a[i].r)-x;
	}
	for(_ i = 1; i <= n-1; ++i) {
		update(a[i].l, a[i].r-1, 1, nn, a[i].mk, 1);
		s += ln[1] * (a[i+1].h-a[i].h);
	}
	printf("%lld\n", s);
	
	return 0;
}

void pushUp(_ pos, _ l, _ r) {
	if(t[pos]) ln[pos] = x[r+1] - x[l];
	else ln[pos] = ln[pos<<1] + ln[pos<<1|1];
	return;
}

void update(_ L, _ R, _ l, _ r, _ c, _ pos) {
	if(L <= l && r <= R) {
		t[pos] += c;
		pushUp(pos, l, r);
		return;
	}
	_ md = (l+r)>>1;
	if(L <= md) update(L, R, l, md, c, pos<<1);
	if(R > md) update(L, R, md+1, r, c, pos<<1|1);
	pushUp(pos, l, r);
	return;
}