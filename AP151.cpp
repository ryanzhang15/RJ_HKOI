#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E3+8;
constant logg = 41;

_ n, l, r, a[maxn], s = (1LL<<(logg+1))-1, b[maxn];
bool c[maxn][maxn];

bool relax(_ x);
bool relax2(_ x);
bool relax1(_ x);
int main() {
	
	scanf("%lld%lld%lld", &n, &l, &r);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i <= n; ++i) a[i] += a[i-1];
	for(_ i = 1LL<<logg; i >= 1; i >>= 1) if(relax(s^i)) s ^= i;
	printf("%lld\n", s);
		
	return 0;
}

bool relax(_ x) {
	if(l == 1) return relax1(x);
	else return relax2(x);
}

bool relax1(_ x) {
	for(_ i = 1; i <= n; ++i) b[i] = r+1;
	b[0] = 0;
	for(_ i = 1; i <= n; ++i) for(_ j = 0; j <= i-1; ++j) if(((a[i]-a[j])|x) <= x) b[i] = min(b[i], b[j]+1);
	return b[n] <= r;
}

bool relax2(_ x) {
	memset(c, false, sizeof c);
	c[0][0] = true;
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= min(r, i); ++j) for(_ k = 0; k <= i-1; ++k) if(((a[i]-a[k])|x) <= x && c[k][j-1]) {
		c[i][j] = true;
		break;
	}
	for(_ i = l; i <= r; ++i) if(c[n][i]) return true;
	return false;
}