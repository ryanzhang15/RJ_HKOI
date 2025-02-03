#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E4+8;
constant mod = 2011;
_ n, dp[maxn];

_ fix(_ x);
_ exponent(_ x, _ c);
int main() {
	
	scanf("%lld", &n);
	dp[1] = 1;
	dp[2] = 3;
	for(_ i = 3; i <= n; ++i) dp[i] = (dp[i-1]+(dp[i-2]<<1))%mod;
	_ o;
	if(!(n & 1)) o = (dp[n>>1]+(dp[(n>>1)-1]<<1))%mod;
	else o = dp[n>>1]; 
	printf("%lld\n", fix(o+(dp[n]-o)*exponent(2, mod-2)));
	
	return 0;
}

_ exponent(_ x, _ c) {
	if(!c) return 1;
	_ t = exponent(x, c>>1);
	t = (t*t)%mod;
	if(c & 1) t = (t*x)%mod;
	return t;
}

_ fix(_ x) {
	return (x%mod+mod)%mod;
}