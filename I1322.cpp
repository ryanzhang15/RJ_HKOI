#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxt = 1E6+8;
constant maxn = 5E4+8;

_ x, y, n, w[maxn], s[maxn], o = -1, l = 1, r, md, f[maxn], g[maxn], p;
struct toy {
	_ w, s;
	bool operator < (const toy &b) const {
		return w < b.w;
	}
} a[maxt];
priority_queue<_> q;

bool check(_ v);
int main() {
	
	scanf("%lld%lld%lld", &x, &y, &n);
	for(_ i = 1; i <= x; ++i) scanf("%lld", &w[i]);
	for(_ i = 1; i <= y; ++i) scanf("%lld", &s[i]);
	sort(w+1, w+1+x);
	sort(s+1, s+1+y);
	for(_ i = 1; i <= n; ++i) scanf("%lld%lld", &a[i].w, &a[i].s);
	sort(a+1, a+1+n);
	r = n;
	for(; l <= r; ) {
		md = (l+r)>>1;
		if(check(md)) {
			o = md;
			r = md-1;
		} else l = md+1;
	}
	printf("%lld\n", o);
	
	return 0;
}

bool check(_ v) {
	for(_ i = 1; i <= x; ++i) f[i] = v;
	for(_ i = 1; i <= y; ++i) g[i] = v;
	q = priority_queue<_>();
	p = 1;
	for(_ i = 1; i <= x; ++i) {
		for(; p <= n && a[p].w < w[i]; ++p) q.push(a[p].s);
		for(; f[i] && !q.empty(); --f[i]) q.pop();
	}
	for(; p <= n; ++p) q.push(a[p].s);
	for(_ i = y; i >= 1; --i) for(; !q.empty() && q.top() < s[i] && g[i]; --g[i]) q.pop();
	return q.empty();
}