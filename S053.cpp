#include <bits/stdc++.h>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E3+8;

_ n, a[maxn], d;
bitset<maxn> v, o;

int main() {
    
    scanf("%lld", &n);
    n <<= 1;
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    sort(a+1, a+1+n);
    for(_ i = 2; i <= n; ++i, v.reset(), o.reset()) {
        d = a[i]-a[1];
        _ p1 = 1, p2 = i;
        for(;;) {
            for(; v[p1]; ) ++p1;
            if(p1 > n) goto out;
            p2 = p1+1;
            for(; (v[p2] || a[p2] - a[p1] != d) && p2 <= n; ) ++p2;
            if(p2 > n) break;
            v[p1] = v[p2] = o[p1] = true;
        }
    }
    
out:
    printf("%lld\n", d);
    for(_ i = 1; i <= n; ++i) if(o[i]) printf("%lld\n", a[i]);
    
    return 0;
}
