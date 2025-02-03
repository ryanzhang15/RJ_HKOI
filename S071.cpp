#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ n, x, y, mnu = 1E18, mxu = -1E18, mnd = 1E18, mxd = -1E18, mx, l, r;

int main() {
	
	scanf("%lld", &n);
	for(; n--; ) {
		scanf("%lld%lld", &x, &y);
		mnu = min(mnu, x-y);
		mxu = max(mxu, x-y);
		mnd = min(mnd, x+y);
		mxd = max(mxd, x+y);
	}
	l = (mnu+mnd+1)>>1;
	r = (mnu+mxd)>>1;
	mx = r-l+(((mnu+mnd)|1) || ((mnu+mxd)|1));
	x = r;
	y = l-mnu;
	l = (mnu+mxd+1)>>1;
	r = (mxu+mxd)>>1;
	if(r-l+(((mnu+mxd)|1) || ((mxd+mxu)|1)) > mx) {
		mx = r-l+(((mnu+mxd)|1) || ((mxd+mxu)|1));
		x = l;
		y = mxd-r;
	}
	printf("%lld %lld\n", x, y);
	
	return 0;
}