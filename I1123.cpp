#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 320+8;
constant maxb = 20+8;
constant maxd = 16+8;

_ a[maxn], b[maxb][maxd], t, n, m, x;
char tp;

int main() {

#ifdef c8korz
	freopen("data.in", "r", stdin);
	freopen("c8k.out", "w", stdout);
#endif

	for(_ i = 0; i <= 16; ++i) b[20][i] = 1;
	for(_ i = 19; i >= 1; --i) for(_ j = 0; j <= 16; ++j) for(_ k = j; k <= 16; ++k) b[i][j] += b[i+1][k];
	
	tp = getchar();
	scanf("%lld", &t);
	for(; t--; ) {
		scanf("%lld", &n);
		if(tp == 'E') {
			vector<_> s;
			for(_ ad = 0; n > 0; n -= 4, ad += 16) {
				_ c = 100;
				for(_ i = 1, t = 1; i <= min(4LL, n); ++i, t *= 256) {
					scanf("%lld", &x);
					c += x*t;
				}
				vector<_> o;
				_ p = 0;
				for(_ i = 1; i <= 20; ++i) {
					_ t = 0;
					for(; t+b[i][p] <= c; ++p) t += b[i][p];
					c -= t;
					o.push_back(p);
				}
				for(_ i : o) if(i) s.push_back(i-1+ad);
			}
			printf("%lld ", s.size());
			for(_ i : s) printf("%lld ", i);
			putchar(10);
		} else {
			scanf("%lld", &m);
			for(_ i = 1; i <= m; ++i) scanf("%lld", &a[i]);
			sort(a+1, a+1+m);
			_ p = 1, sv = n;
			vector<_> s;
			for(_ ad = 0; sv > 0; sv -= 4, ad += 16) {
				vector<_> t;
				{
					vector<_> c;
					for(; p <= m && a[p] < ad+16; ++p) c.push_back(a[p]-ad+1);
					for(_ i = c.size(); i <= 20; ++i) t.push_back(0);
					for(_ i : c) t.push_back(i);
				}
				_ c = 0, r = 0;
				for(_ i = 1; i <= 20; ++i) for(; r < t[i]; ++r) c += b[i][r];
				c -= 100;
				for(_ i = 1; i <= 4; ++i, c >>= 8) s.push_back(c & 255);
			}
			for(; s.size() > n; ) s.pop_back();
			for(_ i : s) printf("%lld ", i);
			putchar(10);
		}
	}

	return 0;
}