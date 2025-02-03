#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 4E4+8;

_ n, a[maxn], d[maxn];
priority_queue<_, vector<_>, greater<_> > q;

int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n-1; ++i) {
		scanf("%lld", &a[i]);
		if(i != n-1) ++d[a[i]];
	}
	for(_ i = 1; i <= n; ++i) if(!d[i]) q.push(i);
	for(_ i = 1; i <= n-2; ++i) {
		printf("%lld %lld\n", q.top(), a[i]);
		q.pop();
		if(!--d[a[i]]) q.push(a[i]);
	}
	printf("%lld %lld\n", a[n-1], q.top());
	
	return 0;
}