#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ k, n, x, y, s, o, p[maxn];
struct work {
	_ a, b;
	bool operator < (const work &y) const {
		return a+b < y.a+y.b;
	}
} a[maxn];
struct sliding_median {
	_ l, r;
	priority_queue<_> lq;
	priority_queue<_, vector<_>, greater<_> > rq;
	_ median() {
		return lq.empty() ? 1E11 : lq.top();
	}
	void insert(_ x) {
		if(x <= median()) {
			l += x;
			lq.push(x);
		} else {
			r += x;
			rq.push(x);
		}
		if((_)lq.size()-(_)rq.size() >= 2) {
			l -= lq.top();
			r += lq.top();
			rq.push(lq.top());
			lq.pop();
		} 
		if((_)rq.size()-(_)lq.size() >= 1) {
			l += rq.top();
			r -= rq.top();
			lq.push(rq.top());
			rq.pop();
		}
		return;
	}
	_ diff() {
		return r-l;
	}
	void reset() {
		lq = priority_queue<_>();
		rq = priority_queue<_, vector<_>, greater<_> >();
		l = r = 0;
		return;
	}
} q;
char cx, cy;

char gc();
int main() {
	
	scanf("%lld%lld", &k, &x);
	for(_ i = x; i--; ) {
		cx = gc();
		scanf("%lld", &x);
		cy = gc();
		scanf("%lld", &y);
		if(cx == cy) s += abs(x-y);
		else a[++n] = (work){x, y};
	}
	if(k == 1) {
		for(_ i = 1; i <= n; ++i) {
			q.insert(a[i].a);
			q.insert(a[i].b);
		}
		printf("%lld\n", s+q.diff()+n);
		exit(0);
	}
	sort(a+1, a+1+n);
	for(_ i = 1; i <= n; ++i) {
		q.insert(a[i].a);
		q.insert(a[i].b);
		p[i] = q.diff();
	}
	o = q.diff();
	q.reset();
	for(_ i = n; i >= 1; --i) {
		q.insert(a[i].a);
		q.insert(a[i].b);
		o = min(o, q.diff()+p[i-1]);
	}
	printf("%lld\n", o+s+n);
	
	return 0;
}

char gc() {
	char ch = getchar();
	for(; ch != 'A' && ch != 'B'; ) ch = getchar();
	return ch;
}