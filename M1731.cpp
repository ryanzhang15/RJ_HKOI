#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant mod = 1E9+7;
constant big = 1E5;
constant maxn = big+8;
constant srt = 320;

_ n, o[maxn];
_ fc[maxn], iv[maxn];
struct qr {
	_ a, b, id;
	bool operator < (const qr &y) const {
		return a < y.a;
	}
} c;
vector<qr> g[srt+8];

inline _ choose(_ a, _ b);
inline _ inverse(_ x, _ p);
int main() {
	
	fc[0] = 1;
	for(_ i = 1; i <= big; ++i) fc[i] = (fc[i-1]*i)%mod;
	for(_ i = 0; i <= big; ++i) iv[i] = inverse(fc[i], mod-2);
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) { 
		scanf("%lld%lld", &c.a, &c.b);
		c.id = i;
		g[(_)sqrt(c.b)].push_back(c);
	}
	for(_ i = 0; i <= srt; ++i) {
		if(g[i].empty()) continue;	
		sort(g[i].begin(), g[i].end());
		_ t = 0;
		for(_ j = 0; j <= g[i][0].b; ++j) t = (t+choose(g[i][0].a, j))%mod;
		o[g[i][0].id] = t;
		for(_ j = 1; j < g[i].size(); ++j) {
			for(_ k = 1, l = g[i][j-1].a; k <= g[i][j].a-g[i][j-1].a; ++k, ++l) t = (t*2%mod-choose(l, g[i][j-1].b))%mod;
			if(g[i][j].b > g[i][j-1].b) for(_ k = 1, l = g[i][j-1].b+1; k <= g[i][j].b-g[i][j-1].b; ++k, ++l) t = (t+choose(g[i][j].a, l))%mod;
			else for(_ k = 1, l = g[i][j-1].b; k <= g[i][j-1].b-g[i][j].b; ++k, --l) t = (t-choose(g[i][j].a, l))%mod;
			o[g[i][j].id] = (t+mod)%mod;
		}
	}
	for(_ i = 1; i <= n; ++i) printf("%lld\n", o[i]);
	
	return 0;
}

inline _ inverse(_ x, _ p) {
	if(!p) return 1;
	_ c = inverse(x, p>>1);
	c = (c*c)%mod;
	if(p & 1) c = (c*x)%mod;
	return c%mod;
}

inline _ choose(_ a, _ b) {
	return fc[a]*iv[b]%mod*iv[a-b]%mod;
}
