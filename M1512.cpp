#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxlg = 35;

_ t, n, a[maxn], x, h[maxlg], c, mx;
bool flg;

int main() {
	
	scanf("%lld", &t);
	for(; t--; ) { 
		memset(a, 0, sizeof a);
		flg = false;
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld", &x);
			for(; !(x & 1); x >>= 1) ++a[i]; 
			if(x != 1) flg = true;
		}
		mx = -1;
		for(_ i = 1; i <= n; ++i) mx = max(mx, a[i]);
		memset(h, 0, sizeof h);
		for(_ i = 1; i <= n; ++i) ++h[a[i]];
		c = h[1];
		for(_ i = 2; i <= mx; ++i) {
			if(c < i-1) flg = true;
			c += (1LL<<(i-1))*h[i];
		}
		puts(flg ? "Impossible" : "Possible");
	}
	
	return 0;
}
