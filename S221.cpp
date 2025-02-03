#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, m, k, x, y, a[maxn], b[maxn], rk[maxn], gl[maxn];
bitset<maxn> v;

bool cmp(_ x, _ y);
int main() {
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		a[i] = n-a[i]+1;
		v.set(a[i]);
	}
	for(; m--; ) {
		scanf("%lld%lld", &x, &y);
		b[x] += y;
	}
	for(_ i = 1; i <= n; ++i) {
		gl[a[i]] = max(gl[a[i]], b[i]);
	}
	bool fs = v[1];
	for(_ i = 2; i <= n; ++i) {
		if(!v[i]) gl[i] = gl[i-1];
		else {
			if(!fs) {
				fs = true;
			} else {
				gl[i] = max(gl[i], gl[i-1]+1);
			}
		}
	}
	_ s = 0;
	for(_ i = 1; i <= n; ++i) {
		_ tg = gl[a[i]]-b[i];
		if(tg) s += (tg-1)/k+1;
		
	}
	printf("%lld\n", s);
	return 0;
}

bool cmp(_ x, _ y) {
	return a[x] < a[y];
}