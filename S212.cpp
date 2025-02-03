#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, k, a[maxn], t[maxn], x, y, cnt;
struct event {
	_ t, dx, p;
	bool operator < (const event &b) const {
		if(t != b.t) return t < b.t;
		return p > b.p;
	}
} e[maxn<<1];
bitset<maxn> v;
deque<_> s;

_ tme(_ x);
int main() {
	
	scanf("%lld%lld", &n, &k);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld%lld", &x, &y);
		e[++cnt] = (event){x, i, 1};
		e[++cnt] = (event){x+tme(y)*60, i, -1};
	}
	sort(e+1, e+1+cnt);
	for(_ i = 1; i <= cnt; ++i) if(~e[i].p) {
		if(s.size() >= 3) a[s[2]] += e[i].t-t[s[2]];
		s.push_front(e[i].dx);
		t[e[i].dx] = e[i].t;
	} else {
		v.set(e[i].dx);
		if(!s.empty() && s[0] == e[i].dx) {
			a[s[0]] += e[i].t-t[s[0]];
			_ e1 = -1, e2 = -1;
			s.pop_front();
			if(!s.empty()) {
				e1 = s.front();
				s.pop_front();
			}
			if(!s.empty()) {
				e2 = s.front();
				s.pop_front();
			}
			for(; !s.empty() && v[s.front()]; ) s.pop_front();
			if(!s.empty()) t[s.front()] = e[i].t;
			if(~e2) s.push_front(e2);
			if(~e1) s.push_front(e1);
		} ef(s.size() >= 2 && s[1] == e[i].dx) {
			a[s[1]] += e[i].t-t[s[1]];
			_ e1 = s.front(), e2 = -1;
			s.pop_front();
			s.pop_front();
			if(!s.empty()) {
				e2 = s.front();
				s.pop_front();
			} 
			for(; !s.empty() && v[s.front()]; ) s.pop_front();
			if(!s.empty()) t[s.front()] = e[i].t;
			if(~e2) s.push_front(e2);
			if(~e1) s.push_front(e1);
		} ef(s.size() >= 3 && s[2] == e[i].dx) {
			a[s[2]] += e[i].t-t[s[2]];
			_ e1 = s.front(), e2 = -1;
			s.pop_front();
			e2 = s.front();
			s.pop_front();
			s.pop_front();
			for(; !s.empty() && v[s.front()]; ) s.pop_front();
			if(!s.empty()) t[s.front()] = e[i].t;
			if(~e2) s.push_front(e2);
			if(~e1) s.push_front(e1);
		}
	}

	for(_ i = 1; i <= n; ++i) printf("%lld\n", a[i]);
	
	return 0;
}

_ tme(_ x) {
	if(x <= 24) return 0;
	ef(x <= 49) return 2;
	ef(x <= 99) return 5;
	ef(x <= 249) return 10;
	ef(x <= 499) return 30;
	ef(x <= 999) return 60;
	ef(x <= 1499) return 120;
	ef(x <= 1999) return 180;
	ef(x <= 2499) return 240;
	return 300;
}