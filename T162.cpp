#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxk = 2E3+8;

_ n, m, k, l = 1, r = 2E9+8, md, s;
struct crow {
	_ x, y;
} a[maxk];
vector<_> g[maxk];
queue<_> q;
bitset<maxk> v;

bool check();
int main() {
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for(_ i = 1; i <= k; ++i) scanf("%lld%lld", &a[i].x, &a[i].y);
	for(; l <= r; ) {
		md = (l+r)>>1;
		if(check()) {
			s = md;
			l = md+1;
		} else r = md-1;
	}
	printf("%lld\n", s);
	
	return 0;
}

bool check() {
	for(_ i = 1; i <= k+4; ++i) g[i].clear();
	for(; !q.empty(); ) q.pop();
	v.reset();
	
	for(_ i = 1; i <= k; ++i) {
		if(a[i].x <= md) {
			g[k+1].push_back(i);
			g[i].push_back(k+1);
		}
		if(a[i].y <= md) {
			g[k+2].push_back(i);
			g[i].push_back(k+2);
		}
		if(n-a[i].x+1 <= md) {
			g[k+3].push_back(i);
			g[i].push_back(k+3);
		}
		if(m-a[i].y+1 <= md) {
			g[k+4].push_back(i);
			g[i].push_back(k+4);
		}
	}
	for(_ i = 1; i <= k; ++i) for(_ j = i+1; j <= k; ++j) if(a[i].x == a[j].x) {
		if(abs(a[i].y-a[j].y) <= (md<<1)-1) {
			g[i].push_back(j);
			g[j].push_back(i);
		}
	} ef(a[i].y == a[j].y) {
		if(abs(a[i].x-a[j].x) <= (md<<1)-1) {
			g[i].push_back(j);
			g[j].push_back(i);
		}
	} else {
		if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y) <= md<<1) {
			g[i].push_back(j);
			g[j].push_back(i);
		}
	}
	q.push(k+2);
	q.push(k+3);
	v.set(k+2);
	v.set(k+3);
	for(; !q.empty(); q.pop()) {
		_ t = q.front();
		for(_ i : g[t]) if(!v[i]) {
			if(i == k+1 || i == k+4) return false;
			v.set(i);
			q.push(i);
		}
	}
	return true;
}