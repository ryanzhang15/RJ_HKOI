#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 26+8;

vector<_> g[maxn];
_ n, l, r, md, s, cl[maxn];

bool recur(_ x, _ c);
bool canSplit();
int main() {
	
	for(;;) {
		scanf("%lld", &n);
		if(!n) break;
		if(getchar() == '\r') getchar();
		for(_ i = 1; i <= n; ++i) {
			getchar();
			getchar();
			char ch = getchar();
			g[i].clear();
			for(; ch != '\r' && ch != '\n'; ch = getchar()) g[i].push_back(ch-'A'+1);
			if(ch == '\r') getchar();
		}
		l = 1;
		r = 9;
		s = 10;
		for(; l <= r; ) {
			md = (l+r)>>1;
			if(canSplit()) {
				r = md-1;
				s = md;
			} else l = md+1;
		}
		printf("%lld\n", s);
	}
	
	return 0;
}

bool canSplit() {
	if(md == 1) {
		for(_ i = 1; i <= n; ++i) if(!g[i].empty()) return false;
		return true;
	}
	memset(cl, 0, sizeof cl);
	return recur(1, 0);
}

bool recur(_ x, _ c) {
	if(x > n) return true;
	bitset<maxn> v;
	for(_ i : g[x]) if(i < x) v.set(cl[i]);
	_ b = min(c+1, md);
	for(_ i = 1; i <= b; ++i) if(!v[i]) {
		cl[x] = i;
		if(recur(x+1, max(c, i))) return true;
	}
	return false;
}