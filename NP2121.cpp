// ID: HK-00018
// Name: Zhang Ryan Jon
// School: Chinese International School

#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef int _;
typedef const long long constant;

constant maxn = 1E7+8;

_ n, x, a[maxn], mx, b[maxn];
bitset<maxn> v;

inline _ read();
inline bool test(_ x);
int main() {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	n = read();
	for(_ i = 1; i <= n; ++i) {
		b[i] = read();
		mx = max(mx, b[i]);
	}
// 	if(mx > 2E5) mx = 1E7;
// 	else mx = 2E5;
    mx = 1E7;
	for(_ i = 7; i <= mx; ++i) if(!v[i] && test(i)) for(_ j = i; j <= mx; j += i) v.set(j);
	a[10000000] = mx+1;
	for(_ i = mx-1; i >= 1; --i) if(!v[i+1]) a[i] = i+1;
	else a[i] = a[i+1];
	
	for(_ i = 1; i <= n; ++i) if(v[b[i]]) puts("-1");
	else printf("%d\n", a[b[i]]);
	
	return 0;
}

inline bool test(_ x) {
	for(; x; x /= 10) if(x%10 == 7) return true;
	return false;
}

inline _ read() {
	_ x = 0;
	char ch = getchar();
	for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
	return x;
}