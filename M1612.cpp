#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, a[maxn], b[maxn], s, l, r = 1E10, md, o, c;

bool check(_ x);
_ vl(_ i, _ x);
_ howMany(_ i, _ x);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &b[i]);
	for(; l <= r; ) {
		md = (l+r)>>1;
		if(check(md)) {
			s = md;
			l = md+1;
		} else r = md-1;
	}
	check(s);
	for(_ i = 1; i <= n; ++i) {
		c += howMany(i, s+1);
		o += vl(i, s+1);
	}
	o += (m-c)*s;
	printf("%lld\n", o);
	
	return 0;
}

_ howMany(_ i, _ x) {
	if(!b[i]) return a[i] >= x ? 1E10 : 0;
	return max(0LL, (_)floor(1.L*(a[i]-x)/b[i])+1);
}

_ vl(_ i, _ x) {
	_ t = howMany(i, x);
	return a[i]*t-b[i]*((t*(t-1))>>1);
}

bool check(_ x) {
	_ rv = 0;
	for(_ i = 1; i <= n; ++i) rv += howMany(i, x);
	return rv >= m;
}