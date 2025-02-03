#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 5E5+8;

_ n, m, s[maxn], q[maxn], mx, dx, p, sm, o[maxn];
struct men {
	_D v;
	_ id;
	bool operator < (men &a) const {
		return v < a.v;
	}
} a[maxn];
priority_queue<_> pq;
_D c, t;

bool cmp(_ a, _ b);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld%lld", &s[i], &q[i]);
		a[i].id = i;
		a[i].v = 1.L*s[i]/q[i];
	}
	sort(a+1, a+1+n);
	for(_ i = 1; i <= n; ++i) {
		pq.push(q[a[i].id]);
		sm += q[a[i].id];
		++p;
		for(; sm*a[i].v > m; ) {
			sm -= pq.top();
			pq.pop();
			--p;
		}
		t = sm*a[i].v;
		if(p > mx) {
			mx = p;
			dx = i;
			c = t;
		} ef(p == mx && c > t) {
			dx = i;
			c = t;
		}
	}
	printf("%lld\n", mx);
	c = a[dx].v;
	for(_ i = 1; i <= dx; ++i) o[i] = a[i].id;
	sort(o+1, o+1+dx, cmp);
	sm = 0;
	for(_ i = 1; i <= dx; ++i) {
		sm += q[o[i]];
		if(c*sm > m) break;
		printf("%lld\n", o[i]);
	}
	
	return 0;
}

bool cmp(_ a, _ b) {
	return q[a] < q[b];
}
