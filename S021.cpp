#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E2+8;
constant maxm = 1E4+8;

struct info {
	_ x, y;
	bool operator < (const info &b) {
		return y < b.y;
	}
} f[maxm];
_ n, m, a[maxn], r[maxn], cnt, o[maxm];

int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) a[i] = i;
	for(_ i = 1; i <= m; ++i) scanf("%lld%lld", &f[i].x, &f[i].y);
	sort(f+1, f+1+m);
	for(_ i = 1; i <= m; ++i) swap(a[f[i].x], a[f[i].x+1]);
	for(_ i = 1; i <= n; ++i) printf("%lld ", a[i]);
	putchar(10);
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i <= n; ++i) r[a[i]] = i;
	for(_ i = 1; i <= n; ++i) a[i] = i;
	for(_ i = n; i >= 2; --i) for(_ j = 1; j <= i-1; ++j) if(r[j] > r[j+1]) {
		swap(r[j], r[j+1]);
		o[++cnt] = j;
	}
	printf("%lld\n", cnt);
	for(_ i = 1; i <= cnt; ++i) printf("%lld %lld\n", o[i], i);
		
	return 0;
}