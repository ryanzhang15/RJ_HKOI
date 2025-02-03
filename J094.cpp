#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E4+8;

_ n, m, w[maxn], f[maxn], p[maxn], o[maxn], c, s;

int main() {
    
    scanf("%lld%lld", &n, &m);
    --n;
    for(_ i = 1; i <= n; ++i) scanf("%lld", &w[i]);
    for(_ i = 2; i <= n; ++i) scanf("%lld", &f[i]);
    p[n+1] = m;
    for(_ i = n; i >= 1; --i) p[i] = min(m, p[i+1] - !!w[i+1] + f[i+1]);
    for(_ i = 1; i <= n; ++i) {
        c -= f[i];
        o[i] = min(w[i], p[i]-c);
        s += o[i]*(n+1-i);
        c += o[i];
        if(c < 0) c = 0;
    }
    printf("%lld\n", s);
    for(_ i = 1; i <= n; ++i) printf("%lld ", o[i]);
    putchar(10);
    
    return 0;
}
