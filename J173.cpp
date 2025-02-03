#include <cstdio>
#include <map>
#include <algorithm>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxlog = 1E2+8;

_ big, ln[maxlog], q, xx, y, z, cz;
map<pair<pair<_, _>, pair<_, _> >, pair<pair<_, _>, _> > x;

pair<pair<_, _>, _> query(_ l, _ r, _ c, _ w);
int main() {

	ln[1] = 1;
	ln[2] = 2;
	for(big = 3; ln[big-1] <= 1E18; ++big) ln[big] = ln[big-1]+ln[big-2];
	--big;
	//printf("%lld\n", big);
	//for(_ i = 1; i <= big; ++i) printf("%lld ", ln[i]);
	//printf("\n------\n");
	scanf("%lld", &q);
	for(; q--; ) {
		scanf("%lld%lld%lld", &xx, &y, &z);
		if(!z) cz = 1;
		ef(z == 1) cz = 2;
		ef(z == 10) cz = 3;
		ef(z == 11) cz = 4;
		printf("%lld\n", query(xx, y, big, cz).second);
	}
	
	return 0;
}

pair<pair<_, _>, _> query(_ l, _ r, _ c, _ w) {
	if(x.count(make_pair(make_pair(l, r), make_pair(c, w)))) return x[make_pair(make_pair(l, r), make_pair(c, w))];
	pair<pair<_, _>, _> rv;
	if(c == 1) rv = make_pair(make_pair(0, 0), 0);
	ef(c == 2) {
		if(l == 1 && r == 2) rv = make_pair(make_pair(0, 1), w == 2);
		ef(l == 1 && r == 1) rv = make_pair(make_pair(0, 0), 0);
		ef(l == 2 && r == 2) rv = make_pair(make_pair(1, 1), 0);
	}
	ef(r <= ln[c-1]) rv = query(l, r, c-1, w);
	ef(l > ln[c-1]) rv = query(l-ln[c-1], r-ln[c-1], c-2, w);
	else {
		pair<pair<_, _>, _> q1 = query(l, ln[c-1], c-1, w), q2 = query(1, r-ln[c-1], c-2, w);
		rv.first.first = q1.first.first;
		rv.first.second = q2.first.second;
		rv.second = q1.second + q2.second;
		if(q1.first.second == 0 && q2.first.first == 0 && w == 1) ++rv.second;
		if(q1.first.second == 0 && q2.first.first == 1 && w == 2) ++rv.second;
		if(q1.first.second == 1 && q2.first.first == 0 && w == 3) ++rv.second;
		if(q1.first.second == 1 && q2.first.first == 1 && w == 4) ++rv.second;
	}
	//printf("l:%lld r:%lld c:%lld w:%lld rv.first.first:%lld rv.first.second:%lld rv.second:%lld\n", l, r, c, w, rv.first.first, rv.first.second, rv.second);
	return x[make_pair(make_pair(l, r), make_pair(c, w))] = rv;
}