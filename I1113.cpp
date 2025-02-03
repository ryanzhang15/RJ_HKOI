#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
_ n, mx, b, s, a[maxn], p[maxn];

inline void write(_ x);
inline _ read();
_ cost(_ l, _ r);
int main() {
	
	n = read();
	mx = read();
	b = read();
	for(_ i = 1; i <= n; ++i) {
		a[i] = read();
		p[i] = p[i-1]+a[i];
	}
	for(_ l = 1, r = 1; l <= n; ++l) {
		for(; r <= n-1 && cost(l, r+1) <= b; ) ++r;
		s = max(s, r-l+1);
	}
	write(s);
	putchar_unlocked(10);
	
	return 0;
}

_ cost(_ l, _ r) {
	_ md = (l+r)>>1;
	return p[l-1]+p[r]-p[md]-p[md-1]+a[md]*((md<<1)-l-r);	
}

inline _ read() {
    _ x = 0;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}

inline void write(_ x) {
    if(x > 9) write(x/10);
    putchar_unlocked((x%10)^48);
    return;
}
