#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E4+8;

_ n, m, oa[maxn], ob[maxn], oc[maxn], od[maxn], a[maxn], ct[maxn];

int main() {
	
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= m; ++i) {
		scanf("%lld", &a[i]);
		++ct[a[i]];
	}
	for(_ i = 1; i*9 < n; ++i) {
		{
			_ sm = 0;
			for(_ d = 9*i+2; d <= n; ++d) {
				_ a = d-9*i-1;
				_ b = a+(i<<1);
				_ c = d-i;
				sm += ct[a]*ct[b];
				od[d] += ct[c]*sm;
				oc[c] += ct[d]*sm;
			}
		}
		{
			_ sm = 0;
			for(_ a = n-9*i-1; a >= 1; --a) {
				_ b = a+(i<<1);
				_ c = b+6*i+1;
				_ d = a+9*i+1;
				sm += ct[c]*ct[d];
				ob[b] += ct[a]*sm;
				oa[a] += ct[b]*sm;
			}
		}
	}
	for(_ i = 1; i <= m; ++i) printf("%lld %lld %lld %lld\n", oa[a[i]], ob[a[i]], oc[a[i]], od[a[i]]);
	
	return 0;
}