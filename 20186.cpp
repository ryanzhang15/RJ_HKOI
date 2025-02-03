#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 1E2+8; //just a guess, nothing was given!
map<str, _> mp;
str a[maxn], frm, to, rt[maxn][maxn], cndrt;
_ dp[maxn][maxn], intf, intt, cnt, p[maxn][maxn], cndds;

_ parseInt();
str parse();
int main() {
	
	memset(dp, 4, sizeof dp);
	for(_ i = 1; i <= 1E2; ++i) for(_ j = 1; j <= 1E2; ++j) p[i][j] = j;
	for(_ i = 1; i <= 1E2; ++i) dp[i][i] = 0;
	
	for(;;) {
		frm = parse();
		if(frm.empty()) break;
		if(mp.count(frm)) intf = mp[frm];
		else {
			intf = ++cnt;
			mp[frm] = cnt;
			a[cnt] = frm;
		}
		to = parse();
		if(mp.count(to)) intt = mp[to];
		else {
			intt = ++cnt;
			mp[to] = cnt;
			a[cnt] = to;
		}
		cndrt = parse();
		cndds = parseInt();
		if(cndds < dp[intt][intf]) {
			dp[intt][intf] = dp[intf][intt] = cndds;
			rt[intt][intf] = rt[intf][intt] = cndrt;
		}
	}
	
	for(_ k = 1; k <= cnt; ++k) for(_ i = 1; i <= cnt; ++i) for(_ j = 1; j <= cnt; ++j) if(dp[i][j] > dp[i][k] + dp[k][j]) {
		dp[i][j] = dp[i][k] + dp[k][j];
		p[i][j] = p[i][k];
	}
	
	for(;;) {
		frm = parse();
		if(frm.empty()) break;
		to = parse();
		intt = mp[frm];
		_ sv = intt;
		intf = mp[to];
		putchar(10);
		putchar(10);
		puts("From                 To                   Route      Miles\n-------------------- -------------------- ---------- -----");
		for(_ u; intt != intf; intt = u) {
			cout << a[intt];
			for(_ i = a[intt].length(); i <= 20; ++i) putchar(32);
			u = p[intt][intf];
			cout << a[u];
			for(_ i = a[u].length(); i <= 20; ++i) putchar(32);
			cout << rt[intt][u];
			for(_ i = rt[intt][u].length(); i <= 10; ++i) putchar(32);
			printf("%5lld\n", dp[intt][u]);
		}
		puts("                                                     -----");
		printf("                                          Total      %5d\n", dp[sv][intf]); 
	}
	
	return 0;
}

str parse() {
	str rv;
	char ch = getchar();
	for(; ch != EOF && ch != ',' && ch != '\n'; ch = getchar()) rv.push_back(ch);
	return rv;
}

_ parseInt() {
	_ rv = 0;
	char ch = getchar();
	for(; ch >= '0' && ch <= '9'; ch = getchar()) rv = (rv<<3)+(rv<<1)+(ch^48);
	if(ch == '\r') getchar();
	return rv;
}