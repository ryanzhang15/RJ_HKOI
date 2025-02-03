#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E2+8;

_ n, k, x, y, girl[maxn], s;
vector<_> g[maxn];
bool v[maxn];

bool dfs(_ x);
int main() {
	
	scanf("%lld%lld", &n, &k);
	for(; k--; ) {
		scanf("%lld%lld", &x, &y);
		g[x].push_back(y);
	}
	
	for(_ i = 1; i <= n; ++i) s += dfs(i);

	printf("%lld\n", s);
	
	return 0;
}

bool dfs(_ x) {
	for(_ i = 0; i < g[x].size(); ++i) if(!v[g[x][i]]) {
		v[g[x][i]] = true;
		if(!girl[g[x][i]] || dfs(girl[g[x][i]])) {
			v[g[x][i]] = false;
			girl[g[x][i]] = x;
			return true;
		}
	}
	return false;
}