#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, d[maxn], nn, o;
map<_, _> mp, fb;
struct tg {
	_ l, a, b, r;
	bool operator < (const tg &c) const {
		if(l != c.l) return l < c.l;
		return a < c.a;
	}
} a[maxn];
vector<tg> g;
struct fenwick {
	_ t[maxn], dr = 1;
	void add(_ x, _ k) {
//		printf("added at %lld, by %lld\n", x, k);
//		for(; x; x -= x & -x) t[x] += k;
		for(; x <= n; x += x & -x) t[x] += k;
//		t[x] += k;
//		if(x == 1) printf("added to 1!!\n");
		return;
	}
	_ query(_ x) {
		_ rv = 0;
//		for(; x <= n; x += x & -x) rv += t[x];
		for(; x; x -= x & -x) rv += t[x];
//		if(dr == 1) for(_ i = 1; i <= x; ++i) rv += t[i];
//		else for(_ i = x; i <= n; ++i) rv += t[i];
		return rv;
	}
} fw, tw;
struct segtree {
	_ ta[maxn<<2], tb[maxn<<2], la[maxn<<2], lb[maxn<<2];
	void pushUp(_ pos) {
		ta[pos] = ta[pos<<1]+ta[pos<<1|1];
		tb[pos] = tb[pos<<1]+tb[pos<<1|1];
//		printf("pushing up t[%lld] = %lld+%lld\n", pos, tb[pos<<1], tb[pos<<1|1]);
		return;
	}

	void pushDown(_ pos) {
		ta[pos<<1] += la[pos];
		ta[pos<<1|1] += la[pos];
		tb[pos<<1] += lb[pos];
		tb[pos<<1|1] += lb[pos];
		la[pos<<1] += la[pos];
		la[pos<<1|1] += la[pos];
		lb[pos<<1] += lb[pos];
		lb[pos<<1|1] += lb[pos];
		la[pos] = lb[pos] = 0;
		return;
	}

	void update(_ L, _ R, _ l, _ r, _ c, _ pos) {
		if(L <= l && r <= R) {
			ta[pos] += c;
			la[pos] += c;
			tb[pos]++;
			lb[pos]++;
//			printf("added to tb[%lld], position %lld\n", pos, l);
			return;
		}
		_ md = (l+r)>>1;
		pushDown(pos);
		if(L <= md) update(L, R, l, md, c, pos<<1);
		if(R > md) update(L, R, md+1, r, c, pos<<1|1);
		pushUp(pos);
//		printf("after update, tb[%lld] = %lld, in range {%lld, %lld}\n", pos, tb[pos], l, r);
		return;
	}

	_ query(_ l, _ r, _ c, _ pos) {
		if(l == r) return ta[pos] <= c ? fw.query(l) : 0;
		_ md = (l+r)>>1;
//		printf("query at {%lld, %lld}, pos = %lld, ta = %lld, tb = %lld, l to md = %lld\n", l, r, pos, ta[pos], fw.query(r), fw.query(md));
		pushDown(pos);
		if(ta[pos<<1] <= c) return max(fw.query(md), query(md+1, r, c, pos<<1|1));
		else return query(l, md, c, pos<<1);
	}
} tr;

int skill(int N, long long S, std::vector<int> L, std::vector<int> A, std::vector<int> B) {
//	tw.dr = 0;
	n = N;
	m = S;
	for(_ i = 1; i <= n; ++i) d[i] = B[i-1];
	sort(d+1, d+1+n);
	for(_ i = 1; i <= n; ++i) {
		if(!fb.count(d[i])) fb[d[i]] = i;
	}
	for(_ i = 1; i <= n; ++i) {
		_ c = fb[B[i-1]];
//		printf("i = %lld, c = %lld, B[i-1] = %d\n", i, c, B[i-1]);
		a[i].l = L[i-1];
		a[i].a = A[i-1];
		a[i].b = c+mp[B[i-1]];
		a[i].r = B[i-1];
		++mp[B[i-1]];
	}
	sort(a+1, a+1+n);
//	for(_ i = 1; i <= n; ++i) printf("i = %lld, l = %lld, a = %lld, b = %lld, r = %lld\n", i, a[i].l, a[i].a, a[i].b, a[i].r);
	for(_ i = 1; i <= n; ++i) {
		g.push_back(a[i]);
		if(a[i].l == a[i+1].l) continue;
//		printf("evaluation at %lld\n", i);
		_ t = m, ts = 0;
		for(tg j : g) {
			++ts;
			t -= j.a;
			if(t < 0) break;
//			printf("at i = %lld, cost left = %lld, query = %lld, updated to %lld\n", i+ts-1, t, tr.query(1, n, t, 1), tr.query(1, n, t, 1)+ts);
//			for(_ j = 1; j <= n; ++j) {
//				printf("i = %lld, j = %lld, tw[j] = %lld, ts = %lld, fw[j] = %lld\n", i, j, tw.query(j), ts, fw.query(j));
//				if(tw.query(j) <= t) o = max(o, ts+fw.query(j));
//			}
			_ l = 1, r = n, md, s = 0;
			for(; l <= r; ) {
				md = (l+r)>>1;
				if(tw.query(md) <= t) {
					s = fw.query(md);
					l = md+1;
				} else r = md-1;
			}
			o = max(o, ts+s);
		}
//		for(_ j = 1; j <= n; ++j) printf("query at %lld = %lld\n", j, fw.query(j));
		for(tg j : g) {
//			tr.update(j.b, n, 1, n, j.r, 1);
			tw.add(j.b, j.r);
			fw.add(j.b, 1);
		}
		g.clear();
	}
	return (int)o;
}

#ifndef ONLINE_JUDGE

int main() {

	int N;
	long long S;
	std::vector<int> L, A, B;
	std::cin >> N >> S;
	L.resize(N);
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; i++)
		std::cin >> L[i];
	for (int i = 0; i < N; i++)
		std::cin >> A[i];
	for (int i = 0; i < N; i++)
		std::cin >> B[i];
	int ans = skill(N, S, L, A, B);
	std::cout << ans << std::endl;

	return 0;
}

#endif

