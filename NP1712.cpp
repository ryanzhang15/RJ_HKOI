#include <cstdio>
#include <cstring>
#include <cctype>
#include <bitset>
#include <iostream>
#include <stack>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;

#define maxn 108

_ t, n, r;
str c, in[maxn];

_ analysis();
_ getCom(str buf);
_ getNum(str buf, _ &dx);
int main() {

	freopen("complexity.in", "r", stdin);
	freopen("complexity.out", "w", stdout);

	scanf("%lld", &t);
	for(; t--; ) {
		scanf("%lld", &n);
		getline(cin, c);
		for(_ i = 1; i <= n; ++i) getline(cin, in[i]);
		r = analysis();
		if(!~r) puts("ERR");
		ef(r == getCom(c)) puts("Yes");
		else puts("No");
	}

	return 0;
}

_ getNum(str buf, _ &dx) {
	_ rv = 0;
	for(; !isdigit(buf[dx]); ++dx) if(buf[dx] == 'n') {
		++dx;
		return 1E7;
	}
	for(; isdigit(buf[dx]); ++dx) rv = (rv<<3)+(rv<<1)+(buf[dx]^48);
	return rv;
}

_ getCom(str buf) {
	_ hd = 4;
	if(buf[3] == 'n') return getNum(buf, hd);
	return 0;
}

_ analysis() {
	_ rv = 0, c = 0, x, y, z, o = -1;
	stack<_> s;
	bitset<maxn> v, u;
	for(_ i = 1; i <= n; ++i) if(in[i][0] == 'E') {
		if(s.empty()) return -1;
		x = s.top();
		s.pop();
		v.reset(x);
		if(u[x]) --c;
		u.reset(x);
		if(o == x) o = -1;
	} else {
		_ t = in[i][2]-'a';
		if(v[t]) return -1;
		v.set(t);
		s.push(t);
		x = 4;
		y = getNum(in[i], x);
		z = getNum(in[i], x);
		if(y > z) {
			if(!~o) o = t;
		} ef(z-y > 1E4) {
			if(!~o) {
				rv = max(rv, ++c);
				u.set(t);
			}
		}
	}
	return s.empty() ? rv : -1;
}

