#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 16+8;
constant mod = 1E9+7;

_ n, m, a[maxn], s;
bitset<maxn> t;

_ f(_ x);
_ inv(_ x, _ p);
void operator ++ (bitset<maxn> &x);
bool operator < (const bitset<maxn> x, const _ y);
int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 0; i < n; ++i) scanf("%lld", &a[i]);
	for(t = 0; t < (1LL<<n); ++t) {
		_ cr = m;
		for(_ i = 0; i < n; ++i) if(t[i]) cr -= a[i]+1;
		if(t.count() & 1) s = (s-f(cr))%mod;
		else s = (s+f(cr))%mod;
	}
	printf("%lld\n", (s+mod)%mod);
	
	return 0;
}

void operator ++ (bitset<maxn> &x) {
    x = x.to_ulong()+1;
}

bool operator < (const bitset<maxn> x, const _ y) {
    return x.to_ulong() < y;
}

_ f(_ x) {
	if(x < 0) return 0;
	_ rv = 1, dn = 1;
	for(_ i = x+1; i <= x+n-1; ++i) rv = (rv*i)%mod;
	for(_ i = 2; i <= n-1; ++i) dn = (dn*i)%mod;
	return (rv*inv(dn, mod-2))%mod;
}

_ inv(_ x, _ p) {
	if(!p) return 1;
	_ c = inv(x, p>>1);
	c = (c*c)%mod;
	if(p & 1) c = (c*x)%mod;
	return c;
}