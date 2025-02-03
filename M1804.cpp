#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ q, a, b, c, d;

__int128 pow(_ x, _ y);
void fracOut(_ nm, _ dn);
_ gcd(_ a, _ b);
int main() {
	
	scanf("%lld", &q);
	for(; q--; ) {
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if(c<<1 == d) fracOut(a-b, a);
		else fracOut(pow(c, a)-pow(c, b)*pow(d-c, a-b), pow(c, a)-pow(d-c, a));
	}
	
	return 0;
}

_ gcd(_ a, _ b) {
	return !b ? a : gcd(b, a%b);
}

void fracOut(_ nm, _ dn) {
	_ g = gcd(nm, dn);
	nm /= g;
	dn /= g;
	printf("%lld %lld\n", nm, dn);
	return;
}

__int128 pow(_ x, _ y) {
	__int128 rv = 1;
	for(_ i = 1; i <= y; ++i) rv *= x;
	return rv;
}