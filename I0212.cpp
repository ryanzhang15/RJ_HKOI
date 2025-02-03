#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E4+8;

_ n, t;
vector<_> a, b, ox, oy;
vector<bool> x, y;

void utopia(vector<_> &rv, vector<_> &a, vector<bool> &p);
int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &t);
		a.push_back(t);
	}
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &t);
		b.push_back(t);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &t);
		_ px = false, py = false;
		if(t == 4) py = true;
		ef(t == 3) px = py = true;
		ef(t == 2) px = true;
		x.push_back(px);
		y.push_back(py);
	}
	utopia(ox, a, x);
	utopia(oy, b, y);
	for(_ i = 0; i < n; ++i) printf("%lld %lld\n", ox[i], oy[i]);
	
	return 0;
}

void utopia(vector<_> &rv, vector<_> &a, vector<bool> &p) {
	_ s = 0, sp, ep;
	bool eq;
	for(_ i = 0; i < p.size()-1; ++i) if(p[i] == p[i+1]) ++s;
	if(p[0]) eq = !!(s & 1);
	else eq = !(s & 1);
	rv.push_back(!!(s & 1) == eq ? -a[s] : a[s]);
	sp = ep = s;
	for(_ i = 1; i < p.size(); ++i) if(p[i] == p[i-1]) rv.push_back(!!(--sp & 1) == eq ? -a[sp] : a[sp]);
	else rv.push_back(!!(++ep & 1) == eq ? -a[ep] : a[ep]);
	
}