#include <bits/stdc++.h>
#define mp make_pair
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 2E5+8;
constant maxm = 3E6+8;

_ n, b[maxn], cx, cy, up, d[maxm];
char a[3][maxn];
struct node {
	_ p, d;
	bool operator < (const node &b) const {
		return d > b.d;
	}
};
priority_queue<node> q;
struct edge {
	_ to, cost;
};
vector<edge> g[maxm];

_ cv(_ x, _ y, _ c);
int main() {

	scanf("%lld %s %s%lld%lld%lld", &n, a[1]+1, a[2]+1, &cx, &cy, &up);
	a[2][1] = a[2][n] = 'o';
	for(_ i = 1; i <= n; ++i) {
		if(a[1][i] != 'x' && a[2][i] != 'x') for(_ j = 1; j <= 3; ++j) {
			g[cv(1, i, j)].push_back((edge){cv(2, i, j|2), 0});
			g[cv(2, i, j)].push_back((edge){cv(1, i, j|1), up});
//			puts("added");
//			printf("added edge from %lld to %lld with cost %lld\n", cv(1, i, j), cv(2, i, j|2), 0LL);
//			printf("added edge from %lld to %lld with cost %lld\n", cv(2, i, j), cv(1, i, j|1), up);
		}
		if(a[1][i] == 'p') b[i] |= 1;
		if(a[2][i] == 'p') b[i] |= 2;
//		printf("b[%lld] = %lld\n", i, b[i]);
	}
	for(_ i = 1; i <= 2; ++i) for(_ j = 1; j <= n-1; ++j) if(a[i][j] != 'x' && a[i][j+1] != 'x') {
		for(_ k = 1; k <= 3; ++k) if((k & b[j]) == b[j]) {
			g[cv(i, j, k)].push_back((edge){cv(i, j+1, i), i == 1 ? cy : cx});
//			printf("added edge from %lld to %lld with cost %lld\n", cv(i, j, k), cv(i, j+1, i), i == 1 ? cy : cx);
		}
	}
	memset(d, 4, sizeof d);
	_ st = cv(2, 1, 2);
	d[st] = 0;
	q.push((node){st, 0});
	for(; !q.empty(); ) {
		node t = q.top();
		q.pop();
//		printf("at node = %lld\n", t.p);
		if(t.d != d[t.p]) continue;
//		puts("ok");
		for(edge i : g[t.p]) if(d[i.to] > d[t.p]+i.cost) {
			d[i.to] = d[t.p]+i.cost;
			q.push((node){i.to, d[i.to]});
		}
	}
	_ s = 1E18;
	for(_ i = 1; i <= 3; ++i) if((i & b[n]) == b[n]) s = min(s, d[cv(2, n, i)]);
	if(s > (_)1E16) s = -1;
	printf("%lld\n", s);

	return 0;
}

_ cv(_ x, _ y, _ c) {
	return ((x-1)*n+y)<<2|c;
}
