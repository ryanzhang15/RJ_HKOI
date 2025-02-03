#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;

_ n, pl, s = 1E18, asx, asy, adx, dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
bool a[maxn][maxn], b[maxn][maxn];
char amr;

void updSol(_ sx, _ sy, _ dx, char mr);
_ monsters(_ sx, _ sy, _ dr, char mr);
char gc();
int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) pl += a[i][j] = gc() == '#';
	if(pl == 1) {
		if(a[1][1]) {
			amr = '/';
			b[1][1] = true;
		} ef(a[1][n]) {
			amr = '\\';
			b[1][n] = true;
		} ef(a[n][1]) {
			amr = '\\';
			b[n][1] = true;
		} ef(a[n][n]) {
			amr = '/';
			b[n][n] = true;
		} else puts("Impossible");
		for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= n; ++j) putchar(b[i][j] ? amr : '.');
		exit(0);
	}
	for(_ i = 1; i <= n; ++i) {
		updSol(1, i, 0, '/');
		updSol(1, i, 0, '\\');
		updSol(i, n, 1, '/');
		updSol(i, n, 1, '\\');
		updSol(n, i, 2, '/');
		updSol(n, i, 2, '\\');
		updSol(i, 1, 3, '/');
		updSol(i, 1, 3, '\\');
	}
	if(s == 1E18) puts("Impossible");
	else {
		memset(b, 0, sizeof b);
		monsters(asx, asy, adx, amr);
		for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= n; ++j) putchar(b[i][j] ? amr : '.');
	}
	
	return 0;
}

char gc() {
	char rv = getchar();
	for(; rv != '.' && rv != '#'; ) rv = getchar();
	return rv;
}

_ monsters(_ sx, _ sy, _ dr, char mr) {
	if(!a[sx][sy]) return 1E18;
	_ x = sx, y = sy, d = 1, rv = 0;
	for(;;) {
		if((x != sx || y != sy) && (_)a[x-1][y]+a[x+1][y]+a[x][y-1]+a[x][y+1] >= 3) return 1E18;
		ef((x != sx || y != sy) && (_)a[x-1][y]+a[x+1][y]+a[x][y-1]+a[x][y+1] == 1) {
			if(d != pl) return 1E18;
			x += dx[dr];
			y += dy[dr];
			if(x <= 0 || y <= 0 || x > n || y > n) return rv;
			x -= dx[dr];
			y -= dy[dr];
			if(dr == 0) dr = mr == '/' ? 1 : 3;
			ef(dr == 1) dr = mr == '/' ? 0 : 2;
			ef(dr == 2) dr = mr == '/' ? 3 : 1;
			else dr = mr == '/' ? 2 : 0;
			b[x][y] = true;
			x += dx[dr];
			y += dy[dr];
			if(x <= 0 || y <= 0 || x > n || y > n) return rv+1;
		} else {
			++d;
			if(a[x+dx[dr]][y+dy[dr]]) {
				x += dx[dr];
				y += dy[dr];
			} else {
				if(dr == 0) dr = mr == '/' ? 1 : 3;
				ef(dr == 1) dr = mr == '/' ? 0 : 2;
				ef(dr == 2) dr = mr == '/' ? 3 : 1;
				else dr = mr == '/' ? 2 : 0;
				if(a[x+dx[dr]][y+dy[dr]]) {
					b[x][y] = true;
					x += dx[dr];
					y += dy[dr];
					++rv;
				} else return 1E18;
			}
		}
	}
}

void updSol(_ sx, _ sy, _ dx, char mr) {
	_ c = monsters(sx, sy, dx, mr);
	if(c < s) {
		s = c;
		asx = sx;
		asy = sy;
		adx = dx;
		amr = mr;
	}
	return;
}