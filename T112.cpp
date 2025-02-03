#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxv = 7;
constant maxn = 1E3+8;

_ n, s;
pair<_, _> dp[2][maxv][maxv][maxv][maxv][maxv][maxv];
struct stt {
	_ t, a, b, c, d, e, f;
} cur;
queue<stt> q;
struct piece {
	_ a, b, c, d, e, f;
} a[maxn];

int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld%lld%lld%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c, &a[i].d, &a[i].e, &a[i].f);
	q.push((stt){0, 0, 0, 0, 0, 0, 0});
	for(_ i = 1; i <= n; ++i) for(; q.front().t < i; ) {
		//printf("i: %lld\n", i);
		//printf("size: %lld stuff: %lld %lld %lld %lld %lld %lld\n", q.size(), q.front().a, q.front().b, q.front().c, q.front().d, q.front().e, q.front().f);
		_ bn = (q.front().a == a[i].d) + (q.front().b == a[i].e) + (q.front().c == a[i].f);
		if(dp[i&1][a[i].a][a[i].b][a[i].c][q.front().d][q.front().e][q.front().f].first != i) {
			dp[i&1][a[i].a][a[i].b][a[i].c][q.front().d][q.front().e][q.front().f].first = i;
			dp[i&1][a[i].a][a[i].b][a[i].c][q.front().d][q.front().e][q.front().f].second = dp[(i&1)^1][q.front().a][q.front().b][q.front().c][q.front().d][q.front().e][q.front().f].second+bn;
			q.push((stt){i, a[i].a, a[i].b, a[i].c, q.front().d, q.front().e, q.front().f});
		} else dp[i&1][a[i].a][a[i].b][a[i].c][q.front().d][q.front().e][q.front().f].second = max(dp[i&1][a[i].a][a[i].b][a[i].c][q.front().d][q.front().e][q.front().f].second, dp[(i&1)^1][q.front().a][q.front().b][q.front().c][q.front().d][q.front().e][q.front().f].second+bn);
		bn = (q.front().b == a[i].d) + (q.front().c == a[i].e) + (q.front().d == a[i].f);
		if(dp[i&1][q.front().a][a[i].a][a[i].b][a[i].c][q.front().e][q.front().f].first != i) {
			dp[i&1][q.front().a][a[i].a][a[i].b][a[i].c][q.front().e][q.front().f].first = i;
			dp[i&1][q.front().a][a[i].a][a[i].b][a[i].c][q.front().e][q.front().f].second = dp[(i&1)^1][q.front().a][q.front().b][q.front().c][q.front().d][q.front().e][q.front().f].second+bn;
			q.push((stt){i, q.front().a, a[i].a, a[i].b, a[i].c, q.front().e, q.front().f});
		} else dp[i&1][q.front().a][a[i].a][a[i].b][a[i].c][q.front().e][q.front().f].second = max(dp[i&1][q.front().a][a[i].a][a[i].b][a[i].c][q.front().e][q.front().f].second, dp[(i&1)^1][q.front().a][q.front().b][q.front().c][q.front().d][q.front().e][q.front().f].second+bn);
		bn = (q.front().c == a[i].d) + (q.front().d == a[i].e) + (q.front().e == a[i].f);
		if(dp[i&1][q.front().a][q.front().b][a[i].a][a[i].b][a[i].c][q.front().f].first != i) {
			dp[i&1][q.front().a][q.front().b][a[i].a][a[i].b][a[i].c][q.front().f].first = i;
			dp[i&1][q.front().a][q.front().b][a[i].a][a[i].b][a[i].c][q.front().f].second = dp[(i&1)^1][q.front().a][q.front().b][q.front().c][q.front().d][q.front().e][q.front().f].second+bn;
			q.push((stt){i, q.front().a, q.front().b, a[i].a, a[i].b, a[i].c, q.front().f});
		} else dp[i&1][q.front().a][q.front().b][a[i].a][a[i].b][a[i].c][q.front().f].second = max(dp[i&1][q.front().a][q.front().b][a[i].a][a[i].b][a[i].c][q.front().f].second, dp[(i&1)^1][q.front().a][q.front().b][q.front().c][q.front().d][q.front().e][q.front().f].second+bn);
		bn = (q.front().d == a[i].d) + (q.front().e == a[i].e) + (q.front().f == a[i].f);
		if(dp[i&1][q.front().a][q.front().b][q.front().c][a[i].a][a[i].b][a[i].c].first != i) {
			dp[i&1][q.front().a][q.front().b][q.front().c][a[i].a][a[i].b][a[i].c].first = i;
			dp[i&1][q.front().a][q.front().b][q.front().c][a[i].a][a[i].b][a[i].c].second = dp[(i&1)^1][q.front().a][q.front().b][q.front().c][q.front().d][q.front().e][q.front().f].second+bn;
			q.push((stt){i, q.front().a, q.front().b, q.front().c, a[i].a, a[i].b, a[i].c});
		} else dp[i&1][q.front().a][q.front().b][q.front().c][a[i].a][a[i].b][a[i].c].second = max(dp[i&1][q.front().a][q.front().b][q.front().c][a[i].a][a[i].b][a[i].c].second, dp[(i&1)^1][q.front().a][q.front().b][q.front().c][q.front().d][q.front().e][q.front().f].second+bn);
		q.pop();
	}
	for(; !q.empty(); q.pop()) s = max(s, dp[n&1][q.front().a][q.front().b][q.front().c][q.front().d][q.front().e][q.front().f].second);
	
	printf("%lld\n", s);
	
	return 0;
}
