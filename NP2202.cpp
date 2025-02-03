#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

_ tc, n, d, e;

_ tr(_ x);
int main() {

	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld%lld", &n, &d, &e);
		_ c = n+2-d*e;
		_ ts = c*c-4*n;
		if(ts < 0) {
			puts("NO");
			continue;
		}
		_ rt = (_)sqrt(1.l*ts);
		_ cr = -1;
		for(_ i = rt-30; i <= rt+30; ++i) if(i >= 0 && i*i == ts) {
			cr = i;
			break;
		}
		if(!~cr) {
			puts("NO");
			continue;
		}
		_ ca = tr(c+cr), cb = tr(c-cr);
		if(~ca) {
			printf("%lld %lld\n", ca, n/ca);
		} ef(~cb) {
			printf("%lld %lld\n", cb, n/cb);
		} else {
			puts("NO");
			continue;
		}
	}


	return 0;
}

_ tr(_ x) {
	if(x <= 0) return -1;
	if(x & 1) return -1;
	x >>= 1;
	_ p = x, q = n/x;
	if((p-1)*(q-1)+1 != e*d) return -1;
	return min(p, q);
}
