#pragma G++ optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma G++ target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <cstdio>
#include <queue>
#include <algorithm>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxin = 1E5+8;
constant maxn = 8E6+8;

_ n, m, nm, dn, k, t, x, c, cnt, in[maxin], a[maxn];
struct _p {
	_ first, second;
};
queue<_p> q[3];

inline void write(_ x);
inline _ read();
inline _p mp(_ x, _ y);
int main() {
	
	freopen("earthworm.in", "r", stdin);
	freopen("earthworm.out", "w", stdout);
	
	n = read();
	m = read();
	k = read();
	nm = read();
	dn = read();
	t = read();
	for(_ i = 1; i <= n; ++i) in[i] = read();
	sort(in+1, in+1+n, greater<_>());
	for(_ i = 1; i <= n; ++i) q[0].push(mp(in[i], 1));
	for(_ i = 1, j = t; i <= m; ++i) {
		if(!q[0].empty() && (q[1].empty() || q[0].front().first+(i-q[0].front().second)*k > q[1].front().first+(i-q[1].front().second)*k) && (q[2].empty() || q[0].front().first+(i-q[0].front().second)*k > q[2].front().first+(i-q[2].front().second)*k)) x = 0;
		ef(!q[1].empty() && (q[2].empty() || q[1].front().first+(i-q[1].front().second)*k > q[2].front().first+(i-q[2].front().second)*k)) x = 1;
		else x = 2;
		c = q[x].front().first+(i-q[x].front().second)*k;
		if(i == j) {
			write(c);
			putchar(32);
			j += t;
		}
		q[x].pop();
		q[1].push(mp(c*nm/dn, i+1));
		q[2].push(mp(c-c*nm/dn, i+1));
	}
	putchar(10);
	for(_ i = 1; ; ++i) {
	    if(q[0].empty() && q[1].empty() && q[2].empty()) break;
		if(!q[0].empty() && (q[1].empty() || q[0].front().first+(m+1-q[0].front().second)*k > q[1].front().first+(m+1-q[1].front().second)*k) && (q[2].empty() || q[0].front().first+(m+1-q[0].front().second)*k > q[2].front().first+(m+1-q[2].front().second)*k)) x = 0;
		ef(!q[1].empty() && (q[2].empty() || q[1].front().first+(m+1-q[1].front().second)*k > q[2].front().first+(m+1-q[2].front().second)*k)) x = 1;
		else x = 2;
		a[++cnt] = q[x].front().first+(m+1-q[x].front().second)*k;
		q[x].pop();
	}
	for(_ i = t; i <= cnt; i += t) {
		write(a[i]);
		putchar(32);
	}
	putchar(10);
	
	return 0;
}

inline _p mp(_ x, _ y) {
	return (_p){x, y};
}

inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar_unlocked()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline void write(_ x) {
    if(x < 0) {
        putchar_unlocked('-');
        write(-x);
        return;
    }
    if(x > 9) write(x/10);
    putchar_unlocked((x%10)^48);
    return;
}