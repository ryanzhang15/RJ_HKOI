#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long _;
typedef vector<_> _v;
typedef const long long constant;

constant maxn = 1E2+8;

char a[maxn];
_ p = 1, n;
_v o;

_v recur();
int main() {
	
	scanf(" %s", a+1);
	n = strlen(a+1);
	o = recur();

	for(_v::iterator i = o.begin(); i != o.end(); ++i) printf("%lld ", *i);
	putchar(10);

	return 0;
}

_v recur() {
	_v rv (10, 0);
	for( ; ;) {
		if(p > n) break;
		if(a[p] == ')') {
			++p;
			break;
		}
		if(a[p+1] == '(') {
			_ t = a[p]^48;
			p += 2;
			_v hold = recur();
			for(_ i = 0; i < 10; ++i) rv[i] += hold[i]*t;
		} else ++rv[a[p++]^48];
		
	}
	return rv;
}

