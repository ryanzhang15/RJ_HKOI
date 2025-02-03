#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 1E2+8;

_ n, m, k, cl = 1, a[maxn][maxn], b[maxn][maxn], sa = -1E11, sb = -1E11, cnt;
struct node {
	_ x, y, pt;
	bool operator < (const node &b) const {
		return pt < b.pt;
	}
};
priority_queue<node> q;

int main() {
		
	scanf("%lld%lld%lld", &n, &m, &k);
	if(!((n*m)&1) && k == n*m/2) {
		for(_ i = 1; i <= n && cnt < k; ++i) for(_ j = 1; j <= m; ++j) if(!((i-j)%2)) {
			a[i][j] = 1;
			if(++cnt == k) break;
		}
		for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= m; ++j) printf("%lld", a[i][j]);
		exit(0);
	}
	if(k > (n*m+1)/2) {
		cl = 0;
		for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) a[i][j] = b[i][j] = 1;
		k = n*m-k;
	}
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) if(!((i+j)&1)) q.push((node){i, j, (_)(i != 1) + (i != n) + (j != 1) + (j != m)});
	if(q.size() >= k) {
		sa = 0;
	 	for(_ i = k; i--; ) {
			node t = q.top();
			q.pop();
			sa += t.pt;
			a[t.x][t.y] = cl;
		}
	}
	for(; !q.empty(); ) q.pop();
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) if((i+j)&1) q.push((node){i, j, (_)(i != 1) + (i != n) + (j != 1) + (j != m)});
	if(q.size() >= k){
		sb = 0;
		for(_ i = k; i--; ) {
			node t = q.top();
			q.pop();
			sb += t.pt;
			b[t.x][t.y] = cl;
		}
	}
	if(sa > sb) for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) b[i][j] = a[i][j];
	for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= m; ++j) printf("%lld", b[i][j]);

	return 0;
}


