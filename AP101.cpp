#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E6+8;

_ n, a, b, c, dp[maxn], p[maxn];
deque<_> q;

bool cmp(_ x, _ y, _ z);
_ vl(_ pt, _ sl);
int main() {
	
	scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &p[i]);
		p[i] += p[i-1];
	}
	q.push_back(0);
	for(_ i = 1; i <= n; ++i) {
		for(; q.size() >= 2 && vl(q[0], i) <= vl(q[1], i); ) q.pop_front();
		dp[i] = vl(q.front(), i)+a*p[i]*p[i]+b*p[i]+c;
		for(; q.size() >= 2 && cmp(q[q.size()-2], q[q.size()-1], i); ) q.pop_back();
		q.push_back(i); 
	}
	printf("%lld\n", dp[n]);
	
	return 0;
}

_ vl(_ pt, _ sl) {
	return -2*a*p[pt]*p[sl]+dp[pt]+a*p[pt]*p[pt]-b*p[pt];
}

bool cmp(_ x, _ y, _ z) {
	_ xx = p[x], xy = dp[x]+a*p[x]*p[x]-b*p[x], yx = p[y], yy = dp[y]+a*p[y]*p[y]-b*p[y], zx = p[z], zy = dp[z]+a*p[z]*p[z]-b*p[z];
	return (yx-xx)*(zy-yy)-(yy-xy)*(zx-yx) >= 0;
}