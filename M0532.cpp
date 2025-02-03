#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E4+8;

_ n, m, k, a[maxn], ls[maxn], t[maxn], s;
set<_> c;
vector<_> ap[maxn];

int main() {
	
	memset(ls, 4, sizeof ls);
	scanf("%lld%lld%lld", &k, &n, &m);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		ap[a[i]].push_back(i);
	}
	for(_ i = 1; i <= m; ++i) ap[i].push_back(10000000000000000LL);
	for(_ i = 1; i <= n; ++i) {
		if(c.count(a[i])) continue;
		if(c.size() >= k) {
			_ mx = -1;
			set<_>::iterator dx;
			for(set<_>::iterator j = c.begin(); j != c.end(); ++j) {
				_ t = *lower_bound(ap[*j].begin(), ap[*j].end(), i);
				if(t >= mx) {
					mx = t;
					dx = j;
				}
			}
			c.erase(dx);
		}
		++s;
		c.insert(a[i]);
	}
	printf("%lld\n", s);
	
	return 0;
}