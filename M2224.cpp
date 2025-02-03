#include <bits/stdc++.h>
#define mp make_pair
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 1E3+8;

_ n, t, ax = 1E11, bx = -1E11, ay = 1E11, by = -1E11, s;
bool a[maxn][maxn], b[maxn][maxn];
struct boundBox {
	_ lx, rx, ly, ry;
	_ vl() {
		if(lx > n) return 1;
		return (rx-lx+1)*(ry-ly+1);
	};
	void add(_ x, _ y) {
		lx = min(lx, x);
		rx = max(rx, x);
		ly = min(ly, y);
		ry = max(ry, y);
		return;
	};
	void init() {
		lx = ly = 1E11;
		rx = ry = -1E11;
		return;
	}
} tl[maxn][maxn], br[maxn][maxn], rw[maxn];

void rect();
void rotate();
int main() {

	scanf("%lld%lld", &n, &t);
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) {
		char ch;
		scanf(" %c", &ch);
		a[i][j] = ch == 'X';
		if(a[i][j]) {
			ax = min(ax, i);
			bx = max(bx, i);
			ay = min(ay, j);
			by = max(by, j);
		}
	}
	s = (bx-ax+1)*(by-ay+1)+t-1;
	if(t == 1) {
		printf("%lld\n", s);
		exit(0);
	}
	rect();
//	printf("pres = %lld\n", s);
	rotate();
	rect();
	rotate();
	rect();
	rotate();
	rect();
	printf("%lld\n", s);

	return 0;
}

void rotate() {
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) b[i][j] = a[n-j+1][i];
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) a[i][j] = b[i][j];
	return;
}

boundBox merge(boundBox x, boundBox y) {
	boundBox rv;
	rv.lx = min(x.lx, y.lx);
	rv.rx = max(x.rx, y.rx);
	rv.ly = min(x.ly, y.ly);
	rv.ry = max(x.ry, y.ry);
	return rv;
}

void rect() {
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) {
		tl[i][j].init();
		br[i][j].init();
	}
//	printf("inivl = %lld\n", tl[1][1].vl());
	for(_ i = 1; i <= n; ++i) rw[i].init();
	if(a[1][1]) tl[1][1].add(1, 1);
	for(_ i = 1; i <= n; ++i) {
		if(i != 1) {
			tl[i][1] = tl[i-1][1];
			if(a[i][1]) tl[i][1].add(i, 1);
		}
		for(_ j = 2; j <= n; ++j) {
			tl[i][j] = tl[i][j-1];
			if(i != 1) tl[i][j] = merge(tl[i][j], tl[i-1][j]);
			if(a[i][j]) tl[i][j].add(i, j);
		}
	}
	if(a[n][n]) br[n][n].add(n, n);
	for(_ i = n; i >= 1; --i) {
		if(i != n) {
			br[i][n] = br[i+1][n];
			if(a[i][n]) br[i][n].add(i, n);
		}
		for(_ j = n-1; j >= 1; --j) {
			br[i][j] = br[i][j+1];
			if(i != n) br[i][j] = merge(br[i][j], br[i+1][j]);
			if(a[i][j]) br[i][j].add(i, j);
		}
	}
//	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) printf("tl[%lld][%lld] = %lld\n", i, j, tl[i][j].vl());
//	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) printf("tl[%lld][%lld] = %lld\n", i, j, br[i][j].vl());
	for(_ i = 1; i <= n-1; ++i) s = min(s, merge(tl[i][n], br[i+1][1]).vl());
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) s = min(s, merge(tl[i-1][n], tl[n][j-1]).vl()+br[i][j].vl());
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) if(a[i][j]) rw[i].add(i, j);
	for(_ i = 2; i <= n-1; ++i) {
		boundBox cr;
		cr.init();
		for(_ j = i; j <= n-1; ++j) {
			cr = merge(cr, rw[j]);
			s = min(s, merge(tl[i-1][n], br[j+1][1]).vl()+cr.vl());
		}
	}
	return;
}

