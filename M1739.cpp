#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E5+8;
constant mod = 1E9+7;

struct edge {
	_ to, cost, next;
} g[maxn<<1];
_ n, m, head[maxn], cnt, x, y, z, dp[maxn], d[maxn];
struct node {
	_ d, p;
	bool operator < (const node &b) const {
		return d > b.d;
	}
};
priority_queue<node> q;

void addEdge(_ x, _ y, _ z);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(; m--; ) {
		scanf("%lld%lld%lld", &x, &y, &z);
		addEdge(x, y, z);
		addEdge(y, x, z);
	}
	memset(d, 4, sizeof d);
	d[1] = 0;
	dp[1] = 1;
	q.push((node){0, 1});
	for(; !q.empty(); ) {
		node c = q.top();
		q.pop();
		if(c.d != d[c.p]) continue;
		for(_ i = head[c.p]; i; i = g[i].next) if(d[g[i].to] > d[c.p] + g[i].cost) {
			d[g[i].to] = d[c.p] + g[i].cost;
			dp[g[i].to] = dp[c.p];
			q.push((node){d[g[i].to], g[i].to});
		} ef(d[g[i].to] == d[c.p] + g[i].cost) dp[g[i].to] = (dp[g[i].to]+dp[c.p])%mod;
	}
	for(_ i = 2; i <= n; ++i) printf("%lld ", dp[i]);
	putchar(10);
	
	return 0;
}

void addEdge(_ x, _ y, _ z) {
	g[++cnt].next = head[x];
	g[cnt].to = y;
	g[cnt].cost = z;
	head[x] = cnt;
	return;
}