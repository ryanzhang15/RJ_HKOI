#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant mod = 1E9+9;
constant maxn = 1E5+8;

_ t, n, a[maxn], r[maxn];

_ modExp(_ x, _ p);
_ gondolaCount();
void gondolaReplace();
bool gondolaGood();
int main() {
	
	scanf("%lld%lld", &t, &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	if(t <= 3) puts(gondolaGood() ? "1" : "0");
	ef(t <= 6) gondolaReplace();
	else printf("%lld\n", gondolaCount());
	
	
	return 0;
}

bool gondolaGood() {
	_ md = -1, dx;
	set<_> s;
	for(_ i = 1; i <= n; ++i) {
		if(s.count(a[i])) return false;
		s.insert(a[i]);
		if(a[i] <= n) {
			if(!~md) {
				md = a[i]%n;
				dx = i;
			} ef(a[i]%n != (a[dx]+i-dx)%n) return false;
		}
	}
	return true;
}

void gondolaReplace() {
	_ mx = -1E11, mn = 1E11;
	for(_ i = 1; i <= n; ++i) {
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	if(mx == n) {
		puts("0");
		return;
	}
	if(mn > n) for(_ i = 1; i <= n; ++i) r[i] = i;
	else {
		_ dx;
		for(_ i = 1; i <= n; ++i) if(a[i] <= n) {
			r[i] = a[i];
			dx = i;
			break;
		}
		for(_ i = dx+1; i <= n; ++i) {
			r[i] = (r[i-1]+1)%n;
			if(!r[i]) r[i] = n;
		}
		for(_ i = dx-1; i >= 1; --i) {
			r[i] = (r[i+1]-1+n)%n;
			if(!r[i]) r[i] = n;
		}
	}
	vector<_p> v;
	vector<_> o;
	for(_ i = 1; i <= n; ++i) if(a[i] > n) v.push_back(make_pair(a[i], r[i]));
	v.push_back(make_pair(n, -1));
	sort(v.begin(), v.end());
	for(_ i = 1; i < v.size(); ++i) {
		o.push_back(v[i].second);
		for(_ j = v[i-1].first+1; j < v[i].first; ++j) o.push_back(j);
	}
	printf("%lld\n", o.size());
	for(_ i : o) printf("%lld\n", i);
	return;
}

_ gondolaCount() {
	if(!gondolaGood()) return 0;
	_ rv = 1;
	vector<_> v;
	for(_ i = 1; i <= n; ++i) if(a[i] > n) v.push_back(a[i]);
	v.push_back(n);
	sort(v.begin(), v.end());
	for(_ i = 1; i < v.size(); ++i) rv = (rv*modExp(v.size()-i, v[i]-v[i-1]-1))%mod;
	if(v.size() == n+1) rv = (rv*n)%mod;
	return rv;
}

_ modExp(_ x, _ p) {
	if(x == 1 || !p) return 1;
	_ c = modExp(x, p>>1);
	c = (c*c)%mod;
	if(p & 1) c = (c*x)%mod;
	return c;
}


