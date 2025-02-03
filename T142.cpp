#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 25E2+8;

_ n, a[maxn][maxn], b[maxn], s;
deque<_> q;

_ binSearch(_ x);
_ monotone();
int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) scanf("%lld", &a[i][j]);
	for(_ i = 1; i <= n; ++i) {
		for(_ j = 1; j <= n; ++j) b[j] = a[i][j];
		s += monotone();
	}
	for(_ i = 1; i <= n; ++i) {
		for(_ j = 1; j <= n; ++j) b[j] = a[j][i];
		s += monotone();
	}
	printf("%lld\n", s);
	
	return 0;
}

_ monotone() {
	q.clear();
	_ rv = 0;
	for(_ i = 1; i <= n; ++i) {
		rv += binSearch(b[i]);
		for(; !q.empty() && q.back() > b[i]; ) q.pop_back();
		q.push_back(b[i]);
	}
	return rv;
}

_ binSearch(_ x) {
	_ l = 0, r = q.size()-1, md, s = 0;
	for(; l <= r; ) {
		md = (l+r)>>1;
		if(q[md] < x) {
			l = md+1;
			s = md;
		} else r = md-1;
	}
	return q.size()-s;
}