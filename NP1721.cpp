
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef unsigned long long u_;
typedef const long long constant;

constant maxn = 1E3+8;

_ T, n, h, f[maxn], top[maxn], bot[maxn], tc, bc, r;
struct hole {
    _ x, y, z;
} a[maxn];
bool s;

_ get(_ x);
bool isTouching(hole a, hole b);
hole getHole();
int main() {
    
    freopen("cheese.in", "r", stdin);
    freopen("cheese.out", "w", stdout);
    
    scanf("%lld", &T);
    for(; T--; ) {
        scanf("%lld%lld%lld", &n, &h, &r);
        tc = bc = 0;
        for(_ i = 1; i <= n; ++i) f[i] = i;
        for(_ i = 1; i <= n; ++i) {
            a[i] = getHole();
            if(a[i].z+r >= h) top[++tc] = i;
            if(a[i].z-r <= 0) bot[++bc] = i;
        }
        for(_ i = 1; i <= n; ++i) for(_ j = i+1; j <= n; ++j) if(isTouching(a[i], a[j])) {
            _ f1 = get(i);
            _ f2 = get(j);
            if(f1 != f2) f[f1] = f2;
        }
        s = false;
        for(_ i = 1; i <= tc && !s; ++i) for(_ j = 1; j <= bc && !s; ++j) if(get(top[i]) == get(bot[j])) s = true;
        puts(s ? "Yes" : "No");
    }
    
    
    return 0;
}

hole getHole() {
    _ x, y, z;
    scanf("%lld%lld%lld", &x, &y, &z);
    return (hole){x, y, z};
}

bool isTouching(hole a, hole b) {
    _ dist = ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y))+((a.z-b.z)*(a.z-b.z));
    return dist <= ((r*r)<<2);
}

_ get(_ x) {
    return f[x] == x ? x : f[x] = get(f[x]);
}
