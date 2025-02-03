#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E4+8;
constant maxk = 1E3+8;

_ k, n, m, b, a[maxk], x, y, f[maxn];
vector<_> g[maxn];
bitset<maxn> v;
struct node {
	_ p, c;
};
queue<node> q;

void bfs(_ x);
int main() {
	
	scanf("%lld%lld%lld%lld", &k, &n, &m, &b);
	for(_ i = 1; i <= k; ++i) scanf("%lld", &a[i]);
	for(; m--; ) {
		scanf("%lld%lld", &x, &y);
		g[x].push_back(y);
	}
	for(_ i = 1; i <= k; ++i) bfs(a[i]);
	for(_ i = 1; i <= n; ++i) if(f[i] == k) printf("%lld ", i);
	putchar(10);
	
	return 0;
}

void bfs(_ x) {
	for(; !q.empty(); ) q.pop();
	v.reset();
	v.set(x);
	q.push((node){x, 0
	});
	for(; !q.empty(); q.pop()) {
		++f[q.front().p];
		if(q.front().c != b) for(vector<_>::iterator i = g[q.front().p].begin(); i != g[q.front().p].end(); ++i) if(!v[*i]) {
			q.push((node){*i, q.front().c+1
			});
			v.set(*i);
		}
	}
	return;
}