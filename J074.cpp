#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 6E3+8;
constant maxt = 6E6+8;

struct plan {
    _D a, b;
    bool operator < (const plan &t) const {
        if(a != t.a) return a < t.a;
        return b < t.b;
    }
} a[maxn];
_ n, cnt = 1, m;
_D in, o[maxt];

int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%Lf%Lf", &a[i].a, &a[i].b);
    sort(a+1, a+1+n);
    for(_D i = 0; i < 6E6; ++i) {
        for(; cnt < n && a[cnt].a+a[cnt].b*i/1E3 > a[cnt+1].a+a[cnt+1].b*i/1E3; ) ++cnt;
        o[(_)i] = a[cnt].a+a[cnt].b*i/1E3;
    }
    scanf("%lld", &m);
    for(; m--; ) {
        scanf("%Lf", &in);
        printf("%.3Lf\n", o[(_)round(in*1E3)]+0.0000001);
    }
    
    
    return 0;
}
