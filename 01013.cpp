#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 20+8;

map<_, _> p;
struct in {
	_ nb, f;
	_D mn;
	bool operator < (const in &b) const {
		return nb < b.nb;
	}
} a[maxn];
struct date {
	_ d, m, y, hr, mn, sc;
} st, ed;
_ n, m, s[maxn], mnth[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, c;

_ getMon(_ mn, _ yr);
bool isLeap(_ yr);
date getDate();
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) scanf("%lld%lld%Lf", &a[i].nb, &a[i].f, &a[i].mn);
	sort(a+1, a+1+n);
	for(_ i = 1; i <= n; ++i) p[a[i].nb] = i;
	for(; m--; ) {
		scanf("%lld", &c);
		c = p[c];
		st = getDate();
		ed = getDate();
		for(_ i = st.m; i <= ed.m-1 || st.y <= ed.y-1; ++i) {
			s[c] += getMon(i, st.y)*24*60*60;
			if(i == 12) {
				++st.y;
				i = 0;
			}
		}
		s[c] += (ed.d-st.d)*24*60*60;
		s[c] += (ed.hr-st.hr)*60*60;
		s[c] += (ed.mn-st.mn)*60;
		s[c] += ed.sc-st.sc;
	}
	puts("Account Number   Time Used         Amount\n*****************************************");
	for(_ i = 1; i <= n; ++i) {
		_ used = !s[i] ? 0 : (s[i]-1)/60+1;
		_D pay = used-a[i].f;
		if(pay > 0) pay *= a[i].mn; 
		else pay = 0;
		if(a[i].f == 100) pay += 80;
		else pay += 50;
		printf("%08lld%18lld%15.2Lf\n", a[i].nb, used, pay);
	}
	
	
	return 0;
}

date getDate() {
	date rv;
	char ch = getchar();
	for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
	rv.d = (ch^48)*10+(getchar()^48);
	rv.m = (getchar()^48)*10+(getchar()^48);
	rv.y = (getchar()^48)*10+(getchar()^48);
	for(ch = getchar(); !(ch >= '0' && ch <= '9'); ) ch = getchar();
	rv.hr = (ch^48)*10+(getchar()^48);
	rv.mn = (getchar()^48)*10+(getchar()^48);
	rv.sc = (getchar()^48)*10+(getchar()^48);
	return rv;
}

bool isLeap(_ yr) {
	yr = 1900 + yr;
	return (!(yr % 400) || (!(yr % 4) && (yr % 100)));
}

_ getMon(_ mn, _ yr) {
	if(mn != 2) return mnth[mn];
	return isLeap(yr) ? 29 : 28;
}

/*
Account Number   Time Used         Amount
*****************************************
00345678                 8          52.80
23456789                 1          80.00
34567890                 1          50.35
45678901                 6          52.10
56789012               120          85.00

5  7
00345678  0  0.35
23456789  100  0.25
34567890  0  0.35
56789012  100  0.25
45678901  0  0.35
23456789  090396  024530  090396  024630
00345678  090396  043010  090396  043120
56789012  100396  230000  110396  010000
34567890  110396  151000  110396  151100
45678901  200396  122025  200396  122545
00345678  220396  000001  220396  000101
00345678  250396  202020  250396  202520 

1 1
12241214  0  0.35
12241214  010395  000000  090396  000000
*/