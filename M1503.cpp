#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 1E3+8;

bitset<maxn> h[maxn];
struct coord {
    _ x, y, id;
    bool operator < (const coord &b) const {
        if(x*x+y*y != b.x*b.x+b.y*b.y) return x*x+y*y < b.x*b.x+b.y*b.y;
        return id < b.id;
    }
} a[maxn];
_ n, m, x, y;
_D dp[maxn];

int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
        a[i].id = i;
    }
    for(; m--; ) {
        scanf("%lld%lld", &x, &y);
        h[x][y] = h[y][x] = true;
    }
    sort(a+1, a+1+n);
    for(_ i = 2; i <= n; ++i) dp[i] = -1;
    dp[1] = 0;
    for(_ i = 2; i <= n; ++i) {
        for(_ j = 1; j <= i-1; ++j) if(h[a[j].id][a[i].id] && dp[j] >= 0 && (unsigned long long)(a[i].x*a[i].x)+a[i].y*a[i].y > (unsigned long long)(a[j].x*a[j].x)+a[j].y*a[j].y) dp[i] = max(dp[i], dp[j]+sqrt((_D)(a[j].x-a[i].x)*(a[j].x-a[i].x)+(_D)(a[j].y-a[i].y)*(a[j].y-a[i].y)));
        if(a[i].id == n) {
            printf("%Lf\n", dp[i]);
            exit(0);
        }
    }
    
    
    return 0;
}
