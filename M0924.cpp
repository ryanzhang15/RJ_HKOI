#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxk = 12+8;

_ n, dg, k, t, tpow[maxk], cnt, mx;
queue<_> q;
bitset<maxn> v;
struct edge {
	_ from, to;
} g[maxn<<1];
bool dp[maxn][maxk];

_ swapDigit(_ t, _ x, _ y);
int main() {
	
	tpow[0] = 1;
	for(_ i = 1; i <= 6; ++i) tpow[i] = tpow[i-1]*10;
	
	scanf("%lld%lld", &n, &k);
	for(dg = 0, t = n; t; ++dg) t /= 10;
	q.push(n);
	v.set(n);
	for(; !q.empty(); q.pop()) {
		t = q.front();
		for(_ i = 1; i <= dg-1; ++i) for(_ j = i+1; j <= dg; ++j) if(swapDigit(t, i, j) / tpow[dg-1]) {
			g[++cnt] = (edge){t, swapDigit(t, i, j)};
			if(!v[swapDigit(t, i, j)]) {
				v.set(swapDigit(t, i, j));
				q.push(swapDigit(t, i, j));
			}
		}
	}
	
	dp[n][0] = true;
	for(_ j = 0; j <= k-1; ++j) for(_ i = 1; i <= cnt; ++i) dp[g[i].to][j+1] |= dp[g[i].from][j];
	for(_ i = 1E5+1; i >= 1; --i) if(dp[i][k]) {
		printf("%lld\n", i);
		exit(0);
	}
	puts("Time to leave");
	
	return 0;
}

_ swapDigit(_ t, _ x, _ y) {
	_ sv = t % tpow[x] / tpow[x-1], sv2 = t % tpow[y] / tpow[y-1];
	t -= sv * tpow[x-1] + sv2 * tpow[y-1];
	t += sv * tpow[y-1] + sv2 * tpow[x-1];
	return t;
}