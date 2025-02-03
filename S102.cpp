#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

struct rg {
	_ h, st, sz;
} a[maxn], b[maxn];
_ n, r = 1;

void reduce();
int main() {
	
	a[0].sz = 1;
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld%lld", &a[i].h, &a[i].sz);
		a[i].st = a[i-1].st+a[i-1].sz;
	}
	for(; ; r <<= 1) reduce();
	
	return 0;
}

void reduce() {
	if(n == 1 && a[1].sz == 1) {
		printf("%lld\n", a[1].st);
		exit(0);
	}
	if(n == 2) {
		if(a[1].sz == 1 && a[2].h == 600) {
			printf("%lld\n", a[1].st);
			exit(0);
		}
		if(a[2].sz == 1 && a[1].h == 600) {
			printf("%lld\n", a[2].st);
			exit(0);
		}
	}
	_ cnt = 0, lst, lsz, lh, lp = -1;
	bool l = false;
	for(_ i = 1; i <= n; ++i) {
		if(l) {
			if(a[i].h > lh) {
				if(--lsz) b[++cnt] = (rg){lh, lst, lsz>>1};
				else lp = lst;
				++a[i].sz;
			} else {
				b[++cnt] = (rg){lh, lst, (lsz+1)>>1};
				if(!--a[i].sz) {
					l = false;
					lp = a[i].st;
					continue;
				} 
				a[i].st += r;
			}
		} 
		if(a[i].sz & 1) {
			l = true;
			lst = a[i].st;
			lsz = a[i].sz;
			lh = a[i].h;
		} else {
			l = false;
			b[++cnt] = (rg){a[i].h, a[i].st, a[i].sz>>1};
		}
	}
	memcpy(a, b, sizeof b);
	n = cnt;
	if(n == 1 && a[1].h == 600 && ~lp) {
		printf("%lld\n", lp);
		exit(0);
	}
	return;
}