#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 10;
constant maxp = 5764801+8;

char a[maxn][maxn];

struct node {
	_ x, y, s;
	vector<_> bx;
	vector<_> by;
} s, t;
_ n, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, id;
queue<node> q;
bitset<maxp> v;
vector<_> empt (3, 0);

bool isVis(node t);
void markVis(node t);
_ hsh(_ x1, _ y1, _ x2, _ y2, _ x3, _ y3, _ x4, _ y4);
void check(node t);
char gc();
int main() {
	
	s.bx = s.by = empt;
	for(_ i = 1; i <= 9; ++i) for(_ j = 1; j <= 9; ++j) a[i][j] = gc();
	a[0][0] = 'X';
	scanf("%lld%lld%lld", &s.x, &s.y, &n);
	for(_ i = 0; i < n; ++i) scanf("%lld%lld", &s.bx[i], &s.by[i]);
	check(s);
	markVis(s);
	q.push(s);
	for(; !q.empty(); q.pop()) {
		s = q.front();
		for(_ i = 0; i < 4; ++i) {
			t = s;
			t.x = s.x + dx[i];
			t.y = s.y + dy[i];
			if(a[t.x][t.y] == '#') continue;
			t.s = s.s+1;
			bool g = true;
			_ bi = -1;
			for(_ j = 0; j < n && g; ++j) if(t.x == t.bx[j] && t.y == t.by[j]) {
				_ nx = t.x+dx[i];
				_ ny = t.y+dy[i];
				if(a[nx][ny] == '#' || (nx == t.bx[0] && ny == t.by[0]) || (nx == t.bx[1] && ny == t.by[1]) || (nx == t.bx[2] && ny == t.by[2])) g = false;
				else bi = j;
				break;
			}
			if(!g) continue;
			if(~bi) {
				t.bx[bi] += dx[i];
				t.by[bi] += dy[i];
				check(t);
			}
			if(!isVis(t)) {
				markVis(t);
				q.push(t);
			}
//			swap(t, s);
//			printf("%lld %lld BOX1: %lld %lld BOX2: %lld %lld BOX3: %lld %lld ID: %lld\n", s.x, s.y, s.bx[0], s.by[0], s.bx[1], s.by[1], s.bx[2], s.by[2], ++id);
//			swap(t, s);
		}
	}
	
	return 0;
}

char gc() {
	char ch;
	for(ch = getchar(); ch != '#' && ch != '.' && ch != 'X'; ) ch = getchar();
	return ch;
}

void check(node t) {
	bool g = true;
	for(_ i = 0; i < n && g; ++i) if(a[t.bx[i]][t.by[i]] != 'X') g = false;
	if(g) {
		printf("%lld\n", t.s);
		//for(_ i = 0; i < n; ++i) printf("BOX: %lld %lld\n", t.bx[i], t.by[i]);
		exit(0);
	}
	return;
}

_ hsh(_ x1, _ y1, _ x2, _ y2, _ x3, _ y3, _ x4, _ y4) {
	_ rv = 0;
	rv = rv*7+x1;
	rv = rv*7+y1;
	rv = rv*7+x2;
	rv = rv*7+y2;
	rv = rv*7+x3;
	rv = rv*7+y3;
	rv = rv*7+x4;
	rv = rv*7+y4;
//	if(rv >= maxp) {
//		printf("OOPS\n");
//	}
	return rv;
}

void markVis(node t) {
	v.set(hsh(t.x-2, t.y-2, t.bx[0]-2, t.by[0]-2, t.bx[1]-2, t.by[1]-2, t.bx[2]-2, t.by[2]-2));
	return;
}

bool isVis(node t) {
	return v[hsh(t.x-2, t.y-2, t.bx[0]-2, t.by[0]-2, t.bx[1]-2, t.by[1]-2, t.bx[2]-2, t.by[2]-2)];
}