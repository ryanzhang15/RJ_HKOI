
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E6+8;

_ n, m, a[maxn], j = 1, s = 0, c = ~0, l = 1E18;

int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= m; ++i) scanf("%lld", &a[i]);
    l = m+1;
    for(_ i = 1; i <= m; ++i) {
        for(; j <= m && s < n; ++j) s += a[j];
        if(s == n && j-i < l) {
            l = j-i;
            c = i;
        }
        s -= a[i];
    }
    if(!~c) puts("Impossible");
    else printf("%lld %lld\n", c, l);
    
    return 0;
}
