#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E4+8;

_ n, x, a[maxn], s = 1E18;
struct node {
	_ r, l;
	bool operator < (const node &b) const {
		return r < b.r;
	}
} b[maxn];

int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		a[x] = i;
	}
	for(_ i = 1; i <= n; ++i) if(a[i] > i) {
		b[i].r = a[i]-i;
		b[i].l = n-b[i].r;
	} else {
		b[i].l = i-a[i];
		b[i].r = n-b[i].l;
	}
	sort(b+1, b+1+n);
	for(_ i = 0; i <= n; ++i) s = min(s, (min(b[i].r, b[i+1].l)<<1)+max(b[i].r, b[i+1].l));
	printf("%lld\n", s);
	
	return 0;
}