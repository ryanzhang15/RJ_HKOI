#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant big = 1000000000;

_ x, y;

_ pw(_ x, _ p);
int main() {

	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);

	scanf("%lld %lld", &x, &y);
	printf("%lld\n", pw(x, y));

	return 0;
}

_ pw(_ x, _ p) {
	if(!p) return 1;
	_ c = pw(x, p>>1);
	if(c == -1) return -1;
	c = c*c;
	if(c > big) return -1;
	if(p & 1) {
		c = c*x;
		if(c > big) return -1;
	}
	return c;
}
