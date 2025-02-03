#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E5+8;
constant maxk = 25E3+8;
constant big = 300;

_ n, m, k, x, y, a[maxn], st[maxn], ed[maxn], cnt, r[maxn], mf[maxn], mb[maxn], cl[maxn];
int f[big+8][maxk], d[big+8][maxk];
vector<_> g[maxn], b[maxn];
_p c[maxn];
bitset<maxn> v;
vector<_p> w[maxn], p[maxn];

void dfs(_ x);
int main() {

    scanf("%lld%lld%lld", &n, &k, &m);
    scanf("%lld", &a[1]);

    for(_ i = 2; i <= n; ++i) {
        scanf("%lld%lld", &x, &a[i]);
        g[x].push_back(i);
    }

	dfs(1);

	for(_ i = 1; i <= k; ++i) c[i] = mp((_)b[i].size(), i);
	sort(c+1, c+1+k, greater<_p>());
	_ tp = min(big, k);
	for(_ i = 1; i <= tp; ++i) {
		v.set(c[i].second);
		mf[c[i].second] = i;
		mb[i] = c[i].second;
	}

	for(_ i = 1; i <= tp; ++i) {
		memset(r, 0, sizeof r);
		for(_ j : b[mb[i]]) r[j] = 1;
		for(_ j = 1; j <= n; ++j) r[j] += r[j-1];
		for(_ j = 1; j <= k; ++j) for(_p pr : p[j]) d[i][j] += r[pr.second]-r[pr.first-1];
	}

	for(_ i = 1; i <= tp; ++i) {
		memset(r, 0, sizeof r);
		for(_p j : p[mb[i]]) {
			++r[j.first];
			--r[j.second+1];
		}
		for(_ j = 1; j <= n; ++j) {
			r[j] += r[j-1];
			f[i][cl[j]] += r[j];
		}
	}

	for(_ i = 1; i <= n; ++i) {
		sort(b[i].begin(), b[i].end());
		sort(w[i].begin(), w[i].end());
	}

//	for(_ i = 1; i <= n; ++i) printf("%lld ", st[i]);
//	putchar(10);
//	for(_ i = 1; i <= n; ++i) printf("%lld ", ed[i]);
//	putchar(10);

//	printf("%lld\n", mf[1]);

//	for(_ i : b[1]) printf("%lld ", i);
//	putchar(10);

//	for(_p j : p[3]) printf("%lld %lld\n", j.first, j.second);

//	for(_ i = 1; i <= n; ++i) printf("%lld ", cl[i]);

//	exit(0);

	for(; m--; ) {
		scanf("%lld%lld", &x, &y);
		if(v[x]) printf("%lld\n", f[mf[x]][y]);
		ef(v[y]) printf("%lld\n", d[mf[y]][x]);
		else {
			_ s = 0, p = 0;
			for(_p i : w[x]) {
				for(; p < b[y].size() && b[y][p] <= i.first; ) ++p;
				s += p*i.second;
			}
			printf("%lld\n", s);
		}
		fflush(stdout);
	}

    return 0;
}

void dfs(_ x) {
	st[x] = ++cnt;
	cl[cnt] = a[x];
	b[a[x]].push_back(cnt);
	for(_ i : g[x]) dfs(i);
	ed[x] = cnt;
	p[a[x]].push_back(mp(st[x], ed[x]));
	w[a[x]].push_back(mp(st[x]-1, -1));
	w[a[x]].push_back(mp(ed[x], 1));
	return;
}

