#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, x, y, z, dp[maxn], p[maxn], c[maxn], d[maxn];
_p a[maxn];

int main() {
	
	scanf("%lld%lld", &x, &y);
	for(_ i = 1; i <= x; ++i) scanf("%lld", &a[++n].first);
	for(_ i = 1; i <= y; ++i) {
		scanf("%lld", &a[++n].first);
		a[n].second = 1;
	}
	sort(a+1, a+1+n);
	x = y = z = 0;
	for(_ i = 1; i <= n; ++i) {
		if(i > 1 && a[i].second == a[i-1].second) {
			p[i] = p[i-1]-a[i-1].first;
			++x;
		} else {
			for(_ j = i; j <= n && a[j].second == a[i].second; ++j) p[i] += a[j].first;
			for(_ j = i-1; j >= y; --j) {
				c[j] = a[i-1].first*(i-j)-p[j]+min(dp[j], dp[j-1]);
				if(j != i-1) c[j] = min(c[j], c[j+1]);
			}
			for(_ j = y; j < i; ++j) {
				d[j] = a[i].first*(i-j)-p[j]+min(dp[j], dp[j-1]);
				if(j != y) d[j] = min(d[j], d[j-1]);
			}
			z = x;
			x = 1;
			y = i;
		}
		if(y == 1) {
			dp[i] = 1E17;
			continue;	
		}
		if(z <= x) dp[i] = c[y-z]-x*a[y-1].first+p[y]-p[i]+a[i].first;
		else dp[i] = min(d[y-x-1]-x*a[y].first+p[y]-p[i]+a[i].first, c[y-x]-x*a[y-1].first+p[y]-p[i]+a[i].first);
	}
	printf("%lld\n", dp[n]);
	
	return 0;
}


