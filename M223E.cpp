#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E3+8;

_ n, c, dx;
char a[maxn];
set<_> st[3];

str sub(_ x, _ y);
int main() {

	scanf("%lld %s", &n, a+1);
	for(_ i = 1; i <= n-2; ++i) {
		str t = sub(i, i+2);
		if(t == "100" || t == "110") st[2].insert(i);
		ef(t == "010" || t == "101") st[1].insert(i);
	}
	for(; !st[1].empty() || !st[2].empty(); ++c) {
		if(!st[2].empty()) dx = *st[2].begin();
		else dx = *st[1].begin();
		sort(a+dx, a+dx+3);
		for(_ i = dx-2; i <= dx+2; ++i) if(i >= 1 && i <= n-2) {
			st[1].erase(i);
			st[2].erase(i);
			str t = sub(i, i+2);
			if(t == "100" || t == "110") st[2].insert(i);
			ef(t == "010" || t == "101") st[1].insert(i);
		}
	}
	printf("%lld\n", c);

	return 0;
}

str sub(_ x, _ y) {
	str rv;
	for(_ i = x; i <= y; ++i) rv += a[i];
	return rv;
}

