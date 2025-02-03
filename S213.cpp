#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E4+8;

_ n, m, p = 1;
struct out {
	_ a, b, c, d;
};
queue<out> q;
bool rev, ft;

void left();
void right(_ x);
void leave();
void move(_ xa, _ ya, _ xb, _ yb);
int main() {
	
	scanf("%lld%lld", &n, &m);
	if(m == 2) {
		if(n == 2) {
			puts("3\n"
			"1 1 1 2\n"
			"2 1 2 2\n"
		 	"2 3 1 3");
			exit(0);
		}
		swap(n, m);
		rev = true;
	}
	for(;;) {
		if(!ft) {
			right(1);
			ft = true;
		} else right(2);
		p += 2;
		left();
		p += 2;
	}
	
	return 0;
}

void move(_ xa, _ ya, _ xb, _ yb) {
	q.push((out){xa, ya, xb, yb});
	return;
}

void leave() {
	printf("%lld\n", q.size());
	for(; !q.empty(); q.pop()) printf("%lld %lld %lld %lld\n", rev ? q.front().b : q.front().a, rev ? q.front().a : q.front().b, rev ? q.front().d : q.front().c, rev ? q.front().c : q.front().d);
	exit(0);
}

void right(_ x) {
	move(p+1, x+1, p+1, x);
	move(p+1, x-1, p, x);
	for(_ i = 1; i <= m-x-1; ++i) {
		move(p+1, x+i+1, p, x+i);
		move(p-1, x+i-1, p-1, x+i);
	}
	move(p-1, m, p, m);
	if(p+1 == n) leave();
	ef(p+2 == n) {
		for(_ i = m; i >= 1; i -= 2) {
			move(p+1, i, p+2, i);
			if(i <= 1) leave();
			move(p+3, i, p+2, i-1);
			if(i <= 2) leave();
		}
		leave();
	}
	move(p+3, m-1, p+3, m);
	move(p+1, m, p+2, m);
	move(p+3, m+1, p+3, m);
	return;
}

void left() {
	move(p+1, m-2, p+1, m-1);
	move(p+1, m, p, m-1);
	for(_ i = 1; i <= m-3; ++i) {
		move(p+1, m-i-2, p, m-i-1);	
		move(p-1, m-i, p-1, m-i-1);
	}
	move(p-1, 1, p, 1);
	if(p+1 == n) leave();
	if(p+2 == n) {
		for(_ i = 1; i <= m; i += 2) {
			move(p+1, i, p+2, i);
			if(i >= m) leave();
			move(p+3, i, p+2, i+1);
			if(i >= m-1) leave;	
		}
		leave();
	}
	move(p+3, 2, p+3, 1);
	move(p+1, 1, p+2, 1);
	move(p+3, 0, p+3, 1);
	return;
}