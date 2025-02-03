#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 30+8;

_ a[maxn], n, rs, sm, t;

void dfs(_ cs, _ st);
int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	sort(a+1, a+1+n, greater<_>());
	for(_ i = 1; i <= n; ++i) sm += a[i];
	for(rs = a[1]; ; ++rs, t = 0) if(!(sm % rs)) dfs(0, ((1<<(n+1))-1) ^ 1);
	
	return 0;
}


void dfs(_ cs, _ st) {
	if(++t > 1E5) return;
	if(!cs && !st) {
		printf("%lld\n", rs);
		exit(0);
	}
	for(_ i = 1; i <= n; ++i) if(st & (1<<i) && a[i]+cs <= rs) dfs((a[i]+cs)%rs, st & ~(1<<i));
	return;
}

/*

30
51 69 75 2 4 90 62 41 98 99 14 41 9 133 6 37 2 19 72 1 44 8 8 21 98 10 10 33 1 24

*/