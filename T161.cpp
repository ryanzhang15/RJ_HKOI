#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, k, p = 1, x, e, t[maxn];
struct _p {
	_ first, second;
	bool operator < (const _p &b) const {
		if(first != b.first) return first > b.first;
		if(first == 2) return t[second] < t[b.second];
		return second < b.second;	
	}
};
priority_queue<pair<_p, _> > q;
bool v[maxn];
_p a[maxn];
char ch;
vector<_> s;

int main() {
	
	memset(t, 4, sizeof t);
	
	scanf("%lld%lld", &n, &k);
	for(_ i = 1; i <= n; ++i) {
		scanf(" %c", &ch);
		a[i].first = 1+(ch == 'T');
		scanf("%lld", &a[i].second);
		if(a[i].first == 1) t[a[i].second] = min(t[a[i].second], i);
	}
	for(_ i = k; i--; ) {
		scanf("%lld", &x);
		for(; p <= x; ++p) q.push(make_pair(a[p], p));
		_ mn = -1, dx;
		for(; !q.empty(); q.pop()) {
			if(v[q.top().first.second]) continue;
			v[q.top().first.second] = true;
			mn = q.top().first.first;
			dx = q.top().second;
			break;
		}
		if(!~mn) {
			puts("Lose");
			exit(0);
		}
		s.push_back(dx);
		e += mn;
	}
	sort(s.begin(), s.end());
	printf("%lld %lld\n", e, k);
	for(_ i : s) printf("%lld ", i);
	putchar(10);
	
	return 0;
}