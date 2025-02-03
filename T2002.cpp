#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 3E2+8;
constant maxs = (maxn*maxn)>>1;

_ n, k, a[maxn], b[maxn], p[maxn], r[maxn], c[2], s[2][maxs];

int main() {
    
    scanf("%lld%lld", &n, &k);
    
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        b[i] = a[i];
    }
    
    for(_ i = 1; i <= n; ++i) p[i] = i;
    for(_ i = 1, j = 1; j <= k-1; ++j, i += 2) swap(p[i], p[i+1]);
    for(_ i = 1; i <= n; ++i) r[p[i]] = i;
    
    for(bool o = true; o; ) {
        o = false;
        for(_ i = 1; i <= n-1; ++i) if(r[a[i]] < r[a[i+1]]) {
            o = true;
            swap(a[i], a[i+1]);
            s[0][++c[0]] = i;
        }
    }
    
    for(bool o = true; o; ) {
        o = false;
        for(_ i = 1; i <= n-1; ++i) if(r[b[i]] > r[b[i+1]]) {
            o = true;
            swap(b[i], b[i+1]);
            s[1][++c[1]] = i;
        }
    }
    
    if(c[0] < c[1]) {
        printf("%lld\n", c[0]);
        for(_ i = 1; i <= c[0]; ++i) printf("%lld ", s[0][i]);
        if(c[0]) putchar(10);
    } else {
        printf("%lld\n", c[1]);
        for(_ i = 1; i <= c[1]; ++i) printf("%lld ", s[1][i]);
        if(c[1]) putchar(10);
    }
    
    return 0;
}
