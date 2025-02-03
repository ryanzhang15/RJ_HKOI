

#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 64+8;

_ n, k;
bitset<maxn> p;

struct matrix {
    vector<vector<_> > data;
    _ n, m;
    void init(_ x, _ y) {
        n = x;
        m = y;
        vector<_> z;
        for(_ i = 1; i <= m+1; ++i) z.push_back(0);
        for(_ i = 1; i <= n+1; ++i) data.push_back(z);
        return;
    }
} x, y;

matrix matrExp(matrix x, _ p);
matrix mult(matrix a, matrix b);
int main() {
    
    scanf("%lld%lld", &n, &k);
    for(_ i = 2; i <= n; ++i) {
        bool ok = true;
        for(_ j = 2; j <= i-1; ++j) if(!(i % j)) ok = false;
        if(ok) p.set(i);
    }
    x.init(n, n);
    y.init(n, 1);
    for(_ i = 1; i <= n; ++i) y.data[i][1] = 1;
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) if((abs(i-j) > 1 && ((i > j && p[i-j]) || (i < j && !p[j-i]))) || i == j) x.data[i][j] = 1;
    x = matrExp(x, k);
    y = mult(x, y);
    for(_ i = 1; i <= n; ++i) printf("%lld", y.data[i][1]);
    putchar(10);
    
    return 0;
}

matrix mult(matrix a, matrix b) {
    matrix rv;
    rv.init(a.n, b.m);
    for(_ i = 1; i <= a.n; ++i) for(_ j = 1; j <= b.m; ++j) for(_ k = 1; k <= a.m; ++k)
        rv.data[i][j] = (rv.data[i][j]+a.data[i][k]*b.data[k][j]) & 1;
    return rv;
}

matrix matrExp(matrix x, _ p) {
    if(p == 1) return x;
    matrix c = matrExp(x, p>>1);
    c = mult(c, c);
    if(p & 1) c = mult(c, x);
    return c;
}


