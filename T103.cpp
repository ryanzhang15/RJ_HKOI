#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;
constant mod = 1183748291;

_ n, s, o, tp[maxn], dp[maxn][maxn], ha[maxn][maxn], hb[maxn][maxn], va[maxn][maxn], vb[maxn][maxn], pv[maxn][maxn], ph[maxn][maxn];
bool a[maxn][maxn], b[maxn][maxn];

_ getHb(_ x, _ l, _ r);
_ getHa(_ x, _ l, _ r);
_ getVb(_ x, _ l, _ r);
_ getVa(_ x, _ l, _ r);
char gc();
int main() {
	
	memset(dp, 4, sizeof dp);
	
	scanf("%lld", &n);
	tp[0] = 1;
	for(_ i = 1; i <= n+3; ++i) tp[i] = (tp[i-1]<<1)%mod;
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) a[i][j] = gc() == '1';
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) b[i][j] = gc() == '1';
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) if(a[i][j]) --s;
	else ++s;
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) {
		ha[i][j] = ((ha[i][j-1]<<1)+a[i][j])%mod;
		hb[i][j] = ((hb[i][j-1]<<1)+b[i][j])%mod;
		va[i][j] = ((va[i-1][j]<<1)+a[i][j])%mod;
		vb[i][j] = ((vb[i-1][j]<<1)+b[i][j])%mod;
		pv[i][j] = pv[i-1][j]+(a[i][j] ? -1 : 1);
		ph[i][j] = ph[i][j-1]+(a[i][j] ? -1 : 1);
	}
	for(_ i = 1; i <= n; ++i) {
		_ mn = 1E11;
		if(i == 1) mn = 0;
		for(_ j = n-i+1; j >= 1; --j) {
			mn = min(mn, dp[i-1][j+1]);
			if(mn > 1E10) continue;
			if(getVa(i, i, i+j-1) != getVb(n-j+1, n-j+1, n) || getHa(i, i, i+j-1) != getHb(n-j+1, n-j+1, n)) continue;
			dp[i][j] = mn+pv[i+j-1][i]-pv[i][i]+ph[i][i+j-1]-ph[i][i-1];
			o = min(o, dp[i][j]);
		}
	}
	printf("%lld\n", s-o);
	
	return 0;
}

char gc() {
	char ch = getchar();
	for(; ch != '1' && ch != '0'; ) ch = getchar();
	return ch;
}

_ getVa(_ x, _ l, _ r) {
	_ rv = va[r][x], mn = ((__int128)va[l-1][x]*tp[r-l+1])%mod;
	return ((rv-mn)%mod+mod)%mod;
}

_ getVb(_ x, _ l, _ r) {
	_ rv = vb[r][x], mn = ((__int128)vb[l-1][x]*tp[r-l+1])%mod;
	return ((rv-mn)%mod+mod)%mod;
}

_ getHa(_ x, _ l, _ r) {
	_ rv = ha[x][r], mn = ((__int128)ha[x][l-1]*tp[r-l+1])%mod;
	return ((rv-mn)%mod+mod)%mod;
}

_ getHb(_ x, _ l, _ r) {
	_ rv = hb[x][r], mn = ((__int128)hb[x][l-1]*tp[r-l+1])%mod;
	return ((rv-mn)%mod+mod)%mod;
}
