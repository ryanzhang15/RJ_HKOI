#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E3+8;

struct plastic {
	_ x, y;
	bool operator == (const plastic &b) const {
		return x == b.x && y == b.y;
	}
} a[maxn];
_ gcd(_ a, _ b);
struct slope {
	_ y, x;
	void make(plastic a, plastic b) {
		y = a.y-b.y;
		x = a.x-b.x;
		_ g = gcd(y, x);
		y /= g;
		x /= g;
		if(!y) x = 0;
		return;
	}
	bool operator < (const slope &b) const {
		if(y != b.y) return y < b.y;
		return x < b.x;
	}
	bool operator == (const slope &b) const {
		return y == b.y && x == b.x;
	}
} c[maxn];
_ n, s, cnt, sc, cr, cb;

int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld%lld", &a[i].x, &a[i].y);
	for(_ i = 1; i <= n; ++i) {
		cnt = sc = cb = 0;
		cr = 1;
		for(_ j = 1; j <= n; ++j) {
			if(a[i] == a[j]) {
				++sc;
				continue;
			}
			c[++cnt].make(a[i], a[j]);
		}
		sort(c+1, c+1+cnt);
		//for(_ i = 1; i <= cnt; ++i) printf("SLOPE: %lld / %lld\n", c[i].y, c[i].x);
		//putchar(10);
		for(_ i = 2; i <= cnt; ++i) {
			if(c[i] == c[i-1]) ++cr;
			else cr = 1;
			cb = max(cb, cr);
		}
		s = max(s, sc+cb);
	}
	
	printf("%lld\n", s);
	
	return 0;
}

_ gcd(_ a, _ b) {
	if(!b) return a;
	return gcd(b, a%b);
}
