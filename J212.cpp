#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, p, q, cnt, r[maxn], g[maxn], b[maxn<<1];

void write(char ch);
char gc();
int main() {
	
	scanf("%lld%lld", &n, &p);
	for(_ i = 1; i <= p; ++i) {
		char c = gc();
		_ x;
		scanf("%lld", &x);
		if(c == 'R') r[x-1] = i;
		ef(c == 'G') g[x] = i;
		ef(c == 'B') b[n-x+1] = i;
	}
	scanf("%lld", &q);
	for(; q--; ) {
		_ x, y;
		scanf("%lld%lld", &x, &y);
		if(!r[x-y] && !g[y] && !b[x]) write('W');
		ef(r[x-y] > g[y] && r[x-y] > b[x]) write('R');
		ef(g[y] > b[x] && g[y] > r[x-y]) write('G');
		else write('B');
	}
	
	return 0;
}

char gc() {
	char ch = getchar();
	for(; ch != 'R' && ch != 'G' && ch != 'B'; ) ch = getchar();
	return ch;
}

void write(char ch) {
	putchar(ch);
	putchar(10);
	return;
}

