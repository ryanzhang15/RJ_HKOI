#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

_ n;
map<char, str> p;
bitset<300> f, b;
char c;
str t = "   ";

str getExpr(char c);
inline char gc();
int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) {
		c = gc();
		t[0] = gc();
		t[1] = gc();
		t[2] = gc();
		if(t[1] == '-') b.set(c);
		p[c] = t;
	}
	c = gc();
	putchar(c);
	putchar('=');
	cout << getExpr(c) << endl;
	
	return 0;
}

inline char gc() {
	char ch = getchar();
	for(; ch == '\r' || ch == '\n' || ch == '='; ) ch = getchar();
	return ch;
}

str getExpr(char c) {
	str rv;
	bool trp = p[c][1] == '/' && b[p[c][0]];
	if(trp) rv += '(';
	if(p[c][0] >= '0' && p[c][0] <= '9') rv += p[c][0];
	else rv += getExpr(p[c][0]);
	if(trp) rv += ')';
	rv += p[c][1];
	trp = b[p[c][2]] || (p[c][1] == '/' && !(p[c][2] >= '0' && p[c][2] <= '9'));
	if(trp) rv += '(';
	if(p[c][2] >= '0' && p[c][2] <= '9') rv += p[c][2];
	else rv += getExpr(p[c][2]);
	if(trp) rv += ')';
	return rv;
}


/*
3
A=B-B
c=3/2
B=c/1
A
*/