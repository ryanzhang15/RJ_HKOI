#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E3+8;

_ r, c, n, x, y;
bool o[maxn][maxn], f[maxn][maxn], g[maxn][maxn], h[maxn][maxn], k[maxn][maxn];

int main() {
	
	scanf("%lld%lld%lld", &r, &c, &n);
	for(; n--; ) {
		scanf("%lld%lld", &x, &y);
		o[x][y] = true;
	}
	f[1][1] = g[r][c] = true;
	for(_ i = 1; i <= r; ++i) for(_ j = 1; j <= c; ++j) if(!(i == 1 && j == 1)) f[i][j] = !o[i][j] && (f[i-1][j] || f[i][j-1]);
	for(_ i = r; i >= 1; --i) for(_ j = c; j >= 1; --j) if(!(i == r && j == c)) g[i][j] = !o[i][j] && (g[i+1][j] || g[i][j+1]);
	for(_ i = r; i >= 1; --i) for(_ j = 1; j <= c; ++j) h[i][j] = h[i+1][j] || h[i][j-1] || (f[i][j] && g[i][j]);
	for(_ i = 1; i <= r; ++i) for(_ j = c; j >= 1; --j) k[i][j] = k[i-1][j] || k[i][j+1] || (f[i][j] && g[i][j]);
	if(!k[1][1]) {
		puts("0");
		exit(0);
	}
//	for(_ i = 1; i <= r; ++i, putchar(10)) for(_ j = 1; j <= c; ++j) printf("%lld ", (_)f[i][j]);
//	putchar(10);
//	for(_ i = 1; i <= r; ++i, putchar(10)) for(_ j = 1; j <= c; ++j) printf("%lld ", (_)g[i][j]);
//	putchar(10);
//	for(_ i = 1; i <= r; ++i, putchar(10)) for(_ j = 1; j <= c; ++j) printf("%lld ", (_)h[i][j]);
//	putchar(10);
//	for(_ i = 1; i <= r; ++i, putchar(10)) for(_ j = 1; j <= c; ++j) printf("%lld ", (_)k[i][j]);
//	putchar(10);
	for(_ i = 1; i <= r; ++i) for(_ j = 1; j <= c; ++j) if(!(i == 1 && j == 1) && !(i == r && j == c) && !o[i][j] && !h[i+1][j-1] && !k[i-1][j+1]) {
		puts("1");
		printf("%lld %lld\n", i, j);
		exit(0);
	}
	puts("2\n2 1\n1 2\n");
	
	
	
	return 0;
}