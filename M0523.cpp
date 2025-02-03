#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 8+8;

_ n, a[maxn], b[maxn], mx, mn;
bitset<maxn> va, vb;

int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &b[i]);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) mx += min(a[i], b[j]);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) if(!va[i] && !vb[j] && a[i] == b[j]) {
        va.flip(i);
        vb.flip(j);
        mn += a[i];
    }
    for(_ i = 1; i <= n; ++i) {
        if(!va[i]) mn += a[i];
        if(!vb[i]) mn += b[i];
    }
    printf("%lld %lld\n", mn, mx);
    
    return 0;
}
