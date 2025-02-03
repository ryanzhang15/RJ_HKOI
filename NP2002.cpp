#include <bits/stdc++.h>

using namespace std;

typedef long long _;

_ c[1000], n, w;

int main() {
    
    freopen("live.in", "r", stdin);
    freopen("live.out", "w", stdout);
    
    scanf("%lld%lld", &n, &w);
    for(_ i = 1; i <= n; ++i) {
        {
            _ x;
            scanf("%lld", &x);
            ++c[x];
        }
        _ x = 0;
        for(_ j = 600; j >= 0; --j) {
            x += c[j];
            if(x >= max(1LL, i*w/100)) {
                printf("%lld ", j);
                break;
            }
        }
    }
    putchar(10);

    return 0;
}
