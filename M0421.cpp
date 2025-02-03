#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;

_ n, a[maxn][maxn], p[maxn][maxn], w[maxn][maxn], x[maxn][maxn], s;

_ bSearch2(_ x, _ y);
_ bSearch1(_ x, _ y);
_ gc();
int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) a[i][j] = p[i][j] = gc();
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) p[i][j] += p[i-1][j];
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) p[i][j] += p[i][j-1];
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) w[i][j] = max(max(w[i-1][j], w[i][j-1]), bSearch1(i, j));
	for(_ i = n; i >= 1; --i) for(_ j = n; j >= 1; --j) x[i][j] = max(max(x[i+1][j], x[i][j+1]), bSearch2(i, j));
	for(_ i = 1; i <= n-2; ++i) if(w[i][n] && x[i+2][1]) s = max(s, w[i][n]*w[i][n]+x[i+2][1]*x[i+2][1]);
	for(_ i = 1; i <= n-2; ++i) if(w[n][i] && x[1][i+2]) s = max(s, w[n][i]*w[n][i]+x[1][i+2]*x[1][i+2]);
	printf("%lld\n", s);
	
	return 0;
}

_ gc() {
	char ch = getchar();
	for(; !(ch == '1' || ch == '0'); ) ch = getchar();
	return ch^48;
}

_ bSearch1(_ x, _ y) {
	if(a[x][y]) return 0;
	_ l = 1, r = min(x, y), md, rv = 1;
	for(; l <= r; ) {
		md = (l+r)>>1;
		if(!(p[x][y]-p[x-md][y]-p[x][y-md]+p[x-md][y-md])) {
			rv = md;
			l = md+1;
		} else r = md-1;
	}
	return rv;
}

_ bSearch2(_ x, _ y) {
	if(a[x][y]) return 0;
	_ l = 1, r = min(n-x, n-y)+1, md, rv = 1;
	for(; l <= r; ) {
		md = (l+r)>>1;
		if(!(p[x+md-1][y+md-1]-p[x-1][y+md-1]-p[x+md-1][y-1]+p[x-1][y-1])) {
			rv = md;
			l = md+1;
		} else r = md-1;
	}
	return rv;
}
