#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 2E3+8;
constant lcm = 2520;
constant maxl = 6E3+8;

_ n, x, a[maxn], l = 1, r = maxl-8, md, s;
bitset<maxl> dp[maxn];
str o;

str walk(_ x);
bool check(_ x);
int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		a[i] = lcm/x;
	}
	for(; l <= r; ) {
		md = (l+r)>>1;
		if(check(md)) {
			s = md;
			r = md-1;
		} else l = md+1;
	}
	check(s);
	for(_ i = 0; i <= s; ++i) if(dp[1][i]) o = o.empty() ? walk(i) : min(o, walk(i));
	for(char &i : o) putchar(i);
	putchar(10);
	
	return 0;
}

bool check(_ x) {
	for(_ i = 1; i <= n+1; ++i) dp[i].reset();
	for(_ i = 0; i <= x; ++i) dp[n+1].set(i);
	for(_ i = n; i >= 1; --i) for(_ j = 0; j <= x; ++j) if(j-a[i] >= 0 && dp[i+1][j-a[i]]) dp[i].set(j);
	ef(j+a[i] <= x && dp[i+1][j+a[i]]) dp[i].set(j);
	return !!dp[1].count();
}

str walk(_ x) {
	str rv;
	_ p = x;
	for(_ i = 1; i <= n; ++i) if(p-a[i] >= 0 && dp[i+1][p-a[i]]) {
		rv += 'd';
		p -= a[i];
	} else {
		rv += 'u';
		p += a[i];
	}
	return rv;
}