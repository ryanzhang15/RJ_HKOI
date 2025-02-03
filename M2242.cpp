#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E5+8;

_ f[maxn], a[maxn], n, m, k, cnt, cnum, low[maxn], dfn[maxn];
v_ g[maxn];
stack<_> st;
bitset<maxn> v;

_ find(_ x);
void paint(_ x);
void tarjan(_ x, _ fa);
std::vector<bool> check_validity(int N, int M, int Q,
                                 std::vector<int> X, std::vector<int> Y, std::vector<int> W,
                                 std::vector<int> U, std::vector<int> V) {
	n = N;
	m = M;
	k = Q;
	vector<int> x = X, y = Y;
	for(_ i = 0; i < m; ++i) {
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	for(_ i = 1; i <= n; ++i) f[i] = i;
	tarjan(1, -1);
	for(_ i = 0; i < m; ++i) if(W[i] >= 2) f[find(x[i])] = find(y[i]);
	vector<bool> s;
	for(_ i = 0; i < k; ++i) {
		s.push_back(find(U[i]) == find(V[i]));
	}
//	printf("k = %lld\n", k);
	return s;
}

void tarjan(_ x, _ fa) {
//	printf("tarjan at %lld, %lld\n", x, fa);
	low[x] = dfn[x] = ++cnt;
	st.push(x);
	v.set(x);
	for(_ i : g[x]) if(i != fa) {
		if(!dfn[i]) {
			tarjan(i, x);
			low[x] = min(low[x], low[i]);
		} ef(v.test(i)) low[x] = min(low[x], dfn[i]);
	}
	if(low[x] == dfn[x]) {
//		printf("at %lld, new color!\n", x);
		++cnum;
		for(; !st.empty() && st.top() != x; ) paint(st.top());
		paint(x);
	}
	return;
}

void paint(_ x) {
	st.pop();
	v.reset(x);
	if(a[cnum]) f[find(a[cnum])] = find(x);
	a[cnum] = x;
	return;
}

_ find(_ x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

#ifndef ONLINE_JUDGE
int main() {

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	vector<int> x, y, c;
	for(_ i = m; i--; ) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		x.push_back(a);
		y.push_back(b);
		c.push_back(d);
	}
	vector<int> u, v;
	for(_ i = q; i--; ) {
		int cu, cv;
		scanf("%d%d", &cu, &cv);
		u.push_back(cu);
		v.push_back(cv);
	}
	vector<bool> s = check_validity(n, m, q, x, y, c, u, v);
//	printf("s.size() = %lld\n", (_)s.size());
	for(bool i : s) if(i) puts("Yes");
	else puts("No");

	return 0;
}
#endif
