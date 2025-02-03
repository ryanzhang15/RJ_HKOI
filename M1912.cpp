#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E2+8;

struct museum {
	_ a, b, c, id;
	bool operator < (const museum &y) const {
		return b > y.b;
	}
} a[maxn];
_ n, m, dp[maxn][maxn], s, k;
bool p[maxn][maxn][maxn];
stack<_> o;

int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c);
		a[i].id = i;
	}
	sort(a+1, a+1+n);
	for(_ i = 1; i <= n; ++i) for(_ j = m; j >= a[i].c; --j) for(_ k = i; k >= 1; --k) if(dp[j-a[i].c][k-1]+a[i].a-(k-1)*a[i].b > dp[j][k]) {
		dp[j][k] = dp[j-a[i].c][k-1]+a[i].a-(k-1)*a[i].b;
		p[i][j][k] = true;
	}
	for(_ i = 1; i <= n; ++i) if(dp[m][i] > s) {
		s = dp[m][i];
		k = i;
	}
	printf("%lld %lld\n", s, k);
	for(_ i = n; i >= 1; --i) if(p[i][m][k]) {
		o.push(a[i].id);
		m -= a[i].c;
		--k;
	}
	for(; !o.empty(); o.pop()) printf("%lld ", o.top());
	putchar(10);
	
	return 0;
}