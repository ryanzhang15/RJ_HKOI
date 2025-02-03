#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 6+8;

_ a[maxn][maxn], c = 1, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, sx, sy;

void lmao(_ x, _ y, _ s, _ lst);
bool done(_ x, _ y);
_ h(_ x, _ y);
int main() {
	
	cin >> sx >> sy;
	for(_ i = 1; i <= 4; ++i) for(_ j = 1; j <= 6; ++j) cin >> a[j][i];
	//IDA*
	for(; ; ++c) lmao(sx, sy, 0, -11);
	
	return 0;


}

//heuristics function
_ h(_ x, _ y) {
	return min(min(x, y), min(7-x, 5-y))-1;
}

bool done(_ x, _ y) {
	return ((x == 1 && !(a[x][y] & 1)) || (y == 1 && !(a[x][y] & 2)) || (x == 6 && !(a[x][y] & 4)) || (y == 4 && !(a[x][y] & 8)));
}

void lmao(_ x, _ y, _ s, _ lst) {
	if(s + h(x, y) > c) return;
	if(done(x, y)) {
		printf("%lld\n", ++s);
		exit(0);
	}
	for(_ i = 0; i < 4; ++i) {
		if(abs(lst-i) == 2) continue;
		_ nx = x + dx[i];
		_ ny = y + dy[i];
		if(nx <= 0 || ny <= 0 || nx > 6 || ny > 4) continue;
		_ nnx = nx + dx[i];
		_ nny = ny + dy[i];
		if((a[x][y] & (1<<i)) && (a[nx][ny] & (1<<i))) continue;
		if(a[x][y] & (1<<i)) {
			a[x][y] &= ~(1<<i);
			a[nx][ny] |= 1<<i;
			a[nx][ny] &= ~(1<<((i+2)%4));
			a[nnx][nny] |= 1<<((i+2)%4);
			lmao(nx, ny, s+1, i);
			a[x][y] |= 1<<i;
			a[nx][ny] &= ~(1<<i);
			a[nx][ny] |= 1<<((i+2)%4);
			a[nnx][nny] &= ~(1<<((i+2)%4));
		} else lmao(nx, ny, s+1, i);
	}
	return;
} 