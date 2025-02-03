#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;

_ n, m, a[maxn], cnt, t, c;
set<_> l;
set<_>::iterator d[maxn];
bool fd;

int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		l.insert(i);
	}
	for(; l.size() > 1; ) {
		t = m-a[*l.rbegin()] + a[*l.begin()];
		fd = true;
		cnt = 0;
		for(set<_>::iterator i = l.begin(); i != l.end(); ++i) {
			set<_>::iterator j = i;
			++j;
			if(j == l.end()) break;
			c = a[*j]-a[*i];
			if(c < t) {
				t = c;
				fd = false;
				cnt = 1;
				d[1] = j;
			} ef(c == t) d[++cnt] = j;
		}
		if(fd) {
			printf("%lld\n", *l.begin());
			l.erase(l.begin());
		}
		for(_ i = 1; i <= cnt; ++i) {
			printf("%lld\n", *d[i]);
			l.erase(d[i]);
		}
	}
	if(l.size() == 1) printf("%lld\n", *l.begin());
	
	return 0;
}