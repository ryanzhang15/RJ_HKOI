#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, a[maxn], r[maxn], p[maxn], t, x, y, q;
map<_, _> c;

void add(_ x);
void remove(_ x);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i <= n; ++i) {
		if(i != 1) remove(a[i-1]);
		for(; t <= n && c.size() < m; ) add(a[++t]);
		if(t > n) r[i] = 1E7;
		else r[i] = t;
	}
	for(_ i = 1; i <= n; ++i) p[i] = r[i] + p[i-1];
	scanf("%lld", &q);
	for(; q--; ) {
		scanf("%lld%lld", &x, &y);
		t = upper_bound(r+1, r+1+n, y)-r-1;
		if(t < x) puts("0");
		else printf("%lld\n", (y+1)*(t-x+1)-p[t]+p[x-1]);
	}
	
	return 0;
}

void remove(_ x) {
	if(!--c[x]) c.erase(x);
	return;
}

void add(_ x) {
	if(!c.count(x)) c[x] = 1;
	else ++c[x];
	return;
}