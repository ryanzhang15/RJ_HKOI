#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxm = 5E2+8;

_ n, m, a[maxn], f[maxm], s, x, y;

int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    s = n;
    for(_ i = 1; i <= n-1; ++i) {
        if(n%i) continue;
        x = 0;
        for(_ j = 1; j <= i; ++j) {
            y = 0;
            for(_ k = j; k <= n; k += i) y = max(y, ++f[a[k]]);
            for(_ k = j; k <= n; k += i) --f[a[k]];
            x += y;
        }
        s = min(s, n-x);
    }
    printf("%lld\n", s);
    
    return 0;
}
