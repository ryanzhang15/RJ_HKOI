#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E6+8;
constant maxd = 1E2+8;

_ mx = -1E18, m, w, l, ml, dl, a[maxd], yr, yu, mu, du, n, d[maxn], c, st, ed, nm[maxd], lp[maxd];
vector<_> o;

int main() {
	
	scanf("%lld%lld%lld%lld%lld", &m, &w, &l, &ml, &dl);
	for(_ i = 1; i <= m; ++i) {
		scanf("%lld", &a[i]);
		yr += a[i];
	}
	scanf("%lld%lld%lld%lld%lld", &yu, &mu, &du, &st, &ed);
	for(_ i = 1; i <= 1E6+1; ++i) {
		d[i] = c;
		c = (c+yr+(i % l ? 0 : dl))%w;
	}
	n = d[yu];
	for(_ i = 1; i <= mu-1; ++i) n = (n + a[i] + (!(yu % l) && i == ml ? dl : 0))%w;
	n = (n+du)%w;
	for(_ i = 0; i <= w-1; ++i) {
		c = i;
		for(_ j = 1; j <= m; ++j) {
			if(a[j] >= 13 && (c+13)%w == n) ++nm[i];
			c = (c+a[j])%w;
		}
	}
	for(_ i = 0; i <= w-1; ++i) {
		c = i;
		for(_ j = 1; j <= m; ++j) {
			if(a[j] + (j == ml ? dl : 0) >= 13 && (c+13)%w == n) ++lp[i];
			c = (c + a[j] + (j == ml ? dl : 0))%w;
		}
	}
	for(_ i = st; i <= ed; ++i) if(i % l) {
		if(nm[d[i]] > mx) {
			mx = nm[d[i]];
			o.clear();
			o.push_back(i);
		} ef(nm[d[i]] == mx) o.push_back(i);
	} else {
		if(lp[d[i]] > mx) {
			mx = lp[d[i]];
			o.clear();
			o.push_back(i);
		} ef(lp[d[i]] == mx) o.push_back(i);
	}
	
	printf("%lld\n", mx);
	for(_ i = 0; i < o.size(); ++i) printf("%lld ", o[i]);
	putchar(10);
	
	return 0;
}