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

constant maxn = 1E5+8;
constant maxm = 1E7+8;
constant big = 1E9+8;

_ n, a[maxn], b[maxn], o[maxn], r[maxn], rt[maxm], lt[maxm], t[maxm], cnt;
v_ g[maxn];

void dfs(_ x, _ fa);
_ query(_ x, _ l, _ r);
void merge(_ &x, _ &y, _ l, _ r);
void update(_ &x, _ L, _ R, _ l, _ r);
std::vector<int> mex_array(int N, std::vector<int> L, std::vector<int> R, std::vector<int> U, std::vector<int> V) {
	n = N;
	for(_ i = 1; i <= n; ++i) {
		a[i] = L[i-1];
		b[i] = R[i-1];
	}
	for(_ i = 0; i < n-1; ++i) {
		g[U[i]+1].push_back(V[i]+1);
		g[V[i]+1].push_back(U[i]+1);
	}
	dfs(1, -1);
	vector<int> rv;
	for(_ i = 1; i <= n; ++i) rv.push_back((int)o[i]);
	return rv;
}

void pushUp(_ pos) {
	t[pos] |= t[lt[pos]] & t[rt[pos]];
	return;
}

void update(_ &x, _ L, _ R, _ l, _ r) {
	if(!x) x = ++cnt;
	if(t[x]) return;
	if(L <= l && r <= R) {
//		printf("hard update at {%lld, %lld}, id %lld for value 1\n", l, r, x);
		t[x] = 1;
		return;
	}
	_ md = (l+r)>>1;
	if(L <= md) update(lt[x], L, R, l, md);
	if(R > md) update(rt[x], L, R, md+1, r);
	pushUp(x);
//	printf("value for {%lld, %lld}, id %lld is %lld\n", l, r, x, (_)t[x]);
	return;
}

void merge(_ &x, _ &y, _ l, _ r) {
	if(!x) x = y;
	ef(!y) return;
	else {
		if(t[x] || t[y]) {
			t[x] |= t[y];
			y = x;
			return;
		}
		if(l == r) return;
		_ md = (l+r)>>1;
		merge(lt[x], lt[y], l, md);
		merge(rt[x], rt[y], md+1, r);
		pushUp(x);
	}
	return;
}

_ query(_ x, _ l, _ r) {
//	printf("query at {%lld, %lld}, x = %lld, lt[x] = %lld, rt[x] = %lld, t is %lld\n", l, r, x, lt[x], rt[x], t[x]);
	if(l == r) return l;
	_ md = (l+r)>>1;
	if(!t[lt[x]]) return query(lt[x], l, md);
	else return query(rt[x], md+1, r);
}

void dfs(_ x, _ fa) {
//	printf("dfs at %lld\n", x);
//	printf("children of %lld: ", x);
//	for(_ i : g[x]) printf("%lld ", i);
//	putchar(10);
	for(_ i : g[x]) if(i != fa) {
		dfs(i, x);
		merge(r[x], r[i], 1, big);
	}
//	printf("updating answer for %lld, with range {%lld, %lld}\n", x, a[x], b[x]);
	update(r[x], a[x], b[x], 1, big);
//	printf("finding answer for %lld\n", x);
	o[x] = query(r[x], 1, big);
	return;
}

#ifndef ONLINE_JUDGE
int main() {

	int n;
	scanf("%d", &n);
	vector<int> l, r;
	for(_ i = n; i--; ) {
		int x, y;
		scanf("%d%d", &x, &y);
		l.push_back(x);
		r.push_back(y);
	}
	vector<int> x, y;
	for(_ i = n; --i; ) {
		int ta, tb;
		scanf("%d%d", &ta, &tb);
		x.push_back(ta);
		y.push_back(tb);
	}
	vector<int> s = mex_array(n, l, r, x, y);
	for(int i : s) printf("%d ", i);
	putchar(10);

	return 0;
}
#endif

