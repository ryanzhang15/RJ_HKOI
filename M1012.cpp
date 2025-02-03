#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 8E4+8;

_ n, a[maxn], r[maxn], s;

_ mr(_ x);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= n; ++i) r[a[i]] = i;
    for(_ i = 1; i <= n; ++i) if(r[i] != i) {
        ++s;
        mr(mr(i));
    }
    printf("%lld\n", s);
    
    return 0;
}

_ mr(_ x) {
    if(a[x] == x) return -1;
    _ p = r[x];
    swap(a[r[x]], a[x]);
    r[a[r[x]]] = r[x];
    _ rv = a[r[x]];
    r[x] = x;
    return rv;
}
