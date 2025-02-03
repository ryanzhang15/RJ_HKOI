
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E2+8;

char a[maxn], b[maxn], s[maxn], c[maxn], d[maxn];
_ n, cnt, tp;
bitset<maxn<<1> o;

void out();
void dfs(_ pc, _ oc);
int main() {
	
	scanf(" %s %s", a+1, b+1);
	n = strlen(a+1);
	for(_ i = 1; i <= n; ++i) {
	    c[i] = a[i];
	    d[i] = b[i];
	}
	sort(c+1, c+1+n);
	sort(d+1, d+1+n);
	for(_ i = 1; i <= n; ++i) if(c[i] != d[i]) {
	    puts("[\n]");
	    exit(0);
	}
	puts("[");
	dfs(1, 1);
	puts("]");
	
	return 0;
}

void dfs(_ pc, _ oc) {
	if(pc > n && oc > n) {
		out();
		return;
	}
	if(pc <= n) {
		o[++cnt] = true;
		s[++tp] = a[pc];
		dfs(pc+1, oc);
		--tp;
		--cnt;
	}
	if(tp && s[tp] == b[oc]) {
		o[++cnt] = false;
		char cur = s[tp--];
		dfs(pc, oc+1);
		s[++tp] = cur;
		--cnt;
	}
	return;
}

void out() {
	for(_ i = 1; i <= (n<<1); ++i) {
		putchar(o[i] ? 'i' : 'o');
		putchar(32);
	}
	putchar(10);
	return;
}