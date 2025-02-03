#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 2E6+8;

_ n, p;
char a[maxn];
struct pr {
	_ c;
	_ x, y;
};

pr dfs();
int main() {

	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);

	scanf("%s", a+1);
	n = strlen(a+1);
	a[n+1] = ')';
	p = 1;
	pr s = dfs();
	printf("%lld\n%lld %lld\n", s.c, s.x, s.y);

	return 0;
}

pr dfs() {
//	puts("entering dfs!");
	vector<pr> g;
	bool ad = false;
	for(; a[p] != ')'; ++p) {
		pr t;
		if(a[p] == '(') {
			++p;
			t = dfs();
		} ef(a[p] == '&') {
			ad = true;
			continue;
		} ef(a[p] == '|') continue;
		else t = (pr){a[p]^48, 0, 0};
		if(ad) {
			ad = false;
			pr c = g.back();
			g.pop_back();
			if(!c.c) g.push_back((pr){0, c.x+1, c.y});
			else g.push_back((pr){c.c&t.c, c.x+t.x, c.y+t.y});
		} else g.push_back(t);
	}
	pr rv = g[0];
	for(_ i = 1; i < g.size(); ++i) {
		if(rv.c) rv = (pr){1, rv.x, rv.y+1};
		else rv = (pr){rv.c|g[i].c, rv.x+g[i].x, rv.y+g[i].y};
	}
	return rv;
}
