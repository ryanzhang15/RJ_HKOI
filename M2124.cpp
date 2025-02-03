#pragma G++ optimize("Ofast");

#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, q, x, y, lz, sm, sz[maxn], v[maxn];
set<_> h;

int main() {

#ifdef c8korz
	freopen("data.in", "r", stdin);
	freopen("c8k.out", "w", stdout);
#endif

	scanf("%lld%lld", &n, &q);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &v[i]);
		sm += v[i];
		sz[i] = 1;
		h.insert(i);
	}
	sort(v+1, v+1+n);
	for(; q--; ) {
		scanf("%lld", &x);
		if(x == 1) {
			scanf("%lld", &y);
			if(y != 1) {
				for(_ i : h) v[i] = (v[i]+lz)/y;
				set<_>::iterator i, j;
				i = j = h.begin();
				++j;
				stack<_> st;
				for(; j != h.end(); ++j) if(v[*i] == v[*j]) {
					sz[*i] += sz[*j];
					st.push(*j);
				} else ++i;
				for(; !st.empty(); st.pop()) h.erase(st.top());
				sm = 0;
				for(_ i : h) sm += v[i]*sz[i];
				lz = 0;
			}
		} else ++lz;
		printf("%lld\n", sm+n*lz);
	}
	
	return 0;
}

