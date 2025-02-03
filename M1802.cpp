#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

_ thr, w, h;
_D s;

void makeHeart(_D w, _D h);
int main() {
	
	scanf("%lld%lld%lld", &thr, &w, &h);
	makeHeart(w, h);
	printf("%.7Lf\n", s);
		
	return 0;
}

void makeHeart(_D w, _D h) {
	if(w < h) swap(w, h);
	_D oa, tm, rm;
	if(w/4 < h) oa = (5.0/8)*w*w/4;
	else oa = (5.0/8)*h*h*4;
	if(oa < thr) return;
	if(w/4 < h) {
		tm = floor(h/(w/4));
		rm = h-(w/4)*tm;
		s += tm*oa;
		makeHeart(w, rm);
	} else {
		tm = floor(w/(h*4));
		rm = w-(h*4)*tm;
		s += tm*oa;
		makeHeart(rm, h);
	}
	return;
}