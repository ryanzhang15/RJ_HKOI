#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, p[maxn], dp[maxn], f[maxn];
deque<_> q;

bool cmp(_ x, _ y, _ z);
_ vl(_ pt, _ sp);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &p[i]);
		p[i] += p[i-1];
	}
	for(; m--; ) {
		q.clear();
		q.push_back(0);
		for(_ i = 1; i <= n; ++i) {
			for(; q.size() >= 2 && vl(q[0], i) <= vl(q[1], i); ) q.pop_front();
			f[i] = vl(q.front(), i);
			for(; q.size() >= 2 && cmp(q[q.size()-2], q[q.size()-1], i); ) q.pop_back();
			q.push_back(i);
		}
		for(_ i = 1; i <= n; ++i) dp[i] = f[i];
	}
	printf("%lld\n", dp[n]);
	
	return 0;
}

_ vl(_ pt, _ sp) {
	return dp[pt]+(p[sp]-p[pt])*p[pt];
}

bool cmp(_ x, _ y, _ z) {
	_ xx = p[x], xy = dp[x]-p[x]*p[x], yx = p[y], yy = dp[y]-p[y]*p[y], zx = p[z], zy = dp[z]-p[z]*p[z];
	return (yx-xx)*(zy-yy)-(yy-xy)*(zx-yx) >= 0;
}