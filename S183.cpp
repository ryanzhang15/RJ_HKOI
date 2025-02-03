#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxr = 80+8;
constant maxn = maxr*maxr;
constant maxk = 1E2+8;

_ n, r, c, k, wc, bc, x, y, vl, t, s = -1E18, wl, cnt;
struct icon {
	_ x, y, v;
	bool operator < (const icon &b) const {
		return v > b.v;
	}
} w[maxn], b[maxn];
struct wallpaper {
	bool d[maxr][maxr];
	_ wc, bc;
} a[maxk];
char ch;
struct coords {
	_ x, y;
};
bool v[maxr][maxr];
queue<coords> wf, bf, wws, bs;
struct shift {
	_ a, b, c, d;
} o[6408];

char gc();
int main() {
	
	scanf("%lld%lld%lld", &n, &r, &c);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld%lld %c%lld", &x, &y, &ch, &vl);
		if(ch == 'W') w[++wc] = (icon){x, y, vl};
		else b[++bc] = (icon){x, y, vl};
	}
	scanf("%lld", &k);
	for(_ i = 1; i <= k; ++i) for(_ j = 1; j <= r; ++j) for(_ l = 1; l <= c; ++l) {
		a[i].d[j][l] = gc() == 'B';
		if(a[i].d[j][l]) ++a[i].bc;
		else ++a[i].wc;
	}
	if(n == r*c) {
		for(_ i = 1; i <= k; ++i) {
			t = 0;
			for(_ j = 1; j <= wc; ++j) if(a[i].d[w[j].x][w[j].y]) t += w[j].v;
			for(_ j = 1; j <= bc; ++j) if(!a[i].d[b[j].x][b[j].y]) t += b[j].v;
			if(t > s) {
				s = t;
				wl = i;
			}
		}
		printf("%lld %lld 0\n", s, wl);
		exit(0);
	}
	sort(w+1, w+1+wc);
	sort(b+1, b+1+bc);
	for(_ i = 1; i <= k; ++i) {
		t = 0;
		for(_ j = 1; j <= min(wc, a[i].bc); ++j) t += w[j].v;
		for(_ j = 1; j <= min(bc, a[i].wc); ++j) t += b[j].v;
		if(t > s) {
			s = t;
			wl = i;
		}
	}
	printf("%lld %lld ", s, wl);
	for(_ i = 1; i <= min(wc, a[wl].bc); ++i) {
		v[w[i].x][w[i].y] = true;
		if(!a[wl].d[w[i].x][w[i].y]) bf.push((coords){w[i].x, w[i].y});
	}
	for(_ i = min(wc, a[wl].bc)+1; i <= wc; ++i) {
		v[w[i].x][w[i].y] = true;
		if(a[wl].d[w[i].x][w[i].y]) wf.push((coords){w[i].x, w[i].y});
	}
	for(_ i = 1; i <= min(bc, a[wl].wc); ++i)  {
		v[b[i].x][b[i].y] = true;
		if(a[wl].d[b[i].x][b[i].y]) wf.push((coords){b[i].x, b[i].y});
	}
	for(_ i = min(bc, a[wl].wc)+1; i <= bc; ++i) {
		v[b[i].x][b[i].y] = true;
		if(!a[wl].d[b[i].x][b[i].y]) bf.push((coords){b[i].x, b[i].y});
	}
	for(_ i = 1; i <= r; ++i) for(_ j = 1; j <= c; ++j) if(!v[i][j]) {
		if(a[wl].d[i][j]) bs.push((coords){i, j});
		else wws.push((coords){i, j});
	}
	for(;;) {
		if(wf.empty() && bf.empty()) break;
		if(!wf.empty() && !wws.empty()) {
			o[++cnt] = (shift){wf.front().x, wf.front().y, wws.front().x, wws.front().y};
			if(a[wl].d[wf.front().x][wf.front().y]) bs.push((coords){wf.front().x, wf.front().y});
			else wws.push((coords){wf.front().x, wf.front().y});
			wf.pop();
			wws.pop();
		}
		if(!bf.empty() && !bs.empty()) {
			o[++cnt] = (shift){bf.front().x, bf.front().y, bs.front().x, bs.front().y};
			if(a[wl].d[bf.front().x][bf.front().y]) bs.push((coords){bf.front().x, bf.front().y});
			else wws.push((coords){bf.front().x, bf.front().y});
			bf.pop();
			bs.pop();
		}
	}
	printf("%lld\n", cnt);
	for(_ i = 1; i <= cnt; ++i) printf("%lld %lld %lld %lld\n", o[i].a, o[i].b, o[i].c, o[i].d);
	
	return 0;
}

char gc() {
	char ch = getchar();
	for(; ch != 'W' && ch != 'B'; ) ch = getchar();
	return ch;
}