#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 5E5+8;

_ t[maxn][26], n, m, cnt, h[maxn], f[maxn], p, s, mn;
str in, c;
queue<_> q;
vector<_> g[maxn];
bool e[maxn];

void dfs2(_ x);
void dfs1(_ x);
void make();
int main() {
	
	freopen("ugly.in", "r", stdin);
	freopen("ugly.out", "w", stdout);
	
	memset(h, 4, sizeof h);
	
	h[0] = 0;
	cin >> n >> c >> m;
	for(; m--; ) make();
	q.push(0);
	for(; !q.empty(); q.pop()) for(_ i = 0; i < 26; ++i) if(t[q.front()][i]) {
		q.push(t[q.front()][i]);
		if(q.front()) f[t[q.front()][i]] = t[f[q.front()]][i];
	} else t[q.front()][i] = t[f[q.front()]][i];
	for(_ i = 1; i <= cnt; ++i) g[f[i]].push_back(i);
	dfs1(0);
	e[0] = false;
	dfs2(0);
	for(_ i = c.size()-1; i >= 0; --i) {
		++mn;
		p = t[p][c[i]-'a'];
		if(e[p]) mn = min(mn, h[p]-1);
		s += mn;
	}
	printf("%lld\n", s);
	
	return 0;
}

void make() {
	cin >> in;
	_ p = 0;
	for(_ i = in.size()-1; i >= 0; --i) {
		if(!t[p][in[i]-'a']) t[p][in[i]-'a'] = ++cnt;
		h[t[p][in[i]-'a']] = h[p]+1;
		p = t[p][in[i]-'a'];
	}
	e[p] = true;
	return;
}

void dfs1(_ x) {
	for(_ i : g[x]) {
		e[i] |= e[x];
		dfs1(i);
	}
	return;
}

void dfs2(_ x) {
	for(_ i : g[x]) {
		if(e[x]) h[i] = min(h[i], h[x]);
		dfs2(i);
	}
	return;
}