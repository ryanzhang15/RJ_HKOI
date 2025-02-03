#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ a[maxn], b[maxn], n, h, m, c, rt, dw, mx, x, p = 1, t = 1;

char gc();
int main() {
	
	scanf("%lld%lld", &n, &h);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);	
		mx = max(mx, a[i]);
	}
	scanf("%lld", &m);
	for(_ i = 1; i <= m; ++i) if(gc() == 'N') {
		++rt;
		b[++c] = -1;
	} else {
		++dw;
		if(!c || !~b[c]) b[++c] = 1;
		else ++b[c];	
	}
	if(!dw) if(h >= mx) {
		puts("FOREVER");
		exit(0);
	} 
	if(!rt) {
		puts("TOP\n0");
		exit(0);
	}
	if(dw) {
		x = (h-mx)/dw;
		if(!((h-mx)%dw)) --x;
	}
	x = max(x, 0LL);
	h -= dw*x;
	p = (p+rt*x)%n;
	if(!p) p = n;
	for(;;) {
		if(!~b[t]) {
			++p;
			if(p > n) p = 1;
			if(h < a[p]) {
				puts("SIDE");
				printf("%lld\n", p-1);
				exit(0);
			}
		} else {
			h -= b[t];
			if(h < a[p]) {
				puts("TOP");
				printf("%lld\n", p-1);
				exit(0);
			}
		}
		++t;
		if(t > c) t = 1;
	}
	
	return 0;
}

char gc() {
	char ch = getchar();
	for(; ch != 'N' && ch != 'D'; ) ch = getchar();
	return ch;
}