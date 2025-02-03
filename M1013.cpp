#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E4+8;

_ n, l = 1, r = 22E8, md, s = -1, o;
struct in {
	_ x, y, z;
} a[maxn];

void check();
int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
	for(; l <= r; ) {
		md = (l+r)>>1;
		check();
		if(o & 1) {
			s = md;
			r = md-1;
		} else l = md+1;
	}
	if(!~s) puts("no corruption");
	else {
		o = 0;
		for(_ i = 1; i <= n; ++i) if(s >= a[i].x && s <= a[i].y && !((s-a[i].x) % a[i].z)) ++o;
		printf("%lld %lld\n", s, o);
	}
	
	return 0;
}

void check() {
	o = 0;
	for(_ i = 1; i <= n; ++i) {
		if(md < a[i].x) continue;
		_ tb = min(md, a[i].y);
		o += (min(md, a[i].y) - a[i].x) / a[i].z + 1;
	}
	return;
}