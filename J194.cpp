#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxk = 1E3+8;

struct range {
    _ s, e;
} a[maxk];
_ n, k, f[maxk], t, s, x, y;
bool v[maxk];

_ find(_ x);
int main() {
    
    scanf("%lld%lld", &n, &k);
    for(_ i = 1; i <= k; ++i) f[i] = i;
    for(_ i = 1; i <= k; ++i) {
        scanf("%lld%lld", &x, &y);
        a[i].s = y;
        a[i].e = y+n-x;
        for(_ j = 1; j <= i-1; ++j) {
            t = find(j);
            if(t == i) continue;
            if(min(a[i].e, a[t].e)+1 >= max(a[i].s, a[t].s)) {
                a[i].s = min(a[i].s, a[t].s);
                a[i].e = max(a[i].e, a[t].e);
                f[t] = i;
            }
        }
    }
    s = -k;
    for(_ i = 1; i <= k; ++i) if(!v[find(i)]) {
        _ fnd = find(i);
        v[fnd] = true;
        _ sz = a[fnd].e - a[fnd].s + 1;
        if(sz & 1) s += ((sz+1)>>1)*sz;
        else s += (sz+1)*(sz>>1);
    }
    printf("%lld\n", s);
    
    return 0;
}

_ find(_ x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
