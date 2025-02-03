#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
constant mod = 1E9+7;

_ n, m, fac[maxn<<1];

_ exponent(_ x, _ c);
int main() {
	
	fac[0] = 1;
	for(_ i = 1; i <= 2E5; ++i) fac[i] = (i*fac[i-1])%mod;
	for(_ i = 1; ; ++i) {
		scanf("%lld%lld", &m, &n);
		if(!(n | m)) break;
		printf("Test #%lld:\n", i);
		if(n > m) {
			puts("0");
			continue;
		}
		_ o = (fac[m+n] * exponent((fac[n]*fac[m])%mod, mod-2))%mod;
		o -= (fac[m+n] * exponent((fac[n-1]*fac[m+1])%mod, mod-2))%mod;
		o = (o+mod)%mod;
		o = (((o*fac[m])%mod)*fac[n])%mod;
		printf("%lld\n", o);
	}
	
	return 0;
}

_ exponent(_ x, _ c) {
	if(!c) return 1;
	_ t = exponent(x, c>>1);
	t = (t*t)%mod;
	if(c & 1) t = (t*x)%mod;
	return t;
}