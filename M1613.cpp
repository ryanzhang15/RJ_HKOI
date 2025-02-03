#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
//constant maxn = 10;

_ n, a[maxn], p[maxn], s = 9E18;

int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= n; ++i) p[i] = p[i-1] + a[i];
    
    for(_ i = 3; i <= n; ++i) {
        _ x, y, z = p[n]-p[i-1], xin = lower_bound(p+1, p+i-1, p[i-1]>>1)-p;
        if(xin != 1 && p[xin]-(p[i-1]>>1) > (p[i-1]>>1)-p[xin-1]) --xin;
        x = p[xin];
        y = p[i-1]-p[xin];
        s = min(s, max(abs(x-y), max(abs(y-z), abs(x-z))));
    }
    
    printf("%lld\n", s);
    
    return 0;
}
