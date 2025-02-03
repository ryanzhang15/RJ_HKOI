#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxk = 2E5+8;
constant maxn = 4E6+8;

struct _c {
	_ x, y;
	bool operator < (const _c &b) const {
		if(x != b.x) return x < b.x;
		return y < b.y;
	}
} t;
set<_c> p;

_ n, m, k, s, u[maxn], d[maxn], sd[maxn], su[maxn], bd[maxn], bu[maxn];

_ verify(_c p);
int main() {
	
	memset(sd, 4, sizeof sd);
	memset(su, 4, sizeof su);
	memset(bd, (1<<7) | (1<<6), sizeof bd);
	memset(bu, (1<<7) | (1<<6), sizeof bu); 
	
	scanf("%lld%lld%lld", &n, &m, &k);
	if(!k) {
		for(_ i = 1; i <= min(n, m); ++i) s += (n-i+1)*(m-i+1);
		printf("%lld\n", s);
		exit(0);
	}
	n <<= 1;
	m <<= 1; 
	for(_ __ = 1; __ <= k; ++__) {
		scanf("%lld%lld", &t.x, &t.y);
		t.x <<= 1;
		t.y <<= 1;
		p.insert(t);
		++u[t.x-t.y+m];
		++d[t.x+t.y];
		su[t.x-t.y+m] = min(su[t.x-t.y+m], t.x);
		sd[t.x+t.y] = min(sd[t.x+t.y], t.x);
		bu[t.x-t.y+m] = max(bu[t.x-t.y+m], t.x);
		bd[t.x+t.y] = max(bd[t.x+t.y], t.x);
	}
	for(_c c = *p.begin(); c.x <= n && c.y <= m; ++c.x, ++c.y) s += verify(c);
	for(_c c = *p.begin(); c.x <= n && c.y >= 0; ++c.x, --c.y) s += verify(c);
	for(_c c = *p.begin(); c.x >= 0 && c.y <= m; --c.x, ++c.y) s += verify(c);
	for(_c c = *p.begin(); c.x >= 0 && c.y >= 0; --c.x, --c.y) s += verify(c);
	s -= 3*verify(*p.begin());
	printf("%lld\n", s);
	
	return 0;
}

_ verify(_c t) {
	if(u[t.x-t.y+m]+d[t.x+t.y]-p.count(t) < k) return 0;
	_ mnx = min(min(su[t.x-t.y+m], sd[t.x+t.y]), t.x), mxx = max(max(bu[t.x-t.y+m], bd[t.x+t.y]), t.x), mny = min(min(su[t.x-t.y+m]-t.x+t.y, t.x+t.y-bd[t.x+t.y]), t.y), mxy = max(max(bu[t.x-t.y+m]-t.x+t.y, t.x+t.y-sd[t.x+t.y]), t.y);
	if(mnx == mxx) {
		mnx -= 2;
		mny -= 2;
		mxx += 2;
		mxy += 2;
	}
	_ mxd = max(max(t.x-mnx, t.y-mny), max(mxx-t.x, mxy-t.y));
	mnx = t.x-mxd;
	mny = t.y-mxd;
	mxx = t.x+mxd;
	mxy = t.y+mxd;
	return max(0LL, min(min(mnx>>1, mny>>1), min((n-mxx)>>1, (m-mxy)>>1))+1);
}