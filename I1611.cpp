#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, l, u, p[maxn];
struct molecule {
    _ w, id;
    bool operator < (const molecule &b) const {
        return w < b.w;
    }
} a[maxn];

int main() {
    
    scanf("%lld%lld%lld", &n, &l, &u);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i].w);
    for(_ i = 2; i <= n; ++i) a[i].id = i-1;
    sort(a+1, a+1+n);
    for(_ i = 1; i <= n; ++i) p[i] = p[i-1]+a[i].w;
    for(_ i = 1; i <= n; ++i) {
        if(p[i] > u || p[n]-p[n-i-1] < l) continue;
        for(_ j = i; j <= n; ++j) if(l <= p[j]-p[j-i] && p[j]-p[j-i] <= u) {
            printf("%lld\n", i);
            for(_ k = j-i+1; k <= j; ++k) printf("%lld ", a[k].id);
            putchar(10);
            exit(0);
        }
        
    }
    puts("0");
    
    return 0;
}
