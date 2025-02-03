#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ r, g, w, x, y, z, p, q, s;

_ dv(_ x, _ y);
int main() {
    
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &r, &g, &w, &x, &y, &z, &p, &q);
    for(_ i = 0; i <= r; ++i) {
        _ j = min(dv(g-1-i*x, z-1), dv(r-i*(w-1), y));
        if(j < 1) break;
        s = max(s, i*p+j*q);
    }
    for(_ i = 0; i <= g; ++i) {
        _ j = min(dv(r-1-i*y, w-1), dv(g-i*(z-1), x));
        if(j < 1) break;
        s = max(s, j*p+i*q);
    }
    printf("%lld\n", s+r*p+g*q);
    
    return 0;
}

_ dv(_ x, _ y) {
    if(x & (1LL<<63)) return 0;
    if(!y) return 1E10;
    return x/y;
}
