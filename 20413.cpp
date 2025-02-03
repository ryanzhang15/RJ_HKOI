#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 30+8;
_ a[maxn], b[maxn];

int main() {
	
	for(; scanf("%lld", &a[1]) && a[1]; ) {
		_ p = 2, sv = 0, uc = 0, dc = 0, ut = 0, dt = 0;
		bool up = true, nc = true;
		for(; scanf("%lld", &a[p]) && a[p]; ) ++p;
		--p;
		for(_ i = 2; i <= p; ++i) if(a[i] == a[i-1]) ++sv;
		ef(a[i] > a[i-1]) {
			if(!up) {
				up = true;
				if(dc) ++dt;
				if(nc) uc += sv;
				else dc += sv;
				sv = 0;
			}
			++uc;
			nc = false;
		} else {
			if(up) {
				up = false;
				if(uc) ++ut;
				if(nc) dc += sv;
				else uc += sv;
				sv = 0;
			}
			++dc;
			nc = false;
		}
		if(up && uc) {
			++ut;
			uc += sv;
		} 
		if(!up && dc) {
			++dt;
			dc += sv;
		}
		printf("Nr values = %lld:  %.6Lf %.6Lf\n", p, ut ? (_D)uc/ut : (_D)0, dt ? (_D)dc/dt : (_D)0);
	}
	
	return 0;
}