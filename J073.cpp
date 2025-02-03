#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E2+8;
_ n, c, x, b[maxn][2], mx, t, f;

int main() {
    
    scanf("%lld%lld", &n, &c);
    for(_ i = 0; i <= n-1; ++i) for(_ j = 0; j <= n-1; ++j) {
        scanf("%lld", &x);
        f |= x;
        if(i == j) continue;
        t = 0;
        for(_ k = i; k != j; k = (k+1)%n) {
            if(!k && i) t = 1;
            b[k][t] += x;
        }
    }
    for(_ i = 0; i <= n-1; ++i) mx = max(mx, max((_)ceil(((long double)(b[i][0]+b[i][1]))/c), (_)ceil(((long double)(b[i][1]))/c)+1));
    if(!f) puts("0");
    else printf("%lld\n", mx);
    
    return 0;
}
