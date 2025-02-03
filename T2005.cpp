#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, w, b, s[maxn], t, o[maxn], sm, v[maxn];
struct rg {
	_ l, r;
} a[maxn], c, sv;

void no();
int main() {
	
	scanf("%lld%lld%lld", &n, &w, &b);
	for(_ i = 1; i <= n-w+1; ++i) scanf("%lld", &s[i]);
	for(_ i = 1; i <= w; ++i) a[i] = (rg){0, b};
	for(_ i = 1, j = w+1; j <= n; i = i+1 > w ? 1 : i+1, ++j) {
		v[j] = v[j-w]+s[j-w+1]-s[j-w];
		a[i].l = max(a[i].l, -v[j]);
		a[i].r = min(a[i].r, b-v[j]);
		if(a[i].l > a[i].r) no();
	}
	c = a[1];
	for(_ i = 2; i <= w; ++i) {
		c.l += a[i].l;
		c.r += a[i].r;
	}
	if(c.r < s[1] || c.l > s[1]) no();
	puts("Yes");
	t = c.l;
	for(_ i = 1; i <= w; ++i) if(t == s[1]) o[i] = a[i].l;
	ef(s[1]-t > a[i].r-a[i].l) {
		o[i] = a[i].r;
		t += a[i].r-a[i].l;
	} else {
		o[i] = a[i].l+s[1]-t;
		t = s[1];
	}
	for(_ i = 2; i <= w; ++i) sm += o[i];
	for(_ i = w+1, j = 2; i <= n; ++i, ++j) {
		o[i] = s[j]-sm;
		sm += o[i]-o[j];
	}
	for(_ i = 1; i <= n; ++i) printf("%lld ", o[i]);
	putchar(10);	
	
	return 0;
}

void no() {
	puts("No");
	exit(0);
}

/*
2 3 4 5 1 2 3 4 1 5 9 2 1 3 4 2 3 4 3 2
20 3 9
9 12 10 8 6 9 8 10 15 16 12 6 8 9 9 9 10 9

1 2 3 4 1 5
6 3 5
6 9 8 10
*/