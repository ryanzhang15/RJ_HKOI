#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant big = 101;
constant maxn = big+8;
constant mod = 1E9+7;

struct matrix {
    vector<vector<_> > data;
    _ n, m;
    inline void init(_ x, _ y) {
        n = x;
        m = y;
        data = vector<vector<_> >(n+1, vector<_>(m+1, 0));
        return;
    }
} x, y;
_ n, k, a[maxn], c;

inline matrix matrExp(matrix x, _ p);
inline matrix mult(matrix a, matrix b);
int main() {
	
	scanf("%lld%lld", &n, &k);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &c);
		++a[c];
	}
	for(_ i = big; i >= 1; --i) a[i] = (a[i]-a[i-1]+mod)%mod;
	++a[1];
	x.init(big, big);
	for(_ i = 1; i <= big-1; ++i) x.data[i][i+1] = 1;
	for(_ i = 1; i <= big; ++i) x.data[big][i] = a[big-i+1];
	x = matrExp(x, k-1);
	y.init(big, 1);
	y.data[0][1] = 1;
	for(_ i = 1; i <= big; ++i) for(_ j = 1; j <= i; ++j) y.data[i][1] = (y.data[i][1]+a[j]*y.data[i-j][1]%mod)%mod;
	if(k == 1) {
		printf("%lld\n", y.data[1][1]);
		exit(0);
	}
	y = mult(x, y);
	printf("%lld\n", y.data[1][1]);
	
	return 0;
}

inline matrix mult(matrix a, matrix b) {
    matrix rv;
    rv.init(a.n, b.m);
    for(_ i = 1; i <= a.n; ++i) for(_ j = 1; j <= b.m; ++j) for(_ k = 1; k <= a.m; ++k) rv.data[i][j] = (rv.data[i][j]+a.data[i][k]*b.data[k][j]%mod)%mod;
    return rv;
}

inline matrix matrExp(matrix x, _ p) {
    if(p <= 1) return x;
    matrix c = matrExp(x, p>>1);
    c = mult(c, c);
    if(p & 1) c = mult(c, x);
    return c;
}

