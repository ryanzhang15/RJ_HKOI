#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 20+8;
constant maxd = 2E2+8;

_ n, m, e, f, b[maxn][maxn], v[maxd], x, y, r[maxd];
char a[maxn][maxn];

void recur(_ x, _ y);
int main() {
	
	scanf("%lld%lld%lld%lld", &n, &m, &e, &f);
	for(_ i = 1; i <= n; ++i) scanf(" %s", a[i]+1);
	for(_ i = 1; i <= e; ++i) {
		scanf("%lld", &r[i]);
		++v[r[i]];
	}
	for(; f--; ) {
		scanf("%lld%lld", &x, &y);
		scanf("%lld", &b[x][y]);
	}
	recur(1, 1);
	
	return 0;
}

void recur(_ x, _ y) {
	if(x > n) {
		for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= m; ++j) printf("%lld ", b[i][j]);
		exit(0);
	}
	if(a[x][y] == 'F') {
		if((x > 2 && b[x-1][y] && b[x-2][y] && b[x][y]-b[x-1][y] != b[x-1][y]-b[x-2][y]) || ((y > 2) && b[x][y-1] && b[x][y-2] && b[x][y]-b[x][y-1] != b[x][y-1]-b[x][y-2])) return;
		recur(y == m ? x+1 : x, y == m ? 1 : y+1);
	} ef(a[x][y] == '.') recur(y == m ? x+1 : x, y == m ? 1 : y+1);
	else {
		if(x > 2 && b[x-1][y] && b[x-2][y] && y > 2 && b[x][y-1] && b[x][y-2]) {
			_ df = b[x-1][y]-b[x-2][y], df2 = b[x][y-1]-b[x][y-2];
			_ nw = b[x-1][y]+df;
			if(nw != b[x][y-1]+df2 || nw < 1 || nw > 200 || !v[nw]) return;
			b[x][y] = nw;
			--v[nw];
			recur(y == m ? x+1 : x, y == m ? 1 : y+1);
			++v[nw];
			b[x][y] = 0;
		} ef(x > 2 && b[x-1][y] && b[x-2][y]) {
			_ df = b[x-1][y]-b[x-2][y];
			_ nw = b[x-1][y]+df;
			if(nw < 1 || nw > 200 || !v[nw]) return;
			b[x][y] = nw;
			--v[nw];
			recur(y == m ? x+1 : x, y == m ? 1 : y+1);
			++v[nw];
			b[x][y] = 0;
		} ef(y > 2 && b[x][y-1] && b[x][y-2]) {
			_ df = b[x][y-1]-b[x][y-2];
			_ nw = b[x][y-1]+df;
			if(nw < 1 || nw > 200 || !v[nw]) return;
			b[x][y] = nw;
			--v[nw];
			recur(y == m ? x+1 : x, y == m ? 1 : y+1);
			++v[nw];
			b[x][y] = 0;
		} else for(_ i = 1; i <= e; ++i) if(v[r[i]]) {
			b[x][y] = r[i];
			--v[r[i]];
			recur(y == m ? x+1 : x, y == m ? 1 : y+1);
			++v[r[i]];
			b[x][y] = 0;
		}
	}
	return;
}
