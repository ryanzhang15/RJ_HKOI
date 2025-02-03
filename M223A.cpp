#include <list>
#include <set>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <ctime>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <random>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <fstream>
#include <queue>

#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef string str;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 1E4+8;
constant maxm = 5E3+8;

_ n, nr, nb, a[maxn], m;
char o[maxn];
vector<_p> c;
bool dp[maxm][maxm];

void flp(_ x);
int main() {

	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	scanf("%lld%lld", &nr, &nb);

	_ cr = 0, cb = 0, r = 0, b = 0, sm = 0;
	for(_ i = 1; i <= n+1; ++i) if(a[i]) {
		if(a[i-1]) o[i] = o[i-1] == 'R' ? 'B' : 'R';
		else o[i] = 'R';
		if(o[i] == 'R') {
			cr += (a[i]+1)>>1;
			cb += a[i]>>1;
		} else {
			cb += (a[i]+1)>>1;
			cr += a[i]>>1;
		}
	} else {
		o[i] = 'X';
		if(!cr && !cb) continue;
		if(cr > cb) {
			for(_ j = i-1; j >= 1 && a[j]; --j) flp(j);
			swap(cr, cb);
		}
		r += cr;
		b += cb;
		sm += cb-cr;
		c.push_back(mp(cb-cr, i-1));
		cr = cb = 0;
	}
	if(nr < r || nr > r+sm) {
		puts("Impossible");
		exit(0);
	}

	m = (_)c.size();
	_ nd = nr-r;
	dp[0][0] = true;
	for(_ i = 1; i <= m; ++i) {
		for(_ j = nd; j >= 0; --j) {
			if(j >= c[i-1].first) dp[i][j] |= dp[i-1][j-c[i-1].first];
			dp[i][j] |= dp[i-1][j];
		}
	}

	if(!dp[m][nd]) {
		puts("Impossible");
		exit(0);
	}

	_ t = nd;
	for(_ j = m; j >= 1; --j) if(!dp[j-1][t]) {
		t -= c[j-1].first;
		for(_ k = c[j-1].second; k >= 1 && a[k]; --k) flp(k);
	}

	o[n+1] = '\0';
	printf("%s\n", o+1);


	return 0;
}

void flp(_ x) {
	o[x] = o[x] == 'R' ? 'B' : 'R';
	return;
}