#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 3E3+8;

_ n, x, t, uk, db;
list<_> a, b;
bitset<maxn> v;

int main() {
	
	scanf("%lld", &n);
	uk = n;
	for(_ i = 1; i <= n; ++i) {
		a.push_back(i);
		b.push_back(-1);
	}
	for(;;) {
		scanf("%lld", &x);
		if(b.front() == -1) {
			v.set(x);
			if(--uk == 1) {
				_ y = -1;
				for(_ i = 1; i <= n; ++i) if(!v[i]) y = i;
				for(list<_>::iterator i = b.begin(); i != b.end(); ++i) if(!~*i) *i = y;
			}
		}
		b.pop_front();
		b.push_front(x);
		scanf("%lld", &x);
		if(x == 2) exit(0);
		if(!x) db = b.front();
		else a.pop_front();
		b.pop_front();
		scanf("%lld", &t);
		for(_ i = 1; i <= t; ++i) {
			b.push_back(b.front());
			b.pop_front();
		}
		if(!x) b.push_back(db);
		if(!~b.front()) {
			puts("0");
			fflush(stdout);
		} else {
			_ ctr = 0;
			for(list<_>::iterator i = a.begin(); i != a.end(); ++i, ++ctr) if(*i == b.front()) break;
			printf("%lld\n", ctr);
			fflush(stdout);
			for(_ i = 1; i <= ctr; ++i) {
				a.push_back(a.front());
				a.pop_front();
			}
		}
	}
	
	return 0;
}