#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+5;
constant mod = 1E4+7;

_ sum[maxn][2], s[maxn][2], c[maxn], a[maxn];
_ n, m, o;

int main() {
    
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &c[i]);
    for(_ i = 1; i <= n; ++i) {
        ++s[c[i]][i&1];
        sum[c[i]][i&1] = (sum[c[i]][i&1]+a[i])%mod;
    }
    for(_ i = 1; i <= n; ++i) o = (o+i*((s[c[i]][i&1]-2)*a[i]%mod+sum[c[i]][i&1]))%mod;
    printf("%lld\n", o);
    
    return 0;
}
